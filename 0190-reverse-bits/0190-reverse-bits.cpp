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
          int lastBit = n % 2; //Last digit
          result = result * 2 + lastBit; //Bit shifts left
          std::cout << result << std::endl; //Bit shifts right
          n /= 2;
        }

        return result;
    }
};