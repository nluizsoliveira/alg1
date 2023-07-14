from graph import Graph

def parse_input(raw_input):
    start, end, raw_distance = raw_input.split(' ')
    distance = round(float(raw_distance), 2)
    return start, end, distance
    
graph = Graph()
qtd_nodes = int(input())
for node in range (qtd_nodes):
    node_id = input()
    graph.add_node(node_id)

qtd_edges = int(input())
for edge in range (qtd_edges):
    raw_input = input()
    start, end, distance = parse_input(raw_input)
    graph.add_edge(start, end, distance)
    
shortest_paths_from_pizzaria = graph.get_shortest_paths('Pizzaria')
qtd_delivers = int(input())
for deliver in range(qtd_delivers):
    end = input()
    distance = shortest_paths_from_pizzaria[end]
    cost = 1.50 + (0.2 * distance)
    print('{:.2f}'.format(cost))
    