class MinStack(object):

    def __init__(self):
        self.stack = []
        

    def push(self, val):

        return self.stack.append(val)
        

    def pop(self):
        return self.stack.pop()
        

    def top(self):
        return self.stack[-1]
        

    def getMin(self):
        return min(self.stack)
        


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(val)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()