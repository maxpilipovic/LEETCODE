class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        //Binary Search
        //Flag being that we found our first value
        int first = binarySearch(nums, 0, nums.size() - 1, false, target); 
        int second = binarySearch(nums, 0, nums.size() - 1, true, target);
        res.push_back(second);
        res.push_back(first);
        //printVector(nums);

        return res;
    }

    int binarySearch(vector<int>& nums, int low, int high, bool flag, int& target)
    {
        int goatedNum = -1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

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

                goatedNum = mid;
                
                //Find other first or second...
                if (flag)
                {
                    high = mid - 1;
                }
                else 
                {
                    low = mid + 1;
                }
            }
        }
        return goatedNum;
    }

    void printVector(const std::vector<int>& vec) 
    {
        std::cout << "[";
        for (size_t i = 0; i < vec.size(); ++i) {
            std::cout << vec[i];
            if (i < vec.size() - 1) {
                std::cout << ", ";
            }
        }
        std::cout << "]" << std::endl;
    }



private:

    std::vector<int> res;

};