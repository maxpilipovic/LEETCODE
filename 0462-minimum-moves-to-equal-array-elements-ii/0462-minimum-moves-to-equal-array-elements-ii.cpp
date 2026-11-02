class Solution {
public:
    int minMoves2(vector<int>& nums) 
    {
        //Sort
        std::sort(nums.begin(), nums.end());  

        int res = 0;
        int low = 0;
        int high = nums.size() - 1;


        while (low < high)
        {
            res += abs(nums[low] - nums[high]);

            //Move pointers.
            low += 1;
            high -= 1;
        } 

        return res;
    }

private:

};