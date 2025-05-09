int** matrixToNodes(int** matrix);
float heuristicEuclidian(int node[]);
int** aStar(int** matrix, int start[], int goal[]);
int** processMatrix(int* matriceNonDecode);
int* reconstructPath(int** closedList, int start, int goal);
int* aStar2(int** matrix, int start[], int goal[]);
int heuristicManhattan(int node[]);
int* dijkstra(int** nodes, int start[]);
int isAccessible(int value);
int* path (int* prev,int goal[], int start[]);