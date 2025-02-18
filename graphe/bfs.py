"""
bfs  : PARCOUR EN LARGEUR
"""
from collections import deque

def bfs(graph, start):
    visited = set()  # Ensemble des nœuds visités
    queue = deque([start])  # File d'attente avec le nœud de départ
    resultat = []  # Liste pour stocker l'ordre des visites

    while queue:
        node = queue.popleft()  # Défilement (FIFO)
        if node not in visited:
            visited.add(node)
            resultat.append(node)
            queue.extend(graph[node])  # Ajouter les voisins non visités
        
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

# Exécuter BFS à partir de 'A'
resultat_bfs = bfs(graph, 'F') # you can chenge any, A,B,C,D,...
print(resultat_bfs)  # ['A', 'B', 'C', 'D', 'E', 'F']
