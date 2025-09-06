#pragma once

#include "Notes.h"
#include <string>
#include <string_view>
#include <memory>
#include <optional>

namespace Notes {

/**
 * @brief Represents a user of the notes system
 */
class User {
public:
    /**
     * @brief Create a new user
     * @param username Unique username for the user
     */
    explicit User(std::string username);

    // Accessors
    [[nodiscard]] std::string_view getUsername() const noexcept;
    [[nodiscard]] const Notes& getNotes() const noexcept;
    Notes& getNotes() noexcept;

    // Note operations
    bool createNote(std::string title, std::unique_ptr<Content> content);
    bool deleteNote(std::string_view title);
    [[nodiscard]] std::optional<const Note*> findNote(std::string_view title) const;

private:
    std::string m_username;
    Notes m_notes;
};

} // namespace Notes
