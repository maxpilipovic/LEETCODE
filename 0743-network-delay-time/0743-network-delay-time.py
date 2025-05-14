from collections import defaultdict
class Solution:
    def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:
        count = 0

        def adjList(edges):

            graph = defaultdict(list)
            
            for node in edges:
                u, dest, w = node

                graph[u].append((w,dest))
        
            return graph

        graph = adjList(times)
        minHeap = [(0, k)]
        visited = set()

        while minHeap:
            w, dest = heapq.heappop(minHeap)

            if dest in visited:
                continue
            visited.add(dest)

            count = max(count, w)

            #BFS Part
            for w2, dest2 in graph[dest]:
                if dest2 not in visited:
                    heapq.heappush(minHeap, (w + w2, dest2))

        return count if len(visited) == n else -1
        