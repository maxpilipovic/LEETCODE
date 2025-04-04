from collections import deque
class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:

        def buildGraph(numCourses, prerequisites):
            graph = {i: [] for i in range(numCourses)}

            for crs, pre in prerequisites:
                graph[crs].append(pre)
            
            return graph

        def dfs(currNode):
            #Base Case
            if currNode in visited:
                return False
            
            if graph[currNode] == []:
                return True

            visited.add(currNode)
            for neighbor in graph[currNode]:
                if not dfs(neighbor): return False
            
            visited.remove(currNode)
            graph[currNode] = []
            return True

        graph = buildGraph(numCourses, prerequisites)
        visited = set()
        
        for i in range(numCourses):
            if not dfs(i): return False
        
        return True


        


       