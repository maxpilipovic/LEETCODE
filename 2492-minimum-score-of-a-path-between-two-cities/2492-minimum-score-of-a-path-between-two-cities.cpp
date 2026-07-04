class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) 
    {
        vector<vector<pair<int, int>>> adj = adjList(n, roads);

        return bfs(adj, n);
    }

    int bfs(vector<vector<pair<int, int>>>& adj, int n)
    {
        queue<int> q;
        vector<bool> visited(n + 1, false);

        q.push(1);
        visited[1] = true;

        int ans = INT_MAX;

        while (!q.empty())
        {
            int city = q.front();
            q.pop();

            for (auto& [neighbor, weight] : adj[city])
            {
                ans = min(ans, weight);

                if (!visited[neighbor])
                {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }

        return ans;
    }

    vector<vector<pair<int, int>>> adjList(int n, vector<vector<int>>& roads) 
    {
        vector<vector<pair<int, int>>> adj(n + 1);

        for (auto& road : roads)
        {
            int u = road[0];  
            int v = road[1];
            int w = road[2];

            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        return adj;
    }
};