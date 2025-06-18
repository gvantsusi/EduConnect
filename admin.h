#ifndef ADMIN_H
#define ADMIN_H

// Includes the necessary header files for managing the database and search system.
#include "database_manager.h"  // To manage the database of opportunities
#include "search_system.h"     // To handle searching of opportunities
#include <string>              // To handle string manipulations

// Admin class handles the management of opportunities through adding, searching, and saving.
class Admin {
public:
    // Constructor that initializes the Admin object with a reference to the DatabaseManager
    Admin(DatabaseManager& db);

    // Adds an opportunity to the database by prompting the admin to input details
    void addOpportunityToDatabase();

    // Searches for opportunities based on title, location, or category
    void searchOpportunity();

    // Prompts the admin for the details of an opportunity, including title, description, category, time, and location.
    bool inputOpportunityDetails(std::string& title, std::string& description,
                                 std::string& category, std::string& time, std::string& location);

private:
    DatabaseManager& db;  // Reference to the DatabaseManager which holds and manages the opportunities
    void saveOpportunitiesToFile();  // Saves the current list of opportunities to a file
    void showCategoryMenu();         // Displays the predefined list of categories for opportunities
};

#endif // ADMIN_H
