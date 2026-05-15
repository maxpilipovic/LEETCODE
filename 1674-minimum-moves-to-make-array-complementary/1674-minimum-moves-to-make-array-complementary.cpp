class Solution {
public:
    int minMoves(vector<int>& nums, int limit) 
    {
        int n = nums.size();
        
        //Cost array +2 cause 0 indexed.
        vector<int> cost(2 * limit + 2, 0);

        for (int i = 0; i < n / 2; i++)
        {
            int a = nums[i];
            int b = nums[n - 1 - i];

            int low = min(a, b);
            int high = max(a, b);
            int sum = a + b;

            cost[2] += 2;

            cost[low + 1] -= 1;
            cost[high + limit + 1] += 1;

            cost[sum] -= 1;
            cost[sum + 1] += 1;
        }

        int ans = INT_MAX;
        int moves = 0;

        for (int target = 2; target <= 2 * limit; target++)
        {
            moves += cost[target];
            ans = min(ans, moves);
        }

        return ans;
    }

private:
    int res = 0;
};