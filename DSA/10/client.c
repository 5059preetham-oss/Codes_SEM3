#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

void run_test(const char* title, int n_vertices, int n_edges, int edges[][2]) {
    /* graph_t is opaque, so it cannot be allocated as a local value here. */
    graph_t *g = malloc(4096);
    if (g == NULL) {
        fprintf(stderr, "Failed to allocate graph\n");
        return;
    }

    init_graph(g, n_vertices, n_edges);
    for(int i = 0; i < n_edges; ++i) {
        add_edge(g, edges[i][0], edges[i][1]);
    }
    
    printf("==== %s ====\n", title);
    disp(g);
    
    int eul = check_eulerian(g);
    printf("Eulerian check   : ");
    if(eul == 2) printf("Euler circuit exists\n");
    else if(eul == 1) printf("Euler path only\n");
    else printf("Not Eulerian\n");
    
    int star_hub = check_star(g);
    printf("Star check       : ");
    if(star_hub != -1) printf("Star, hub = %c\n", star_hub + 'A');
    else printf("Not a star\n");
    
    printf("Network topology : %s\n\n", topology_name(identify_topology(g)));
    
    deinit_graph(g);
    free(g);
}

int main() {
    int e1[][2] = {{0,1},{0,2},{1,2},{1,3},{2,4},{3,4},{3,5},{4,6},{5,6},{5,7},{6,7}};
    run_test("Handout graph (8 vertices, 11 edges)", 8, 11, e1);

    int e2[][2] = {{0,1},{1,2},{2,3},{3,4},{4,0}};
    run_test("Cycle of 5 vertices", 5, 5, e2);

    int e3[][2] = {{0,1},{1,2},{2,3}};
    run_test("Path of 4 vertices", 4, 3, e3);

    int e4[][2] = {{0,1},{0,2},{0,3},{0,4},{0,5}};
    run_test("Star with 1 hub and 5 leaves", 6, 5, e4);

    int e5[][2] = {{0,1},{0,2},{0,3},{0,4},{1,2},{1,3},{1,4},{2,3},{2,4},{3,4}};
    run_test("Complete graph K5", 5, 10, e5);

    int e6[][2] = {{0,1},{0,2},{1,3},{1,4},{2,5},{2,6}};
    run_test("Binary tree, 7 vertices", 7, 6, e6);

    int e7[][2] = {{0,1},{1,2},{2,0},{2,3},{3,4},{4,2}};
    run_test("Bow-tie (two triangles sharing a vertex)", 5, 6, e7);

    int e8[][2] = {{0,1},{2,3}};
    run_test("Disconnected graph", 4, 2, e8);

    return 0;
}