#ifndef GRAPH_H
#define GRAPH_H

#include <stdio.h>
#include <stdlib.h>

typedef struct node type_node;
typedef struct edge type_edge;
typedef struct graph type_graph;

struct edge {
    type_node* target_node;
    int distance;
};

struct node {
    int id;
    int weight;
    int edges_size;
    type_edge* edges;
};

struct graph {
    int size;
    type_node* nodes;
};

int verify_edge(type_graph* graphx, int id1, int id2);
type_graph* generate_graph(int size);
void print_graph(type_graph graphx);
void free_graph(type_graph* graphx);

#endif // GRAPH_H