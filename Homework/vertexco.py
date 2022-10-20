import random, sys, itertools, pprint


def create_random_directed_graph(n, p=0.5):
    vertices = [i for i in range(n)]
    edges = [[0 for _ in range(n)] for _ in range(n)]

    for i in range(n):
        for j in range(i + 1, n):
            if i != j:
                q = random.uniform(0, 1)
                if q < p:
                    v = random.randint(1, 100)
                    edges[i][j] = v
                    edges[j][i] = v

    return (vertices, edges)

def aproximado_vertexco(graph, shuffle=True):
    vertices, edges = graph[0], graph[1]

    edges_list = []
    for i in range(len(vertices)):
        for j in range(i + 1, len(vertices)):
            if edges[i][j] > 0:
                edges_list += [(i, j)]


    if shuffle:
        random.shuffle(edges_list)


    c = [False for _ in range(len(vertices))]
    
    while len(edges_list) > 0:
        edge = edges_list.pop()
        c[edge[0]] = True
        c[edge[1]] = True
        i = len(edges_list) - 1
        while i > -1:
            if edge[0] in edges_list[i] or edge[1] in edges_list[i]:
                edges_list.pop(i)
            i -= 1
            
    for i in range(len(vertices)):
        is_disconnected = True
        j = 0
        while j < len(vertices) and is_disconnected:
            if i != j and edges[i][j] > 0:
                is_disconnected = False
            j += 1
        if is_disconnected:
            c[i] = True

    c = [i for i in range(len(vertices)) if c[i]]

    return list(c)


def fuerzabruta_vertexco(graph):
    vertices, edges = graph
    best_c = vertices.copy()
    min_c = len(vertices)
    
    for r in range(1, len(vertices) + 1):
        for c in itertools.combinations(vertices, r):
            c = list(c)
            
            covered = [False for _ in range(len(vertices))]

            for v in c:
                covered[v] = True
                for v2 in range(len(vertices)):
                    if v != v2 and edges[v][v2] > 0:
                        covered[v2] = True

            covers_all = True
            i = 0
            while i < len(vertices) and covers_all:
                if not covered[i]:
                    covers_all = False
                i += 1
                
            if covers_all and len(c) < min_c:
                best_c = c
                min_c = len(c)

    return best_c



def main(n, p):
    graph = create_random_directed_graph(n, p)

    print("Cantidad Vertices=", graph[0])
    print("Cantidad de Aristas =")
    pprint.pprint(graph[1])
    print()

    best_bf = fuerzabruta_vertexco(graph)
    print("----Algoritmo Fuerza Bruta---- =  ", best_bf)

    best_approx = aproximado_vertexco(graph)
    print("----Aproximación---- =", best_approx)


if __name__ == "__main__":
    
    n = int(sys.argv[1])
    p = float(sys.argv[2])

    main(n, p)
