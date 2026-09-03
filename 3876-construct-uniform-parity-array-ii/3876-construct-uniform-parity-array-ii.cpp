class Solution {
public:
    bool uniformArray(vector<int>& nums1) 
    {
        int j = 0;
        int even = -1;
        int odd = -1;

        for (int i{}; i < nums1.size(); i++)
        {
            if (nums1[i] % 2 == 0)
            {
                if (even == -1 || nums1[i] < even)
                {
                    even = nums1[i];
                }
            }
            else
            {
                if (odd == -1 || nums1[i] < odd)
                {
                    odd = nums1[i];
                }
            }
        }

        bool canBeOdd = true;
        bool canBeEven = true;

        for (int i{}; i < nums1.size(); i++)
        {
            int x = nums1[i];

            if (x % 2 == 0)
            {
                if (odd == -1 || !(odd < x)) 
                {
                    canBeOdd = false;
                }
            }
            else
            {
                if (odd == -1 || !(odd < x)) 
                {
                    canBeEven = false;
                }
            }
        }

        return canBeOdd || canBeEven;
    }
};