class Solution:
    def isBipartite(self, graph: List[List[int]]) -> bool:
        color = {}

        def dfs(node, c):
            if node in color:
                return color[node] == c
            
            color[node] = c

            for neighbor in graph[node]:
                if not dfs(neighbor, 1 - c):
                    return False
            
            return True

        #Loop through each node
        for node in range(len(graph)):

            #We check for it not being in hashy(color). Reason why MIGHT NOT BE CONNECTED
            if node not in color:
                if not dfs(node, 0):
                    return False
        
        return True
