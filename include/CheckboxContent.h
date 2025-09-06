#pragma once

#include "Content.h"
#include <string>
#include <string_view>

namespace Notes {

/**
 * @class CheckboxContent
 * @brief Represents a checkbox item with toggleable state
 * * Provides functionality for a checkbox-style content item that can be
 * toggled between checked and unchecked states.
 */
class CheckboxContent final : public Content {
public:
    /**
     * @brief Constructs a checkbox item with given text
     * @param text The label text for the checkbox
     */
    explicit CheckboxContent(std::string_view text);

    /**
     * @brief Default destructor
     */
    ~CheckboxContent() override = default;

    /**
     * @brief Toggles the checked state
     * @return Reference to this object for method chaining
     */
    CheckboxContent& toggle();

    /**
     * @brief Displays the checkbox state and text
     */
    std::string view() const override;

    /**
     * @brief Gets the current checked state
     * @return true if checked, false otherwise
     */
    [[nodiscard]] bool isChecked() const noexcept;

    /**
     * @brief Edits the text content of the checkbox.
     * @param newText The new text for the checkbox.
     */
    void edit(const std::string& newText) override;

private:
    std::string m_text;
    bool m_checked{false};
};

} // namespace Notes
