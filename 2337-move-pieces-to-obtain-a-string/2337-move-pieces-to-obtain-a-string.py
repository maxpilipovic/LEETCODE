class Solution:
    def canChange(self, start: str, target: str) -> bool:
        #check structural integrity
        if start.replace('_', '') != target.replace('_', ''):
            return False

        i = 0
        j = 0
        
        while i < len(start) and j < len(start):

            while i < len(start) and start[i] == '_':
                i += 1
            while j < len(start) and target[j] == '_':
                j += 1

            if i < len(start) and j < len(start):
                if start[i] != target[j]:
                    return False
                
                if start[i] == 'L' and i < j: 
                    return False
                if target[j] == 'R' and  i > j:
                    return False
            i += 1
            j += 1

        return True
                



            
        