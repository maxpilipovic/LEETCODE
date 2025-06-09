class Solution:
    def numOfMinutes(self, n: int, headID: int, manager: List[int], informTime: List[int]) -> int:
        
        def adjList(edges):

            graph = {}

            for i in range(n):
                graph[i] = []
            
            for edge in range(len(edges)):
                if manager[edge] == -1:
                    continue

                graph[manager[edge]].append(edge)

            return graph

        def dfs(node, graph, informTime):

            #Base Case
            if not graph[node]: #[]
                return 0

            #Recursive
            maxTime = 0
            for neighbor in graph[node]:
                maxTime = max(maxTime, dfs(neighbor, graph, informTime))
            
            return informTime[node] + maxTime



        graph = adjList(manager)
        print(graph)
        #visited = set()
        res = dfs(headID, graph, informTime)

        return res

        