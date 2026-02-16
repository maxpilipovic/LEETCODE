class Solution {
public:
    int reverseBits(int n) {
        uint32_t result = 0;
        //n -> bit shifting right
        //101
        //10
        //01

        //result
        //000
        //001
        //010
        //101
        
        for (int i = 0; i < 32; i++)
        {
            int lastBit = n % 2;
            result = result <<= 1;
            result += lastBit;
            n >>= 1;
        }


        return result;
    }
};