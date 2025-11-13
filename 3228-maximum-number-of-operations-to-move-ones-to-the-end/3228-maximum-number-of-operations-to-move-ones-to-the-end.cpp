class Solution {
public:
    int maxOperations(string s) {
        
        int n = s.size();
        int countOnes = 0;
        //bool flag = false;

        for (int i = 0; i < n; i++)
        {

            if (s[i] == '1')
            {
                countOnes += 1;
            }

            if (i < n - 1 && s[i] == '1' && s[i + 1] == '0') //NO BOUNDS CHECK?
            {
                res += countOnes;
                //countOnes = 0;
            }

        }

        return res;
    }

private:
    int res = 0;
};