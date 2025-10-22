class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        
        std::sort(nums.begin(), nums.end());

        int left = 0;
        
        //Grab the max vlue
        int maxVal = *std::max_element(nums.begin(), nums.end());

        vector<int> numsSeen(maxVal + k + 1, 0);

        //Add what we've seen...
        for (int i = 0; i < nums.size(); i++)
        {
            numsSeen[nums[i]] += 1;
        }

        //printArray(numsSeen);

        //Prefix sum...
        vector<int> prefix(maxVal + k + 2, 0);
        for (int i = 0; i <= maxVal + k; i++) {
            prefix[i + 1] = prefix[i] + numsSeen[i];
        }

        //printArray(prefix);

        for (int target = 0; target <= maxVal + k; target++) {
            int left = max(0, target - k);
            int right = min(maxVal, target + k);
            
            int alreadyAtTarget = numsSeen[target];
            
            int inRange = prefix[right + 1] - prefix[left] - alreadyAtTarget;
            
            int canConvert = min(inRange, numOperations);
            
            res = max(res, alreadyAtTarget + canConvert);
        }

        return res;
    }

    void printArray(vector<int>& nums)
    {

        for (int i = 0; i < nums.size(); i++)
        {
            std::cout << nums[i] << " ";

            if (i == nums.size() - 1)
            {
                std::cout << std::endl;
            }
        }
    }

private:
    int res = 1; //Lowest it can be..
};