#ifndef GRAPH2_H
#define GRAPH2_H

#define MAXSIZE 100

typedef struct {
    int n_vertices_;
    int n_edges_;
    int adj_mat_[MAXSIZE][MAXSIZE];
} graph_t;

void init_graph(graph_t* g, int v, int e);
void add_edge(graph_t* g, int u, int v);
void disp(graph_t* g);
void deinit_graph(graph_t* g);
int connected_components(graph_t* g);
int connect_components(graph_t* g);

#endif