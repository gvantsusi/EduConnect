#ifndef SEARCH_SYSTEM_H
#define SEARCH_SYSTEM_H

#include "database_manager.h"  // Include to interact with the DatabaseManager class for accessing opportunities
#include <string>  // For handling string data

// The SearchSystem class allows searching for opportunities based on title, location, or category.
// It provides a set of methods to search for opportunities stored in the DatabaseManager.
class SearchSystem {
public:
    // Constructor to initialize the SearchSystem with a reference to the DatabaseManager.
    SearchSystem(DatabaseManager& db);

    // Searches for opportunities by title and displays matching results
    void searchByTitle(const std::string& title) const;

    // Searches for opportunities by location and displays matching results
    void searchByLocation(const std::string& location) const;

    // Searches for opportunities by category and displays matching results
    void searchByCategory(const std::string& category) const;

    // Main search function that allows the user to choose search criteria (title, location, or category)
    void searchOpportunity();

private:
    DatabaseManager& db;  // Reference to the DatabaseManager that stores the opportunities
};

#endif // SEARCH_SYSTEM_H
