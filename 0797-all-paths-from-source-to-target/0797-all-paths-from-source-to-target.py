class Solution:
    def allPathsSourceTarget(self, graph: List[List[int]]) -> List[List[int]]:

        res = []

        def adjList(edges):
            
            graph = {}

            #Nodes
            for i in range(len(edges)):
                graph[i] = edges[i]
            
            return graph
        
        def dfs(node, array, targetNode, visited):
            
            #Append
            array.append(node)
            visited.add(node)

            #Base Case
            if node == targetNode:
                res.append(array.copy())
                array.pop()
                visited.remove(node)
                return

            #Loop through neighbors
            for neighbor in adjList[node]:
                if neighbor not in visited:
                    dfs(neighbor, array, targetNode, visited)
            
            array.pop()
            visited.remove(node)
            
        targetNode = len(graph) - 1
        adjList = adjList(graph)
        print(adjList)
        visited = set()

        dfs(0, [], targetNode, visited)

        return res
