class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        vector<int> res(nums.size(), 1);

        int left = 1;

        for (int i{}; i < nums.size(); i++)
        {
            res[i] = left;
            left *= nums[i];
        }

        printVector(res);

        int right = 1;

        for (int i = nums.size() - 1; i >= 0; i--)
        {
            res[i] *= right;
            right *= nums[i];
        }

        printVector(res);
        
        return res;
    }

    void printVector(const vector<int>& v) 
    {
        cout << "[";
        for (size_t i = 0; i < v.size(); ++i) {
            cout << v[i];
            if (i + 1 < v.size()) cout << ", ";
        }
        cout << "]" << endl;
    }

private:

};