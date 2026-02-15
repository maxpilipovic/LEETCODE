class Solution {
public:
    string addBinary(string a, string b) 
    {
        int i = a.size() - 1;
        int j = b.size() - 1;
        int carry = 0;
        string res = "";

        while (i >= 0 || j >= 0 || carry)
        {
            int bitA = (i >= 0) ? (a[i] - '0') : 0;
            int bitB = (j >= 0) ? (b[j] - '0') : 0;
            int alphaBit = 0;

            if (bitA == 1 && bitB == 1 && carry == 0)
            {
                alphaBit = 0;    
                carry = 1;
            }

            else if (bitA == 1 && bitB == 1 && carry == 1)
            {
                alphaBit = 1;
                carry = 1;
            }

            else if (bitA == 0 && bitB == 1 && carry == 1)
            {
                alphaBit = 0;
                carry = 1;
            }

            else if (bitA == 0 && bitB == 1 && carry == 0)
            {
                alphaBit = 1;
                carry = 0;
            }

            else if (bitA == 1 && bitB == 0 && carry == 1)
            {
                alphaBit = 0;
                carry = 1;
            }

            else if (bitA == 1 && bitB == 0 && carry == 0)
            {
                alphaBit = 1;
                carry = 0;
            }

            else if (bitA == 0 && bitB == 0 && carry == 0)
            {
                alphaBit = 0;
                carry = 0;
            }

            else //bitA == 0 && bitB == 0 && carry == 1
            {
                alphaBit = 1;
                carry = 0;
            }

            res.push_back(alphaBit + '0');

            i -= 1;
            j -= 1;

        }

        //Reverse
        reverse(res.begin(), res.end());

        return res;
    }

private:

};