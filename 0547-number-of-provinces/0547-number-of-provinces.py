class Solution:
    def findCircleNum(self, isConnected: List[List[int]]) -> int:

        def adjList(grid):

            graph = {}
            rows = len(grid)
            cols = len(grid[0])

            #Populate the graph
            for i in range(rows):
                graph[i] = []
            
            for row in range(rows):
                for col in range(cols):
                    
                    #Thats the same node
                    if row == col:
                        continue
                    
                    if grid[row][col] == 1:
                        graph[row].append(col)

            return graph
        
        def dfs(node, visited, graph):
            
            if node in visited:
                return
            
            visited.add(node)

            for neighbor in graph[node]:
                dfs(neighbor, visited, graph)

        graph = adjList(isConnected)
        visited = set()
        count = 0

        for i in range(len(isConnected)):
            if i not in visited:
                dfs(i, visited, graph)
                count += 1

        return count


                

        
