class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) 
    {
        //Sort based on last value ascending & tiebreaker on first in descending
        sort(intervals.begin(), intervals.end(),
            [](const vector<int>& a, const vector<int>& b)
            {
                //If the values are differnet
                if (a[1] != b[1])
                {
                    return a[1] < b[1]; //Ascending
                }
                
                return a[0] > b[0]; //Decending
            });

        //Previous values
        int p1 = -1;
        int p2 = -1;

        for (const auto& interval : intervals)
        {

            int left = interval[0];
            int right = interval[1];

            //Print
            cout << interval[0] << endl;
            cout << interval[1] << endl;
            
            int count = 0;

            if (p1 >= left && p1 <= right)
            {
                count++;
            }

            if (p2 >= left && p2 <= right)
            {
                count++;
            }

            if (count == 2)
            {
                continue;
            }

            if (count == 1)
            {
                int newNum = right;
                hashy.insert(newNum);
                p1 = p2; //Old second largest becomes first...
                p2 = newNum; //Far right val
            }

            if (count == 0)
            {
                //Do something else
                int first = right - 1;
                int second = right;

                hashy.insert(first);
                hashy.insert(second);
                p1 = first;
                p2 = second;
            }

        }


        return hashy.size();

    }



private:
    unordered_set<int> hashy;
    int res = 0;
};