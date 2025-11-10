class Solution {
public:
    int minOperations(vector<int>& nums) {
        
        std::stack<int> stack;

        for (int i = 0; i < nums.size(); i++)
        {
            
            while (!stack.empty() && stack.top() > nums[i])
            {
                stack.pop();
            }

            if (nums[i] > 0 && (stack.empty() || nums[i] != stack.top()))
            {
                groupCount += 1;
                stack.push(nums[i]);
            }

        }

        return groupCount;
    }

private:
    int groupCount = 0;
    int minEleCount = 0;
};