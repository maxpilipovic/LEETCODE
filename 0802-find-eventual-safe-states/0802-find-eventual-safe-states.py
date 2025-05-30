class Solution:
    def eventualSafeNodes(self, graph: List[List[int]]) -> List[int]:

        def adjList(graph):

            adjList = {}
            
            for node in range(len(graph)):
                if node not in adjList:
                    adjList[node] = []
                for dest in graph[node]:
                    adjList[node].append(dest)

            return adjList

        def dfs(node, adjList, visited, res):

            #Base Case
            if node in visited: #Found a cycle
                return False
            
            if node in res:
                return True

            visited.add(node)

            #Recursive
            for neighbor in adjList[node]:
                if dfs(neighbor, adjList, visited, res) == False:
                    return False
            
            visited.remove(node) #Node is processed
            res.add(node)
            return True


        adjList = adjList(graph)
        res = set()

        #Adds initial terminal nodes
        for i in adjList:
            if adjList[i] == []:
                res.add(i)
    
        for node in range(len(graph)):
            visited = set()
            dfs(node, adjList, visited, res)
        
        return sorted(res)

        

    


        