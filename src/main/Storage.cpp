#include "Storage.h"
#include "TextContent.h"
#include <fstream>
#include "../include/third_party/json.hpp"

namespace Notes {

/**
 * @brief Constructs a new Storage object with a specified path.
 * @param storagePath The file path where the notes will be stored.
 */
Storage::Storage(std::filesystem::path storagePath)
    : m_storagePath(std::move(storagePath))
{
}

/**
 * @brief Saves a collection of notes to a file in JSON format.
 * @param notes The collection of notes to save.
 * @return `true` if the notes were saved successfully, `false` otherwise.
 */
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

        // Write the JSON array to the file with 4-space indentation for readability.
        file << std::setw(4) << notesJson << std::endl;
        return true;
    } catch (...) {
        // Catch any exceptions that might occur during file I/O or JSON processing.
        return false;
    }
}

/**
 * @brief Loads a collection of notes from a JSON file.
 * @return An `std::optional` containing a `Notes` object if the notes were loaded
 * successfully, or `std::nullopt` otherwise.
 */
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
        // Catch any exceptions during file I/O or JSON parsing.
        return std::nullopt;
    }
}

/**
 * @brief Gets the current storage file path.
 * @return A constant reference to the `std::filesystem::path` of the storage file.
 */
const std::filesystem::path& Storage::getPath() const noexcept {
    return m_storagePath;
}

/**
 * @brief Sets a new storage file path.
 * @param newPath The new file path to use for storage.
 * @return `true` if the path was set successfully, `false` if the parent
 * directory of the new path does not exist.
 */
bool Storage::setPath(const std::filesystem::path& newPath) {
    if (!std::filesystem::exists(newPath.parent_path())) {
        return false;
    }
    m_storagePath = newPath;
    return true;
}

} // namespace Notes
