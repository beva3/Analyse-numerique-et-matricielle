def dfs_iteratif(graph, start):
    visited = set()
    stack = [start]  # Pile (LIFO)
    resultat = []  # Liste pour stocker l'ordre des visites

    while stack:
        node = stack.pop()  # Dépiler (LIFO)
        if node not in visited:
            visited.add(node)
            resultat.append(node)
            stack.extend(reversed(graph[node]))  # Ajouter les voisins dans l'ordre

    return resultat  # Retourne l'ordre des visites


# Représentation du graphe (liste d’adjacence)
graph = {
    'A': ['B', 'C'],
    'B': ['A', 'D', 'E'],
    'C': ['A', 'F'],
    'D': ['B'],
    'E': ['B', 'F'],
    'F': ['C', 'E']
}

# Exécuter DFS itérati
print(dfs_iteratif(graph, 'A'))  # ['A', 'C', 'F', 'E', 'B', 'D']
print(dfs_iteratif(graph, 'B'))  # ['A', 'C', 'F', 'E', 'B', 'D']
print(dfs_iteratif(graph, 'C'))  # ['A', 'C', 'F', 'E', 'B', 'D']
print(dfs_iteratif(graph, 'D'))  # ['A', 'C', 'F', 'E', 'B', 'D']
print(dfs_iteratif(graph, 'E'))  # ['A', 'C', 'F', 'E', 'B', 'D']
print(dfs_iteratif(graph, 'F'))  # ['A', 'C', 'F', 'E', 'B', 'D']

