class Solution {
public:
    int minOperations(vector<int>& nums) {
        
        //Empty case
        if (nums.size() == 0)
        {
            return 0;
        }

        int countOnes = 0;
        for (int num : nums)
        {
            if (num == 1)
            {
                countOnes += 1;
            }
        }

        //If there is a one then GG
        if (countOnes > 0)
        {
            return nums.size() - countOnes;
        }

        //Otherwise lets find the GCD of the array..
        int minLen = findGCD(nums);

        if (minLen == INT_MAX)
        {
            return -1;
        }
                //How many it takes to make one '1' and then make the rest.
        return (minLen - 1) + (nums.size() - 1);
    }

    int findGCD(vector<int>& nums)
    {
        int minLen = INT_MAX;

        for (int i = 0; i < nums.size(); i++)
        {
            int gcd = nums[i];
            for (int j = i + 1; j < nums.size(); j++)
            {
                gcd = std::gcd(gcd, nums[j]);

                //Find the min if it's 1
                if (gcd == 1)
                {
                    minLen = std::min(minLen, j - i + 1);
                    break;
                }
            }
        }

        return minLen;
    }


private:
    int res = 0;
};