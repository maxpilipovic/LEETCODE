class Solution:
    def findSmallestSetOfVertices(self, n: int, edges: List[List[int]]) -> List[int]:
        
        def adjList(edges):

            graph = {}

            for edge in edges:

                a,b = edge

                if a not in graph:
                    graph[a] = []
                if b not in graph:
                    graph[b] = []

                graph[a].append(b)

            return graph
        
        res = []
        hashy = set()
        for incomingEdge, outgoingEdge in edges:

            hashy.add(outgoingEdge)
        
        for i in range(n):

            if i not in hashy:
                res.append(i)
        
        return res
