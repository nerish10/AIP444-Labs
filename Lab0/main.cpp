#include <iostream>
#include <vector>
#include <string>

std::string summarizeRanges(const std::vector<int>& values) {
    if (values.empty()) {
        return "none";
    }

    std::string result = "";
    size_t n = values.size();
    size_t i = 0;

    while (i < n) {
        int start = values[i];
        
        while (i + 1 < n && values[i + 1] == values[i] + 1) {
            i++;
        }
        int end = values[i];

        if (start == end) {
            result += std::to_string(start);
        } else {
            result += std::to_string(start) + "-" + std::to_string(end);
        }

        if (i + 1 < n) {
            result += ", ";
        }

        i++;
    }

    return result;
}

int main() {
    std::cout << "[] -> " << summarizeRanges({}) << "\n";
    std::cout << "[7] -> " << summarizeRanges({7}) << "\n";
    std::cout << "[1, 2, 3, 4, 5] -> " << summarizeRanges({1, 2, 3, 4, 5}) << "\n";
    std::cout << "[98, 99, 100] -> " << summarizeRanges({98, 99, 100}) << "\n";
    std::cout << "[1, 3, 5, 7] -> " << summarizeRanges({1, 3, 5, 7}) << "\n";
    std::cout << "[0, 10, 20] -> " << summarizeRanges({0, 10, 20}) << "\n";
    std::cout << "[1, 2, 3, 5, 7, 8, 9] -> " << summarizeRanges({1, 2, 3, 5, 7, 8, 9}) << "\n";
    std::cout << "[2, 4, 5, 6, 9, 11, 12] -> " << summarizeRanges({2, 4, 5, 6, 9, 11, 12}) << "\n";

    return 0;
}