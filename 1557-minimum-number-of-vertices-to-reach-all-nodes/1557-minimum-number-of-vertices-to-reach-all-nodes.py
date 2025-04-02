class Solution:
    def findSmallestSetOfVertices(self, n: int, edges: List[List[int]]) -> List[int]:
        
        res = []
        hashy = set()

        for a, b in edges:
            hashy.add(b)
        
        print(hashy)

        for i in range(n):
            if i not in hashy:
                res.append(i)
        
        return res
