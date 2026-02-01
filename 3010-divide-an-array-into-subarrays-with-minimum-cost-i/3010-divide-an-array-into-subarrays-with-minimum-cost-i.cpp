class Solution {
public:
    int minimumCost(vector<int>& nums) 
    {
        //Sort nums
        //std::sort(nums.begin(), nums.end());
        
        int count = 1;
        int res = nums[0];
        
        priority_queue<int, vector<int>, greater<int>> minHeap;

        for (int i = 1; i < nums.size(); i++)
        {
            minHeap.push(nums[i]);
        }

        while (count < 3)
        {
            res += minHeap.top();
            minHeap.pop();
            
            count += 1;
        }

        return res;
    }

private:

};