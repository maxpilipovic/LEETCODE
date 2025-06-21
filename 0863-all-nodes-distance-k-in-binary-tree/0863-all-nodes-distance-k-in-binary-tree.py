# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

from collections import deque
class Solution:
    def distanceK(self, root: TreeNode, target: TreeNode, k: int) -> List[int]:
        

        #1. Convert this adjList for graph traversal
        graph = {} #[]

        def dfs(node):
            
            nonlocal graph

            #Base Case
            if not node:
                return

            if node.val not in graph:
                graph[node.val] = []
            
            #Adds the value
            if node.left:
                graph[node.val].append(node.left.val)

                if node.left.val not in graph:
                    graph[node.left.val] = []
                graph[node.left.val].append(node.val)
                dfs(node.left)
            
            if node.right:
                graph[node.val].append(node.right.val)

                if node.right.val not in graph:
                    graph[node.right.val] = []
                graph[node.right.val].append(node.val)
                dfs(node.right)
        
        dfs(root)
        

        #2. BFS.
        visited = set()
        queue = deque()
        res = []

        for key in graph:
            if key == target.val:
                queue.append((key, 0))

        while queue:
            node, val = queue.popleft()

            if node in visited:
                continue

            #Add our visited
            visited.add(node)

            if val == k:
                #Append?
                res.append(node)

            for neighbor in graph[node]:
                queue.append((neighbor, val + 1))
        
        return res

            

            
