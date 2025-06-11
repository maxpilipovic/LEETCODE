from collections import deque
class Solution:
    def minMutation(self, startGene: str, endGene: str, bank: List[str]) -> int:
        
        if endGene not in bank:
            return -1
        
        genes = ['A', 'C', 'G', 'T']
        
        #Use a set, O(1)
        bankSet = set(bank)
        visited = set()

        queue = deque()
        queue.append((startGene, 0))

        while queue:
            gene, mutationCount = queue.popleft()

            if gene == endGene:
                return mutationCount
            
            for i in range(len(gene)):
                for g in genes:
                    if gene[i] != g:
                        mutated = gene[:i] + g + gene[i+1:]

                        if mutated in bankSet and mutated not in visited:
                            visited.add(mutated)
                            queue.append((mutated, mutationCount + 1))
    
        return -1



