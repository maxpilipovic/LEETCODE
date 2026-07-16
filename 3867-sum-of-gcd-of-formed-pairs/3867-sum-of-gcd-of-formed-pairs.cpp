class Solution {
public:
    long long gcdSum(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int> prefixGcd(n);

        int mx = 0;

        for (int i{}; i < n; i++)
        {
            mx = max(mx, nums[i]);
            prefixGcd[i] = gcd(nums[i], mx);
        }

        //Sort
        sort(prefixGcd.begin(), prefixGcd.end());

        for (int i{}; i < n / 2; i++)
        {
            ans += gcd(prefixGcd[i], prefixGcd[n - i - 1]);
        }

        return ans;
    }

private:
    long long ans = 0;
};