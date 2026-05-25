class Solution {
public:
    bool check(vector<int>& nums) 
    {
        int drops = 0;
        int n = nums.size();

        for (int i{}; i < nums.size(); i++)
        {
            //wrap
            int next = (i + 1) % n;

            if (nums[i] > nums[next])
            {
                drops += 1;
            } 
        }
        
        return drops <= 1;
    }

private:

};