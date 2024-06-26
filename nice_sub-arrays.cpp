#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std ;

int countNiceSubarrays(vector<int>& nums, int k) {
    unordered_map<int, int> odd_count_map;
    odd_count_map[0] = 1; // Start with 0 odd numbers seen once
    
    int odd_count = 0; // How many odd numbers we've seen so far
    int nice_subarrays = 0; // The count of nice subarrays
    
    for (int num : nums) {
        if (num % 2 == 1) {
            odd_count++; // Increase count if the number is odd
        }
        
        // Check how many times we have seen (odd_count - k) before
        nice_subarrays += odd_count_map[odd_count - k];
        
        // Record the current odd_count in the map
        odd_count_map[odd_count]++;
    }
    
    return nice_subarrays;
}

int main() {
    vector<int> nums = {1, 1, 2, 1, 1};
    int k = 3;
    
    int result = countNiceSubarrays(nums, k);
    
    cout << "Number of nice subarrays: " << result << endl;
    
    return 0;
}
