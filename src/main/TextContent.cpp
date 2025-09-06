#include "TextContent.h"
#include <utility>

namespace Notes {

/**
 * @brief Constructs a new TextContent object.
 * @param text The initial text content for the note. A `std::string_view`
 * is used to efficiently create the content without an unnecessary copy.
 */
TextContent::TextContent(std::string_view text)
    : m_text(text)
{
}

/**
 * @brief Creates a copy of the text content.
 * @return A new `std::string` containing a copy of the content. This is useful
 * when the caller needs a modifiable copy of the text.
 */
std::string TextContent::view() const {
    return m_text;
}

/**
 * @brief Replaces the current text content with new text.
 * @param newText The new text to be stored in the content.
 */
void TextContent::edit(const std::string& newText) {
    m_text = newText;
}

/**
 * @brief Gets a constant reference to the internal text string.
 * @return A constant reference to the `std::string` that stores the text.
 */
const std::string& TextContent::getText() const noexcept {
    return m_text;
}

} // namespace Notes
