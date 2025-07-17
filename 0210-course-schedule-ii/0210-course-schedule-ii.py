from collections import defaultdict
class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        
        def adjList(edges):
            
            graph = defaultdict(list)

            #Generate our values -> []
            for edge in edges:
                a,b = edge

                graph[b].append(a)

            return graph

        def dfs(node, path):

            #Base Case
            if node in path:
                return False
                #Return false (THIS IS CYCLE)
            
            #Cycle
            if node in visited:
                return True
            
            path.add(node)
            for neighbor in graph[node]:
                if not dfs(neighbor, path):
                    return False
            
            path.remove(node)
            visited.add(node)
            res.append(node)
            return True
            #path.remove(node)
        
        graph = adjList(prerequisites)
        print(graph)
        visited = set()
        path = set()
        res = []

        for course in range(numCourses):
            if course not in visited:
                if not dfs(course, path):
                    return []
        
        return res[::-1]