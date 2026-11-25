class Solution {
public:
    int waysToMakeFair(vector<int>& nums) 
    {
        int prefixSumOdd = 0;
        int prefixSumEven = 0;
        int count = 0;

        //Add all even
        for (int i{}; i < nums.size(); i += 2)
        {
            prefixSumEven += nums[i];
        }   

        //Add all odd
        for (int i = 1; i < nums.size(); i += 2)
        {
            prefixSumOdd += nums[i];
        } 

        int leftEven = 0;
        int leftOdd = 0;

        //Loop thru
        for (int i{}; i < nums.size(); i++)
        {
            int rightEven = 0;
            int rightOdd = 0;

            if (i % 2 == 0)
            {
                //Even
                rightEven = prefixSumEven - leftEven - nums[i];
                rightOdd = prefixSumOdd - leftOdd;
            }
            else
            {
                //Odd
                rightEven = prefixSumEven - leftEven;
                rightOdd = prefixSumOdd - leftOdd - nums[i];
            }

            //Right side flips parity after removal
            int tempEven = leftEven + rightOdd;
            int tempOdd = leftOdd + rightEven;

            if (tempEven == tempOdd)
            {
                count += 1;
            }

            //Move nums[i] into the left side
            if (i % 2 == 0)
            {
                leftEven += nums[i];
            }
            else
            {
                leftOdd += nums[i];
            }
        }

        return count;
    }
};