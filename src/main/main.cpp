#include "User.h"
#include "Content.h"
#include "TextContent.h"
#include "CheckboxContent.h"

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <limits> 

/**
 * @brief Displays the main menu options to the user.
 * This is a simple helper function to keep the main loop clean.
 */
void displayMenu() {
    std::cout << "\nNotes App Menu:\n";
    std::cout << "1. Create New Note\n";
    std::cout << "2. Add Content to a Note\n";
    std::cout << "3. View All Notes\n";
    std::cout << "4. Edit Content in a Note\n";
    std::cout << "5. Delete a Note\n";
    std::cout << "6. Exit\n";
    std::cout << "Enter your choice: ";
}

/**
 * @brief The main entry point for the Notes application.
 * Manages the user interface and interacts with the User and Note objects.
 */
int main() {
    // Create a User instance to represent the current user and hold their notes.
    Notes::User currentUser("maitri_user");
    int choice;
    std::string title;
    std::string text;
    size_t contentIndex;

    // Main application loop that continues until the user chooses to exit.
    do {
        displayMenu();
        std::cin >> choice;
        // The following line is crucial for clearing the input buffer.
        // It discards the rest of the line, including the newline character,
        // which prevents std::getline from skipping future input.
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choice) {
            case 1: { // Create New Note
                std::cout << "Enter the note title: ";
                std::getline(std::cin, title);

                std::cout << "Enter initial content for the note: ";
                std::getline(std::cin, text);

                // Create a unique pointer to hold the initial content.
                std::unique_ptr<Notes::Content> initialContent;
                initialContent = std::make_unique<Notes::TextContent>(text);

                // Attempt to create the note using the User's method.
                if (currentUser.createNote(title, std::move(initialContent))) {
                    std::cout << "Note '" << title << "' created successfully." << std::endl;
                } else {
                    std::cout << "Failed to create note. A note with this title might already exist." << std::endl;
                }
                break;
            }
            case 2: { // Add Content to a Note
                std::cout << "Enter the title of the note to add content to: ";
                std::getline(std::cin, title);

                std::optional<Notes::Note*> currentNoteOpt = currentUser.findNote(title);

                if (!currentNoteOpt) {
                    std::cout << "Note not found." << std::endl;
                    break;
                }
                
                Notes::Note* currentNote = *currentNoteOpt;

                std::cout << "Enter the content to add (text): ";
                std::getline(std::cin, text);

                currentNote->appendContent(text);

                std::cout << "Content added to note '" << currentNote->getTitle() << "'." << std::endl;
                break;
            }
            case 3: { // View All Notes
                // Check if there are any notes to display.
                if (currentUser.getNotes().empty()) {
                    std::cout << "No notes found.\n";
                    break;
                }

                // Iterate through the notes and print their titles and content.
                for (const auto& note : currentUser.getNotes()) {
                    std::cout << "\n--- Note: " << note->getTitle() << " ---\n";
                    
                    std::cout << "  - " << note->getContent() << "\n";
                }
                break;
            }
            case 4: { // Edit Content in a Note
                std::cout << "Enter the title of the note to edit: ";
                std::getline(std::cin, title);

                std::optional<Notes::Note*> currentNoteOpt = currentUser.findNote(title);

                if (!currentNoteOpt) {
                    std::cout << "Note not found.\n";
                    break;
                }
                
                Notes::Note* currentNote = *currentNoteOpt;

                std::cout << "Current content:\n" << currentNote->getContent() << "\n";
                std::cout << "Enter new content (e.g., [x] to mark a checkbox as complete): ";
                std::getline(std::cin, text);

                currentNote->editContent(text);
                std::cout << "Content updated successfully." << std::endl;
                break;
            }
            case 5: { // Delete a Note
                std::cout << "Enter the title of the note to delete: ";
                std::getline(std::cin, title);

                if (currentUser.removeNote(title)) {
                    std::cout << "Note '" << title << "' deleted successfully." << std::endl;
                } else {
                    std::cout << "Failed to delete note. Note not found." << std::endl;
                }
                break;
            }
            case 6: { // Exit
                std::cout << "Exiting application. Goodbye!" << std::endl;
                break;
            }
            default: { // Invalid Choice
                std::cout << "Invalid choice. Please try again." << std::endl;
                break;
            }
        }
    } while (choice != 6); // Loop continues as long as the choice is not 6.

    return 0;
}
