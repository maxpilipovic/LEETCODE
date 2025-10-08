class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) 
    {
        int n = potions.size();
        vector<int> res;

        //Sort potions
        std::sort(potions.begin(), potions.end());

        for (int num : spells)
        {
            int x = binarySearch(num, potions, success);

            if (x != -1)
            {
                int sum = n - x;
                res.push_back(sum);
            }
            else 
            {
                res.push_back(0);
            }
        }

        return res;
    }

    int binarySearch(int num, vector<int>& potions, long long success)
    {

        //Perform
        int left = 0;
        int right = potions.size() - 1;
        int idx = -1;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            long long product = (long long)potions[mid] * num;
            
            //cout << product 
            if (product >= success)
            {
                
                idx = mid;
                //cout << potions[mid] << endl;
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }

        }

        return idx;
    }



private:
};