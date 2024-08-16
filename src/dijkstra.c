#include "../include/dijkstra.h"

/**
 * from wikipedia:
 * Dijkstra's algorithm finds the shortest path from a given source node to every other node. It can also be used to find the shortest path to a specific destination node, by terminating the algorithm once the shortest path to the destination node is known.
 */

#define INFINITY 2147483647 // biggest int

int searchMinimal(bool* node_list, int* distance, int size) {
    int aux_id = -1;
    int aux = INFINITY;
    for (int id = 0; id < size; id++) {
        if (node_list[id] == false && distance[id] <= aux) {
            aux = distance[id], aux_id = id;
        }
    }
    //printf("minimal: %d of id %d\n", aux, aux_id);
    return aux_id;
}

void DijkstraSearch(type_graph* graphx, int target_node_id, int source_node_id){
    int graph_size = graphx->size;
    int distance[graph_size];
    int previous[graph_size];
    bool node_list[graph_size]; // Q

    for(int id=0; id < graph_size; id++){
        distance[id] = INFINITY;
        previous[id] = -1;
        node_list[id] = false;
    }
    distance[source_node_id] = 0;

    for(int count = 0; count < graph_size - 1; count++){

        int id_minimal = searchMinimal(node_list, distance, graph_size);
        node_list[id_minimal] = true;

        // finding the neighbors of id_minimal
        int neighbors_size = graphx->nodes[id_minimal].edges_size;

        for (int id = 0; id < neighbors_size; id++) {
            int neighbor_id = graphx->nodes[id_minimal].edges[id].target_node->id;

            if (node_list[neighbor_id] == false && distance[id_minimal] != INFINITY) {
                int dist_to_neighbor = graphx->nodes[id_minimal].edges[id].distance;
                int aux = distance[id_minimal] + dist_to_neighbor;

                //printf("u: %d, dist[u]: %d + weight: %d < dist[neighbr]: %d\n",id_minimal, distance[id_minimal], dist_to_neighbor, distance[neighbor_id]);
                if (aux < distance[neighbor_id]) {
                    distance[neighbor_id] = aux;
                    previous[neighbor_id] = id_minimal;
                }
            }
        }
    }

    int aux = target_node_id;
    printf("\nShortests path from %d to %d traverse a distance of size %d with the following nodes:-", source_node_id, target_node_id, distance[target_node_id]);

    if (previous[aux] != -1 || aux == source_node_id) {
        while (aux != -1) {
            printf("%d-", aux);
            aux = previous[aux];
        }
    }
    printf("\n");

    // Print the calculated shortest distances
    printf("\nOverall results of the Djikstra Algorithm:\n");
    printf("Vertex \t Distance from Start node(%d)\n", source_node_id);
    for (int i = 0; i < graph_size; i++)
        printf("%d \t\t %d\n", i, distance[i]);

    printf("end\n");
}