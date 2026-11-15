class Solution {
public:
    int numOfSubarrays(vector<int>& arr) 
    {
        int odd = 0;
        int even = 1;

        int res = 0;

        dfs(0, 0, odd, even, res, arr);

        return res;
    }

    void dfs(int i, int parity, int& odd, int& even,
             int& res, vector<int>& arr)
    {
        if (i >= arr.size())
            return;

        parity = (parity + arr[i]) % 2;

        if (parity == 0)
        {
            res = (res + odd) % 1000000007;
            even++;
        }
        else
        {
            res = (res + even) % 1000000007;
            odd++;
        }

        dfs(i + 1, parity, odd, even, res, arr);
    }
};