class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) 
    {
        using T = std::tuple<int, int, int>;
        std::priority_queue<T, std::vector<T>, std::greater<T>> min_heap;
        vector<vector<int>> res;

        for (int i = 0; i < (int)nums1.size() && i < k; i++)
        {
           min_heap.emplace(nums1[i] + nums2[0], i, 0);  
        }

        while (!min_heap.empty() && (int)res.size() < k)
        {
            auto [sum, i, j] = min_heap.top();
            min_heap.pop();

            res.push_back({nums1[i], nums2[j]});

            if (j + 1 < (int)nums2.size())
            {
               min_heap.emplace(nums1[i] + nums2[j + 1], i, j + 1); 
            }
        }

        return res;
    }

private:

};