#include "../include/graph.h"
#include "../include/dijkstra.h"

int main() {

    int graphsize;

    printf("graph size:\n");
    scanf("%d", &graphsize);

    type_graph* graphx = generate_graph(graphsize);
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