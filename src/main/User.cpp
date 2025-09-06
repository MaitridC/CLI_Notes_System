#include "User.h"
#include <utility>

namespace Notes {

/**
 * @brief Constructs a new User object.
 * @param username The username for the new user. `std::move` is used to
 * transfer ownership of the string, which is more efficient than a copy.
 */
User::User(std::string username)
    : m_username(std::move(username))
{
}

/**
 * @brief Gets the username of the user.
 * @return A `std::string_view` providing a non-owning, read-only view of the
 * username. This avoids unnecessary memory allocation and copying.
 */
std::string_view User::getUsername() const noexcept {
    return m_username;
}

/**
 * @brief Gets a constant reference to the user's notes.
 * @return A constant reference to the `Notes` collection.
 */
const Notes& User::getNotes() const noexcept {
    return m_notes;
}

/**
 * @brief Gets a mutable reference to the user's notes.
 * @return A reference to the `Notes` collection, allowing the caller to
 * modify the notes.
 */
Notes& User::getNotes() noexcept {
    return m_notes;
}

/**
 * @brief Creates and adds a new note to the user's collection.
 * @param title The title of the new note.
 * @param content A unique pointer to the content of the note. This function takes
 * ownership of the content object.
 * @return `true` if the note was added successfully, `false` otherwise.
 */
bool User::createNote(std::string title, std::unique_ptr<Content> content) {
    if (!content) {
        return false;
    }
   
    auto note = std::make_unique<Note>(std::move(title), std::move(content));
    return m_notes.addNote(std::move(note));
}

/**
 * @brief Deletes a note by its title.
 * @param title A `std::string_view` representing the title of the note to delete.
 * @return `true` if the note was found and removed, `false` otherwise.
 */
bool User::deleteNote(std::string_view title) {
    return m_notes.removeNote(title);
}

/**
 * @brief Finds a note by its title.
 * @param title A `std::string_view` representing the title of the note to find.
 * @return An `std::optional` containing a constant pointer to the found note if
 * it exists, or `std::nullopt` if it does not.
 */
std::optional<const Note*> User::findNote(std::string_view title) const {
    return m_notes.findNote(title);
}

} // namespace Notes
