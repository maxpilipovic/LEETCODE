class Solution {
public:
    int climbStairs(int n) 
    {
        vector<int> memo(n + 1, -1);
        return climbStairs2(0, n, memo);    
    }

    int climbStairs2(int steps, int n, vector<int>& memo)
    {
        //Base case
        if (steps > n)
        {
            return 0;
        }

        if (steps == n)
        {
            return 1;
        }

        //Check memo
        if (memo[steps] != -1)
        {
            return memo[steps];
        }

        //Choice 1
        int one = climbStairs2(steps + 1, n, memo);

        //Choice 2
        int two = climbStairs2(steps + 2, n, memo);

        //Add to meom
        memo[steps] = one + two;

        return one + two;
    }
};