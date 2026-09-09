class Solution {
public:
    int countCommas(int n) 
    {

        int start = 1000;

        while (start <= n)
        {
            int size = intLength(start);

            int commas = std::max(0, static_cast<int>(floor((size - 1) / 3)));

            //Add to commas
            count += commas;

            //Increment start
            start += 1;
        }

        return count;
    }
    
    int intLength(int n)
    {
        if (n == 0)
        {
            return 1;
        }

        return std::floor(std::log10(n)) + 1;
    }

private:
    int count = 0;
};