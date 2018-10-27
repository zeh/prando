"""
Python implementation for Breadth First Search algorithm
"""

from queue import Queue

dummy_graph = {
	'A': ['C', 'E'],
	'B': ['C', 'E', 'G'],
	'C': ['D', 'F', 'G'],
	'D': ['H'],
	'E': ['A', 'B', 'C'],
	'F': ['D', 'I'],
	'G': ['A'],
	'H': [],
	'I': ['B', 'C']
}


def bfs(graph):
	q = Queue()
	visited_nodes = []

	# Get the first node in the graph, mark it as 'visited' and add it to the queue 
	first_node = list(graph.keys())[0]
	visited_nodes.append(first_node)
	q.put(first_node)

	while not q.empty():
		node = q.get()
		for n in graph[node]:
			if n not in visited_nodes:
				visited_nodes.append(n)
				q.put(n)

	return visited_nodes


def main():
	bfs_sequence = bfs(dummy_graph)
	print(bfs_sequence)

if __name__ == '__main__':
	main()
