class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> curr;
        backtrack(0, 0, curr, candidates, target);

        return res;
    }

    void backtrack(int i, int currSum, vector<int>& curr, vector<int>& candidates, int target)
    {

        if (currSum > target)
        {
            return;
        }

        if (currSum == target)
        {
            res.push_back(curr);
            return;
        }

        for (int j = i; j < candidates.size(); j++)
        {

            curr.push_back(candidates[j]);
            backtrack(j, currSum + candidates[j], curr, candidates, target);
            curr.pop_back();
        }

        return;
    }

private:

    vector<vector<int>> res;
};