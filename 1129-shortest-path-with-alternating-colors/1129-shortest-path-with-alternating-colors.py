from collections import deque
class Solution:
    def shortestAlternatingPaths(self, n: int, redEdges: List[List[int]], blueEdges: List[List[int]]) -> List[int]:
        
        def adjList(edges):

            graph = {}

            #Makes the nodes
            for i in range(n):
                graph[i] = []

            #Edge
            for edge in edges:
                a,b = edge
                graph[a].append(b)
            
            return graph
        
        red, blue = 0, 1
        redGraph = adjList(redEdges)
        blueGraph = adjList(blueEdges)

        distances = [[float('inf')] * 2 for _ in range(n)]
        distances[0][red] = 0
        distances[0][blue] = 0
        print(distances)

        visited = set()
        visited.add((0, red))
        visited.add((0, blue))

        queue = deque()
        queue.append((0, red))
        queue.append((0, blue))

        while queue:

            node, color = queue.popleft()

            if color == 0: #RED
                for neighbor in blueGraph[node]:
                    if (neighbor, blue) not in visited:
                        visited.add((neighbor, blue))
                        distances[neighbor][blue] = distances[node][color] + 1
                        queue.append((neighbor, blue))
            else:
                for neighbor in redGraph[node]:
                    if (neighbor, red) not in visited:
                        visited.add((neighbor, red))
                        distances[neighbor][red] = distances[node][color] + 1
                        queue.append((neighbor, red))
            
        #Final result
        result = []
        print(distances)
        for redDist, blueDist in distances:
            shortest = min(redDist, blueDist)
            result.append(shortest if shortest != float('inf') else -1)
        
        return result







        