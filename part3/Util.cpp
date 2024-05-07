#include "Util.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

namespace Util{

    void writeToFile(const std::string& filename, const std::string& data) {
        std::ofstream file(filename, std::ios_base::app); // Open the file in append mode
        if (file.is_open()) {
            file << data << "\n"; // Append data to the file
            file.close(); // Close the file
        } else {
            std::cerr << "Unable to open file: " << filename << std::endl;
        }
    }

}