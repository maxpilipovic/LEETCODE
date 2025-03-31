from collections import deque
class Solution:
    def canVisitAllRooms(self, rooms: List[List[int]]) -> bool:
        
        #Iterative
        #DFS

        hashy = set([0])
        stack = [0]

        while stack:

            room = stack.pop()

            for key in rooms[room]:
                if key not in hashy:
                    hashy.add(key)
                    stack.append(key)
        
        print(hashy)
        print(rooms)
        return True if len(hashy) == len(rooms) else False

