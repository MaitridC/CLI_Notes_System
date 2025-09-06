#pragma once

#include "Content.h"
#include <memory>
#include <string>
#include <chrono>

namespace Notes {

class Note {
public:
    // Constructor
    explicit Note(std::string title, std::unique_ptr<Content> content);
    
    // Getters
    [[nodiscard]] const std::string& getTitle() const noexcept;
    [[nodiscard]] const std::string& getContent() const;  // Add this declaration
    [[nodiscard]] std::chrono::system_clock::time_point getCreatedAt() const noexcept;
    
    // Operations
    void editContent(const std::string& newContent);
    [[nodiscard]] bool isModified() const noexcept;

private:
    std::string m_title;
    std::unique_ptr<Content> m_content;
    std::chrono::system_clock::time_point m_createdAt;
    bool m_isModified{false};
};

} // namespace Notes
