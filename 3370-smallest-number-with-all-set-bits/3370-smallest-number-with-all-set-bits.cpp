class Solution {
public:
    int smallestNumber(int n) {
        
        //Edge Case
        if (n == 1)
        {
            return 1;
        }

        return backtrack(n, 1);
        
    }

    int backtrack(int n, int x)
    {
        if (x >= n)
        {
            return x;
        }

        return backtrack(n, x * 2 + 1);
    }

};