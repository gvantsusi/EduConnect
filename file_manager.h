#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include "database_manager.h"
#include <string>

// Handles saving and loading opportunities to/from a file
class FileManager {
public:
    // Saves opportunities from the DatabaseManager to a file
    static void saveOpportunitiesToFile(const std::string& filename, const DatabaseManager& db);

    // Loads opportunities from a file into the DatabaseManager
    static void loadOpportunitiesFromFile(const std::string& filename, DatabaseManager& db);
};

#endif // FILE_MANAGER_H
