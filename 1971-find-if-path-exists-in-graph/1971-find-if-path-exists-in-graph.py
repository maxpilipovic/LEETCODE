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

        def bfs(graph, src, destination):
            queue = deque([src])
            visited = set()

            while queue:
                node = queue.popleft()

                if node == destination:
                    return True
                
                for neighbor in graph[node]:
                    if neighbor not in visited:
                        queue.append(neighbor)
                        visited.add(neighbor)
            
            return False

        graph = adjList(edges)
        
        return bfs(graph, source, destination)
        
