class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        
        int countZeros = 0;
        bool flag = false;
        
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 1)
            {

                if (flag == false)
                {
                    flag = true;
                    countZeros = 0;
                    continue;
                }

                if (flag && countZeros < k)
                {
                    return false;
                }
                countZeros = 0;
            }
            else
            {
                countZeros += 1;
            }
        }

        return true;
    }
};