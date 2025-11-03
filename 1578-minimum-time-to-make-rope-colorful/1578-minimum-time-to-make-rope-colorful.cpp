class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        
        int n = colors.size();

        //Start one ahead..
        for (int i = 0; i < n; i++)
        {
            int j = i + 1;

            //Allows us to not skip i
            int max = neededTime[i];
            int total = neededTime[i];

            //Looks for duplicates...
            while (j < n && colors[i] == colors[j])
            {
                total += neededTime[j];    
                max = std::max(max, neededTime[j]);
                j++;
            }


            //We subtract from total and added to time
            cout << total << endl;
            time += (total - max);
            i = j - 1;
        }


        return time;
    }

private:
    int time = 0;
};