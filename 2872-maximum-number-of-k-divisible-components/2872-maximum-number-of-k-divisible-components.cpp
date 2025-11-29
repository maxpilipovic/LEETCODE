class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {

        //Create our AdjList
        unordered_map<int, vector<int>> adjList = createAdjList(n, edges, values);    

        //Print for testing
        print(adjList);

        //DFS
        dfs(0, 0, adjList, n, values, k);

        return res;
    }

    long long dfs(int i, int parent, unordered_map<int, vector<int>>& adjList, int n, vector<int>& values, int k)
    {
        
        //Increment our sum
        long long currSum = values[i];
        
        for (auto& neighbor : adjList[i])
        {

            if (neighbor == parent)
            {
                continue;
            }

           long long child = dfs(neighbor, i, adjList, n, values, k);

            currSum += child;
        }

        //If check
        if (currSum % k == 0)
        {
            res += 1;
            return 0;
        }

        return currSum;
    }

    unordered_map<int, vector<int>> createAdjList(int n, vector<vector<int>>& edges, vector<int>& values)
    {

        unordered_map<int, vector<int>> adjList;

        //Build the AdjList
        for (auto& edge : edges)
        {
            int a = edge[0];
            int b = edge[1];

            //Add both since it's not a directed graph.
            adjList[a].push_back(b);
            adjList[b].push_back(a);

        }


        return adjList;
    }

    void print(const unordered_map<int, vector<int>>& m) 
    {
        cout << "{" << endl;
        for (const auto& [key, vec] : m) {
            cout << "  " << key << ": [";
            for (size_t i = 0; i < vec.size(); i++) {
                cout << vec[i];
                if (i < vec.size() - 1) cout << ", ";
            }
            cout << "]" << endl;
        }
        cout << "}" << endl;
    }

private:
    int res = 0;
};