#include "Notes.h"
#include <algorithm>

namespace Notes {

bool Notes::addNote(std::unique_ptr<Note> note) {
    if (!note) {
        return false;
    }

    auto titleExists = std::any_of(m_notes.begin(), m_notes.end(),
        [&note](const auto& existing) {
            return existing->getTitle() == note->getTitle();
        });

    if (titleExists) {
        return false;
    }

    m_notes.push_back(std::move(note));
    return true;
}

std::optional<const Note*> Notes::findNote(std::string_view title) const {
    auto it = std::find_if(m_notes.begin(), m_notes.end(),
        [title](const auto& note) {
            return note->getTitle() == title;
        });

    return it != m_notes.end() ? std::optional<const Note*>{it->get()} 
                              : std::nullopt;
}

bool Notes::removeNote(std::string_view title) {
    auto it = std::find_if(m_notes.begin(), m_notes.end(),
        [title](const auto& note) {
            return note->getTitle() == title;
        });

    if (it == m_notes.end()) {
        return false;
    }

    m_notes.erase(it);
    return true;
}

size_t Notes::size() const noexcept {
    return m_notes.size();
}

bool Notes::empty() const noexcept {
    return m_notes.empty();
}

void Notes::clear() noexcept {
    m_notes.clear();
}

} // namespace Notes
