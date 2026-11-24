class Solution {
public:
    int minSubarray(vector<int>& nums, int p) 
    {
        long long total = 0;

        for (int x : nums)
        {
            total += x;
        }

        //Base Case
        int r = total % p;
        if (r == 0)
        {
            return 0;
        }

        unordered_map<int, int> last;
        last[0] = -1;

        int n = nums.size();
        int ans = n;
        int curr = 0;

        for (int i{}; i < n; i++)
        {

            curr = (curr + nums[i]) % p;

            int need = (curr - r + p) % p;

            if (last.count(need))
            {
                ans = min(ans, i - last[need]);
            }

            last[curr] = i;
        }

        //Cant remove entire array
        return ans == n ? -1 : ans;
    }

private:

};