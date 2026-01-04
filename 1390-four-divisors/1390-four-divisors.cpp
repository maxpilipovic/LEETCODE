class Solution {
public:
    int sumFourDivisors(vector<int>& nums) 
    {

        for (int i = 0; i < nums.size(); i++)
        {
            int n = nums[i];
            int localCount = 2;
            int localSum = 1 + n;

            for (int d = 2; d * d <= n; d++)
            {
                if (n % d == 0)
                {
                    int newNum = n / d;

                    if (d == newNum)
                    {
                        localCount += 1;
                        localSum += d;
                    }
                    else
                    {
                        localCount += 2;
                        localSum += d + newNum;
                    }

                    if (localCount > 4)
                    {
                        break;
                    }
                }


            }

            if (localCount == 4)
            {
                globalCount += localSum;
            }
        }

        return globalCount;
    }

private:
    int globalCount = 0;
};