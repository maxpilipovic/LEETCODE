class Solution:
    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
        
        def dfs(graph, current, target, visited):
            if current == target:
                return True
            visited.add(current)

            for neighbor in graph.get(current, []):
                if neighbor not in visited:
                    if dfs(graph, neighbor, target, visited):
                        return True
            return False
        
        graph = {}

        for a, b in edges:
            visited = set()

            if a in graph and b in graph and dfs(graph, a, b, visited):
                return [a, b]
            
            if a not in graph:
                graph[a] = []
            if b not in graph:
                graph[b] = []
            graph[a].append(b)
            graph[b].append(a)

        return []


        

