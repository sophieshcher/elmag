from collections import deque

def bfs(graph, start, depth):
    visited = {start}
    queue = deque([(start, 0)])
    result = set()

    while queue:
        node, d = queue.popleft()
        if d > 0:
            result.add(node)
        if d < depth:
            for neighbor in graph.get(node, []):
                if neighbor not in visited:
                    visited.add(neighbor)
                    queue.append((neighbor, d + 1))
    return result

def find_common_friends(graph, user1, user2):
    friends1 = bfs(graph, user1, depth=1)
    friends2 = bfs(graph, user2, depth=1)
    # print(friends2)
    common_friends = friends1 & friends2

    friends_of_friends1 = bfs(graph, user1, depth=2) - friends1
    # print(friends_of_friends1)
    friends_of_friends2 = bfs(graph, user2, depth=2) - friends2
    # print(friends_of_friends2)
    common_friends_of_friends = friends_of_friends1 & friends_of_friends2

    return list(common_friends), list(common_friends_of_friends)

# 🔹 Приклад графа:
social_graph = {
    "A": ["B", "H", "C"],
    "B": ["A", "D", "E","C", "H"],
    "C": ["A", "F", "H"],
    "D": ["B", "G"],

}

common, common_ff = find_common_friends(social_graph, "A", "B")

print("Спільні друзі:", common)
print("Спільні друзі друзів:", common_ff)

# common, common_ff = find_common_friends(social_graph, "B", "C")
#
# print("Спільні друзі:", common)
# print("Спільні друзі друзів:", common_ff)
#
# common, common_ff = find_common_friends(social_graph, "G", "H")
#
# print("Спільні друзі:", common)
# print("Спільні друзі друзів:", common_ff)
