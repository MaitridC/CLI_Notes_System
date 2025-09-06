#include "Storage.h"
#include "TextContent.h"
#include <fstream>
#include "../include/third_party/json.hpp"

namespace Notes {

Storage::Storage(std::filesystem::path storagePath)
    : m_storagePath(std::move(storagePath))
{
}

bool Storage::save(const Notes& notes) const {
    try {
        std::ofstream file(m_storagePath);
        if (!file) {
            return false;
        }

        nlohmann::json notesJson = nlohmann::json::array();
        
        for (const auto& note : notes) {
            nlohmann::json noteJson;
            noteJson["title"] = note->getTitle();
            noteJson["content"] = note->getContent();
            noteJson["created_at"] = std::chrono::system_clock::to_time_t(
                note->getCreatedAt()
            );
            notesJson.push_back(noteJson);
        }

        file << std::setw(4) << notesJson << std::endl;
        return true;
    } catch (...) {
        return false;
    }
}

std::optional<Notes> Storage::load() const {
    try {
        std::ifstream file(m_storagePath);
        if (!file) {
            return std::nullopt;
        }

        nlohmann::json notesJson;
        file >> notesJson;

        Notes notes;
        for (const auto& noteJson : notesJson) {
            auto note = std::make_unique<Note>(
                noteJson["title"].get<std::string>(),
                std::make_unique<TextContent>(noteJson["content"].get<std::string>())
            );
            notes.addNote(std::move(note));
        }

        return notes;
    } catch (...) {
        return std::nullopt;
    }
}

const std::filesystem::path& Storage::getPath() const noexcept {
    return m_storagePath;
}

bool Storage::setPath(const std::filesystem::path& newPath) {
    if (!std::filesystem::exists(newPath.parent_path())) {
        return false;
    }
    m_storagePath = newPath;
    return true;
}

} // namespace Notes
