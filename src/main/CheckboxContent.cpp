#include "CheckboxContent.h"
#include <iostream>
#include <string>

namespace Notes {

// --- CheckboxContent Implementations ---

/**
 * @brief Constructs a checkbox item with given text.
 * @param text The label text for the checkbox.
 */
CheckboxContent::CheckboxContent(std::string_view text) 
    : m_text{text}, m_checked{false} {}

/**
 * @brief Toggles the checked state.
 * @return Reference to this object for method chaining.
 */
CheckboxContent& CheckboxContent::toggle() {
    m_checked = !m_checked;
    return *this;
}

/**
 * @brief Displays the checkbox state and text.
 */
std::string CheckboxContent::view() const {
    // This method must return a string, not print to cout.
    // The previous implementation was incorrect and is now fixed.
    return std::string{m_checked ? "[X] " : "[ ] "} + m_text.data();
}

/**
 * @brief Edits the content of the checkbox.
 * @param newText The new label text for the checkbox.
 */
void CheckboxContent::edit(const std::string& newText) {
    // This is the missing method that caused the linker error.
    m_text = newText;
}

/**
 * @brief Gets the current checked state.
 * @return true if checked, false otherwise.
 */
bool CheckboxContent::isChecked() const noexcept {
    return m_checked;
}

} // namespace Notes
