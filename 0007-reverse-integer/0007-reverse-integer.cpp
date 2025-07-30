class Solution {
public:
    int reverse(int x) {
        
        int64_t res = 0;
        int64_t MAX = std::numeric_limits<int>::max();
        int64_t MIN = std::numeric_limits<int>::min();

        while (x != 0)
        {
            int digit = x % 10;
            x /= 10;

            res = (res * 10) + digit;
        }

        //Figure out our bounds
        if (res > MAX || res < MIN)
        {
            return 0;
        }

        return res;        

    }
};