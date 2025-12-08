class Solution {
public:
    int countTriples(int n) {
        
        int a = 1;
        int b = 1;
        int c = n;


        for (int c = 1; c <= n; c++)
        {
            int cRes = c * c;

            for (int a = 1; a < c; a++)
            {
                
                //Calculcate b from here???
                int bRes = cRes - (a * a);
                int b = sqrt(bRes);

                if (b <= c && b > 0 && b * b == bRes)
                {
                    res += 1;
                }
            }
        }

        return res;        
    }

private:
    int res = 0;
};