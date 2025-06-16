class Solution:
    def maximalNetworkRank(self, n: int, roads: List[List[int]]) -> int:
        
        #Count all the edges that are connected to both node (a,b) we are visiting.
        def adjList(edges):

            graph = {}

            for edge in edges:
                a,b = edge

                if a not in graph:
                    graph[a] = []
                if b not in graph:
                    graph[b] = []

                graph[a].append(b)
                graph[b].append(a)

            return graph

        maxCount = 0
        graph = adjList(roads)
        print(graph)

        for i in range(n):
            for j in range(i + 1, n):

                #total = len(graph[i]) + len(graph[j])
                total = len(graph.get(i, [])) + len(graph.get(j, []))

                if j in graph.get(i, []):
                    total -= 1
                
                #Check the max
                maxCount = max(maxCount, total)
        
        return maxCount
        
