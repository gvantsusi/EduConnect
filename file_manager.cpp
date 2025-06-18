#include "file_manager.h"
#include <fstream>
#include <iostream>

// Saves opportunities from the DatabaseManager to a file
void FileManager::saveOpportunitiesToFile(const std::string& filename, const DatabaseManager& db) {
    std::ofstream file(filename);  // Open the file for writing
    if (!file) {
        throw std::ios_base::failure("Failed to open file for saving.");
    }

    // Loop through each opportunity and write to the file
    for (int i = 0; i < db.getOpportunityCount(); ++i) {
        const Opportunity* opp = db.getOpportunity(i);  // Get the opportunity pointer
        if (opp) {
            file << opp->getTitle() << ","
                 << opp->getDescription() << ","
                 << opp->getCategory() << ","
                 << opp->getTime() << ","
                 << opp->getLocation() << std::endl;
        }
    }
}

// Loads opportunities from a file into the DatabaseManager
void FileManager::loadOpportunitiesFromFile(const std::string& filename, DatabaseManager& db) {
    std::ifstream file(filename);  // Open the file for reading
    if (!file) {
        throw std::ios_base::failure("Failed to open file for reading.");
    }

    std::string title, description, category, time, location;
    // Read the opportunity data from the file and add to the database
    while (std::getline(file, title, ',') &&
           std::getline(file, description, ',') &&
           std::getline(file, category, ',') &&
           std::getline(file, time, ',') &&
           std::getline(file, location)) {
        db.addOpportunity(title, description, category, time, location);  // Add opportunity to database
    }
}
