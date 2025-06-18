#include "opportunity.h"
#include <iostream>

// Constructor initializes the opportunity with title, description, category, time, and location.
Opportunity::Opportunity(const std::string& title, const std::string& description,
                         const std::string& category, const std::string& time, const std::string& location)
    : title(title), description(description), category(category), time(time), location(location) {}

// Displays the opportunity's information in a formatted way
void Opportunity::displayOpportunityInfo() const {
    std::cout << "Title: " << title << "\n"
              << "Description: " << description << "\n"
              << "Category: " << category << "\n"
              << "Time: " << time << "\n"
              << "Location: " << location << std::endl;
}

// Getter method to return the title of the opportunity
std::string Opportunity::getTitle() const {
    return title;
}

// Getter method to return the description of the opportunity
std::string Opportunity::getDescription() const {
    return description;
}

// Getter method to return the category of the opportunity
std::string Opportunity::getCategory() const {
    return category;
}

// Getter method to return the time of the opportunity
std::string Opportunity::getTime() const {
    return time;
}

// Getter method to return the location of the opportunity
std::string Opportunity::getLocation() const {
    return location;
}
