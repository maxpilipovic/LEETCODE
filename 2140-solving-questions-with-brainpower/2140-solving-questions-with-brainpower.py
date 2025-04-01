class Solution:
    def mostPoints(self, questions: List[List[int]]) -> int:

        
        def function(i, questions):

            #Base Case
            if i >= len(questions):
                return 0
            
            points, brainpower = questions[i]

            #Calculate the question
            calculate = points + function(i + brainpower + 1, questions)
            #Skip
            skip = function(i + 1, questions)

            return max(calculate, skip)



        
        return function(0, questions)



        