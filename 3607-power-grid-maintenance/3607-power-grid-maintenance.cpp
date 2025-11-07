class Solution {
public:
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        
        //1. Created adjList
        unordered_map<int, vector<int>> adjList = getAdjList(connections);
        printAdjList(adjList);

        //2. Use BFS/DFS to 'create' connected components.

        //Map each node to 'strongly connected component' 
        unordered_map<int, int> nodeToComp;
        int compID = 0;
        unordered_map<int, priority_queue<int, vector<int>, greater<int>>> minHeap; //Minheap
        unordered_set<int> visited; //Not sure..
        queue<int> queue;

        //BFS
        //Looping over our nodes..
        for (int i = 1; i <= c; i++)
        {

            //Does not exist...
            if (!visited.count(i))
            {
                compID++; 
                queue.push(i);
                visited.insert(i);

                //While something in queue
                while (!queue.empty())
                {
                    auto ele = queue.front();
                    queue.pop();

                    nodeToComp[ele] = compID;
                    minHeap[compID].push(ele);

                    //Loop through our neighbors.
                    for (int neighbor : adjList[ele])
                    {
                        if (!visited.count(neighbor))
                        {
                            visited.insert(neighbor);
                            queue.push(neighbor);
                        }
                    }
                }
            }
        }

        //3. We'd have to apply the queries using minheap..
        //printMap(nodeToComp);
        //printMapOfHeaps(minHeap);

        unordered_set<int> online;
        
        //Everything is online at first!
        for (int i = 1; i <= c; i++)
        {
            online.insert(i);
        }

        for (const auto& q : queries)
        {

            if (q[0] == 1)
            {   
                
                //GRAB THE INTIAL VALUE FORM MINHEAP
                if (online.count(q[1])) {
                    res.push_back(q[1]);
                    continue;
                }

                //Component...
                int comp = nodeToComp[q[1]];
                auto& pq = minHeap[comp];

                //Not empty AND top value is online!
                if (!pq.empty() && online.count(pq.top()))
                {
                    res.push_back(pq.top());
                }
                else
                {
                    //Not empty
                    while (!pq.empty() && !online.count(pq.top()))
                    {
                        pq.pop();
                    }

                    if (!pq.empty() && online.count(pq.top()))
                    {
                        res.push_back(pq.top());
                    }
                    if (pq.empty())
                    {
                        res.push_back(-1);
                    }
                }

            }
            else if (q[0] == 2)
            {
                //Remove it..
                online.erase(q[1]);
            }
        }

        return res;
    }

    unordered_map<int, vector<int>> getAdjList(vector<vector<int>>& connections) 
    {

        unordered_map<int, vector<int>> adjList;

        for (const auto& c : connections)
        {
                int a = c[0];
                int b = c[1];

                //Append both because undirected graph...
                adjList[a].push_back(b);
                adjList[b].push_back(a);
        }

        return adjList;
    }

    //Print function for unordered_map<int, vector<int>>
    void printAdjList(const unordered_map<int, vector<int>>& adjList) 
    {

        for (const auto& [node, neighbors] : adjList) {
            cout << node << ": ";
            for (int neighbor : neighbors) {
                cout << neighbor << " ";
            }
            cout << endl;
        }

    }

    void printMap(const unordered_map<int, int>& m, const string& name = "Map") {
        cout << name << " (size: " << m.size() << "):" << endl;
        if (m.empty()) {
            cout << "  (empty)" << endl;
            return;
        }
        
        // Sort keys for consistent output
        vector<int> keys;
        for (const auto& [key, value] : m) {
            keys.push_back(key);
        }
        sort(keys.begin(), keys.end());
        
        for (int key : keys) {
            cout << "  " << key << " -> " << m.at(key) << endl;
        }
    }

private:
    vector<int> res;

    //DSU/Union find
};