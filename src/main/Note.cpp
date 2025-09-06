#include "Note.h"
#include <utility>

namespace Notes {

/**
 * @brief Constructs a new Note object.
 * @param title The title of the note.
 * @param content A unique pointer to the content object associated with the note.
 */
Note::Note(std::string title, std::unique_ptr<Content> content)
    : m_title(std::move(title))
    , m_content(std::move(content))
    , m_createdAt(std::chrono::system_clock::now())
{
}

/**
 * @brief Retrieves the title of the note.
 * @return A constant reference to the note's title.
 */
const std::string& Note::getTitle() const noexcept {
    return m_title;
}

/**
 * @brief Retrieves the content of the note.
 * @return A constant reference to the note's content.
 */
const std::string& Note::getContent() const {
    return m_content->view();
}

/**
 * @brief Retrieves the timestamp of when the note was created.
 * @return A `std::chrono::system_clock::time_point` representing the creation time.
 */
std::chrono::system_clock::time_point Note::getCreatedAt() const noexcept {
    return m_createdAt;
}

/**
 * @brief Edits the content of the note and updates its modification status.
 * @param newContent The new content string to set.
 */
void Note::editContent(const std::string& newContent) {
    m_content->edit(newContent);
    m_isModified = true;
}

/**
 * @brief Checks if the note has been modified since its creation.
 * @return `true` if the note has been modified, `false` otherwise.
 */
bool Note::isModified() const noexcept {
    return m_isModified;
}

} // namespace Notes
