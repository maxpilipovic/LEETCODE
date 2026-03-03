class Solution {
public:
    char findKthBit(int n, int k) 
    {

        std::string res = "0";

        for (int i = 2; i <= n; i++)
        {
            buildString(res);
        }

        return res[k - 1]; //res is 1 indexed

    }

    void buildString(std::string& res)
    {
        std::string temp = res;

        //Invert
        for (char& c : temp)
        {
            if (c == '0')
            {
                c = '1';
            }
            else
            {
                c = '0';
            }
        }
        
        //Reverse
        std::reverse(temp.begin(), temp.end());

        //Concatenate
        res = res + "1" + temp;
    }
};