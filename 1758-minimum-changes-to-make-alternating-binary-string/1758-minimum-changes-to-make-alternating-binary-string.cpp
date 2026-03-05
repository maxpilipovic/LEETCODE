class Solution {
public:
    int minOperations(string s) 
    {

        std::string temp = s;

        int res = 0;

        for (int i = 1; i < temp.size(); i++)
        {
            char& c = temp[i];

            if (c == temp[i - 1])
            {
                if (c == '1')
                {
                    c = '0';
                    res += 1;
                }
                else
                {
                    c = '1';
                    res += 1;
                }
            }
        }

        int res2 = 0;
        std::string temp2 = s;

        // force first char to opposite
        temp2[0] = (temp2[0] == '0') ? '1' : '0';
        res2 = 1; // because we flipped index 0

        for (int i = 1; i < temp2.size(); i++)
        {
            char& c = temp2[i];

            if (c == temp2[i - 1])
            {
                c = (c == '1') ? '0' : '1';
                res2 += 1;
            }
        }

        return min(res, res2);
    }

    void Print(string& s)
    {
        for (char c : s)
        {
            cout << c << std::endl;
        }
    }

private:
    int res = 0;
};