class Solution:
    def findJudge(self, n: int, trust: List[List[int]]) -> int:
        
        def adjList(edges):

            graph = {}
            
            #Build nodes first
            for i in range(1, n+1):
                graph[i] = []

            for edge in edges:
                a,b = edge

                graph[a].append(b)
            
            return graph
        
        res = []
        graph = adjList(trust)
        print(graph)

        for key in graph:
            if graph[key] == []:
                res.append(key)

        
        for judge in res:
            count = 0
            for a,b in trust:
                if judge == b:
                    count += 1

            if n-1 == count:
                return judge
        
        return -1
        print(res)
        
