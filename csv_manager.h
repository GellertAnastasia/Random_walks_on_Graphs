#ifndef CSV_MANAGER
#define CSV_MANAGER

#include <fstream>
#include <string>
#include <vector>

class CSVManager {
private:
    std::ofstream file;

public:
    CSVManager(const std::string& filename, const std::vector<std::string>& headers);

    void writeRow(const std::vector<std::string>& values);

    void close();
};

#endif