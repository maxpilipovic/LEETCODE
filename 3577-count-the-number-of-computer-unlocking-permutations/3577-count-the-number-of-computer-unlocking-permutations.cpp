class Solution {
public:
    int countPermutations(vector<int>& complexity) 
    {
        const int MOD = 1'000'000'007;
        int n = complexity.size();

        //Check if its possible first
        for (int i = 1; i < n; ++i) {
            if (complexity[i] <= complexity[0]) {
                return 0; 
            }
        }

        long long res = 1;
        for (int i = 2; i <= n - 1; ++i) {
            res = (res * i) % MOD;
        }

        return res;
    }


private:
    int res = 0;
};