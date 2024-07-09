#include <vector>
#include <iostream>

int removeElement(std::vector<int>& nums, int val) {
    int k = 0; // Pointer to place the next non-val element
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] != val) {
            nums[k] = nums[i];
            k++;
        }
    }
    return k;
}

int main() {
    std::vector<int> nums = {3, 2, 2, 3, 4, 2, 5};
    int val = 3;
    int k = removeElement(nums, val);

    std::cout << "The number of elements not equal to " << val << " is: " << k << std::endl;
    std::cout << "The modified array is: ";
    for (int i = 0; i < k; ++i) {
        std::cout << nums[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
