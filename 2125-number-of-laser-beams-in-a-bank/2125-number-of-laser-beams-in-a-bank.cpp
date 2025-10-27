class Solution {
public:
    int numberOfBeams(vector<string>& bank) 
    {
        int rows = bank.size();
        int cols = bank[0].size();
        vector<int> lasers;
        int count = 0;
        for (int row = 0; row < rows; row++)
        {
            count = 0;
            for (int col = 0; col < cols; col++)
            {
                //If we can see a 1
                if (bank[row][col] == '1')
                {
                    count++;
                }
            }

            if (count > 0)
            {
                lasers.push_back(count);
            }
        }

        printArray(lasers);

        return findLasers(lasers);
    }

    int findLasers(vector<int>& lasers)
    {
        int total = 0;

        for (int i = 1; i < lasers.size(); i++)
        {
            total += lasers[i - 1] * lasers[i];
        }


        return total;
        
    } 

    void printArray(vector<int>& bank)
    {
        for (int i = 0; i < bank.size(); i++)
        {
            cout << bank[i];

            if (i == bank.size() - 1)
            {
                cout << std::endl; 
            }
            else 
            {
                cout << " "; //Space
            }

        }
    }

private:
    int res = 0;
};