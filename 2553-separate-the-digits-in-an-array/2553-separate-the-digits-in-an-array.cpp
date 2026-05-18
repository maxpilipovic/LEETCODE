class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) 
    {
        vector<int> res;

        for (int i = 0; i < nums.size(); i++)
        {
            //Add num to res
            addNum(nums[i], res);
        }

        return res;
    }

    void addNum(int num, vector<int>& res)
    {
        vector<int> digits;

        while (num > 0)
        {
            digits.push_back(num % 10);
            num /= 10;
        }

        reverse(digits.begin(), digits.end());

        for (int d : digits)
        {
            res.push_back(d);
        }

    }

private:

};