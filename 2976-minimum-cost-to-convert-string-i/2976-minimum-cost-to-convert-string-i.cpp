class Solution {
public:

    struct Edge 
    {
        int to;
        int cost;
    };

    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) 
    {

        const long long INF = 1LL << 60;

        //adjList
        vector<vector<Edge>> adjList(26); //Up to 26 different chars

        for (int i = 0; i < original.size(); i++)
        {
            int u = original[i] - 'a';
            int v = changed[i] - 'a';
            int w = cost[i];

            adjList[u].push_back({v, w});
        }

        //Dijikstras from each node
        vector<vector<long long>> distFrom(26, vector<long long>(26, INF));
        using State = pair<long long,int>;
        for (int i = 0; i < 26; i++) //distFrom size... always the same 26 chars
        {
            priority_queue<State, vector<State>, greater<State>> pq;
            distFrom[i][i] = 0;
            pq.push({0, i});

            while (!pq.empty())
            {
                auto [d, u] = pq.top(); //d distance and u curr node
                pq.pop();

                if (d > distFrom[i][u])
                {
                    continue;
                }

                for (auto &e : adjList[u])
                {
                    int v = e.to;
                    int w = e.cost;

                    long long newCost = d + (long long) w;

                    if (newCost < distFrom[i][v])
                    {
                        distFrom[i][v] = newCost;
                        pq.push({newCost, v});
                    }
                }
            }
        }

        //Sum cost
        for (int i = 0; i < (int)source.size(); i++)
        {
            if (source[i] == target[i])
            {
                //If its same!!! then zero.
                continue;
            }

            int a = source[i] - 'a';
            int b = target[i] - 'a';

            long long best = distFrom[a][b];

            if (best >= INF / 2)
            {
                return -1;
            }

            total += best;
        }

        return total;
    }

private:
    long long total = 0;
};