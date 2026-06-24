class Solution {
public:
    void nextPermutation(vector<int>& nums) 
    {
        int n = nums.size();
        
        //Comparing elementrs to both left and reight
        int i = n - 2;

        //Find pivot first
        while (i >= 0 && nums[i] >= nums[i + 1])
        {
            i -= 1;
        }

        //If pivots exists, swap with next biggest number
        if (i >= 0)
        {
            int j = n - 1;

            //Start from n - 1 and move left until we find the smallest 'increase'
            while (nums[j] <= nums[i]) 
            {
                j--;
            }

            swap(nums[i], nums[j]);
        }

        //If pivot does not exist. Just reverse
        reverse(nums.begin() + i + 1, nums.end());
    }
};