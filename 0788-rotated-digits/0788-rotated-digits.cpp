class Solution {
public:
    int rotatedDigits(int n) 
    {

        int count = 0;

        while (count <= n)
        {

            int newInt = count;
            int newNum = 0;
            bool changed = false;
            bool valid = true;

            while (newInt > 0)
            {
                int lastDigit = newInt % 10;

                //Simulate the rotation
                int rotatedNum = rotateNum(lastDigit);

                if (rotatedNum == -1)
                {
                    //if its fucked...
                    valid = false;
                    break;
                }
                else if (rotatedNum != lastDigit)
                {
                    //If its different
                    //Build the int
                    changed = true;
                    newNum = newNum * 10 + rotatedNum;
                }
                else
                {
                    //If its the same
                    //Build the int
                    newNum = newNum * 10 + rotatedNum;
                }

                newInt /= 10;
            }

            //Final check
            if (changed && valid)
            {
                //Increase counter
                res += 1;
            }
            
            //Increment count
            count += 1;

        }

        return res;
    }

    int rotateNum(int lastDigit)
    {
        int rotatedValue = -1;

        switch(lastDigit)
        {
            case 0:
            case 1:
            case 8:
                rotatedValue = lastDigit;
                break;
            case 2:
                rotatedValue = 5;
                break;
            case 5:
                rotatedValue = 2;
                break;
            case 6:
                rotatedValue = 9;
                break;
            case 9:
                rotatedValue = 6;
                break;
        }

        return rotatedValue;
    }

private:
    int res = 0;
};