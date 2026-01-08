class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        //Rules
        //Same Length
        //Not Empty
        //
        //Base Case

        int n = nums1.size();
        int m = nums2.size();

        if (n == 0 || m == 0)
        {
            return 0;
        }

        //Assign the size...
        memo.assign(n, vector<int>(m, UNVISITED));

        return dp(nums1, nums2, 0, 0);
    }

    int dp(vector<int>& nums1, vector<int>& nums2, int i, int j)
    {
        int n = (int)nums1.size();
        int m = (int)nums2.size();

        if (i == n || j == m)
        {
            return NEG_INF;
        }

        int& ans = memo[i][j];

        if (ans != UNVISITED)
        {
            return ans;
        }

        int prod = nums1[i] * nums2[j];
        //Option 1: Take this pair, and optionally extend
        int take = prod;
        int next = dp(nums1, nums2, i + 1, j + 1);

        if (next != NEG_INF)
        {
            take = max(take, prod + max(0, next));
        }

        //Option 2: Skip
        int skip1 = dp(nums1, nums2, i + 1, j);
        int skip2 = dp(nums1, nums2, i, j + 1);

        ans = max({take, skip1, skip2});

        return ans;

    }

private:
    static constexpr int NEG_INF = -1000000000;
    static constexpr int UNVISITED = INT_MIN;

    vector<vector<int>> memo;


};