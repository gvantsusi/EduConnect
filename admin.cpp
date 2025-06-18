#include "admin.h"
#include "search_system.h"
#include <iostream>

// Constructor initializes the Admin object with a reference to the DatabaseManager
// The DatabaseManager handles storing and retrieving opportunities from the database.
Admin::Admin(DatabaseManager& db) : db(db) {}

// Method to add a new opportunity to the database
void Admin::addOpportunityToDatabase() {
    // Declare variables to store the user-provided opportunity details
    std::string title, description, category, time, location;
    
    // Prompt the admin to input opportunity details
    bool canceled = inputOpportunityDetails(title, description, category, time, location);

    // If the user cancels the process by typing 'back', return to the main menu
    if (canceled) {
        std::cout << "Going back to the main menu...\n";
        return;
    }

    // Add the new opportunity to the database
    db.addOpportunity(title, description, category, time, location);

    // Save the updated list of opportunities to the file
    saveOpportunitiesToFile();

    // Inform the admin that the opportunity has been successfully added and saved
    std::cout << "Opportunity added and saved successfully!" << std::endl;
}

// Method to prompt the admin for opportunity details and validate input
// It gathers the title, description, category, time, and location from the user.
bool Admin::inputOpportunityDetails(std::string& title, std::string& description,
                                     std::string& category, std::string& time, std::string& location) {
    // Ask the admin for the title of the opportunity
    std::cout << "Enter opportunity title (or type 'back' to return to the main menu): ";
    std::getline(std::cin, title);
    
    // If the admin types 'back', cancel the process and return to the main menu
    if (title == "back") return true;

    // Ask the admin for a description of the opportunity
    std::cout << "Enter opportunity description: ";
    std::getline(std::cin, description);

    // Show the predefined category options to the admin
    showCategoryMenu();
    int categoryChoice;
    std::cout << "Enter the number for the category (or type 'back' to return to the main menu): ";
    std::cin >> categoryChoice;
    std::cin.ignore();  // To ignore the newline character left in the input buffer

    // Handle 'back' input for category choice, which will return to the main menu
    if (categoryChoice == 0) {
        return true;
    }

    // Validate the chosen category and assign it to the category variable
    const std::vector<std::string> categories = {"Internship", "Lecture", "Workshop", "Summer Camp", "Conference", "Training", "Volunteer Opportunity"};
    if (categoryChoice >= 1 && categoryChoice <= categories.size()) {
        category = categories[categoryChoice - 1];  // Set category based on user choice
    } else {
        // If the input is invalid, default to "Other"
        std::cout << "Invalid category choice, defaulting to 'Other'." << std::endl;
        category = "Other";  // Default to "Other" if the input is not valid
    }

    // Ask the admin for the time of the opportunity
    std::cout << "Enter opportunity time: ";
    std::getline(std::cin, time);

    // Ask the admin for the location of the opportunity
    std::cout << "Enter opportunity location: ";
    std::getline(std::cin, location);

    return false;  // Return false to indicate the process was completed (not canceled)
}

// Method to display the predefined list of opportunity categories
void Admin::showCategoryMenu() {
    std::cout << "\n--- Category Menu ---\n";
    std::cout << "1. Internship\n";
    std::cout << "2. Lecture\n";
    std::cout << "3. Workshop\n";
    std::cout << "4. Summer Camp\n";
    std::cout << "5. Conference\n";
    std::cout << "6. Training\n";
    std::cout << "7. Volunteer Opportunity\n";
    std::cout << "0. Go back\n";  // Option to return to the main menu
}

// Method to save the list of opportunities to a file
void Admin::saveOpportunitiesToFile() {
    // Use the DatabaseManager to save the opportunities to a file
    db.saveOpportunitiesToFile("opportunities.txt");  // Save to "opportunities.txt"
    std::cout << "Saved to opportunities.txt.\n";  // Inform the admin that the data was saved
}

// Method to search for opportunities by title, location, or category
void Admin::searchOpportunity() {
    // Create a SearchSystem object and pass the database reference
    SearchSystem searchSystem(db);
    
    // Call the searchOpportunity method from the SearchSystem class to perform the search
    searchSystem.searchOpportunity();
}
