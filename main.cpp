#include "admin.h"
#include "database_manager.h"
#include <iostream>

int main() {
    // Dynamically allocate memory for the DatabaseManager and Admin objects
    DatabaseManager* db = new DatabaseManager();  // The database that stores opportunities
    Admin* admin = new Admin(*db);  // Admin object for adding and searching opportunities

    // Load opportunities from file when the program starts
    std::cout << "Loading opportunities from file...\n";
    db->loadOpportunitiesFromFile("opportunities.txt");  // Load existing opportunities from the file
    std::cout << "Opportunities loaded from file.\n";  // Debugging statement

    int choice;
    do {
        // Display the main menu to the user
        std::cout << "\n--- Main Menu ---\n";
        std::cout << "1. Add Opportunity\n";
        std::cout << "2. Search Opportunity\n";
        std::cout << "3. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;  // Capture user choice
        std::cin.ignore();  // Ignore the newline character left by std::cin

        // Handle the user's menu choice using a switch-case
        switch (choice) {
            case 1:
                std::cout << "Adding opportunity...\n";  // Debugging statement
                admin->addOpportunityToDatabase();  // Add new opportunity via the admin object
                break;
            case 2:
                std::cout << "Searching opportunity...\n";  // Debugging statement
                admin->searchOpportunity();  // Let the user search for an opportunity via the admin object
                break;
            case 3:
                std::cout << "Exiting the program.\n";  // Inform the user that the program is exiting
                break;
            default:
                std::cout << "Invalid choice, please try again.\n";  // Handle invalid input
                break;
        }
    } while (choice != 3);  // Repeat the menu until the user chooses to exit (option 3)

    // Clean up dynamically allocated memory
    delete admin;  // Delete the admin object
    delete db;     // Delete the database manager object

    return 0;  // Return success
}
