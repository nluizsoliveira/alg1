class PriorityQueue:
    def __init__(self):
        self.queue = []

    def push(self, distance, node):
        self.queue.append((distance, node))
        self.queue.sort()

    def pop(self):
        if self.is_empty():
            return None
        else:
            return self.queue.pop(0)

    def is_empty(self):
        return len(self.queue) == 0