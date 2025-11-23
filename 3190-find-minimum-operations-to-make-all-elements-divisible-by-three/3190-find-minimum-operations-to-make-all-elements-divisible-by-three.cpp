class Solution {
public:
    int minimumOperations(vector<int>& nums) 
    {

        for (int i = 0; i < nums.size(); i++)
        {

            int count = nums[i] % 3;

            if (count == 0)
            {
                continue;
            }
            else if (count == 1)
            {
                globalCount += 1;
            }
            else if (count == 2)
            {
                globalCount += 1;
            }
        }

        return globalCount;
        
    }

private:
    int globalCount = 0;
    
};