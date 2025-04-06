from collections import deque
class Solution:
    def validPath(self, n: int, edges: List[List[int]], source: int, destination: int) -> bool:

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

        def dfs(graph, src, destination, visited):
            
            if src == destination:
                return True

            visited.add(src)

            if src == destination:
                return True
            
            for neighbor in graph[src]:
                if neighbor not in visited:
                    if dfs(graph, neighbor, destination, visited) == True:
                        return True

            return False

        graph = adjList(edges)
        visited = set()
        return dfs(graph, source, destination, visited)
        
