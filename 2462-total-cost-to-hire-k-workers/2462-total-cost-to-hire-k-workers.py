import heapq
class Solution:
    def totalCost(self, costs: List[int], k: int, candidates: int) -> int:
        
        minHeap = []

        left = 0
        right = len(costs) - 1
        count = 0

        #Create the inital heap
        for i in range(candidates):
            if left <= right:
                heapq.heappush(minHeap, (costs[left], left))
                left += 1
        print(left)
        print(right)
        print(minHeap)

        for i in range(candidates):
            if left <= right:
                heapq.heappush(minHeap, (costs[right], right))
                right -= 1
        print()
        print(left)
        print(right)
        print(minHeap)

        #Hire k workers
        while k > 0:
            currCost, index = heapq.heappop(minHeap)
            count += currCost
            k -= 1

            if left <= right:
                if index < left:
                    heapq.heappush(minHeap, (costs[left], left))
                    left += 1
                else:
                    heapq.heappush(minHeap, (costs[right], right))
                    right -= 1
        
        return count

