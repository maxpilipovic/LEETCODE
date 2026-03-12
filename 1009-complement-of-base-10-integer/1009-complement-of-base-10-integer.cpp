class Solution {
public:
    int bitwiseComplement(int n) 
    {
        if (n == 0)
        {
            return 1;
        }

        int mask = 0;
        int temp = n;

        while (temp > 0)
        {
            //Creates 1's of same bit size...
            mask = (mask << 1) | 1;
            temp >>= 1;
        }

        //n xor with mask flips everything
        return n ^ mask;
    }
};