class Solution {
public:
    int nextBeautifulNumber(int n) 
    {

        int temp = n + 1;

        while (true)
        {
            if (isBalanced(temp))
            {
                return temp;
            }
            temp++;
        }
        
    }

    //Could use dictionary and convert and loop with string. but this works as well lowkey.
    bool isBalanced(int temp)
    {
        vector<int> count(10, 0);

        while (temp > 0)
        {
            count[temp % 10]++;
            temp /= 10;
            //cout << temp << std::endl;
        }

        for (int i = 0; i < 10; i++)
        {
            if (count[i] > 0 && count[i] != i)
            {
                return false;
            }
        }

        return true;
    }
};