#include "User.h"
#include <utility>

namespace Notes {

User::User(std::string username)
    : m_username(std::move(username))
{
}

std::string_view User::getUsername() const noexcept {
    return m_username;
}

const Notes& User::getNotes() const noexcept {
    return m_notes;
}

Notes& User::getNotes() noexcept {
    return m_notes;
}

bool User::createNote(std::string title, std::unique_ptr<Content> content) {
    if (!content) {
        return false;
    }
    
    auto note = std::make_unique<Note>(std::move(title), std::move(content));
    return m_notes.addNote(std::move(note));
}

bool User::deleteNote(std::string_view title) {
    return m_notes.removeNote(title);
}

std::optional<const Note*> User::findNote(std::string_view title) const {
    return m_notes.findNote(title);
}

} // namespace Notes
