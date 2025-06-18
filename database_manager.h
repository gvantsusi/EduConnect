#ifndef DATABASE_MANAGER_H
#define DATABASE_MANAGER_H

#include <string>
#include <vector>
#include "opportunity.h"  // Include the Opportunity class header to work with Opportunity objects

// DatabaseManager class manages the collection of opportunities and provides methods to manipulate them
// It handles adding, displaying, saving, and loading opportunities to/from a file.
class DatabaseManager {
public:
    // Constructor initializes the DatabaseManager, can be extended for future initialization tasks
    DatabaseManager();

    // Adds a new opportunity to the collection
    // Parameters: title, description, category, time, and location of the opportunity
    void addOpportunity(const std::string& title, const std::string& description,
                        const std::string& category, const std::string& time, const std::string& location);
    
    // Displays all opportunities in the collection
    // This will print out the details of each opportunity in the collection
    void displayAllOpportunities() const;

    // Saves the current list of opportunities to a file
    // Parameters: filename to save the opportunities
    void saveOpportunitiesToFile(const std::string& filename) const;
    
    // Loads opportunities from a file and populates the collection
    // Parameters: filename to load the opportunities from
    void loadOpportunitiesFromFile(const std::string& filename);

    // Returns the number of opportunities currently in the collection
    // This is useful for iterating through the list of opportunities
    size_t getOpportunityCount() const;

    // Returns a pointer to an opportunity at a specific index
    // Parameters: index of the opportunity to retrieve
    const Opportunity* getOpportunity(int index) const;

private:
    // A vector that stores all the opportunities
    // The vector dynamically resizes as more opportunities are added
    std::vector<Opportunity> opportunities;
};

#endif // DATABASE_MANAGER_H
