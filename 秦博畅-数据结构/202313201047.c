#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int v;
    struct Node *next;
} Node;

typedef struct Graph {
    int n_vtx;
    Node **adj;
} Graph;

void del_edge(Graph *g, int s, int d) {
    Node *tmp = g->adj[s];
    Node *pre = NULL;

    while (tmp != NULL && tmp->v != d) {
        pre = tmp;
        tmp = tmp->next;
    }

    if (tmp == NULL) {
        printf("Edge not found!\n");
        return;
    }

    if (pre == NULL) {
        g->adj[s] = tmp->next;
    } else {
        pre->next = tmp->next;
    }

    free(tmp);
}

void dfs_matrix(int **adj_mat, int n_vtx, int vtx, int *vis) {
    printf("%d ", vtx);
    vis[vtx] = 1;

    for (int i = 0; i < n_vtx; i++) {
        if (adj_mat[vtx][i] == 1 && !vis[i]) {
            dfs_matrix(adj_mat, n_vtx, i, vis);
        }
    }
}

typedef struct Queue {
    int *items;
    int front;
    int rear;
    int size;
} Queue;

Queue *create_queue(int size) {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->items = (int *)malloc(size * sizeof(int));
    q->front = 0;
    q->rear = -1;
    q->size = size;
    return q;
}

void enqueue(Queue *q, int val) {
    if (q->rear == q->size - 1) {
        printf("Queue is full\n");
        return;
    }
    q->items[++(q->rear)] = val;
}

int dequeue(Queue *q) {
    if (q->front > q->rear) {
        printf("Queue is empty\n");
        return -1;
    }
    return q->items[(q->front)++];
}

void bfs_matrix(int **adj_mat, int n_vtx, int start) {
    int *vis = (int *)malloc(n_vtx * sizeof(int));
    for (int i = 0; i < n_vtx; i++) {
        vis[i] = 0;
    }

    Queue *q = create_queue(n_vtx);
    vis[start] = 1;
    enqueue(q, start);

    while (q->front <= q->rear) {
        int curr = dequeue(q);
        printf("%d ", curr);

        for (int i = 0; i < n_vtx; i++) {
            if (adj_mat[curr][i] == 1 && !vis[i]) {
                vis[i] = 1;
                enqueue(q, i);
            }
        }
    }

    free(vis);
    free(q->items);
    free(q);
}

void dfs_adj_list(Graph *g, int vtx, int *vis) {
    printf("%d ", vtx);
    vis[vtx] = 1;

    Node *adj_node = g->adj[vtx];
    while (adj_node != NULL) {
        if (!vis[adj_node->v]) {
            dfs_adj_list(g, adj_node->v, vis);
        }
        adj_node = adj_node->next;
    }
}

void bfs_adj_list(Graph *g, int start) {
    int *vis = (int *)malloc(g->n_vtx * sizeof(int));
    for (int i = 0; i < g->n_vtx; i++) {
        vis[i] = 0;
    }

    Queue *q = create_queue(g->n_vtx);
    vis[start] = 1;
    enqueue(q, start);

    while (q->front <= q->rear) {
        int curr = dequeue(q);
        printf("%d ", curr);

        Node *adj_node = g->adj[curr];
        while (adj_node != NULL) {
            if (!vis[adj_node->v]) {
                vis[adj_node->v] = 1;
                enqueue(q, adj_node->v);
            }
            adj_node = adj_node->next;
        }
    }

    free(vis);
    free(q->items);
    free(q);
}

typedef struct Stack {
    int *items;
    int top;
    int size;
} Stack;

Stack *create_stack(int size) {
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->items = (int *)malloc(size * sizeof(int));
    s->top = -1;
    s->size = size;
    return s;
}

void push(Stack *s, int val) {
    if (s->top == s->size - 1) {
        printf("Stack is full\n");
        return;
    }
    s->items[++(s->top)] = val;
}

int pop(Stack *s) {
    if (s->top == -1) {
        printf("Stack is empty\n");
        return -1;
    }
    return s->items[(s->top)--];
}

void dfs_nonrec(Graph *g, int start) {
    int *vis = (int *)malloc(g->n_vtx * sizeof(int));
    for (int i = 0; i < g->n_vtx; i++) {
        vis[i] = 0;
    }

    Stack *s = create_stack(g->n_vtx);
    push(s, start);

    while (s->top != -1) {
        int vtx = pop(s);

        if (!vis[vtx]) {
            printf("%d ", vtx);
            vis[vtx] = 1;
        }

        Node *adj_node = g->adj[vtx];
        while (adj_node != NULL) {
            if (!vis[adj_node->v]) {
                push(s, adj_node->v);
            }
            adj_node = adj_node->next;
        }
    }

    free(vis);
    free(s->items);
    free(s);
}

void compute_degrees_matrix(int **adj_mat, int n_vtx) {
    int *in_deg = (int *)malloc(n_vtx * sizeof(int));
    int *out_deg = (int *)malloc(n_vtx * sizeof(int));

    for (int i = 0; i < n_vtx; i++) {
        in_deg[i] = 0;
        out_deg[i] = 0;
    }

    for (int i = 0; i < n_vtx; i++) {
        for (int j = 0; j < n_vtx; j++) {
            if (adj_mat[i][j] == 1) {
                out_deg[i]++;
                in_deg[j]++;
            }
        }
    }

    for (int i = 0; i < n_vtx; i++) {
        printf("Vertex %d: In-Degree = %d, Out-Degree = %d\n", i, in_deg[i],
               out_deg[i]);
    }

    free(in_deg);
    free(out_deg);
}

void compute_degrees_adj_list(Graph *g) {
    int *in_deg = (int *)malloc(g->n_vtx * sizeof(int));
    int *out_deg = (int *)malloc(g->n_vtx * sizeof(int));

    for (int i = 0; i < g->n_vtx; i++) {
        in_deg[i] = 0;
        out_deg[i] = 0;
    }

    for (int i = 0; i < g->n_vtx; i++) {
        Node *adj_node = g->adj[i];
        while (adj_node != NULL) {
            out_deg[i]++;
            in_deg[adj_node->v]++;
            adj_node = adj_node->next;
        }
    }

    for (int i = 0; i < g->n_vtx; i++) {
        printf("Vertex %d: In-Degree = %d, Out-Degree = %d\n", i, in_deg[i],
               out_deg[i]);
    }

    free(in_deg);
    free(out_deg);
}

void topo_sort_matrix(int **adj_mat, int n_vtx) {
    int *in_deg = (int *)malloc(n_vtx * sizeof(int));
    int *queue = (int *)malloc(n_vtx * sizeof(int));
    int front = 0, rear = 0;

    for (int i = 0; i < n_vtx; i++) {
        in_deg[i] = 0;
    }
    for (int i = 0; i < n_vtx; i++) {
        for (int j = 0; j < n_vtx; j++) {
            if (adj_mat[i][j] == 1) {
                in_deg[j]++;
            }
        }
    }

    for (int i = 0; i < n_vtx; i++) {
        if (in_deg[i] == 0) {
            queue[rear++] = i;
        }
    }

    while (front < rear) {
        int vtx = queue[front++];
        printf("%d ", vtx);

        for (int i = 0; i < n_vtx; i++) {
            if (adj_mat[vtx][i] == 1) {
                in_deg[i]--;
                if (in_deg[i] == 0) {
                    queue[rear++] = i;
                }
            }
        }
    }

    free(in_deg);
    free(queue);
}

void topo_sort_adj_list(Graph *g) {
    int *in_deg = (int *)malloc(g->n_vtx * sizeof(int));
    int *queue = (int *)malloc(g->n_vtx * sizeof(int));
    int front = 0, rear = 0;

    for (int i = 0; i < g->n_vtx; i++) {
        in_deg[i] = 0;
    }

    for (int i = 0; i < g->n_vtx; i++) {
        Node *adj_node = g->adj[i];
        while (adj_node != NULL) {
            in_deg[adj_node->v]++;
            adj_node = adj_node->next;
        }
    }

    for (int i = 0; i < g->n_vtx; i++) {
        if (in_deg[i] == 0) {
            queue[rear++] = i;
        }
    }

    while (front < rear) {
        int vtx = queue[front++];
        printf("%d ", vtx);

        Node *adj_node = g->adj[vtx];
        while (adj_node != NULL) {
            in_deg[adj_node->v]--;
            if (in_deg[adj_node->v] == 0) {
                queue[rear++] = adj_node->v;
            }
            adj_node = adj_node->next;
        }
    }

    free(in_deg);
    free(queue);
}

Graph *create_graph(int n) {
    Graph *g = (Graph *)malloc(sizeof(Graph));
    g->n_vtx = n;
    g->adj = (Node **)malloc(n * sizeof(Node *));

    for (int i = 0; i < n; i++) {
        g->adj[i] = NULL;
    }

    return g;
}

void add_edge(Graph *g, int s, int d) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->v = d;
    new_node->next = g->adj[s];
    g->adj[s] = new_node;

    new_node = (Node *)malloc(sizeof(Node));
    new_node->v = s;
    new_node->next = g->adj[d];
    g->adj[d] = new_node;
}

void create_adj_matrix(Graph *g, int edges[][2], int n_edges) {
    int **adj_mat = (int **)malloc(g->n_vtx * sizeof(int *));
    for (int i = 0; i < g->n_vtx; i++) {
        adj_mat[i] = (int *)malloc(g->n_vtx * sizeof(int));
        for (int j = 0; j < g->n_vtx; j++) {
            adj_mat[i][j] = 0;
        }
    }

    for (int i = 0; i < n_edges; i++) {
        int s = edges[i][0];
        int d = edges[i][1];
        adj_mat[s][d] = 1;
        adj_mat[d][s] = 1;
    }

    for (int i = 0; i < g->n_vtx; i++) {
        for (int j = 0; j < g->n_vtx; j++) {
            printf("%d ", adj_mat[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < g->n_vtx; i++) {
        free(adj_mat[i]);
    }
    free(adj_mat);
}

void adj_matrix_to_adj_list(int **adj_mat, int n_vtx, Graph *g) {
    for (int i = 0; i < n_vtx; i++) {
        for (int j = 0; j < n_vtx; j++) {
            if (adj_mat[i][j] == 1) {
                add_edge(g, i, j);
            }
        }
    }
}

int **adj_list_to_adj_matrix(Graph *g) {
    int **adj_mat = (int **)malloc(g->n_vtx * sizeof(int *));
    for (int i = 0; i < g->n_vtx; i++) {
        adj_mat[i] = (int *)malloc(g->n_vtx * sizeof(int));
        for (int j = 0; j < g->n_vtx; j++) {
            adj_mat[i][j] = 0;
        }
    }

    for (int i = 0; i < g->n_vtx; i++) {
        Node *tmp = g->adj[i];
        while (tmp) {
            adj_mat[i][tmp->v] = 1;
            tmp = tmp->next;
        }
    }

    return adj_mat;
}

Graph *reverse_adj_list(Graph *g) {
    Graph *rev_g = create_graph(g->n_vtx);

    for (int i = 0; i < g->n_vtx; i++) {
        Node *tmp = g->adj[i];
        while (tmp) {
            add_edge(rev_g, tmp->v, i);
            tmp = tmp->next;
        }
    }

    return rev_g;
}

/*
总时间复杂度计算：
创建逆图： O(n)
遍历顶点： O(n)
遍历所有边并添加反向边： O(e)
因此，整体时间复杂度为：
O(n) + O(n) + O(e) = O(n + e)
*/