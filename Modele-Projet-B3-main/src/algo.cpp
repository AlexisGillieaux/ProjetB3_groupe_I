#include <config.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>




int** processMatrix(int* matriceNonDecode)
{
    int** matriceDecode = (int**)malloc(13 * sizeof(int*));
    if (matriceNonDecode == NULL) {
        return NULL;
    }

    for (int i = 0; i < 13; i++)
    {
        matriceDecode[i] = (int*)malloc(13 * sizeof(int));
        for (int j = 0; j < 13; j++)
        {
            matriceDecode[i][j] = matriceNonDecode[i * 13 + j];
        }
    }
    free(matriceNonDecode); 
    return matriceDecode;
}

float heuristicEuclidian(int node[]) {
    return sqrt(pow(node[1], 2) + pow(node[2], 2));
}
float heuristicManhattan(int node[]) {
    return abs(node[1]) + abs(node[2]);
}
int** matrixToNodes(int** matrix){
    int** nodes = (int**)malloc(36*sizeof(int*));
    for (int i = 0; i < 36; i++){
        nodes[i] = (int*)malloc(8*sizeof(int));
        nodes[i][0] = i; // nom du noeud
        nodes[i][1] = i%6; // x coordinate
        nodes[i][2] = i/6; // y coordinate
        nodes[i][3] = matrix[1+2*(i/6)][1+2*(i%6)]; //type
        nodes[i][4] = matrix[1+2*(i/6)][1+2*(i%6)-1]; //left
        nodes[i][5] = matrix[1+2*(i/6)][1+2*(i%6)+1]; //right
        nodes[i][6] = matrix[1+2*(i/6)-1][1+2*(i%6)]; //up
        nodes[i][7] = matrix[1+2*(i/6)+1][1+2*(i%6)]; //down
    }
    return nodes;
}

    
bool isAccessible(int value) {
    return value == 0 || value == 2 || value == 3;
}

int* dijkstra(int** nodes, int start[]) {
    int dist[36]; // Tableau pour stocker les distances
    int* prev = (int*)malloc(36 * sizeof(int)); // Tableau pour stocker les noeuds précédents
    int priorityQueue[36]; // File de priorité pour les noeuds à explorer
    dist[start[0]] = 0; // Distance du noeud de départ à lui-même
    priorityQueue[start[0]] = 0; // Ajouter le noeud de départ à la file de priorité
    for (int i = 0; i < 36; i++) {
        if (i != start[0]) {
            dist[i] = 256; // Initialiser les distances à l'infini
            prev[i] = -1; // Initialiser les noeuds précédents à -1
            priorityQueue[i] = 256; // Initialiser la file de priorité
        }

    }
    while (true){
        int isPriorityQueueEmpty = 1;
        for (int i = 0; i < 36; i++){
            if (priorityQueue[i] != 256){
                isPriorityQueueEmpty = 0;
                break;
            }
        }
        if (isPriorityQueueEmpty == 1){
            return prev; // Si la file de priorité est vide, sortir de la boucle
        }
        else{
            int currentNode = -1;
            int minDistance = 256;
            for (int i = 0; i < 36; i++)
            {
                if (priorityQueue[i] != 256 && dist[i] < minDistance) {
                    minDistance = dist[i];
                    currentNode = i;
                    priorityQueue[i] = 256; // Marquer le noeud comme visité
                }
            }
            int neighbor1 = currentNode - 1;
            int neighbor2 = currentNode + 1;
            int neighbor3 = currentNode - 6;
            int neighbor4 = currentNode + 6;
            if (neighbor1 < 0)
            {
            neighbor1 = -1;
            }
            if (neighbor2 > 35)
            {
                neighbor2 = -1;
            }
            if (neighbor3 < 0)
            {
                neighbor3 = -1;
            }
            if (neighbor4 > 35)
            {
                neighbor4 = -1;
            }
            if (nodes[neighbor1][4] == 1 && neighbor1 != -1) {
                neighbor1 = -1; // Noeud inaccessible
            }
            if (nodes[neighbor2][5] == 1 && neighbor2 != -1) {
                neighbor2 = -1; // Noeud inaccessible
            }
            if (nodes[neighbor3][6] == 1 && neighbor3 != -1) {
                neighbor3 = -1; // Noeud inaccessible
            }
            if (nodes[neighbor4][7] == 1 && neighbor4 != -1) {
                neighbor4 = -1; // Noeud inaccessible
            }
            int neighbors[4] = { neighbor1, neighbor2, neighbor3, neighbor4 };
            for (int i = 0; i < 4; i++) {
                if (neighbors[i] != -1 ) {
                    int neighborNode = neighbors[i];
                    int alt = dist[currentNode] + 1; // Coût entre les noeuds adjacents est 1
                    if (alt < dist[neighborNode]) {
                        dist[neighborNode] = alt;
                        prev[neighborNode] = currentNode; // Mettre à jour le noeud précédent
                        priorityQueue[neighborNode] = alt; // Ajouter le voisin à la file de priorité
                    }
                }
            }
        }
    }
}
int* path (int* prev,int goal[], int start[]){
    int reversedPath[36];
    int pathSize = 0;
    for (int i = 0; i < 36; i++)
    {
        reversedPath[i] = -1; // Initialiser le tableau de chemin inversé
    }
    reversedPath[0]= prev[goal[0]]; // Marquer le noeud de but comme visité
    for (int i = 1; i < 36; i++){
        if(reversedPath[i] == -1 || reversedPath[i] == start[0]){
            break;
        }
        reversedPath[i] = prev[reversedPath[i-1]]; // Marquer le noeud de but comme visité
        pathSize++;
    }
    int* path = (int*)malloc((pathSize + 1) * sizeof(int)); // Allouer de la mémoire pour le chemin
    for (int i = 0; i < pathSize; i++){
        path[i] = reversedPath[pathSize - i - 1]; // Inverser le chemin
    } 
    free(prev); // Libérer la mémoire allouée pour le tableau de noeuds précédents  
    return path; // Retourner le chemin
}

int* reconstructPath(int** closedList, int start, int goal) {
    int* path = (int*)malloc(36 * sizeof(int));
    int pathSize = 0;
    int currentNode = goal;

    while (currentNode != start) {
        path[pathSize++] = currentNode; // Add the node index to the path
        currentNode = closedList[currentNode][0]; // Parent node index
    }
    path[pathSize++] = start; // Add the start node index

    // Reverse the path to get it in the correct order
    int* finalPath = (int*)malloc(pathSize * sizeof(int));
    for (int i = 0; i < pathSize; i++) {
        finalPath[i] = path[pathSize - i - 1];
    }
    finalPath[pathSize] = -1; // Add a sentinel value to indicate the end of the path
    free(path);

    return finalPath;
}

int* aStar2(int** matrix, int start[], int goal[]) {
    int** nodes = matrixToNodes(matrix);
    int openList[36][7];
    int** closedList = (int**)malloc(36 * sizeof(int*));
    for (int i = 0; i < 36; i++) {
        closedList[i] = (int*)malloc(7 * sizeof(int));
        for (int j = 0; j < 7; j++) {
            closedList[i][j] = -1;
        }
    }
    int openListSize = 0;
    int closedListSize = 0;
    int currentNode[7];
    float gScore[36];
    float fScore[36];

    for (int i = 0; i < 36; i++) {
        gScore[i] = 256;
        fScore[i] = 256;
    }

    gScore[start[0]] = 0;
    fScore[start[0]] = heuristicManhattan(&nodes[start[0]][1]);

    for (int j = 0; j < 7; j++) {
        openList[openListSize][j] = nodes[start[0]][j];
    }
    openListSize++;

    while (openListSize > 0) {
        float minFScore = 256;
        int minIndex = -1;

        for (int i = 0; i < openListSize; i++) {
            if (fScore[openList[i][0]] < minFScore) {
                minFScore = fScore[openList[i][0]];
                minIndex = i;
            }
        }

        for (int j = 0; j < 7; j++) {
            currentNode[j] = openList[minIndex][j];
        }
        if (currentNode[0] == goal[0]) {
            int* path = reconstructPath(closedList, start[0], goal[0]);
            for (int i = 0; i < 36; i++) {
                free(closedList[i]);
                free(nodes[i]);
            }
            free(closedList);
            free(nodes);
            return path;
        }

        for (int i = minIndex; i < openListSize - 1; i++) {
            for (int j = 0; j < 7; j++) {
                openList[i][j] = openList[i + 1][j];
            }
        }
        openListSize--;

        for (int j = 0; j < 7; j++) {
            closedList[currentNode[0]][j] = currentNode[j];
        }
        closedListSize++;

        int neighbors[4] = {
            currentNode[4] ? currentNode[0] - 1 : -1,
            currentNode[5] ? currentNode[0] + 1 : -1,
            currentNode[6] ? currentNode[0] - 6 : -1,
            currentNode[7] ? currentNode[0] + 6 : -1
        };

        for (int i = 0; i < 4; i++) {
            if (neighbors[i] != -1 && isAccessible(nodes[neighbors[i]][3])) {
                int neighborNode[7];
                for (int j = 0; j < 7; j++) {
                    neighborNode[j] = nodes[neighbors[i]][j];
                }

                bool inClosedList = false;
                for (int j = 0; j < closedListSize; j++) {
                    if (closedList[j][0] == neighborNode[0]) {
                        inClosedList = true;
                        break;
                    }
                }
                if (inClosedList) {
                    continue;
                }

                float tentativeGScore = gScore[currentNode[0]] + 1;
                if (tentativeGScore < gScore[neighborNode[0]]) {
                    gScore[neighborNode[0]] = tentativeGScore;
                    fScore[neighborNode[0]] = gScore[neighborNode[0]] + heuristicManhattan(&nodes[neighborNode[0]][1]);

                    for (int j = 0; j < 7; j++) {
                        closedList[neighborNode[0]][j] = neighborNode[j];
                    }
                    closedList[neighborNode[0]][0] = currentNode[0];

                    bool inOpenList = false;
                    for (int j = 0; j < openListSize; j++) {
                        if (openList[j][0] == neighborNode[0]) {
                            inOpenList = true;
                            break;
                        }
                    }
                    if (!inOpenList) {
                        for (int j = 0; j < 7; j++) {
                            openList[openListSize][j] = neighborNode[j];
                        }
                        openListSize++;
                    }
                }
            }
        }
    }

    for (int i = 0; i < 36; i++) {
        free(closedList[i]);
        free(nodes[i]);
    }
    free(closedList);
    free(nodes);
    return NULL;
}
int** aStar(int** matrix, int start[], int goal[]) {
    // Initialisation des variables
    int** nodes = matrixToNodes(matrix);
    int openList[36][7]; // Liste ouverte
    int closedList[36][7]; // Liste fermée
    int openListSize = 0; // Taille de la liste ouverte
    int closedListSize = 0; // Taille de la liste fermée
    int currentNode[7]; // Noeud courant
    float gScore[36]; // Coût du chemin depuis le début jusqu'à ce noeud
    float fScore[36]; // Coût total estimé du début au but en passant par ce noeud
    for (int i = 0; i < 36; i++) {
        gScore[i] = 256; // Initialiser gScore à l'infini
        fScore[i] = 256; // Initialiser fScore à l'infini
        closedList[i][0] = -1; // Initialiser la liste fermée avec -1
        closedList[i][1] = -1;
        closedList[i][2] = -1;
        closedList[i][3] = -1;
        closedList[i][4] = -1;
        closedList[i][5] = -1;
        closedList[i][6] = -1;
    }
    gScore[start[0]] = 0; // Coût du chemin depuis le début jusqu'au noeud de départ
    fScore[start[0]] = heuristicManhattan(&nodes[start[0]][1]); // Utiliser l'heuristique de Manhattan

    openList[openListSize][0] = start[0]; // Ajouter le noeud de départ à la liste ouverte
    openListSize++;

    while (openListSize > 0) {
        // Trouver le noeud avec le coût total le plus bas dans la liste ouverte
        float minFScore = 256;
        for (int i = 0; i < openListSize; i++) {
            if (fScore[openList[i][0]] < minFScore) {
                minFScore = fScore[openList[i][0]];
                currentNode[0] = openList[i][0];
                currentNode[1] = openList[i][1];
                currentNode[2] = openList[i][2];
                currentNode[3] = openList[i][3];
                currentNode[4] = openList[i][4];
                currentNode[5] = openList[i][5];
                currentNode[6] = openList[i][6];
            }
        }

        // Vérifier si le noeud courant est le but
        if (currentNode[0] == goal[0]) {
            // Construire le chemin en remontant les parents
            int** path = (int**)malloc(36 * sizeof(int*));
            int pathSize = 0;
            int tempNode = currentNode[0];
            while (tempNode != start[0]) {
                path[pathSize] = (int*)malloc(7 * sizeof(int));
                for (int j = 0; j < 7; j++) {
                    path[pathSize][j] = closedList[tempNode][j]; // Use closedList to reconstruct the path
                }
                pathSize++;
                tempNode = closedList[tempNode][0]; // Parent node index
            }
            path[pathSize] = (int*)malloc(7 * sizeof(int));
            for (int j = 0; j < 7; j++) {
                path[pathSize][j] = nodes[start[0]][j];
            }
            pathSize++;

            // Libérer la mémoire des noeuds
            for (int i = 0; i < 36; i++) {
                free(nodes[i]);
            }
            free(nodes);

            return path; // Retourner le chemin
        }

        // Retirer le noeud courant de la liste ouverte
        int indexToRemove = -1;
        for (int i = 0; i < openListSize; i++) {
            if (openList[i][0] == currentNode[0]) {
                indexToRemove = i;
                break;
            }
        }
        if (indexToRemove != -1) {
            for (int i = indexToRemove; i < openListSize - 1; i++) {
                for (int j = 0; j < 7; j++) {
                    openList[i][j] = openList[i + 1][j];
                }
            }
            openListSize--;
        }

        // Ajouter le noeud courant à la liste fermée
        for (int j = 0; j < 7; j++) {
            closedList[currentNode[0]][j] = currentNode[j];
        }
        closedListSize++;

        // Explorer les voisins du noeud courant
        int neighbors[4] = {
            currentNode[4] ? currentNode[0] - 1 : -1, // left
            currentNode[5] ? currentNode[0] + 1 : -1, // right
            currentNode[6] ? currentNode[0] - 6 : -1, // up
            currentNode[7] ? currentNode[0] + 6 : -1  // down
        }; // Map accessibility to node indices
        for (int i = 0; i < 4; i++) {
            if (neighbors[i] != -1 && isAccessible(nodes[neighbors[i]][3])) { // Vérifier si le voisin est accessible
                int neighborNode[7];
                for (int j = 0; j < 7; j++) {
                    neighborNode[j] = nodes[neighbors[i]][j];
                }

                // Vérifier si le voisin est déjà dans la liste fermée
                bool inClosedList = false;
                for (int j = 0; j < closedListSize; j++) {
                    if (closedList[j][0] == neighborNode[0]) {
                        inClosedList = true;
                        break;
                    }
                }
                if (inClosedList) {
                    continue;
                }

                // Calculer le coût gScore pour ce voisin
                float tentativeGScore = gScore[currentNode[0]] + 1; // Distance entre les noeuds adjacents est 1
                if (tentativeGScore < gScore[neighborNode[0]]) {
                    // Mettre à jour les scores et ajouter à la liste ouverte
                    gScore[neighborNode[0]] = tentativeGScore;
                    fScore[neighborNode[0]] = gScore[neighborNode[0]] + heuristicManhattan(&nodes[neighborNode[0]][1]);
                    for (int j = 0; j < 7; j++) {
                        closedList[neighborNode[0]][j] = neighborNode[j]; // Copy neighbor details
                    }
                    closedList[neighborNode[0]][0] = currentNode[0]; // Set parent node index explicitly

                    // Ajouter le voisin à la liste ouverte s'il n'y est pas déjà
                    bool inOpenList = false;
                    for (int j = 0; j < openListSize; j++) {
                        if (openList[j][0] == neighborNode[0]) {
                            inOpenList = true;
                            break;
                        }
                    }
                    if (!inOpenList) {
                        for (int j = 0; j < 7; j++) {
                            openList[openListSize][j] = neighborNode[j];
                        }
                        openListSize++;
                    }
                }
            }
        }
    }

    // Si aucun chemin n'est trouvé, retourner NULL
    for (int i = 0; i < 36; i++) {
        free(nodes[i]);
    }
    free(nodes);
    return NULL;
}

