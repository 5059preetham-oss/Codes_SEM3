#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

void init_graph(graph_t *ptr_graph, int n_vertices, int n_edges) {
    ptr_graph->n_vertices_ = n_vertices;
    ptr_graph->n_edges_ = n_edges;
    for(int i = 0; i < ptr_graph->n_vertices_; ++i) {
        for(int j = 0; j < ptr_graph->n_vertices_; ++j) {
            ptr_graph->adj_mat_[i][j] = 0;
        }
    }
}

void add_edge(graph_t *ptr_graph, int from, int to) {
    ptr_graph->adj_mat_[from][to] = 1;
    ptr_graph->adj_mat_[to][from] = 1;
}

static void dfs_recursive(graph_t *g, int visited[], int u) {
    visited[u] = 1;
    printf("visited %c \n", u + 'A');
    for(int i = 0; i < g->n_vertices_; ++i) {
        if(g->adj_mat_[u][i] && !visited[i]) {
            dfs_recursive(g, visited, i);
        }
    }
}

static void dfs_silent(graph_t *g, int visited[], int u) {
    visited[u] = 1;
    for(int i = 0; i < g->n_vertices_; ++i) {
        if(g->adj_mat_[u][i] && !visited[i]) {
            dfs_silent(g, visited, i);
        }
    }
}

void dfs(graph_t *ptr_graph, int u) {
    int visited[MAXSIZE];
    for(int i = 0; i < ptr_graph->n_vertices_; ++i) {
        visited[i] = 0;
    }
    dfs_recursive(ptr_graph, visited, u);
    printf("\n");
}

void disp(graph_t *ptr_graph) {
    for(int i = 0; i < ptr_graph->n_vertices_; ++i) {
        printf("%c  ", i + 'A');
        for(int j = 0; j < ptr_graph->n_vertices_; ++j) {
            printf("%2d ", ptr_graph->adj_mat_[i][j]);
        }
        printf("\n");
    }
}

void deinit_graph(graph_t *ptr_graph) {
    ptr_graph->n_vertices_ = 0;
    ptr_graph->n_edges_ = 0;
}

int degree(graph_t *g, int v) {
    int deg = 0;
    for(int i = 0; i < g->n_vertices_; ++i) {
        if(g->adj_mat_[v][i]) {
            deg++;
        }
    }
    return deg;
}

int count_edges(graph_t *g) {
    int edges = 0;
    for(int i = 0; i < g->n_vertices_; ++i) {
        for(int j = i + 1; j < g->n_vertices_; ++j) {
            if(g->adj_mat_[i][j]) {
                edges++;
            }
        }
    }
    return edges;
}

int is_connected(graph_t *g) {
    if(g->n_vertices_ == 0) return 0;
    int visited[MAXSIZE] = {0};
    dfs_silent(g, visited, 0);
    for(int i = 0; i < g->n_vertices_; ++i) {
        if(!visited[i]) return 0;
    }
    return 1;
}

int check_eulerian(graph_t *g) {
    if (g->n_vertices_ == 0 || count_edges(g) == 0) return 0;

    int visited[MAXSIZE] = {0};
    int start_node = -1;
    
    for (int i = 0; i < g->n_vertices_; ++i) {
        if (degree(g, i) > 0) {
            start_node = i;
            break;
        }
    }
    
    if (start_node != -1) {
        dfs_silent(g, visited, start_node);
    }
    
    for (int i = 0; i < g->n_vertices_; ++i) {
        if (degree(g, i) > 0 && !visited[i]) {
            return 0;
        }
    }

    int odd_count = 0;
    for (int i = 0; i < g->n_vertices_; ++i) {
        if (degree(g, i) % 2 != 0) {
            odd_count++;
        }
    }

    if (odd_count == 0) return 2;
    if (odd_count == 2) return 1;
    return 0;
}

int check_star(graph_t *g) {
    if(g->n_vertices_ < 3) return -1;
    int hub = -1;
    for(int i = 0; i < g->n_vertices_; ++i) {
        if(degree(g, i) == g->n_vertices_ - 1) {
            hub = i;
            break;
        }
    }
    if(hub == -1) return -1;
    
    for(int i = 0; i < g->n_vertices_; ++i) {
        if(i != hub && degree(g, i) != 1) {
            return -1;
        }
    }
    return hub;
}

topology_t identify_topology(graph_t *g) {
    if(!is_connected(g) || g->n_vertices_ < 2) {
        return NOT_NETWORK;
    }

    int all_two = 1;
    for(int i = 0; i < g->n_vertices_; ++i) {
        if(degree(g, i) != 2) {
            all_two = 0;
            break;
        }
    }
    if(all_two && g->n_vertices_ >= 3) {
        return RING;
    }

    int e = count_edges(g);
    int ones = 0, twos = 0;
    for(int i = 0; i < g->n_vertices_; ++i) {
        if(degree(g, i) == 1) ones++;
        else if(degree(g, i) == 2) twos++;
    }
    if(e == g->n_vertices_ - 1 && ones == 2 && twos == g->n_vertices_ - 2) {
        return BUS;
    }

    if(check_star(g) != -1) {
        return STAR;
    }

    int all_n_minus_one = 1;
    for(int i = 0; i < g->n_vertices_; ++i) {
        if(degree(g, i) != g->n_vertices_ - 1) {
            all_n_minus_one = 0;
            break;
        }
    }
    if(all_n_minus_one) {
        return FULL_MESH;
    }

    if(e == g->n_vertices_ - 1) {
        return TREE;
    }

    return HYBRID;
}

const char *topology_name(topology_t t) {
    switch(t) {
        case RING: return "Ring";
        case BUS: return "Bus";
        case STAR: return "Star";
        case FULL_MESH: return "Full Mesh";
        case TREE: return "Tree";
        case HYBRID: return "Hybrid";
        case NOT_NETWORK: return "Not a network";
        default: return "Unknown";
    }
}