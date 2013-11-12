#include "queue.h"

#ifndef GRAPH_H_
#define GRAPH_H_

struct EdgeRecord{
    int vertex;
    int weights;
    struct EdgeRecord *next;
    struct EdgeRecord *last;
};
struct TableRecord{
    int preVertex;
    int dist;
};  

typedef struct EdgeRecord *Edge;
typedef struct TableRecord *Table;
typedef Edge *Graph;

Graph CreateGraph(int VertexNumber);
void AddEdge(Graph graph,int v,int w,int weights);
void DeleteEdge(Graph graph,int v,int w);
Edge IsConnected(Graph graph,int v,int w);
void ShowGraph(Graph graph,int VertexNumber);
Table Dijkstra(Graph graph,int source,int vertexNumber);
void ShowTable(Table table,int length);
void PrintPath(Table table,int v,int w);

#endif
