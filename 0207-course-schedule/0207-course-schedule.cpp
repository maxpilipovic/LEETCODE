class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        //1. Adjacency List.
        //2. We want to run dfs.
        //3. I think we need to find cycles.
        adjacencyList(prerequisites);
        printAdjList(adjList);

        for (int i = 0; i < numCourses; i++)
        {
            if (!dfs(i, numCourses))
            {
                return false;
            }
        }

        return true;
    }

    bool dfs(int node, int numCourses)
    {

        //Base Case

        if (path.count(node))
        {
            return false;
        }

        if (visited.count(node)) 
        {
            return true; //Already looked at, no cycle
        }

        path.insert(node);

        for (int neighbor : adjList[node])
        {
            if (!dfs(neighbor, numCourses)) 
            {
                return false;
            }
        }

        visited.insert(node); //This node is now fully explored...
        path.erase(node);

        return true;
    }

    unordered_map<int, vector<int>> adjacencyList(vector<vector<int>>& edges)
    {
        for (const auto& edge : edges)
        {
            int a = edge[0];
            int b = edge[1];

            adjList[b].push_back(a);
        }

        return adjList;
    }

    void printAdjList(const unordered_map<int, vector<int>>& adjList) 
    {
        if (adjList.empty()) 
        {
            cout << "Adjacency list is empty." << endl;
            return;
        }
        
        cout << "Adjacency List:" << endl;
        for (const auto& pair : adjList) 
        {
            cout << pair.first << " -> ";
            
            if (pair.second.empty()) 
            {
                cout << "[]";
            } else 
            {
                cout << "[";
                for (size_t i = 0; i < pair.second.size(); ++i) 
                {
                    cout << pair.second[i];
                    if (i < pair.second.size() - 1) 
                    {
                        cout << ", ";
                    }
                }
                cout << "]";
            }
            cout << endl;
        }
    }

private:

    unordered_set<int> path;
    unordered_set<int> visited;
    unordered_map<int, vector<int>> adjList;
};