class Solution {
public:
    int binaryGap(int n) 
    {
        int lastPos = -1;
        int maxPos = 0;
        int pos = 0;

        while (n > 0)
        {
            if (n & 1)
            {
                if (lastPos != -1)
                {
                    maxPos = std::max(maxPos, pos - lastPos);
                }
                lastPos = pos;
            } 

            pos++;
            n >>= 1;
        }   

        return maxPos; 
    }
};