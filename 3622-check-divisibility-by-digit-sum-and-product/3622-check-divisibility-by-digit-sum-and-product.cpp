class Solution {
public:
    bool checkDivisibility(int n) 
    {
        int dSum = digitSum(n);
        int dProduct = digitProduct(n);

        return n % (dSum + dProduct) == 0;
    }

    int digitSum(int n)
    {
        int x = 0;

        while (n > 0)
        {
            int temp = n % 10;

            //Add to x
            x += temp;

            n /= 10;
        }

        return x;
    }

    int digitProduct(int n)
    {
        int x = 1;

        while (n > 0)
        {
            int temp = n % 10;

            //Add to x
            x *= temp;

            n /= 10;
        }

        return x;
    }
};