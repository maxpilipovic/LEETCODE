class Solution:
    def getHint(self, secret: str, guess: str) -> str:
        
        my_dict = dict()
        my_dict2 = dict()

        bulls = 0
        cows = 0

        #Find bulls and count cows
        for i in range(len(secret)):
            if secret[i] == guess[i]:
                bulls += 1
            else:
                if secret[i] in my_dict:
                    my_dict[secret[i]] += 1
                else:
                    my_dict[secret[i]] = 1 
        
                if guess[i] in my_dict2:
                    my_dict2[guess[i]] += 1
                else:
                    my_dict2[guess[i]] = 1
        
        #Compare
        for key in my_dict:
            if key in my_dict2:
                #Take the min
                minValue = min(my_dict[key], my_dict2[key])
                cows += minValue

        return str(bulls) + "A" + str(cows) + "B" 




        