class Solution {
public:
    int specialTriplets(vector<int>& nums) 
    {
        
        //Add hashy left
        hashyLeft[nums[0]] += 1;

        //Get right count
        for (int i = 2; i < nums.size(); i++)
        {
            hashyRight[nums[i]] += 1;
        }

        //Actual Loop
        for (int j = 1; j < nums.size() - 1; j++)
        {
            
            if (hashyRight.count(nums[j] * 2) && hashyLeft.count(nums[j] * 2))
            {
                //Stupid mod stuff to make it work
                res = (res + (1LL * hashyLeft[nums[j] * 2] * hashyRight[nums[j] * 2]) % MOD) % MOD;
            }


            //Add the left side
            hashyLeft[nums[j]] += 1;

            //Remove the right side
            hashyRight[nums[j + 1]] -= 1;
            if (hashyRight[nums[j + 1]] == 0) {
                hashyRight.erase(nums[j + 1]);
            }
            
        }

        return res;
    }

private:
    static const int MOD = 1e9 + 7;
    int res = 0;
    unordered_map<int, int> hashyLeft;
    unordered_map<int, int> hashyRight;
};