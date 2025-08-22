//
//  main.cpp
//  1.CountRealNumbers
//
//  Created by Anton Vachkov on 17.08.25.
//

#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <utility>

int main() {
    std::map<double, int> occurrenses;
    
    std::string buffer;
    std::getline(std::cin, buffer);
    
    std::istringstream iss(buffer);
    
    double num;
    while (iss >> num) {
        std::pair<std::map<double, int>::iterator, bool> insertResult = occurrenses.insert(std::pair<double, int>(num, 1)); // way 1
        if (!insertResult.second) {
            insertResult.first->second++;
        }
        
        // occurrenses[num]++; // way 2
    }
    
    for (std::map<double, int>::iterator it = occurrenses.begin(); it != occurrenses.end(); it++) {
        std::cout << it->first << " -> " << it->second << std::endl;
    }
    
    return 0;
}
