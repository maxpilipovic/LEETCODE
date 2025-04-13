from collections import defaultdict
class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:

        def adjList(prerequisites):
            graph = defaultdict(list)
            
            for src, prereq in prerequisites:
                graph[src].append(prereq)
            
            return graph

        def dfs(node):
            
            if node in path:
                return False

            if node in visited:
                return True
            
            path.add(node)
            for neighbor in graph[node]:
                if dfs(neighbor) == False:
                    return False

            path.remove(node)
            visited.add(node)

            return True
        
        
        
        graph = adjList(prerequisites)
        visited = set()
        path = set()

        for i in range(numCourses):
            if not dfs(i):
                return False

        return True