class Solution {
public:
    bool checkString(string s) 
    {
        int countA = 0;
        int countB = 0;

        for (char c : s)
        {
            //Base Case
            if (c == 'a' && countB > 0)
            {
                return false;
            }

            if (c == 'a')
            {
                countA += 1;
            }

            if (c == 'b')
            {
                countB += 1;
            }


        }

        return true;
    }

private:

};