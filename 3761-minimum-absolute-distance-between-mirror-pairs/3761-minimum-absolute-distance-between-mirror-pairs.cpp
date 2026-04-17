class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) 
    {
        unordered_map<int, int> x;

        for (int j = 0; j < nums.size(); j++)
        {
            if (x.contains(nums[j]))
            {
                int dist = j - x[nums[j]];
                res = min(res, dist);
            }

            int rev = reverseInt(nums[j]);
            x[rev] = j;
        }

        if (res == INT_MAX)
        {
            return -1;
        }

        return res;
    }

    int reverseInt(int x)
    {
        int rev = 0;

        while (x > 0)
        {
            int digit = x % 10;
            rev = rev * 10 + digit;
            x /= 10;
        }

        return rev;
    }

private:
    int res = INT_MAX;
};