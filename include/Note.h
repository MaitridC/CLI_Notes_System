#pragma once

#include "Content.h"
#include <memory>
#include <string>
#include <chrono>

namespace Notes {

/**
 * @class Note
 * @brief Represents a single note entry with a title, content, and metadata.
 */
class Note {
public:
    /**
     * @brief Constructs a new Note object.
     * @param title The title of the note.
     * @param content A unique pointer to the content object associated with the note.
     */
    explicit Note(std::string title, std::unique_ptr<Content> content);
    
    // Getters
    /**
     * @brief Retrieves the title of the note.
     * @return A constant reference to the note's title.
     */
    [[nodiscard]] const std::string& getTitle() const noexcept;
    
    /**
     * @brief Retrieves the content of the note.
     * @return A constant reference to the note's content.
     */
    [[nodiscard]] const std::string& getContent() const;
    
    /**
     * @brief Retrieves the timestamp of when the note was created.
     * @return A `std::chrono::system_clock::time_point` representing the creation time.
     */
    [[nodiscard]] std::chrono::system_clock::time_point getCreatedAt() const noexcept;
    
    // Operations
    /**
     * @brief Edits the content of the note and updates its modification status.
     * @param newContent The new content string to set.
     */
    void editContent(const std::string& newContent);
    
    /**
     * @brief Checks if the note has been modified since its creation.
     * @return `true` if the note has been modified, `false` otherwise.
     */
    [[nodiscard]] bool isModified() const noexcept;

private:
    std::string m_title;
    std::unique_ptr<Content> m_content;
    std::chrono::system_clock::time_point m_createdAt;
    bool m_isModified{false};
};

} // namespace Notes
