#!/usr/bin/python3

"""
Python implementation for Depth First Search algorithm
"""

dummy_graph = {
	'A': set(['C', 'E']),
	'B': set(['C', 'E', 'G']),
	'C': set(['D', 'F', 'G']),
	'D': set(['H']),
	'E': set(['A', 'B', 'C']),
	'F': set(['D', 'I']),
	'G': set(['A']),
	'H': set([]),
	'I': set(['B', 'C'])
}

def dfs(graph, node, visited_nodes):
	if node not in visited_nodes:
		visited_nodes.append(node)
		for n in graph[node]:
			dfs(graph, n, visited_nodes)
	return visited_nodes


def main():
	first_node = list(dummy_graph.keys())[0]
	dfs_sequence = dfs(dummy_graph, first_node, [])
	print(dfs_sequence)

if __name__ == '__main__':
	main()
	
