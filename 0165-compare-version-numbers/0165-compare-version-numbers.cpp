class Solution {
public:
    int compareVersion(string version1, string version2) {

        int v1Size = version1.size();
        int v2Size = version2.size();
        int i = 0;
        int j = 0;

        //Two Pointer...
        while (i < v1Size || j < v2Size)
        {
            long long num1 = 0;
            long long num2 = 0;

            while (i < v1Size && version1[i] != '.')
            {
                //Convert to long long. Not sure...
                num1 = num1 * 10 + (version1[i] - '0');
                i++;
            }

            while (j < v2Size && version2[j] != '.')
            {
                //Convert to float. Not sure...
                num2 = num2 * 10 + (version2[j] - '0');
                j++;
            }

            cout << num1 << endl;
            cout << num2 << endl;

            //Compare our num1 and num2.
            if (num1 > num2)
            {
                return 1;
            }
            else if (num1 < num2)
            {
                return -1;
            }

            //Increase... skips '.'
            i++;
            j++;
        }

        return 0;
    }


private:
    int res;
};