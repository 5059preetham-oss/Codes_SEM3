#ifndef GRAPH_H
#define GRAPH_H

typedef struct node {
    int vertex;
    struct node* next;
} node_t;

typedef struct {
    int n_vertices_;
    int n_edges_;
    node_t** adj_list_;
} graph_t;

void init_graph(graph_t* g, int v, int e);
void add_edge(graph_t* g, int u, int v);
void disp(graph_t* g);
void deinit_graph(graph_t* g);

#endif