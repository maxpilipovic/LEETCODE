class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {

        //Sliding window
        int n = nums.size();
        int prevLen = 0;
        int currLen = 1;
        int maxK = 0;

        for (int i = 1; i < n; i++)
        {

            if (nums[i] > nums[i - 1])
            {
                currLen += 1;
            }
            else
            {
                //Break Point...

                //Option 1
                int option1 = currLen / 2;

                //Option 2
                int option2 = std::min(prevLen, currLen);

                maxK = std::max(maxK, std::max(option1, option2));

                //For next iteration
                prevLen = currLen;
                currLen = 1;

            }
        }

        int option1 = currLen / 2;
        int option2 = std::min(prevLen, currLen);
        maxK = std::max(maxK, std::max(option1, option2));

        return maxK;
    }

private:

};