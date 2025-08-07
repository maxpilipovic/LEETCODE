class Solution {
public:
    int minDeletion(vector<int>& nums) {
        
        int n = nums.size();
        int deletions = 0;

        //Base Case
        if (nums.empty())
        {
            return 0;
        }

        for (int i = 0; i < n - 1; i++)
        {

            if ((i - deletions) % 2 == 0 && nums[i] == nums[i + 1])
            {
                deletions++;
            }   
        }

        if ((n - deletions) % 2 != 0)
        {
            deletions++;
        }

        return deletions;
    }
};