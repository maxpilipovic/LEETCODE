class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        
        int newValue = original;
        int n = nums.size();
        int i = 0;

        while (i < n)
        {
            if (newValue == nums[i])
            {
                newValue *= 2;
                i = 0;
                continue;
            }

            i += 1;


        } 

        return newValue;
    }
};