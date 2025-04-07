from collections import deque
class Solution:
    def allPathsSourceTarget(self, graph: List[List[int]]) -> List[List[int]]:
        #DFS
        def adjList(graph):

            adjList = {}

            for i, neighbors in enumerate(graph):

                if i not in adjList:
                    adjList[i] = neighbors

            return adjList

        def bfs(adjList, node, dest, path, res):

            queue = deque([(node, path)])

            while queue:
                node, path = queue.popleft()

                if node == dest:
                    res.append(path[:])
                
                for neighbor in adjList[node]:
                    queue.append([neighbor, path + [neighbor]])
                    
        adjList = adjList(graph)
        dest = len(graph) - 1
        res = []
        bfs(adjList, 0, dest, [0], res)

        return res
        
        
        
                


        