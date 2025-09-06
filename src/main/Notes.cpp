#include "Notes.h"
#include <algorithm>

namespace Notes {

/**
 * @brief Adds a new note to the collection.
 * @param note A unique pointer to the Note object to be added. 
 * @return `true` if the note was added successfully, `false` otherwise.
 */
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

/**
 * @brief Finds a note by its title.
 * @param title The title of the note to find.
 * @return An `std::optional` containing a constant pointer to the found note if
 * it exists, or `std::nullopt` otherwise. This provides a safe way to handle
 * cases where the note is not found.
 */
std::optional<const Note*> Notes::findNote(std::string_view title) const {
    auto it = std::find_if(m_notes.begin(), m_notes.end(),
        [title](const auto& note) {
            return note->getTitle() == title;
        });

    return it != m_notes.end() ? std::optional<const Note*>{it->get()} 
                              : std::nullopt;
}

/**
 * @brief Removes a note from the collection by its title.
 * @param title The title of the note to remove.
 * @return `true` if a note with the specified title was found and removed, `false`
 * if no such note was found.
 */
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

/**
 * @brief Gets the number of notes in the collection.
 * @return The number of notes as a `size_t`.
 */
size_t Notes::size() const noexcept {
    return m_notes.size();
}

/**
 * @brief Checks if the collection is empty.
 * @return `true` if the collection contains no notes, `false` otherwise.
 */
bool Notes::empty() const noexcept {
    return m_notes.empty();
}

/**
 * @brief Removes all notes from the collection.
 */
void Notes::clear() noexcept {
    m_notes.clear();
}

} // namespace Notes
