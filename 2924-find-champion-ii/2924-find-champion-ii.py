from collections import defaultdict
class Solution:
    def findChampion(self, n: int, edges: List[List[int]]) -> int:

        def adjList(edges):

            graph = {}

            for edge in edges:
                a, b = edge

                if a not in graph:
                    graph[a] = []
                if b not in graph:
                    graph[b] = []

                graph[a].append(b)
            
            return graph
        
        graph = adjList(edges)
        print(graph)

        #Converts to indegrees
        indegree = defaultdict(int)
        for u in graph:
            for v in graph[u]:
                indegree[v] += 1 
        
        #Add extra 0's
        for i in range(n):
            if i not in indegree:
                indegree[i] = 0
        print(indegree)

        candidates = [x for x in range(n) if indegree[x] == 0]
        print(candidates)
        
        return candidates[0] if len(candidates) == 1 else -1
        