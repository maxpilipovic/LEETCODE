class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) 
    {
        int n = (int)grid.size();
        vector<int> zeros(n, 0);

        //Count zeros
        for (int i = 0; i < n; i++)
        {
            int count = 0;

            for (int j = n - 1; j >= 0; j--)
            {
                if (grid[i][j] == 0)
                {
                    count++;
                }
                else
                {
                    break;  //STOP when we hit first 1
                }
            }

            zeros[i] = count;
        }

        int swaps = 0;

        for (int i = 0; i < n; i++)
        {
            int need = n - 1 - i;

            int j = i;

            while (j < n && zeros[j] < need)
            {
                j += 1;
            }

            if (j == n)
            {
                return -1;
            }

            //Doees the swaps
            while (j > i)
            {
                swap(zeros[j], zeros[j - 1]);
                swaps++;
                j--;
            }
        }

        return swaps;
    }
};