from collections import deque, defaultdict

class Solution:
    def calcEquation(self, equations: List[List[str]], values: List[float], queries: List[List[str]]) -> List[float]:
        
        adj = defaultdict(list)

        for i, eq in enumerate(equations):
            a, b = eq
            adj[a].append((b, values[i]))
            adj[b].append((a, 1 / values[i]))
        
        def bfs(src, target):
            if src not in adj or target not in adj:
                return -1.0
            if src == target:
                return 1.0
            
            queue = deque()
            visited = set()

            queue.append((src, 1.0))
            visited.add(src)

            while queue:
                node, weight = queue.popleft()

                if node == target:
                    return weight
                
                for neighbor, edge_weight in adj[node]:
                    if neighbor not in visited:
                        queue.append((neighbor, weight * edge_weight))
                        visited.add(neighbor)
            return -1.0

        return [bfs(q[0], q[1]) for q in queries]
