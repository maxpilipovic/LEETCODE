from collections import defaultdict
class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        
        def adjacencyList(edges):

            graph = defaultdict(list)

            for edge in edges:

                a,b = edge

                if b not in graph:
                    graph[b] = []
                if a not in graph:
                    graph[a] = []

                #Add
                graph[b].append(a)
            
            return graph

        graph = adjacencyList(prerequisites)
        print(graph)
        visited = set()

        #DFS
        def dfs(node, visited, path):
            
            #Base Case
            if node in path:
                return False
            
            if node in visited:
                return True
            
            path.add(node)
            #Recursive
            for neighbor in graph[node]:
                
                if not dfs(neighbor, visited, path):
                    return False
            
            #Backtrack
            path.remove(node)
            #Fully explored.
            visited.add(node)

            return True

        for node in range(numCourses):
            print(node)
            if not dfs(node, visited, set()):
                return False
        
        return True
