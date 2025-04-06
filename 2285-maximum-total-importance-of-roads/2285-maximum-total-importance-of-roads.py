class Solution:
    def maximumImportance(self, n: int, roads: List[List[int]]) -> int:

        def adjList(roads):
            graph = {}

            for road in roads:

                a,b = road

                if a not in graph:
                    graph[a] = []
                if b not in graph:
                    graph[b] = []
                
                graph[a].append(b)
                graph[b].append(a)

            return graph
        
        graph = adjList(roads)
        
        #Step 2: Create the importance depending on edges
        degree = {}

        for node in graph:
            degree[node] = len(graph[node])

        #Step 3. Sort by degree in decending order
        sorted_vertices = sorted(degree.items(), key=lambda item: item[1], reverse=True)
        print(sorted_vertices)    

        #Step 4.
        importance = {}

        for i, (vertex, degree) in enumerate(sorted_vertices):
            importance[vertex] = n - i
        print(importance)

        #Step 5: Calculate the importance
        res = 0
        for road in roads:
            a, b = road
            res += importance[a] + importance[b]
        
        return res
