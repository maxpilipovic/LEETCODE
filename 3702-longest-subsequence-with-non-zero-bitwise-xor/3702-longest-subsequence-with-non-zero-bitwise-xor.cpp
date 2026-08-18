class Solution {
public:
    int longestSubsequence(vector<int>& nums) 
    {
        int total = 0;
        bool flag = false;

        for (int num : nums)
        {
            total ^= num;

            if (num != 0)
            {
                //Has non zero
                flag = true;
            }
        }

        if (total !=0 )
        {
            return nums.size();
        }

        if (!flag)
        {
            //Everything is false.
            return 0;
        }

        return nums.size() - 1;
    }
};