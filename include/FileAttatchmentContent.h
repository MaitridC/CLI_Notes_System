#pragma once

#include "Content.h"
#include <string>

namespace Notes {

/**
 * @class FileAttachmentContent
 * @brief Represents file attachments in the Notes system. This class stores a URI and a filename for a file, but does not handle the file data itself.
 * It is marked as `final` because it is not designed to be inherited from.
 */
class FileAttachmentContent final : public Content {
public:
    /**
     * @brief Constructs a FileAttachmentContent object.
     * @param uri The URI or path to the file.
     * @param filename The name of the file.
     */
    FileAttachmentContent(const std::string& uri, const std::string& filename);
    
    /**
     * @brief Provides a string representation of the file attachment.
     * @return A formatted string showing the filename and its URI.
     */
    [[nodiscard]] std::string view() const override;

    /**
     * @brief Edits the content. This method is not implemented for file attachments as the content is immutable.
     * @param newText New text to replace the existing content. This parameter is ignored.
     */
    void edit(const std::string& newText) override;

private:
    std::string m_fileUri;
    std::string m_filename;
};

} // namespace Notes
