#include <iostream>
#include <chrono>
#include <vector>
#include "StringData.h"

int linear_search(std::vector<std::string> container, std::string element)
{
    for (int i = 0; i < container.size(); i++)
    {
        if (container[i] == element)
            return i;
    }
    return -1;
}

int binary_search(std::vector<std::string> container, std::string element)
{
    int front = 0;
    int back = container.size();
    int mid = (front + back) / 2;
    while (element != container[mid])
    {
        if (front == mid && mid == back)
        {
            return -1;
        }
        else if (element < container[mid])
        {
            back = mid;
            mid = (front + back) / 2;
        }
        else if (element > container[mid])
        {
            front = mid + 1;
            mid = (front + back) / 2;
        }
    }
    return mid;
}

int main()
{
    std::vector<std::string>  data = getStringData();

    auto time = std::chrono::system_clock::now();
    linear_search(data, "not_here");
    auto time2 = std::chrono::system_clock::now();
    std::chrono::duration<double> diff = time2 - time;
    std::cout << "Linear search for not_here: " << diff.count() <<" secs\n";

    time = std::chrono::system_clock::now();
    binary_search(data, "not_here");
    time2 = std::chrono::system_clock::now();
    diff = time2 - time;
    std::cout << "Binary search for not_here: " << diff.count() <<" secs\n";

    time = std::chrono::system_clock::now();
    linear_search(data, "mzzzz");
    time2 = std::chrono::system_clock::now();
    diff = time2 - time;
    std::cout << "Linear search for mzzzz: " << diff.count() <<" secs\n";

    time = std::chrono::system_clock::now();
    binary_search(data, "mzzzz");
    time2 = std::chrono::system_clock::now();
    diff = time2 - time;
    std::cout << "Binary search for mzzzz: " << diff.count() <<" secs\n";


    time = std::chrono::system_clock::now();
    linear_search(data, "aaaaa");
    time2 = std::chrono::system_clock::now();
    diff = time2 - time;
    std::cout << "Linear search for aaaaa: " << diff.count() <<" secs\n";

    time = std::chrono::system_clock::now();
    binary_search(data, "aaaaa");
    time2 = std::chrono::system_clock::now();
    diff = time2 - time;
    std::cout << "Binary search for aaaaa: " << diff.count() <<" secs\n";
}