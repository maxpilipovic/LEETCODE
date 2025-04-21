class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:

        def adjList(prerequisites):

            graph = {}

            for node in range(numCourses):
                graph[node] = []
            
            for edge in prerequisites:
                a, b = edge

                graph[b].append(a)
            
            return graph

        def dfs(graph, node, visited, path):
            
            #Base Case
            if node in path:
                print("gets here")
                return False
            
            if node in visited:
                return True
            
            visited.add(node)
            path.add(node)
            for neighbor in graph[node]:
                if not dfs(graph, neighbor, visited, path):
                    return False
            
            path.remove(node)

            return True


        graph = adjList(prerequisites)
        visited = set()
        print(graph)

        for node in range(numCourses):
            if node not in visited:
                if not dfs(graph, node, visited, set()):
                    return False
        
        return True




        