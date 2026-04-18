class Solution {
public:
    int mirrorDistance(int n) 
    {
        int reverse = reverseInt(n);
        cout << reverse << std::endl;

        int x = abs(n - reverse);

        return x;
    }

    int reverseInt(int n)
    {
        int rev = 0;

        while (n != 0)
        {
            //first int... 
            int digit = n % 10;
            rev = rev * 10 + digit; //Adding that digit.
            n /= 10; //Removing first digit.
        }   

        return rev;
    }

private:

};