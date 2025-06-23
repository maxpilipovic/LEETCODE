class Solution {
public:
    bool isPalindrome(int x) {
        
        if (x < 0) 
        {
            return false;
        }

        int original = x;
        int64_t reversed = 0;

        while (x > 0) 
        {
            //Get first
            int digit = x % 10;
            

            //Get reversed
            reversed = reversed * 10 + x % 10;
            x /= 10;
            

        }

        return original == reversed;
    }
};