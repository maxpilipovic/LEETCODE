from collections import deque
class Solution:
    def pushDominoes(self, dominoes: str) -> str:
        
        #QUEUE BASED SOLUTION

        dom = list(dominoes)
        queue = deque()

        for i, d in enumerate(dom):

            if d == 'L' or d == 'R':
                queue.append((i, d))
        
        while queue:
            index, domino = queue.popleft()

            if domino == "L" and index > 0 and dom[index - 1] == ".":
                queue.append((index - 1, 'L'))
                dom[index - 1] = 'L'
            
            elif domino == "R":
                if index + 1 < len(dom) and dom[index + 1] == ".":
                    if index + 2 < len(dom) and dom[index + 2] == "L":
                        queue.popleft()
                    else:
                        queue.append((index + 1, 'R'))
                        dom[index + 1] = 'R'
        

        return "".join(dom)





        