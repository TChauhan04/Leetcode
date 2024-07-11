#include <vector>
#include <iostream>

int removeDuplicates(std::vector<int>& nums) {
    if (nums.empty()) return 0 ; // If the array is empty, return 0

    int k = 1; // Start with the first element, which is always unique
    for (int i = 1; i < nums.size(); ++i) { // Iterate from the second element
        if (nums[i] != nums[i - 1]) { // If the current element is different from the previous one
            nums[k] = nums[i]; // Place it at the k-th position
            k++; // Increment the position for the next unique element
        }
    }
    return k ; // Return the number of unique elements
}

int main() {
    std::vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    int k = removeDuplicates(nums);

    std::cout << "The number of unique elements is: " << k << std::endl;
    std::cout << "The modified array is: ";
    for (int i = 0; i < k; ++i) {
        std::cout << nums[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
