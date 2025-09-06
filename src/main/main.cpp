#include "User.h"
#include "Content.h"
#include "TextContent.h"
#include "CheckboxContent.h"

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <limits>

void displayMenu() {
    std::cout << "\nNotes App Menu:\n";
    std::cout << "1. Create New Note\n";
    std::cout << "2. Add Content to a Note\n";
    std::cout << "3. View All Notes\n";
    std::cout << "4. Edit Content in a Note\n";
    std::cout << "5. Exit\n";
    std::cout << "Enter your choice: ";
}

int main() {
    Notes::User currentUser("maitri_user");
    int choice;
    std::string title;
    std::string text;
    size_t contentIndex;

    do {
        displayMenu();
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choice) {
            case 1: { 
                std::cout << "Enter the note title: ";
                std::getline(std::cin, title);

                std::cout << "Enter initial content for the note: ";
                std::getline(std::cin, text);

                std::unique_ptr<Notes::Content> initialContent;
                initialContent = std::make_unique<Notes::TextContent>(text);

                if (currentUser.createNote(title, std::move(initialContent))) {
                    std::cout << "Note '" << title << "' created successfully." << std::endl;
                } else {
                    std::cout << "Failed to create note. A note with this title might already exist." << std::endl;
                }
                break;
            }
            case 2: { 
                std::cout << "Enter the title of the note to add content to: ";
                std::getline(std::cin, title);

                std::optional<const Notes::Note*> currentNoteOpt = currentUser.findNote(title);

                if (!currentNoteOpt) {
                    std::cout << "Note not found." << std::endl;
                    break;
                }
                
                Notes::Note* currentNote = const_cast<Notes::Note*>(*currentNoteOpt);

                std::cout << "Enter the content to add (text or checkbox): ";
                std::getline(std::cin, text);

                std::shared_ptr<Notes::Content> newContent;
                if (text.find("[x]") == 0 || text.find("[ ]") == 0) {
                    newContent = std::make_shared<Notes::CheckboxContent>(text);
                } else {
                    newContent = std::make_shared<Notes::TextContent>(text);
                }

                currentNote->editContent(text);

                std::cout << "Content added/edited in note '" << currentNote->getTitle() << "'." << std::endl;
                break;
            }
            case 3: {
                if (currentUser.getNotes().empty()) {
                    std::cout << "No notes found.\n";
                    break;
                }

                for (const auto& note : currentUser.getNotes()) {
                    std::cout << "\n--- Note: " << note->getTitle() << " ---\n";
                    
                    std::cout << "  - " << note->getContent() << "\n";
                }
                break;
            }
            case 4: { 
                std::cout << "Enter the title of the note to edit: ";
                std::getline(std::cin, title);

                std::optional<const Notes::Note*> currentNoteOpt = currentUser.findNote(title);

                if (!currentNoteOpt) {
                    std::cout << "Note not found.\n";
                    break;
                }
                
                Notes::Note* currentNote = const_cast<Notes::Note*>(*currentNoteOpt);

                std::cout << "Current content:\n" << currentNote->getContent() << "\n";
                std::cout << "Enter new content: ";
                std::getline(std::cin, text);

                currentNote->editContent(text);
                std::cout << "Content updated successfully." << std::endl;
                break;
            }
            case 5: {
                std::cout << "Exiting application. Goodbye!" << std::endl;
                break;
            }
            default: {
                std::cout << "Invalid choice. Please try again." << std::endl;
                break;
            }
        }
    } while (choice != 5);

    return 0;
}
