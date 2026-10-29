#include "graph.h"
#include <stdio.h>
#include <stdlib.h>

void init_graph(graph_t* g, int v, int e) {
    g->n_vertices_ = v;
    g->n_edges_ = e;
    g->adj_list_ = (node_t**)malloc(v * sizeof(node_t*));
    for (int i = 0; i < v; i++) {
        g->adj_list_[i] = NULL;
    }
}

void add_edge(graph_t* g, int u, int v) {
    node_t* n1 = (node_t*)malloc(sizeof(node_t));
    n1->vertex = v;
    n1->next = g->adj_list_[u];
    g->adj_list_[u] = n1;

    node_t* n2 = (node_t*)malloc(sizeof(node_t));
    n2->vertex = u;
    n2->next = g->adj_list_[v];
    g->adj_list_[v] = n2;
}

void disp(graph_t* g) {
    for (int i = 0; i < g->n_vertices_; i++) {
        printf("%c : ", i + 'A');
        node_t* temp = g->adj_list_[i];
        while (temp) {
            printf("%d ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

void deinit_graph(graph_t* g) {
    for (int i = 0; i < g->n_vertices_; i++) {
        node_t* temp = g->adj_list_[i];
        while (temp) {
            node_t* del = temp;
            temp = temp->next;
            free(del);
        }
    }
    free(g->adj_list_);
}