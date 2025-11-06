class Solution {
public:
    Solution(vector<int>& w) {
        
        prefixSum.resize(w.size());
        prefixSum[0] = w[0];
        total = w[0];

        for (int i = 1; i < w.size(); i++)
        {
            prefixSum[i] = prefixSum[i - 1] + w[i];
            total += w[i];
        }
    }
    
    int pickIndex() {

        int randomNum = std::rand() % total + 1;

        //Gets the index of the int...
        return binarySearch(0, prefixSum.size() - 1, randomNum);
    }

    int binarySearch(int left, int right, int target)
    {

        while (left < right)
        {
            int mid = left + (right - left) / 2;

            if (prefixSum[mid] < target)
            {
                left = mid + 1;
            }
            else if (prefixSum[mid] >= target)
            {
                right = mid;
            }
        }

        return left;
    }

private:
    vector<int> prefixSum;
    int total;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */