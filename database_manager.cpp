#include "database_manager.h"
#include <iostream>
#include <fstream>

// Constructor to initialize the DatabaseManager object
// The constructor doesn't perform any initialization in this case, but can be extended in the future.
DatabaseManager::DatabaseManager() {}

// Method to add a new opportunity to the database
// This method creates an Opportunity object with the given details and adds it to the internal collection.
void DatabaseManager::addOpportunity(const std::string& title, const std::string& description,
                                     const std::string& category, const std::string& time, const std::string& location) {
    Opportunity newOpportunity(title, description, category, time, location);  // Create the new Opportunity
    opportunities.push_back(newOpportunity);  // Add the new opportunity to the collection
}

// Method to display all the opportunities stored in the database
// This method loops through each opportunity in the collection and calls the display method on each one.
void DatabaseManager::displayAllOpportunities() const {
    for (const auto& opp : opportunities) {
        opp.displayOpportunityInfo();  // Display the information for each opportunity
    }
}

// Method to save all opportunities to a file
// It opens the specified file in write mode and writes each opportunity to the file, formatted with commas.
void DatabaseManager::saveOpportunitiesToFile(const std::string& filename) const {
    try {
        std::ofstream file(filename);  // Open the file for writing
        if (!file) {
            throw std::ios_base::failure("Failed to open file for saving.");  // Throw an exception if file can't be opened
        }

        // Loop through each opportunity and write its details to the file
        for (const auto& opp : opportunities) {
            file << opp.getTitle() << ","      // Write title
                 << opp.getDescription() << "," // Write description
                 << opp.getCategory() << ","    // Write category
                 << opp.getTime() << ","        // Write time
                 << opp.getLocation() << std::endl; // Write location
        }
    } catch (const std::ios_base::failure& e) {
        std::cerr << "Error: " << e.what() << std::endl;  // Print the error message if file operations fail
    }
}


// Method to load opportunities from a file
// It reads the opportunity details from the file and adds them to the internal collection.
void DatabaseManager::loadOpportunitiesFromFile(const std::string& filename) {
    std::ifstream file(filename);  // Open the file for reading
    if (!file) {
        std::cerr << "Warning: File " << filename << " not found. No opportunities loaded." << std::endl;
        return;  // Return if file can't be opened
    }

    // Declare variables to store data read from the file
    std::string title, description, category, time, location;

    // Read the opportunity details from the file and add them to the collection
    while (std::getline(file, title, ',') &&
           std::getline(file, description, ',') &&
           std::getline(file, category, ',') &&
           std::getline(file, time, ',') &&
           std::getline(file, location)) {
        addOpportunity(title, description, category, time, location);  // Add the opportunity to the database
    }

    std::cout << "Opportunities loaded successfully.\n";  // Confirmation message after loading the file
}

// Method to get the total number of opportunities in the database
// It returns the size of the vector containing the opportunities.
size_t DatabaseManager::getOpportunityCount() const {
    return opportunities.size();  // Return the size of the opportunities vector
}

// Method to retrieve an opportunity by its index
// It returns a pointer to the Opportunity at the specified index, or nullptr if the index is out of bounds.
const Opportunity* DatabaseManager::getOpportunity(int index) const {
    if (index >= 0 && index < opportunities.size()) {
        return &opportunities[index];  // Return a pointer to the opportunity at the given index
    }
    return nullptr;  // Return nullptr if the index is invalid
}
