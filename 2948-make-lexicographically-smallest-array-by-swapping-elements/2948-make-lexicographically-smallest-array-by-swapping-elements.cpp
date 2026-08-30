class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) 
    {
        int n = nums.size();
        //Pair<value, original index>
        vector<pair<int,int>> arr(n);

        for (int i = 0; i < n; i++) 
        {
            arr[i] = {nums[i], i};
        }

        sort(arr.begin(), arr.end());

        vector<int> ans(n);
        int i = 0;
        while (i < n) {
            int j = i;
            // extend the group while consecutive sorted values are within limit
            while (j + 1 < n && arr[j+1].first - arr[j].first <= limit) j++;

            // collect original indices in this group, sort them
            vector<int> idx;
            for (int k = i; k <= j; k++) idx.push_back(arr[k].second);
            sort(idx.begin(), idx.end());

            // assign sorted values (arr[i..j] already sorted by value) 
            // to sorted indices in order
            for (int k = 0; k < idx.size(); k++) {
                ans[idx[k]] = arr[i + k].first;
            }

            i = j + 1;
        }

        return ans;
    }
};