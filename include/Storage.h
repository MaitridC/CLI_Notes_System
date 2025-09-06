#pragma once

#include "Notes.h"
#include <filesystem>
#include <optional>
#include <string_view>

namespace Notes {

/**
 * @brief Handles persistence of notes to filesystem
 */
class Storage {
public:
    explicit Storage(std::filesystem::path storagePath);
    
    // Storage operations
    [[nodiscard]] bool save(const Notes& notes) const;
    [[nodiscard]] std::optional<Notes> load() const;
    
    // Path management
    [[nodiscard]] const std::filesystem::path& getPath() const noexcept;
    bool setPath(const std::filesystem::path& newPath);

private:
    std::filesystem::path m_storagePath;
};

} // namespace Notes
