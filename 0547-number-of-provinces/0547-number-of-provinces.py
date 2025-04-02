class Solution:
    def findCircleNum(self, isConnected: List[List[int]]) -> int:
        
        n = len(isConnected) #Numbner of cities
        visited = set()
        provinces = 0
        
        def dfs(city):
            for neighbor in range(n):
                if isConnected[city][neighbor] == 1 and neighbor not in visited:
                    visited.add(neighbor)
                    dfs(neighbor)

        for city in range(n):
            if city not in visited:
                provinces += 1 #Add province
                visited.add(city) #Add to hashy
                dfs(city)
        
        return provinces

