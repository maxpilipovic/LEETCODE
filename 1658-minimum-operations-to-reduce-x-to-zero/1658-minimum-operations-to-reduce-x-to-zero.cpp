class Solution {
public:
    int minOperations(vector<int>& nums, int x) 
    {
        int n = nums.size();

        //Find the max
        int total = 0;

        for (int i{}; i < nums.size(); i++)
        {
            total += nums[i];
        }     

        int left = 0;
        int currSum = 0;
        for (int right{}; right < nums.size(); right++)
        {

            //Add to sum
            currSum += nums[right];

            while (left <= right && total - currSum < x)
            {
                currSum -= nums[left];
                left += 1;
            }

            //If our sum is x.
            if (total - currSum == x)
            {
                int subject = findDistance(left, right, n - 1);

                //Get the min
                res = min(res, subject);
            }   
        }

        return res == INT_MAX ? -1 : res;
    }

    int findDistance(int left, int right, int n)
    {

        int realLeft = left;
        int realRight = n - right;

        return realLeft + realRight;
    }

private:
    int res = INT_MAX;
};