class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) 
    {
        sort(events.begin(), events.end());

        int n = events.size();
        vector<int> suffixMax(n);

        //Grab value.
        suffixMax[n - 1] = events[n - 1][2];

        //Loop backwards.
        for (int i = n - 2; i >= 0; i--)
        {
            suffixMax[i] = max(events[i][2], suffixMax[i + 1]);
        }

        //Answer
        int ans = 0;


        for (int i = 0; i < n; i++) 
        {
            int currentValue = events[i][2];
            ans = max(ans, currentValue);

            int nextIndex = findNextEvent(events, events[i][1]);

            if (nextIndex < n) 
            {
                ans = max(ans, currentValue + suffixMax[nextIndex]);
            }
        }

        return ans;

    }

    int findNextEvent(vector<vector<int>>& events, int currentEnd) {
        int left = 0;
        int right = events.size();

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (events[mid][0] > currentEnd) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }

private:

};