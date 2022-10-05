#include <iostream>
#include <vector>
#include "StringData.h"

// Implements the linear search algorithm
int linearSearch(std::vector<std::string> container, std::string element) {
    for(int i=0; i<container.size(); i++) {
        if(container[i] == element) return i;
    }
    return -1;
}

// Implements the binary search algorithm
int binarySearch(std::vector<std::string> container, std::string element) {
    int min = 0;
    int max = container.size() - 1;

    while(min <= max) {
        int mid = (min + (max - min) / 2);
        if(container[mid] == element)
            return mid;
        else if(container[mid] > element)
            max = mid - 1;
        else
            min = mid + 1;
    }

    return -1;
}

void searchAndTime(std::string element, std::vector<std::string> data) {
    std::chrono::time_point<std::chrono::system_clock> startTime;
    std::chrono::time_point<std::chrono::system_clock> endTime;
    std::chrono::duration<double> diff;

    std::cout << "Searching for " << element << ":\n" << std::endl;

    startTime = std::chrono::system_clock::now();
    std::cout << "Linear Search Index: " << linearSearch(data, element) << std::endl;
    endTime = std::chrono::system_clock::now();
    diff = endTime - startTime;
    std::cout << "Linear Search Time: " << diff.count() << " secs" << std::endl;

    startTime = std::chrono::system_clock::now();
    std::cout << "Binary Search Index: " << binarySearch(data, element) << std::endl;
    endTime = std::chrono::system_clock::now();
    diff = endTime - startTime;
    std::cout << "Binary Search Time: " << diff.count() << " secs\n" << std::endl;
}

int main() {
    std::vector<std::string> data = getStringData();

    // Implements methods for the strings
    searchAndTime("not_here", data);
    searchAndTime("mzzzz", data);
    searchAndTime("aaaaa", data);

    return 0;
}
