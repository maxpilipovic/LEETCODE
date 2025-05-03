import heapq
class SmallestInfiniteSet:

    def __init__(self):

        self.curr = 1
        self.hashy = set()
        self.heapy = []
        

    def popSmallest(self) -> int:
        if self.heapy:
            val = heapq.heappop(self.heapy)
            self.hashy.remove(val)
            return val
        else:
            val = self.curr
            self.curr += 1
            return val

    def addBack(self, num: int) -> None:
        if num not in self.hashy and num < self.curr:
            self.hashy.add(num)
            heapq.heappush(self.heapy, num)
        


# Your SmallestInfiniteSet object will be instantiated and called as such:
# obj = SmallestInfiniteSet()
# param_1 = obj.popSmallest()
# obj.addBack(num)