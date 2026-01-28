class Solution {
public:

    struct Edge
    {
        int to;
        int cost;
        //int id;
    };

    int minCost(int n, vector<vector<int>>& edges) 
    {
        vector<vector<Edge>> adjList(n); 

        for (int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];

            //Pushing node u ->
            //to -> v -> neighbor node
            //cost -> w -> cost
            //id -> i -> index of the edge in the input (unique identifier)
            adjList[u].push_back({v, w,});
            adjList[v].push_back({u, 2 * w});

        }

        //Dijikstras setup...
        const long long INF = (1LL << 60);
        vector<long long> dist(n, INF);
        dist[0] = 0;

        //Min heap. (Cost so far, node)
        using P = pair<long long, int>; //cost, node
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0, 0});

        //Dijikstra algo
        while (!pq.empty())
        {
            auto [d, u] = pq.top();
            pq.pop();

            if (d != dist[u])
            {
                continue;
            }

            for (auto &e : adjList[u])
            {
                int v = e.to;
                long long nd = d + e.cost;

                if (nd < dist[v])
                {
                    dist[v] = nd;
                    pq.push({nd, v});
                }
            }
        }

        return dist[n - 1] == INF ? -1 : (int)dist[n - 1];
    }

private:

};