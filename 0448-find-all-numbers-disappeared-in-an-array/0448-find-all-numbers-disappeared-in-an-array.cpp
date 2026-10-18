class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) 
    {
        int n = nums.size();

        //bool[] seen = new bool[n + 1];

        vector<int> res;

        for (int i{}; i < nums.size(); i++)
        {
            int index = abs(nums[i]) - 1;

            if (nums[index] > 0)
            {
                nums[index] = -nums[index];
            }
            
        }

        for (int i{}; i < nums.size(); i++)
        {
            if (nums[i] > 0)
            {
                res.push_back(i + 1);
            }
        }

        return res;
    }
};