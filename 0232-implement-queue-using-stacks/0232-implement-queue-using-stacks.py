class MyQueue:

    def __init__(self):
        self.inStack = []
        self.outStack = []

    def push(self, x: int) -> None:
        self.inStack.append(x)

    def pop(self) -> int:
        
        if not self.outStack:
            while self.inStack:
                x = self.inStack.pop()
                self.outStack.append(x)
        return self.outStack.pop()

    def peek(self) -> int:
        if not self.outStack:
            while self.inStack:
                x = self.inStack.pop()
                self.outStack.append(x)
        return self.outStack[-1]

    def empty(self) -> bool:
        if not self.outStack and not self.inStack:
            return True
        else:
            return False


# Your MyQueue object will be instantiated and called as such:
# obj = MyQueue()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.peek()
# param_4 = obj.empty()