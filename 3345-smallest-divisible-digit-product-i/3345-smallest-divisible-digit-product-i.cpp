class Solution {
public:
    int smallestNumber(int n, int t) 
    {
        while (n > 0)
        {
            int x = findDigitProduct(n);

            if (x % t == 0)
            {
                return n;
            }

            n += 1;
        }

        return -1;
    }

    int findDigitProduct(int n)
    {
        int c = 1;

        std::string res = to_string(n);

        for (int i{}; i < res.size(); i++)
        {
            c *= (res[i] - '0');
        }

        return c;
    }
};