class Solution {
public:
    int smallestNumber(int n) 
    {
        int x = n;

        while (true)
        {
            if (allOnes(x))
            {
                return x;
            }

            x++;
        }

        return 0;
    }

    bool allOnes(int x)
    {
        while (x > 0)
        {
            if ((x & 1) == 0) //Found a 0 bit
                return false;
            x >>= 1;
        }
        return true;
    }
};