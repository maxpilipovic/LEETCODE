class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        if (nums.empty())
        {
            return {};
        }
        
        int n = nums.size();
        vector<int> curr;
        vector<bool> used(n, false); 

        backtrack(nums, 0, curr, n, used);

        return res;
    }

    void backtrack(vector<int>& nums, int index, vector<int>& curr, int n, vector<bool>& used)
    {

        if (curr.size() == n)
        {
            res.push_back(curr);
        }

        if (index >= n)
        {
            return;
        }

        for (int i = 0; i < n; i++)
        {
            if (used[i])
            {
                continue;
            }

            used[i] = true;
            curr.push_back(nums[i]);
            backtrack(nums, i, curr, n, used);
            curr.pop_back();
            used[i] = false;
        }

    }

private:
    vector<vector<int>> res;
};