#pragma once

#include "Content.h"
#include <string>

namespace Notes {

/**
 * @class FileAttachmentContent
 * @brief Represents file attachments in the Notes system
 */
class FileAttachmentContent final : public Content {
public:
    FileAttachmentContent(const std::string& uri, const std::string& filename);
    
    [[nodiscard]] std::string view() const override;
    void edit(const std::string& newText) override;

private:
    std::string m_fileUri;
    std::string m_filename;
};

} // namespace Notes