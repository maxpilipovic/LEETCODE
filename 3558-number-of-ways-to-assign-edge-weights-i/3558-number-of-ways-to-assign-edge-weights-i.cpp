class Solution {
public:
    int assignEdgeWeights(vector<vector<int>>& edges) 
    {
        constexpr const int MOD = 1e9 + 7;

        unordered_map<int, vector<int>> adjList = getAdjList(edges);  

        int depth = dfs(1, -1, adjList, 0);

        return modPow(2, depth - 1, MOD);
    }

    int modPow(long long base, int exp, int mod)
    {
        long long result = 1;

        while (exp > 0)
        {
            if (exp % 2 == 1)
            {
                result = (result * base) % mod;
            }

            base = (base * base) % mod;
            exp /= 2;
        }

        return result;
    }

    int dfs(int node, int parent, unordered_map<int, vector<int>>& adjList, int depth)
    {
        //DFS TO FIND MAX DEPTH
        int maxDepth = depth;

        for (int neighbor: adjList[node])
        {
            if (neighbor == parent)
            {
                //No need
                continue;
            }

            maxDepth = max(maxDepth, dfs(neighbor, node, adjList, depth + 1));
        }

        return maxDepth;
    }

    unordered_map<int, vector<int>> getAdjList(vector<vector<int>>& edges)
    {
        unordered_map<int, vector<int>> adjList;

        for (vector<int>& edge : edges)
        {
            int key = edge[0];
            int value = edge[1];

            adjList[key].push_back(value);
            adjList[value].push_back(key);
        }

        return adjList;
    }
};