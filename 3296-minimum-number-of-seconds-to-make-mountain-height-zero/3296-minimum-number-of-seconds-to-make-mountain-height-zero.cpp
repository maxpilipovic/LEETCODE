class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) 
    {
        //(nextFinishTime, workerTime, unitsDoneAfterThisFinish)
        using T = tuple<long long, long long, long long>;

        priority_queue<T, vector<T>, greater<T>> pq;    

        //Add everything to pq
        for (int workerTime : workerTimes)
        {
            pq.push({workerTime, workerTime, 1});
        }

        while (removed < mountainHeight)
        {
            auto [finishTime, t, unitsDone] = pq.top();
            pq.pop();

            ans = finishTime;
            removed++;

            //Formula
            long long nextFinish = finishTime + (unitsDone + 1) * t;

            pq.push({nextFinish, t, unitsDone + 1});

        }

        return ans;

    }

private:
    long long ans = 0;
    int removed = 0;
};