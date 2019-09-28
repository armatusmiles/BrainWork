class GraphStructure:
    def __init__(self, input_graphs):
        self.graph_list = input_graphs

    def is_parent(self, parent, graph):
        # Graph not found in Graph list
        if graph not in self.graph_list:
            return False

        if parent == graph:
            return True

        if self.graph_list[graph].count(parent) != 0:
            return True
        
        for graph in self.graph_list[graph]:
            if self.is_parent(parent, graph) == True:
                return True
        
        return False
    
#    A   X
#   /|\ / \
#  B C Y   Z
#   \|  \ /
#    D   V
#   / \   \
#  E   F   W
#       \
#        G

input_graphs = { 
    'G' : ['F'],
    'A' : [],
    'B' : ['A'],
    'C' : ['A'],
    'D' : ['B', 'C'],
    'E' : ['D'],
    'F' : ['D'],
    # another branch
    'X' : [],
    'Y' : ['X', 'A'],
    'Z' : ['X'],
    'V' : ['Z', 'Y'],
    'W' : ['V'],
}

search_input = [
    ('A','G', True),
    ('A', 'Z', False),
    ('A','W', True),
    ('X', 'W', True),
    ('X', 'QWE', False),
    ('A', 'X', False),
    ('X', 'X', True),
    ('1', '1', False),
]

gs = GraphStructure(input_graphs)

for inp in search_input:
    assert gs.is_parent(inp[0], inp[1]) == inp[2]

print('Test finished')
