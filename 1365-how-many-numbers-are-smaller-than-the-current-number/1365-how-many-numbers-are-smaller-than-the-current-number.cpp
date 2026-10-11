class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) 
    {
        vector<int> res;

        for (int i{}; i < nums.size(); i++)
        {
            int local = 0;
            for (int j{}; j < nums.size(); j++)
            {
                if (i != j && nums[j] < nums[i])
                {
                    local += 1;
                }
            }

            res.push_back(local);
        }    

        return res;
    }

private:

};