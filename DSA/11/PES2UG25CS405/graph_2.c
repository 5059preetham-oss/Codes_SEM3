#include "graph_2.h"
#include <stdio.h>

void init_graph(graph_t* g, int v, int e) {
    g->n_vertices_ = v;
    g->n_edges_ = 0; 
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            g->adj_mat_[i][j] = 0;
        }
    }
}

void add_edge(graph_t* g, int u, int v) {
    g->adj_mat_[u][v] = 1;
    g->adj_mat_[v][u] = 1;
}

void disp(graph_t* g) {
    printf("  ");
    for (int i = 0; i < g->n_vertices_; i++) {
        printf("%c ", i + 'A');
    }
    printf("\n");
    for (int i = 0; i < g->n_vertices_; i++) {
        printf("%c ", i + 'A');
        for (int j = 0; j < g->n_vertices_; j++) {
            printf("%d ", g->adj_mat_[i][j]);
        }
        printf("\n");
    }
}

void deinit_graph(graph_t* g) {
    /* No dynamic allocations to free */
}

int to_visit(int* visited, int n) {
    for (int i = 0; i < n; i++) {
        if (!visited[i]) return i;
    }
    return -1;
}

void dfs_recursive(int n, int mat[MAXSIZE][MAXSIZE], int* visited, int u) {
    visited[u] = 1;
    for (int v = 0; v < n; v++) {
        if (mat[u][v] && !visited[v]) {
            dfs_recursive(n, mat, visited, v);
        }
    }
}

int connected_components(graph_t* g) {
    int visited[MAXSIZE] = {0};
    int count = 0;
    int u = to_visit(visited, g->n_vertices_);
    while (u != -1) {
        count++;
        dfs_recursive(g->n_vertices_, g->adj_mat_, visited, u);
        u = to_visit(visited, g->n_vertices_);
    }
    return count;
}

/* Finds components, stores one representative per component in reps[],
   adds the minimum connecting edges, and returns how many were added. */
int connect_components(graph_t *ptr_graph)
{
    int visited[MAXSIZE];
    int reps[MAXSIZE];
    int k = 0;
 
    for (int i = 0; i < ptr_graph->n_vertices_; ++i)
        visited[i] = 0;
 
    int u = to_visit(visited, ptr_graph->n_vertices_);
    while (u != -1)
    {
        reps[k++] = u;                       /* representative city */
        dfs_recursive(ptr_graph->n_vertices_, ptr_graph->adj_mat_, visited, u);
        u = to_visit(visited, ptr_graph->n_vertices_);
    }
 
    printf("Components = %d, connections needed = %d\n", k, k > 0 ? k - 1 : 0);
    for (int i = 0; i + 1 < k; ++i)
    {
        printf("Connect %c - %c\n", reps[i] + 'A', reps[i + 1] + 'A');
        add_edge(ptr_graph, reps[i], reps[i + 1]);
        ptr_graph->n_edges_++;
    }
    return k > 0 ? k - 1 : 0;
}