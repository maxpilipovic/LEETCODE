from collections import deque
class Solution:
    def maxTargetNodes(self, edges1: List[List[int]], edges2: List[List[int]], k: int) -> List[int]:
        
        def bfs(start, adj, k):

            q = deque()
            q.append((start, -1))
            count = 0

            while q and k >= 0:
                size = len(q)
                count += size
                for _ in range(size):
                    u, parent = q.popleft()
                    for v in adj[u]:
                        if v != parent:
                            q.append((v, u))
                k -= 1

            return count

        #Helper function to create adjlist
        def adjList(edges):
            
            graph = {}

            for edge in edges:

                a,b = edge

                if a not in graph:
                    graph[a] = []
                if b not in graph:
                    graph[b] = []
                
                #Undirected
                graph[a].append(b)
                graph[b].append(a)

            return graph
        
        graph1 = adjList(edges1)
        graph2 = adjList(edges2)

        #Edges
        m = len(edges1) + 1
        n = len(edges2) + 1

        #Preprocess (Find the best node in tree2)

        best = 0
        for i in range(n):
            connections = bfs(i, graph2, k - 1)
            best = max(best, connections)
        
        res = []
        for i in range(m):
            connections = bfs(i, graph1, k)
            res.append(connections + best)
        
        return res