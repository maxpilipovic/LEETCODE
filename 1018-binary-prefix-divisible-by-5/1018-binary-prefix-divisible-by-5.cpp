class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        
        int remainder = 0;

        for  (int i = 0; i < nums.size(); i++)
        {


            remainder = (remainder * 2 + nums[i]) % 5;
            res.push_back(remainder == 0);
        }

        return res;
    }

private:
    vector<bool> res;
};