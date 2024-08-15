#include "graph.h"
#include <time.h>

int verify_edge(type_graph* graphx, int id1, int id2) {
    for (int i = 0; i < graphx->nodes[id1].edges_size; i++) {
        int target_node_id = graphx->nodes[id1].edges[i].target_node->id;
        if (target_node_id == id2) {
            return 0;
        }
    }
    return 1;
}

type_graph* generate_graph(int size) {
    type_graph* graphx = (type_graph*) malloc(sizeof(type_graph));
    graphx->size = size;
    graphx->nodes = (type_node*) malloc(size * sizeof(type_node));

    for (int i = 0; i < size; i++) {
        type_node aux_node;
        aux_node.id = i;
        aux_node.weight = 0;
        aux_node.edges_size = 0;
        aux_node.edges = NULL;
        graphx->nodes[i] = aux_node;
    }

    srand(time(NULL));

    for (int i = 0; i < size - 1; i++) {
        int target = i + 1;
        type_edge aux_edge;
        aux_edge.distance = 1 + rand() % 10;
        aux_edge.target_node = &(graphx->nodes[target]);

        graphx->nodes[i].edges = (type_edge*) realloc(graphx->nodes[i].edges, (graphx->nodes[i].edges_size + 1) * sizeof(type_edge));
        graphx->nodes[i].edges[graphx->nodes[i].edges_size] = aux_edge;
        graphx->nodes[i].edges_size++;
    }

    // Randomly add more edges
    int additional_edges = rand() % (size * 2);
    for (int i = 0; i < additional_edges; i++) {
        int source = rand() % size;
        int target = rand() % size;

        if (source != target && verify_edge(graphx, source, target)) {
            type_edge aux_edge;
            aux_edge.distance = 1 + rand() % 10;
            aux_edge.target_node = &(graphx->nodes[target]);

            graphx->nodes[source].edges = (type_edge*) realloc(graphx->nodes[source].edges, (graphx->nodes[source].edges_size + 1) * sizeof(type_edge));
            graphx->nodes[source].edges[graphx->nodes[source].edges_size] = aux_edge;
            graphx->nodes[source].edges_size++;
        }
    }
    return graphx;
}

void print_graph(type_graph graphx) {
    printf("graph_size: %d\n", graphx.size);
    for (int i = 0; i < graphx.size; i++) {
        for (int j = 0; j < graphx.nodes[i].edges_size; j++) {
            printf("(%d) -[%d]-> (%d)\n", graphx.nodes[i].id, graphx.nodes[i].edges[j].distance, graphx.nodes[i].edges[j].target_node->id);
        }
    }
}

void free_graph(type_graph* graphx) {
    for (int i = 0; i < graphx->size; i++) {
        free(graphx->nodes[i].edges);
    }
    free(graphx->nodes);
    free(graphx);
}
