#pragma once

#include <string>

namespace Notes {

/**
 * @class Content
 * @brief Abstract base class for all content types in the Notes system
 */
class Content {
public:
    virtual ~Content() = default;

    /**
     * @brief Get a string representation of the content
     * @return String representation of the content
     */
    [[nodiscard]] virtual std::string view() const = 0;

    /**
     * @brief Edit the content
     * @param newText New content to replace existing content
     */
    virtual void edit(const std::string& newText) = 0;
};

} // namespace Notes