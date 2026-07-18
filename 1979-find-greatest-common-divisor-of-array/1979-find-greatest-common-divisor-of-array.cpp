class Solution {
public:
    int findGCD(vector<int>& nums) 
    {
        int min = INT_MAX;
        int max = INT_MIN;

        for (int i{}; i < nums.size(); i++)
        {
            if (nums[i] < min)
            {
                min = nums[i];
            }

            if (nums[i] > max)
            {
                max = nums[i];
            }
        }

        return std::gcd(min, max);
    }

private:
    int gcd = 0;
};