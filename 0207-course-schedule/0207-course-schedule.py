class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:

        def adjList(edges):

            graph = {}

            for edge in edges:
                a,b = edge

                if a not in graph:
                    graph[a] = []
                if b not in graph:
                    graph[b] = []

                graph[b].append(a)
            
            return graph
        
        def dfs(node, visited, path, graph):
            
            if node in path: #Cycle detection
                return True

            if node in visited: #Speed up.
                return False 
            
            path.add(node)

            for neighbor in graph.get(node, []):
                if dfs(neighbor, visited, path, graph):
                    return True
            
            path.remove(node)
            visited.add(node)

            return False

        

        graph = adjList(prerequisites)
        visited = set()

        print(graph)


        for node in range(numCourses - 1):
            if dfs(node, visited, set(), graph):
                return False
        
        return True


        