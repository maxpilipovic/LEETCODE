class Solution {
public:
    int longestBalanced(vector<int>& nums) 
    {
        const int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            std::unordered_set<int> evens;
            std::unordered_set<int> odds;
            int oddCount = 0;
            int evenCount = 0;

            for (int j = i; j < n; j++)
            {

                if (nums[j] % 2 == 0)
                {
                    //Even
                    evenCount += 1;
                    evens.insert(nums[j]);
                }
                else
                {
                    //Odd
                    oddCount += 1;
                    odds.insert(nums[j]);
                }

                if (evens.size() == odds.size())
                {
                    res = std::max(res, j - i + 1);
                }
            }
        }

        return res;
    }

private:
    int res = 0;

};