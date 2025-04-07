from collections import deque
class Solution:
    def countCompleteComponents(self, n: int, edges: List[List[int]]) -> int:


        def adjList(edges):

            graph = {}

            for i in range(n):
                graph[i] = []

            for edge in edges:
                a,b = edge

                graph[a].append(b)
                graph[b].append(a)
            
            return graph
        
        def bfs(graph, start, visited):
            
            queue = deque([start])
            visited.add(start)
            nodes = [start]
            edgeCount = 0

            while queue:
                node = queue.popleft()

                for neighbor in graph[node]:
                    edgeCount += 1
                    if neighbor not in visited:
                        visited.add(neighbor)
                        queue.append(neighbor)
                        nodes.append(neighbor)

            return nodes, edgeCount // 2 #Since each edge is connected twice
                    
        graph = adjList(edges)
        maxCount = 0
        visited = set()

        for node in graph:
            if node not in visited:
                print(node)
                nodes, edgeCount = bfs(graph, node, visited)
                k = len(nodes)

                if edgeCount == (k * (k - 1)) // 2:
                    maxCount += 1

        return maxCount


        