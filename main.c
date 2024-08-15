#include "graph.h"
#include "dijkstra.h"

int main() {
    type_graph* graphx = generate_graph(10);
    print_graph(*graphx);

    int startNode, endNode;

    printf("start node:\n");
    scanf("%d", &startNode);
    printf("end node:\n");
    scanf("%d", &endNode);

    DijkstraSearch(graphx, endNode, startNode);

    free_graph(graphx);

    return 0;
}