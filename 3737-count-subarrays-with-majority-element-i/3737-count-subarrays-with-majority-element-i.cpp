class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) 
    {
        int ans = 0;

        for (int start = 0; start < nums.size(); start++)
        {
            ans += dfs(start, nums, target, 0, 0);
        }

        return ans;
    }

    void printMatrix(const vector<vector<int>>& matrix)
    {
        for (const auto& row : matrix)
        {
            for (int value : row)
            {
                cout << value << " ";
            }
            cout << '\n';
        }
    }

    int dfs(int i, vector<int>& nums, int target, int currCount, int length)
    {
        //Base Case
        if (i >= nums.size())
        {
            return 0;
        }

        //Increase currCount if the current val is == target.
        if (nums[i] == target)
        {
            currCount += 1;
        }

        length += 1;

        int ans = 0;

        if (currCount > length / 2)
        {
            //Add curr
            ans += 1;
        }

        //DFS part
        ans += dfs(i + 1, nums, target, currCount, length);

        return ans;
    }

private:
    vector<vector<int>> res;
};