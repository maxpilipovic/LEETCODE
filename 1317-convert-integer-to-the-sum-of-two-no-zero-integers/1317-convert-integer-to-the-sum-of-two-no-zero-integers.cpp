class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        
        while (flag)
        {
            getTwoIntegers(n);
            checkDigits(res);
        }

        return res;
    }

    bool checkDigits(vector<int> res)
    {

        std::string aStr = std::to_string(res[0]);
        std::string bStr = std::to_string(res[1]);

        if ((aStr.find(targetChar) !=std::string::npos || bStr.find(targetChar) != std::string::npos))
        {
            //We know we have 0.
            flag = true;
            return flag;
        }

        flag = false;
        return flag;
    }

    void getTwoIntegers(int n)
    {
        if (a == 0 && b == 0)
        {
            a = n - 1;
            b = 1;
            res.push_back(a);
            res.push_back(b);
            return;
        }
        
        //Clear our elements
        res.clear();

        //Calculate new stuff
        a = a - 1;
        b = b + 1;

        //Append back to array
        res.push_back(a);
        res.push_back(b);
    }


private:
    bool flag = true;
    char targetChar = '0';
    vector<int> res;
    int a = 0;
    int b = 0;
};