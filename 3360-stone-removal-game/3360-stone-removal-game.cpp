class Solution {
public:
    bool canAliceWin(int n) 
    {
        int flag = true;
        int count = 10;

        while (n >= 0)
        {
            
            n -= count;
            count -= 1;
            
            if (flag)
            {
                flag = false;
            }
            else
            {
                flag = true;
            }

            //Base Case
            if (n < 0)
            {
                if (flag)
                {
                    //Alice
                    return true;
                }
                else
                {
                    //Bob
                    return false;
                }
            }
        }   

        return true; 
    }
};