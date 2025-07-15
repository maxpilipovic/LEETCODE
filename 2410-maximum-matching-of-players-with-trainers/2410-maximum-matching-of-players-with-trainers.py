from collections import Counter
class Solution:
    def matchPlayersAndTrainers(self, players: List[int], trainers: List[int]) -> int:
        
        players.sort()
        trainers.sort()
        print(players)
        print(trainers)
        my_dict = Counter(trainers)
        res = 0

        for i in range(len(players)):
            bestMatch = float('inf')
            bestTrainer = -1
            #maxVal = nums[i]

            for j in range(len(trainers)):

                if trainers[j] >= players[i] and my_dict[trainers[j]] > 0:

                    if trainers[j] < bestMatch:

                        bestMatch = trainers[j]
                        bestTrainer = trainers[j]
                
            if bestTrainer != -1:
                my_dict[bestTrainer] -=1
                res += 1
                
        return res