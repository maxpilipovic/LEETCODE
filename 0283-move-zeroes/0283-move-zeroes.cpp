class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        int i = 0;

        for (int j = 0; j < nums.size(); j++) 
        {
            
            if (nums[j] != 0) 
            {
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;

                i += 1;
            }
        }


    }
};