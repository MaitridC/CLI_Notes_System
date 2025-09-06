#include "Note.h"
#include <utility>

namespace Notes {

Note::Note(std::string title, std::unique_ptr<Content> content)
    : m_title(std::move(title))
    , m_content(std::move(content))
    , m_createdAt(std::chrono::system_clock::now())
{
}

const std::string& Note::getTitle() const noexcept {
    return m_title;
}

const std::string& Note::getContent() const {
    return m_content->view();
}

std::chrono::system_clock::time_point Note::getCreatedAt() const noexcept {
    return m_createdAt;
}

void Note::editContent(const std::string& newContent) {
    m_content->edit(newContent);
    m_isModified = true;
}

bool Note::isModified() const noexcept {
    return m_isModified;
}

} // namespace Notes
