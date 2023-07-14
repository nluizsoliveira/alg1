from priority_queue import PriorityQueue

class Graph:
    def __init__(self):
        self.adjacency_map = {}

    def add_node(self, node):
        if node not in self.adjacency_map:
            self.adjacency_map.update({node: []})

    def add_edge(self, start, end, distance):
        if start in self.adjacency_map and end in self.adjacency_map:
            self.adjacency_map.get(start).append((end, distance))
            self.adjacency_map.get(end).append((start, distance))

    def get_shortest_paths(self, start):
        if start not in self.adjacency_map:
            return None

        distances = self.initialize_distances_from_node(start)
        priority_queue = PriorityQueue()
        priority_queue.push(0, start)

        while not priority_queue.is_empty():
            current_distance, current_node = priority_queue.pop()

            if current_distance <= distances[current_node]:
                self.update_neighbors_distances(current_distance, current_node, distances, priority_queue)

        return distances

    def initialize_distances_from_node(self, start):
        distances = {node: float('infinity') for node in self.adjacency_map}
        distances[start] = 0
        return distances

    def update_neighbors_distances(self, current_distance, current_node, distances, priority_queue):
        for neighbor, distance in self.adjacency_map[current_node]:
            distance = current_distance + distance
            if distance < distances[neighbor]:
                distances[neighbor] = distance
                priority_queue.push(distance, neighbor)