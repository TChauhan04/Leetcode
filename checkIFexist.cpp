class Solution {
public:
    bool checkIfExist(vector<int>& arr) 
{
        std::unordered_map<int, int> value_indices;

    for (int index = 0; index < arr.size(); ++index) 
    {
        int value = arr[index];
        // Check if value * 2 or value / 2 exists in the map
        if (value_indices.find(value * 2) != value_indices.end() ||
            (value % 2 == 0 && value_indices.find(value / 2) != value_indices.end())) 
        {
            return true;
        }
        value_indices[value] = index;
    }
    
    return false;
}

int main() 
{
    std::vector<int> arr = {10, 2, 5, 3};
    if (checkIfExist(arr))
    {
        std::cout << "True" << std::endl;
    } else 
    {
        std::cout << "False" << std::endl;
    }

    return 0;
    }
};
