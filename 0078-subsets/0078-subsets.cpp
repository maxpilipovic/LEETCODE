class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        std::vector<int> curr;

        dfs(nums, curr, 0);

        return res;
    }

    void dfs(vector<int>& nums, vector<int> curr, int i)
    {

        //Base Case
        if (i >= nums.size())
        {
            res.push_back(curr);
            return;
        }

        //Add
        curr.push_back(nums[i]);

        //Take 
        dfs(nums, curr, i + 1);

        //Skip
        curr.pop_back();
        dfs(nums, curr, i + 1);
        
    }

private:
    vector<vector<int>> res;
};