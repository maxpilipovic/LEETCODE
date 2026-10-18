class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) 
    {
        int n = nums.size();

        //Vec with size n and all values 0.
        vector<int> res(n, 0);

        for (int i{}; i < n; i++)
        {
            int local = 0;

            for (int j{}; j < n; j++)
            {

                if (i != j && nums[j] < nums[i])
                {
                    local += 1;
                }
            }

            res[i] = local;
        }    

        return res;
    }

private:

};