def construct_adj(V, edges):
    adj = [[] for _ in range(V)]
    for u, v in edges:
        adj[u].append(v)
        adj[v].append(u)
    return adj

def dfs(u, visited, adj):
    visited[u] = True
    for v in adj[u]:
        if not visited[v]:
            dfs(v, visited, adj)

def count_components(V, adj, skip):
    visited = [False] * V
    count = 0
    for i in range(V):
        if i != skip and not visited[i]:
            dfs(i, visited, adj)
            count += 1
    return count

def find_articulation_points(V, edges):
    adj = construct_adj(V, edges)
    original_components = count_components(V, adj, -1)
    articulation_points = []

    for i in range(V):
        new_components = count_components(V, adj, i)
        if new_components > original_components:
            articulation_points.append(i)

    return articulation_points

V = 5
edges = [[0, 1], [0, 2], [2, 1], [0, 3], [3, 4]]
print("Articulation points:", find_articulation_points(V, edges))
