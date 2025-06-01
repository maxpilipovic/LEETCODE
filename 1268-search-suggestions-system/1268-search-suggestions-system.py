class Solution:
    def suggestedProducts(self, products: List[str], searchWord: str) -> List[List[str]]:
        
        res = []
        products.sort()

        left = 0
        right = len(products) - 1

        for i in range(len(searchWord)):
            char = searchWord[i]

            while left <= right and (len(products[left]) <= i or products[left][i] != char):
                left += 1
            while left <= right and (len(products[right]) <= i or products[right][i] != char):
                right -= 1
            
            res.append([])
            remain = right - left + 1
            for j in range(min(3, remain)):
                res[-1].append(products[left + j])
            
        return res