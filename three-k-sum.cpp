#include <iostream>
#include <unordered_map>
#include <vector>

std::vector<int> findTripleWithSum3K(std::vector<int>& nums, int k) {
    int n = nums.size();
    
    for (int i = 0; i < n - 2; ++i) {
        std::unordered_map<int, int> map;
        
        int currentSum = k - nums[i];
        for (int j = i + 1; j < n; ++j) {
            if (map.find(currentSum - nums[j]) != map.end()) {
                std::vector<int> result = {nums[i], nums[j], currentSum - nums[j]};
                return result;
            }
            map[nums[j]] = j;
        }
    }

    // If no such triplet found
    return {};
}

int main() {
    std::vector<int> numbers = {1, 4, 3, 7, 9, 10, 12};
    int k = 18; // Desired sum 3k

    std::vector<int> result = findTripleWithSum3K(numbers, k);
    
    if (result.size() == 3) {
        std::cout << "Triple with sum 3k found: " << result[0] << ", " << result[1] << ", " << result[2] << std::endl;
    } else {
        std::cout << "No such triplet found with the sum 3k." << std::endl;
    }
    
    return 0;
}
