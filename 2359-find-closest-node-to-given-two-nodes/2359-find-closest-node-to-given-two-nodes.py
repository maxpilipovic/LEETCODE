class Solution:
    def closestMeetingNode(self, edges: List[int], node1: int, node2: int) -> int:
        
        def adjList(edges):

            graph = {}

            #Create each node with []
            for i in range(len(edges)):
                graph[i] = []
                
            for edge in range(len(edges)):
                if edges[edge] != -1:
                    graph[edge].append(edges[edge])
                else:
                    graph[edge] = []
            
            return graph
        
        def bfs(node, distMap, visited, graph):

            queue = deque()
            queue.append((node, 0))

            #Add on first iteration
            visited.add(node)

            #BFS
            while queue:

                node, distance = queue.popleft()

                #Store the distance
                distMap[node] = distance

                for neighbor in graph[node]:
                    if neighbor not in visited:
                        queue.append((neighbor, distance + 1))
                        visited.add(neighbor)


        graph = adjList(edges)

        node1Map = {}
        node2Map = {}

        bfs(node1, node1Map, set(), graph)
        bfs(node2, node2Map, set(), graph)

        print(node1Map)
        print(node2Map)

        minDist = float('inf')
        resultNode = -1

        for node in node1Map.keys() & node2Map.keys():
            maxDist = max(node1Map[node], node2Map[node])

            if maxDist < minDist or (maxDist == minDist and node < resultNode):
                minDist = maxDist
                resultNode = node
        
        return resultNode


        


