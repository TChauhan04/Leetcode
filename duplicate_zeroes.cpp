#include <iostream>
#include <vector>

void duplicateZeros(std::vector<int>& arr) {
    int length = arr.size();
    int i = 0;
    
    while (i < length) {
        if (arr[i] == 0) {
            // Shift elements to the right
            for (int j = length - 1; j > i; --j) {
                arr[j] = arr[j - 1];
            }
            // Duplicate the zero
            ++i;  // Move past the duplicated zero
            if (i < length) {  // Avoid index out of range
                arr[i] = 0;
            }
        }
        ++i;
    }
}

int main() {
    std::vector<int> arr = {1, 0, 2, 3, 0, 4, 5, 0};
    
    duplicateZeros(arr);
    
    // Print the modified array
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    
    return 0;
}
