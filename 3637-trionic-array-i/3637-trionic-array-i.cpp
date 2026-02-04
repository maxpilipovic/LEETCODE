class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = (int)nums.size();
        if (n < 4) return false;

        // Try all p, q with 0 < p < q < n-1
        for (int p = 1; p <= n - 3; p++) 
        {
            for (int q = p + 1; q <= n - 2; q++) 
            {
                if (isTrionic(p, q, nums))
                {
                    return true;
                }
            }
        }

        return false;
    }

    bool isTrionic(int p, int q, const vector<int>& nums) {
        int n = (int)nums.size();

        bool check1 = true, check2 = true, check3 = true;

        for (int i = 0; i < p; i++) 
        {
            if (!(nums[i] < nums[i + 1])) 
            {
                check1 = false;
                break;
            }
        }

        for (int i = p; i < q; i++) 
        {
            if (!(nums[i] > nums[i + 1])) 
            {
                check2 = false;
                break;
            }
        }

        for (int i = q; i < n - 1; i++) 
        {
            if (!(nums[i] < nums[i + 1])) 
            {
                check3 = false;
                break;
            }
        }

        return check1 && check2 && check3;
    }

private:

};