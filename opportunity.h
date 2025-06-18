#ifndef OPPORTUNITY_H
#define OPPORTUNITY_H

#include <string>

// The Opportunity class represents an educational opportunity with details like title, description,
// category, time, and location. It includes methods to display the opportunity information and
// retrieve each detail through getters.
class Opportunity {
public:
    // Constructor to initialize an opportunity with title, description, category, time, and location
    Opportunity(const std::string& title, const std::string& description,
                const std::string& category, const std::string& time, const std::string& location);

    // Displays all the details of the opportunity
    void displayOpportunityInfo() const;

    // Getter methods to retrieve the individual details of the opportunity
    std::string getTitle() const;
    std::string getDescription() const;
    std::string getCategory() const;  // Get the category of the opportunity
    std::string getTime() const;      // Get the time of the opportunity
    std::string getLocation() const;  // Get the location of the opportunity

private:
    // Data members to store the details of the opportunity
    std::string title;
    std::string description;
    std::string category;
    std::string time;
    std::string location;
};

#endif // OPPORTUNITY_H
