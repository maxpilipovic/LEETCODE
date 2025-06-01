class Solution:
    def canVisitAllRooms(self, rooms: List[List[int]]) -> bool:
        
        def adjList(edges):

            graph = {}

            for i in range(len(edges)):
                graph[i] = rooms[i]
            
            return graph
        
        def dfs(node, visited, graph):
            
            #Base Case
            if node in visited:
                return
            #Do we need a base?

            visited.add(node)

            for neighbor in graph[node]:
                dfs(neighbor, visited, graph)



        graph = adjList(rooms)
        visited = set()
        dfs(0, visited, graph)

        return len(visited) == len(rooms)
