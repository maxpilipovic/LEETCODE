class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {

        vector<int> ans(nums.size(), -1);

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] % 2 == 0)
            {
                continue;
            }


            int temp = nums[i];
            int count = 0;
            while (temp & 1)
            {
                count++;
                temp >>= 1;
            }

            // Minimum x
            ans[i] = nums[i] - (1 << (count - 1));

        } 

        return ans;  
    }


private:

};