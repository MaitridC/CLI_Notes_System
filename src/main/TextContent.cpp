#include "TextContent.h"
#include <utility>

namespace Notes {

TextContent::TextContent(std::string_view text)
    : m_text(text)
{
}

std::string TextContent::view() const {
    return m_text;
}

void TextContent::edit(const std::string& newText) {
    m_text = newText;
}

const std::string& TextContent::getText() const noexcept {
    return m_text;
}

} // namespace Notes
