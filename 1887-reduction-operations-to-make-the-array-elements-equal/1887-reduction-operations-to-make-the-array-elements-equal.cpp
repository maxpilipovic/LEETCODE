class Solution {
public:
    int reductionOperations(vector<int>& nums) 
    {
        vector<int> curr = nums;
        int n = nums.size();

        //Sort
        std::sort(curr.begin(), curr.end());

        for (int i = n - 1; i >= 0; i--)
        {
            int largest = curr[i];
            int count = i;
            int secondLargest = largest;

            while (count >= 0 && secondLargest >= largest)
            {
                //First case wont work
                secondLargest = curr[count];
                count -= 1;
            }   

            //If this does not run they are all equal.
            if (secondLargest == largest)
            {
                //we know we found it
                return globalCount;
            }

            //Fix count cause it went past by 1. look at while
            int secondIdx = count + 1;

            //Grab everything to the right
            globalCount += (n - 1) - secondIdx;  

            //We need to move in case of doubles
            i = secondIdx + 1;

            largest = secondLargest;
        }

        return globalCount;
    }
private:
    int globalCount = 0;
};