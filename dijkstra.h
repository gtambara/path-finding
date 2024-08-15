#ifndef DJIKSTRA_H
#define DJIKSTRA_H

#include "graph.h"
#include <string.h>
#include <stdbool.h>

void DijkstraSearch(type_graph* graphx, int target_node_id, int source_node_id);
int searchMinimal(bool* node_list, int* distance, int size);

#endif // DJIKSTRA_H