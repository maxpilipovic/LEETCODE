class Solution {
public:
    vector<int> resultArray(vector<int>& nums) 
    {
        vector<int> nums1;
        vector<int> nums2; 

        nums1.push_back(nums[0]);
        nums2.push_back(nums[1]);

        for (int i = 2; i < nums.size(); i++)
        {

            if (nums1.back() > nums2.back())
            {
                nums1.push_back(nums[i]);
            }
            else
            {
                nums2.push_back(nums[i]);
            }
        }

        vector<int> res;
        res.insert(res.end(), nums1.begin(), nums1.end());
        res.insert(res.end(), nums2.begin(), nums2.end());
        
        return res;
    }
};