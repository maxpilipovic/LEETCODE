class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        
        #adj matrix
        def adjMatrix(edges):
            graph = {i: [] for i in range(numCourses)}

            for edge in edges:

                a,b = edge
                
                graph[b].append(a)

            return graph

        def dfs(node, visited, graph, visiting):
            
            if node in visiting:
                return False
            if node in visited:
                return True
            
            visiting.add(node)
            for neighbor in graph[node]:
                if not dfs(neighbor, visited, graph, visiting):
                    return False
            
            visiting.remove(node)
            visited.add(node)
            return True
                
        visited = set()
        graph = adjMatrix(prerequisites)
        print(graph)

        for i in range(numCourses):
            if i not in visited:
                visiting = set()
                if not dfs(i, visited, graph, visiting):
                    return False
        
        return True


