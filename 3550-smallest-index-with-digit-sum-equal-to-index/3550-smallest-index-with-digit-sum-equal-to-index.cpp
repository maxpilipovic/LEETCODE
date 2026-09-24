class Solution {
public:
    int smallestIndex(vector<int>& nums) 
    {

        int sum = 0;

        for (int i{}; i < nums.size(); i++)
        {
            int x = sumOfDigits(nums[i]);

            if (i == x)
            {
                return i;
            }
        }    

        return -1;
    }

    int sumOfDigits(int x)
    {
        int num = x;
        int sum = 0;
        while (num)
        {
            int y = num % 10;

            //Add to sum
            sum += y;

            //Divide by 10
            num /= 10;
        }

        return sum;
    }
};