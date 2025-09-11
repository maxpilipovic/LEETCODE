class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        //Extra logic to check if sorted on right or left
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right)
        {

            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {return mid;}

            //We want to find if left or right half is
            //sorted/pivot
            if (nums[left] <= nums[mid])
            {
                //Left sorted
                if (nums[left] <= target && target <= nums[mid])
                {
                    right = mid - 1;
                }
                else 
                {
                    left = mid + 1;
                }
            }
            else
            //Right sorted
            {
                if (nums[mid] < target && target <= nums[right])
                {
                    left = mid + 1;
                }
                else
                {
                    right = mid - 1;
                }
            }
        }

        return -1;

    }
};