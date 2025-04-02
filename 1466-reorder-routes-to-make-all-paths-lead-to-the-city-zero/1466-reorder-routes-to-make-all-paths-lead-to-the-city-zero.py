from collections import deque
class Solution:
    def minReorder(self, n: int, connections: List[List[int]]) -> int:
        
        #Step 1. We need to make a adjacency list
        adj = {i: [] for i in range(n)}

        for a, b in connections:
            adj[a].append((b, 1)) #1 Represents outgoing edge
            adj[b].append((a, 0)) #0 Represents incoming edge
        
        print(adj)

        stack = [0]
        visited = set([0])
        reversals = 0

        while stack:
            city = stack.pop()
            print(city)

            for neighbor, needsReversal in adj[city]:
                if neighbor not in visited:
                    visited.add(neighbor)
                    stack.append(neighbor)
                    reversals += needsReversal
        
        return reversals


