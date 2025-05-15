from collections import defaultdict
class Solution:
    def minCostConnectPoints(self, points: List[List[int]]) -> int:
        
        def adjList(edges):

            graph = defaultdict(list)

            for i in range(len(points)):
                a,b = points[i]
                for j in range(i + 1, len(points)):
                    c,d = points[j]
                    dist = abs(a-c) + abs(b-d)

                    #Undirected, need both ways
                    graph[i].append((dist, j))
                    graph[j].append((dist, i))

            return graph
        
        graph = adjList(points)
        minHeap = [(0, 0)] #first value
        visited = set()
        count = 0

        while minHeap:
            w, node = heapq.heappop(minHeap)

            if node in visited:
                continue

            visited.add(node)
            count += w

            #BFS PART
            for w2, dest in graph[node]:
                heapq.heappush(minHeap, (w2, dest))

        return count if len(visited) == len(points) else -1

