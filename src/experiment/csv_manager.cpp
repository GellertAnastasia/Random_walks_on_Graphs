#include "csv_manager.h"

#include <filesystem>
#include <stdexcept>

CSVManager::CSVManager(const std::string& filename, const std::vector<std::string>& headers) {
    std::filesystem::path filePath(filename);
    if (filePath.has_parent_path()) {
        std::filesystem::create_directories(filePath.parent_path());
    }

    file.open(filename);

    if (!file.is_open()) {
        throw std::runtime_error("Could not open CSV file: " + filename);
    }

    for (size_t i = 0; i < headers.size(); ++i) {
        if (i > 0) {
            file << ",";
        }

        file << headers[i];
    }

    file << "\n";
}

void CSVManager::writeRow(const std::vector<std::string>& values) {
    for (size_t i = 0; i < values.size(); ++i) {
        if (i > 0) {
            file << ",";
        }

        file << values[i];
    }

    file << "\n";
}

void CSVManager::close() {
    file.close();
}