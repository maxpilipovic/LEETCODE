from collections import defaultdict
class Solution:
    def findCheapestPrice(self, n: int, flights: List[List[int]], src: int, dst: int, k: int) -> int:
        
        def adjList(edges):

            graph = defaultdict(list)


            for edge in edges:
                a, b, c = edge

                graph[a].append((b,c))
            
            return graph
        
        graph = adjList(flights)
        minHeap = []
        minHeap.append((0, src, k + 1))
        visited = dict()

        while minHeap:

            w, node, k = heapq.heappop(minHeap)

            if (node in visited) and (visited[node] >= k):
                continue
            visited[node] = k

            if node == dst:
                return w
            
            if k == 0:
                #Skip the iteration
                continue
            

            #BFS PART
            for dest, w2 in graph[node]:
                heapq.heappush(minHeap, (w + w2, dest, k - 1))

        return -1
                