class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) 
    {

        std::sort(nums.begin(), nums.end());
        vector<int> res;

        for (int i{}; i < nums.size(); i++)
        {
            if (nums[i] == target)
            {
                res.push_back(i);
            }
        }    

        return res;
    }

private:

};