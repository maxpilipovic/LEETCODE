class Solution:
    def eventualSafeNodes(self, graph: List[List[int]]) -> List[int]:
        
        
        def adjList(edges):

            graph2 = {}

            for i in range(len(edges)):
                graph2[i] = []
            
            for edge in range(len(edges)):
                for i in edges[edge]:
                    graph2[edge].append(i)
            
            return graph2
        
        def dfs(node, visited, graph2, path):

            #CHECKING FOR CYCLES

            #Base Case
            if node in path:
                return True
            
            if node in visited:
                return False
            
            path.add(node)

            for neighbor in graph2[node]:
                if dfs(neighbor, visited, graph2, path):
                    return True

            #We know its safe.
            path.remove(node)
            visited.add(node)

            return False




        graph2 = adjList(graph)
        res = []
        visited = set()
        
        for node in graph2:
            #Check if visited?
            if not dfs(node, visited, graph2, set()):
                res.append(node)
        
        return sorted(res)

