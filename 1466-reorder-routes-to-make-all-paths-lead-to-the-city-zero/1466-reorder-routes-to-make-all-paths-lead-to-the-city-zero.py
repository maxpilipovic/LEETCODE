from collections import deque
class Solution:
    def minReorder(self, n: int, connections: List[List[int]]) -> int:
        
        def adjList(edges, directedEdges):

            graph = {}
            
            for edge in edges:
                a,b = edge

                if a not in graph:
                    graph[a] = []
                if b not in graph:
                    graph[b] = []

                graph[a].append(b)
                graph[b].append(a)
                directedEdges.add((a, b))


            return graph
        directedEdges = set()
        graph = adjList(connections, directedEdges)

        res = 0
        visited = set()
        print(graph)
        print(directedEdges)

        queue = deque()
        queue.append(0)
        visited.add(0)

        while queue:
            node = queue.popleft()

            for neighbor in graph[node]:
                if neighbor not in visited:

                    if (node, neighbor) in directedEdges:
                        res += 1
                    queue.append(neighbor)
                    visited.add(neighbor)
        
        return res