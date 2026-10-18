class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) 
    {
        int n = nums.size();

        vector<bool> seen(n + 1);
        //bool[] seen = new bool[n + 1];

        vector<int> res;

        for (int i{}; i < nums.size(); i++)
        {
            int value = nums[i];

            seen[value] = true;
        }

        for (int i = 1; i < seen.size(); i++)
        {
            if (seen[i] == false)
            {
                res.push_back(i);
            }
        }

        return res;
    }
};