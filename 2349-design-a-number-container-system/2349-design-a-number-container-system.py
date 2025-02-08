class NumberContainers:

    def __init__(self):
        self.my_dict = {}
        self.idx = defaultdict(list)
        

    def change(self, index: int, number: int) -> None:
        self.my_dict[index] = number
        heappush(self.idx[number], index)
        

    def find(self, number: int) -> int:
        if number not in self.idx:
            return -1
        #Loop thru list
        while self.idx[number]:
            i = self.idx[number][0]
            if self.my_dict[i] == number:
                return i
            heappop(self.idx[number])
        return -1



        


# Your NumberContainers object will be instantiated and called as such:
# obj = NumberContainers()
# obj.change(index,number)
# param_2 = obj.find(number)