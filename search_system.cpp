#include "search_system.h"
#include <iostream>

// Constructor initializes the SearchSystem with a reference to the DatabaseManager
SearchSystem::SearchSystem(DatabaseManager& db) : db(db) {}

// Main search function where the user chooses the search type (Title, Location, or Category)
void SearchSystem::searchOpportunity() {
    int searchChoice;
    
    // Display search options
    std::cout << "\n--- Search Options ---\n";
    std::cout << "1. Search by Title\n";
    std::cout << "2. Search by Location\n";
    std::cout << "3. Search by Category\n";
    std::cout << "Enter your choice: ";
    std::cin >> searchChoice;
    std::cin.ignore();  // To ignore the newline left in the input buffer

    std::string searchQuery;
    
    // Based on user's choice, perform the respective search
    switch (searchChoice) {
        case 1:
            std::cout << "Enter the title to search for: ";
            std::getline(std::cin, searchQuery);
            searchByTitle(searchQuery);
            break;
        case 2:
            std::cout << "Enter the location to search for: ";
            std::getline(std::cin, searchQuery);
            searchByLocation(searchQuery);
            break;
        case 3:
            std::cout << "Enter the category to search for: ";
            std::getline(std::cin, searchQuery);
            searchByCategory(searchQuery);
            break;
        default:
            std::cout << "Invalid choice!" << std::endl;
            break;
    }
}

// Searches for opportunities by title and displays matching results
void SearchSystem::searchByTitle(const std::string& title) const {
    bool found = false;
    
    // Iterate through all opportunities in the database
    for (int i = 0; i < db.getOpportunityCount(); ++i) {
        const Opportunity* opp = db.getOpportunity(i);
        
        // If title matches, display the opportunity
        if (opp && opp->getTitle().find(title) != std::string::npos) {
            opp->displayOpportunityInfo();
            found = true;
        }
    }

    // If no matching opportunity found, inform the user
    if (!found) {
        std::cout << "No opportunities found with that title.\n";
    }
}

// Searches for opportunities by location and displays matching results
void SearchSystem::searchByLocation(const std::string& location) const {
    bool found = false;
    
    // Iterate through all opportunities in the database
    for (int i = 0; i < db.getOpportunityCount(); ++i) {
        const Opportunity* opp = db.getOpportunity(i);
        
        // If location matches, display the opportunity
        if (opp && opp->getLocation().find(location) != std::string::npos) {
            opp->displayOpportunityInfo();
            found = true;
        }
    }

    // If no matching opportunity found, inform the user
    if (!found) {
        std::cout << "No opportunities found in that location.\n";
    }
}

// Searches for opportunities by category and displays matching results
void SearchSystem::searchByCategory(const std::string& category) const {
    bool found = false;
    
    // Iterate through all opportunities in the database
    for (int i = 0; i < db.getOpportunityCount(); ++i) {
        const Opportunity* opp = db.getOpportunity(i);
        
        // If category matches, display the opportunity
        if (opp && opp->getCategory().find(category) != std::string::npos) {
            opp->displayOpportunityInfo();
            found = true;
        }
    }

    // If no matching opportunity found, inform the user
    if (!found) {
        std::cout << "No opportunities found in that category.\n";
    }
}
