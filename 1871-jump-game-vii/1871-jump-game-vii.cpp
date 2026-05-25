class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) 
    {
        int n = s.size();
        vector<bool> x(n, false);
        x[0] = true;
        
        return dp(1, s, minJump, maxJump, x, n);
    }

    bool dp(int i, string& s, int minJump, int maxJump, vector<bool>& x, int n)
    {
        int reachableCount = 0;

        for (int i = 1; i < n; i++)
        {
            if (i - minJump >= 0 && x[i - minJump])
            {
                reachableCount++;
            }

            if (i - maxJump - 1 >= 0 && x[i - maxJump - 1])
            {
                reachableCount--;
            }

            if (s[i] == '0' && reachableCount > 0)
            {
                x[i] = true;
            }
        }

        return x[n - 1];
    }

private:

};