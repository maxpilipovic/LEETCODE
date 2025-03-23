from collections import deque
class Solution:
    def predictPartyVictory(self, senate: str) -> str:

        queueD = deque()
        queueR = deque()

        for i in range(len(senate)):
            if senate[i] == 'R':
                queueR.append(i)
            
            if senate[i] == 'D':
                queueD.append(i)

        while queueD and queueR:
            d = queueD.popleft()
            r = queueR.popleft()

            if d > r:
                queueR.append(r + len(senate))
            else:
                queueD.append(d + len(senate))
        
        return "Radiant" if queueR else "Dire"

            



        