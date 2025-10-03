class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        if (candidates.empty())
        {
            return {};
        }
        vector<int> curr;
        backtrack(candidates, target, 0, 0, curr);

        return res;
    }

    void backtrack(vector<int>& candidates, int target, int index, int count, vector<int>& curr)
    {
        
        //Base Cases
        if (count > target)
        {
            return;
        }

        if (index >= candidates.size())
        {
            return;
        }

        if (count == target)
        {
            res.push_back(curr);
        }

        for (int i = index; i < candidates.size(); i++)
        {
            curr.push_back(candidates[i]);
            count += candidates[i];
            backtrack(candidates, target, i, count, curr);
            curr.pop_back();
            count -= candidates[i];
        }
    }

private:
    vector<vector<int>> res;

};