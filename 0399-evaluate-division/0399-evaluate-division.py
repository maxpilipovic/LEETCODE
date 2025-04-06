from collections import deque
class Solution:
    def calcEquation(self, equations: List[List[str]], values: List[float], queries: List[List[str]]) -> List[float]:
        
        adj = collections.defaultdict(list)

        for i, eq in enumerate(equations):
            a, b = eq
            adj[a].append([b, values[i]])
            adj[b].append([a, 1 / values[i]])
        
        def bfs(src, target):
            if src not in adj and target not in adj:
                return -1
            
            queue = deque()
            visited = set()

            queue.append([src, 1])
            visited.add(src)

            while queue:
                node, weight = queue.popleft()

                if node == target:
                    return weight
                
                for neighbor, weight2 in adj[node]:
                    if neighbor not in visited:
                        queue.append((neighbor, weight * weight2))
                        visited.add(neighbor)
            return -1

        return [bfs(q[0], q[1]) for q in queries]
