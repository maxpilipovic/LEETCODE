class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
        if (binarySearch(nums, target, 0, nums.size() - 1))
        {
            return res;
        }

        return findPosition(nums, target);
    }

    bool binarySearch(vector<int>& nums, int target, int low, int high)
    {
        int mid;

        while (low <= high)
        {
            mid = low + (high - low) / 2;

            if (nums[mid] < target)
            {
                low = mid + 1;
            }
            else if (nums[mid] > target)
            {
                high = mid - 1;
            }
            else
            {
                res = mid;
                return true;
            }
        }

        return false;
    }

    int findPosition(vector<int>& nums, int target)
    {
        //Edge case
        if (target <= nums[0])
        {
            return 0;
        }

        //Find position to insert;
        for (int i = 0; i < nums.size(); i++)
        {
            
            if (nums[i] >= target)
            {
                return i;
            }

        }
        
        return nums.size();
    }

private:
    int res;
};