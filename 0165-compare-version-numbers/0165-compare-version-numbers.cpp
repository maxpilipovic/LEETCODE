class Solution {
public:
    int compareVersion(string version1, string version2) 
    {
        
        int v1Size = version1.size();
        int v2Size = version2.size();

        int i = 0;
        int j = 0;

        while (i < v1Size || j < v2Size)
        {
            long long num1 = 0;
            long long num2 = 0;

            while (version1[i] != '.' && i < v1Size)
            {
                num1 = num1 * 10 + (version1[i] - '0');
                i++;
            }

            while (version2[j] != '.' && j < v2Size)
            {
                num2 = num2 * 10 + (version2[j] - '0');
                j++;
            }

            if (num1 < num2)
            {
                return -1;
            }
            if (num1 > num2)
            {
                return 1;
            }

            //Skip remainde
            if (i < v1Size && version1[i] == '.')
            {
                i++;
            }
            if (j < v2Size && version2[j] == '.')
            {
                j++;
            }

        }

        return 0;
    }
};