#include <bits/stdc++.h>

typedef struct Node {
    int vertex;
    struct Node *next;
} Node;

typedef struct Graph {
    int numVertices;
    Node **adjLists;
} Graph;

void deleteEdge(Graph *graph, int src, int dest) {
    Node *temp = graph->adjLists[src];
    Node *prev = NULL;

    while (temp != NULL && temp->vertex != dest) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Edge not found!\n");
        return;
    }

    if (prev == NULL) {
        graph->adjLists[src] = temp->next;
    } else {
        prev->next = temp->next;
    }

    free(temp);
}
void DFS(int **adjMatrix, int numVertices, int vertex, int *visited) {
    printf("%d ", vertex);
    visited[vertex] = 1;

    for (int i = 0; i < numVertices; i++) {
        if (adjMatrix[vertex][i] == 1 && !visited[i]) {
            DFS(adjMatrix, numVertices, i, visited);
        }
    }
}

typedef struct Queue {
    int *items;
    int front;
    int rear;
    int maxSize;
} Queue;

Queue *createQueue(int maxSize) {
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->items = (int *)malloc(maxSize * sizeof(int));
    queue->front = 0;
    queue->rear = -1;
    queue->maxSize = maxSize;
    return queue;
}

void enqueue(Queue *queue, int value) {
    if (queue->rear == queue->maxSize - 1) {
        printf("Queue is full\n");
        return;
    }
    queue->items[++(queue->rear)] = value;
}

int dequeue(Queue *queue) {
    if (queue->front > queue->rear) {
        printf("Queue is empty\n");
        return -1;
    }
    return queue->items[(queue->front)++];
}

void BFS(int **adjMatrix, int numVertices, int startVertex) {
    int *visited = (int *)malloc(numVertices * sizeof(int));
    for (int i = 0; i < numVertices; i++) {
        visited[i] = 0;
    }

    Queue *queue = createQueue(numVertices);
    visited[startVertex] = 1;
    enqueue(queue, startVertex);

    while (queue->front <= queue->rear) {
        int currentVertex = dequeue(queue);
        printf("%d ", currentVertex);

        for (int i = 0; i < numVertices; i++) {
            if (adjMatrix[currentVertex][i] == 1 && !visited[i]) {
                visited[i] = 1;
                enqueue(queue, i);
            }
        }
    }

    free(visited);
    free(queue->items);
    free(queue);
}
void DFS_AdjList(Graph *graph, int vertex, int *visited) {
    printf("%d ", vertex);
    visited[vertex] = 1;

    Node *adjList = graph->adjLists[vertex];
    while (adjList != NULL) {
        if (!visited[adjList->vertex]) {
            DFS_AdjList(graph, adjList->vertex, visited);
        }
        adjList = adjList->next;
    }
}
void BFS_AdjList(Graph *graph, int startVertex) {
    int *visited = (int *)malloc(graph->numVertices * sizeof(int));
    for (int i = 0; i < graph->numVertices; i++) {
        visited[i] = 0;
    }

    Queue *queue = createQueue(graph->numVertices);
    visited[startVertex] = 1;
    enqueue(queue, startVertex);

    while (queue->front <= queue->rear) {
        int currentVertex = dequeue(queue);
        printf("%d ", currentVertex);

        Node *adjList = graph->adjLists[currentVertex];
        while (adjList != NULL) {
            if (!visited[adjList->vertex]) {
                visited[adjList->vertex] = 1;
                enqueue(queue, adjList->vertex);
            }
            adjList = adjList->next;
        }
    }

    free(visited);
    free(queue->items);
    free(queue);
}

typedef struct Stack {
    int *items;
    int top;
    int maxSize;
} Stack;

Stack *createStack(int maxSize) {
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->items = (int *)malloc(maxSize * sizeof(int));
    stack->top = -1;
    stack->maxSize = maxSize;
    return stack;
}

void push(Stack *stack, int value) {
    if (stack->top == stack->maxSize - 1) {
        printf("Stack is full\n");
        return;
    }
    stack->items[++(stack->top)] = value;
}

int pop(Stack *stack) {
    if (stack->top == -1) {
        printf("Stack is empty\n");
        return -1;
    }
    return stack->items[(stack->top)--];
}

void DFS_NonRecursive(Graph *graph, int startVertex) {
    int *visited = (int *)malloc(graph->numVertices * sizeof(int));
    for (int i = 0; i < graph->numVertices; i++) {
        visited[i] = 0;
    }

    Stack *stack = createStack(graph->numVertices);
    push(stack, startVertex);

    while (stack->top != -1) {
        int vertex = pop(stack);

        if (!visited[vertex]) {
            printf("%d ", vertex);
            visited[vertex] = 1;
        }

        Node *adjList = graph->adjLists[vertex];
        while (adjList != NULL) {
            if (!visited[adjList->vertex]) {
                push(stack, adjList->vertex);
            }
            adjList = adjList->next;
        }
    }

    free(visited);
    free(stack->items);
    free(stack);
}

void computeInOutDegreesMatrix(int **adjMatrix, int numVertices) {
    int *inDegrees = (int *)malloc(numVertices * sizeof(int));
    int *outDegrees = (int *)malloc(numVertices * sizeof(int));

    for (int i = 0; i < numVertices; i++) {
        inDegrees[i] = 0;
        outDegrees[i] = 0;
    }

    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            if (adjMatrix[i][j] == 1) {
                outDegrees[i]++;
                inDegrees[j]++;
            }
        }
    }

    for (int i = 0; i < numVertices; i++) {
        printf("Vertex %d: In-Degree = %d, Out-Degree = %d\n", i, inDegrees[i],
               outDegrees[i]);
    }

    free(inDegrees);
    free(outDegrees);
}
void computeInOutDegreesAdjList(Graph *graph) {
    int *inDegrees = (int *)malloc(graph->numVertices * sizeof(int));
    int *outDegrees = (int *)malloc(graph->numVertices * sizeof(int));

    for (int i = 0; i < graph->numVertices; i++) {
        inDegrees[i] = 0;
        outDegrees[i] = 0;
    }

    for (int i = 0; i < graph->numVertices; i++) {
        Node *adjList = graph->adjLists[i];
        while (adjList != NULL) {
            outDegrees[i]++;
            inDegrees[adjList->vertex]++;
            adjList = adjList->next;
        }
    }

    for (int i = 0; i < graph->numVertices; i++) {
        printf("Vertex %d: In-Degree = %d, Out-Degree = %d\n", i, inDegrees[i],
               outDegrees[i]);
    }

    free(inDegrees);
    free(outDegrees);
}

void topologicalSortMatrix(int **adjMatrix, int numVertices) {
    int *inDegrees = (int *)malloc(numVertices * sizeof(int));
    int *queue = (int *)malloc(numVertices * sizeof(int));
    int front = 0, rear = 0;

    for (int i = 0; i < numVertices; i++) {
        inDegrees[i] = 0;
    }
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            if (adjMatrix[i][j] == 1) {
                inDegrees[j]++;
            }
        }
    }

    for (int i = 0; i < numVertices; i++) {
        if (inDegrees[i] == 0) {
            queue[rear++] = i;
        }
    }

    while (front < rear) {
        int vertex = queue[front++];
        printf("%d ", vertex);

        for (int i = 0; i < numVertices; i++) {
            if (adjMatrix[vertex][i] == 1) {
                inDegrees[i]--;
                if (inDegrees[i] == 0) {
                    queue[rear++] = i;
                }
            }
        }
    }

    free(inDegrees);
    free(queue);
}
void topologicalSortAdjList(Graph *graph) {
    int *inDegrees = (int *)malloc(graph->numVertices * sizeof(int));
    int *queue = (int *)malloc(graph->numVertices * sizeof(int));
    int front = 0, rear = 0;

    for (int i = 0; i < graph->numVertices; i++) {
        inDegrees[i] = 0;
    }

    for (int i = 0; i < graph->numVertices; i++) {
        Node *adjList = graph->adjLists[i];
        while (adjList != NULL) {
            inDegrees[adjList->vertex]++;
            adjList = adjList->next;
        }
    }

    for (int i = 0; i < graph->numVertices; i++) {
        if (inDegrees[i] == 0) {
            queue[rear++] = i;
        }
    }

    while (front < rear) {
        int vertex = queue[front++];
        printf("%d ", vertex);

        Node *adjList = graph->adjLists[vertex];
        while (adjList != NULL) {
            inDegrees[adjList->vertex]--;
            if (inDegrees[adjList->vertex] == 0) {
                queue[rear++] = adjList->vertex;
            }
            adjList = adjList->next;
        }
    }

    free(inDegrees);
    free(queue);
}

typedef struct Node {
    int vertex;
    struct Node *next;
} Node;

typedef struct Graph {
    int numVertices;
    Node **adjLists;
} Graph;

Graph *createGraph(int vertices) {
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->numVertices = vertices;
    graph->adjLists = (Node **)malloc(vertices * sizeof(Node *));

    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
    }

    return graph;
}

void addEdge(Graph *graph, int src, int dest) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->vertex = dest;
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;
    newNode = (Node *)malloc(sizeof(Node));
    newNode->vertex = src;
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}
void createAdjMatrix(Graph *graph, int edges[][2], int numEdges) {
    int **adjMatrix = (int **)malloc(graph->numVertices * sizeof(int *));
    for (int i = 0; i < graph->numVertices; i++) {
        adjMatrix[i] = (int *)malloc(graph->numVertices * sizeof(int));
        for (int j = 0; j < graph->numVertices; j++) {
            adjMatrix[i][j] = 0;
        }
    }

    for (int i = 0; i < numEdges; i++) {
        int src = edges[i][0];
        int dest = edges[i][1];
        adjMatrix[src][dest] = 1;
        adjMatrix[dest][src] = 1;
    }

    for (int i = 0; i < graph->numVertices; i++) {
        for (int j = 0; j < graph->numVertices; j++) {
            printf("%d ", adjMatrix[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < graph->numVertices; i++) {
        free(adjMatrix[i]);
    }
    free(adjMatrix);
}
void adjMatrixToAdjList(int **adjMatrix, int numVertices, Graph *graph) {
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            if (adjMatrix[i][j] == 1) {
                addEdge(graph, i, j);
            }
        }
    }
}
int **adjListToAdjMatrix(Graph *graph) {
    int **adjMatrix = (int **)malloc(graph->numVertices * sizeof(int *));
    for (int i = 0; i < graph->numVertices; i++) {
        adjMatrix[i] = (int *)malloc(graph->numVertices * sizeof(int));
        for (int j = 0; j < graph->numVertices; j++) {
            adjMatrix[i][j] = 0;
        }
    }

    for (int i = 0; i < graph->numVertices; i++) {
        Node *temp = graph->adjLists[i];
        while (temp) {
            adjMatrix[i][temp->vertex] = 1;
            temp = temp->next;
        }
    }

    return adjMatrix;
}
Graph *reverseAdjList(Graph *graph) {
    Graph *reverseGraph = createGraph(graph->numVertices);

    for (int i = 0; i < graph->numVertices; i++) {
        Node *temp = graph->adjLists[i];
        while (temp) {
            addEdge(reverseGraph, temp->vertex, i);
            temp = temp->next;
        }
    }

    return reverseGraph;
}
/*
总时间复杂度计算：
创建逆图： O(n)
遍历顶点： O(n)
遍历所有边并添加反向边： O(e)
因此，整体时间复杂度为：
O(n) + O(n) + O(e) = O(n + e)
*/