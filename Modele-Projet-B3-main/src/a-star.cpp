#include <config.h>

float heuristicEuclidian(int node[]) {
    return sqrt(pow(node[0], 2) + pow(node[1], 2));
}
int** matrixToNodes(int** matrix){
    int** nodes = (int**)malloc(36*sizeof(int*));
    for (int i = 0; i < 36; i++){
        nodes[i] = (int*)malloc(7*sizeof(int));
        nodes[i][0] = i%6; // x coordinate
        nodes[i][1] = i/6; // y coordinate
        nodes[i][2] = matrix[1+2*(i/6)][1+2*(i%6)]; //type
        nodes[i][3] = matrix[1+2*(i/6)][1+2*(i%6)-1]; //left
        nodes[i][4] = matrix[1+2*(i/6)][1+2*(i%6)+1]; //right
        nodes[i][5] = matrix[1+2*(i/6)-1][1+2*(i%6)]; //up
        nodes[i][6] = matrix[1+2*(i/6)+1][1+2*(i%6)]; //down
    }
    return nodes;
}