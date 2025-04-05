class Solution:
    def findJudge(self, n: int, trust: List[List[int]]) -> int:
        
        def adjList(array):
            
            graph = {}

            for i in array:
                a,b = i

                if a not in graph:
                    graph[a] = []
                
                graph[a].append(b)
            
            return graph
        
        graph = adjList(trust)
        trust = [0] * n

        for node in graph:
            for neighbor in graph[node]:
                trust[neighbor - 1] += 1
                trust[node - 1] -= 1
        
        for i in range(n):
            if trust[i] == n - 1:
                return i + 1
        
        return -1
