class Solution 
{
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) 
    {
        int i = 0;
        int j = 0;

        int n = nums1.size();
        int m = nums2.size();

        while (i < n && j < m)
        {

            if (i <= j && nums1[i] <= nums2[j])
            {
                int dist = j - i;

                //Calculate the min
                res = max(res, dist);
                j += 1;
            }
            else
            {
                i += 1;
                j += 1;
            }
        }

        if (res == INT_MIN)
        {
            return 0;
        }

        return res;
    }

private:
    int res = INT_MIN;
};