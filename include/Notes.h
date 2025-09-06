#pragma once

#include "Note.h"
#include <vector>
#include <memory>
#include <optional>
#include <string_view>

namespace Notes {

class Notes {
public:
    /**
     * @brief Add a new note to collection
     * @return true if added successfully
     */
    bool addNote(std::unique_ptr<Note> note);

    /**
     * @brief Find note by title
     * @return Optional pointer to found note
     */
    [[nodiscard]] std::optional<const Note*> findNote(std::string_view title) const;

    /**
     * @brief Remove note by title
     * @return true if note was found and removed
     */
    bool removeNote(std::string_view title);

    /**
     * @brief Get collection statistics
     */
    [[nodiscard]] size_t size() const noexcept;
    [[nodiscard]] bool empty() const noexcept;
    
    /**
     * @brief Clear all notes
     */
    void clear() noexcept;

    /**
     * @brief Collection iterators
     */
    [[nodiscard]] auto begin() const { return m_notes.begin(); }
    [[nodiscard]] auto end() const { return m_notes.end(); }

private:
    std::vector<std::unique_ptr<Note>> m_notes;
};

} // namespace Notes
