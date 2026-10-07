class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) 
    {

        int res = 0;
        int local = 0;

        for (int i{}; i < nums.size(); i++)
        {
            if (nums[i] == 1)
            {
                local += 1;
            }
            else
            {
                local = 0;
            }

            //Calculate max
            res = max(res, local);
        }    

        return res;
    }
};