class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:

        #Directed graph
        #Topological sort
        def adjList(prerequisites):

            graph = {}

            for i in range(numCourses):
                graph[i] = []

            for edge in prerequisites:
                a, b = edge

                graph[b].append(a)
            

            return graph
        
        def dfs(node):
            if visited[node] == 1:
                #Cycle detected
                return True
            if visited[node] == 2:
                #Already processed
                return False

            visited[node] = 1

            for neighbor in graph[node]:
                if dfs(neighbor):
                    return True

            visited[node] = 2
            res.append(node)
            return False

        graph = adjList(prerequisites)
        visited = [0] * numCourses #0: unvisited #1: visiting #2: visited
        res = []

        for node in range(numCourses):
            if visited[node] == 0:
                if dfs(node):
                    return []
    
        return res[::-1]



        
