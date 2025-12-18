class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        map<std::pair<int, int>, int> memo;
        int res = dfs(0, amount, coins, memo);

        if (res == INT_MAX)
        {
            return -1;
        }
        
        return res;
    }

    int dfs(int i, int currAmount,  vector<int>& coins, map<std::pair<int, int>, int>& memo)
    {

        if (currAmount == 0)
        {
            return 0;
        }

        if (i >= coins.size() || currAmount < 0)
        {
            return INT_MAX;
        }

        //Cache
        if (memo.count({i, currAmount})) {
            return memo[{i, currAmount}];
        }

        //Take, skip
        int stay = dfs(i, currAmount - coins[i], coins, memo);
        if (stay != INT_MAX)
        {
            stay += 1;
        }

        int skip = dfs(i + 1, currAmount, coins, memo);

        memo[{i, currAmount}] = min(stay, skip);

        return memo[{i, currAmount}];
    }

private:
    
};