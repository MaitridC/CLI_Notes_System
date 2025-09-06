#pragma once

#include "Content.h"
#include <string>
#include <string_view>

namespace Notes {

/**
 * @brief Represents plain text content in a note
 */
class TextContent final : public Content {
public:
    /**
     * @brief Construct text content with initial text
     * @param text Initial content text
     */
    explicit TextContent(std::string_view text);

    /**
     * @brief Get the text content
     * @return The content as a string
     */
    [[nodiscard]] std::string view() const override;

    /**
     * @brief Edit the text content
     * @param newText New content to replace existing text
     */
    void edit(const std::string& newText) override;

    /**
     * @brief Get raw text content
     * @return Reference to the content text
     */
    [[nodiscard]] const std::string& getText() const noexcept;

private:
    std::string m_text;
};

} // namespace Notes
