class Solution {
public:
    bool stoneGame(vector<int>& piles) 
    {
        int n = piles.size();
        vector<vector<int>> memo(n, vector<int>(n, INT_MIN));
        return maxDiff(piles, 0, n - 1, memo) > 0;
    }

    int maxDiff(vector<int>& piles, int left, int right, vector<vector<int>>& memo)
    {
        if (left > right) return 0;
        if (memo[left][right] != INT_MIN) return memo[left][right];

        int pickLeft = piles[left] - maxDiff(piles, left + 1, right, memo);
        int pickRight = piles[right] - maxDiff(piles, left, right - 1, memo);

        return memo[left][right] = max(pickLeft, pickRight);
    }



private:
};