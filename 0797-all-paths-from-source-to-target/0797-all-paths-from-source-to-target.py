class Solution:
    def allPathsSourceTarget(self, graph: List[List[int]]) -> List[List[int]]:

        def adjList(graph):

            adjList = {}

            for i, neighbors in enumerate(graph):

                if i not in adjList:
                    adjList[i] = neighbors

            return adjList

        def dfs(graph, node, dest, path, res):
            
            if node == dest:
                res.append(path[:]) #Copy of entire path

            
            for neighbor in graph[node]:
                dfs(graph, neighbor, dest, path + [neighbor], res)

        adjList = adjList(graph)
        dest = len(graph) - 1
        res = []
        dfs(adjList, 0, dest, [0], res)

        return res
        
        
        
                


        