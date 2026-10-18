class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) 
    {
        int n = nums.size();
        unordered_set<int> x;
        vector<int> res;

        for (int i{}; i < nums.size(); i++)
        {
            x.insert(nums[i]);
        }

        int num = 1;

        while (num <= n)
        {
            if (!x.count(num))
            {
                res.push_back(num);
            }

            num += 1;
        }

        return res;
    }
};