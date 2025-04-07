from collections import deque
class Solution:
    def countCompleteComponents(self, n: int, edges: List[List[int]]) -> int:
        #DFS

        def adjList(edges):

            graph = {}

            for i in range(n):
                graph[i] = []

            for edge in edges:
                a,b = edge

                graph[a].append(b)
                graph[b].append(a)
            
            return graph
        
        def dfs(graph, start, visited, nodes):
            
            visited.add(start)
            nodes.append(start)
            edgeCount = len(graph[start])
            
            for neighbor in graph[start]:
                if neighbor not in visited:
                    edgeCount += dfs(graph, neighbor, visited, nodes)
            
            return edgeCount


                    
        graph = adjList(edges)
        maxCount = 0
        visited = set()

        for node in graph:
            if node not in visited:
                nodes = []
                print(node)
                edgeCount = dfs(graph, node, visited, nodes)
                k = len(nodes)

                if edgeCount // 2 == (k * (k - 1)) // 2:
                    maxCount += 1

        return maxCount


        