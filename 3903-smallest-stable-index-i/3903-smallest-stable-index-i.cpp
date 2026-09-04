class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) 
    {
        int n = nums.size();
        vector<int> prefixMax(n);
        vector<int> suffixMin(n);

        prefixMax[0] = nums[0];

        for (int i = 1; i < n; i++) 
        {
            prefixMax[i] = std::max(prefixMax[i - 1], nums[i]);
        }

        printArray(prefixMax);

        suffixMin[n - 1] = nums[n - 1];

        for (int i = n - 2; i >= 0; i--) 
        {
            suffixMin[i] = std::min(suffixMin[i + 1], nums[i]);
        }

        for (int i{}; i < prefixMax.size(); i++)
        {
            if (prefixMax[i] - suffixMin[i] <= k )
            {
                return i;
            }
        }
        
        printArray(suffixMin);

        return -1;
    }

    void printArray(const vector<int>& arr) 
    {
        std::cout << "[";
        for (int i = 0; i < arr.size(); i++) {
            std::cout << arr[i];
            if (i != arr.size() - 1) {
                std::cout << ", ";
            }
        }
        std::cout << "]" << std::endl;
    }

};