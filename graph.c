#include<stdio.h>
#include "graph.h"

Graph CreateGraph(int VertexNumber){
    Graph graph = (Graph) calloc((VertexNumber + 1),sizeof(Edge));

    if(graph == NULL){
        printf("CreateGraph failed\n");
    }

    return graph;
}

void AddEdge(Graph graph,int v,int w,int weights){
    if(graph == NULL){
        printf("AddEdge Error,Graph is null\n");
        return;
    }

    if(!IsConnected(graph,v,w)){
        Edge e = (Edge) malloc(sizeof(struct EdgeRecord));

        if(e == NULL){
            printf("Edge malloc error!\n");
            return;
        }

        e->vertex = w;
        e->weights = weights;
        e->next = graph[v];
        e->last = NULL;

        if(graph[v] != NULL){
            graph[v]->last = e;
        }
        graph[v] = e;
    }
}

void DeleteEdge(Graph graph,int v,int w){
    if(graph == NULL){
        printf("DeleteEdge Error,Graph is null\n");
        return;
    }

    Edge e = IsConnected(graph,v,w);

    if(e){
        if(e->last == NULL){
            graph[v] = e->next;
            e->next->last == NULL;
        }else{
            e->last->next = e->next;
            e->next->last = e->last;
        }

        free(e);
    }
}

Edge IsConnected(Graph graph,int v,int w){
    if(graph == NULL){
        printf("IsConnected error\n");
        return NULL;
    }

    Edge e = graph[v];

    while(e){
        if(e->vertex == w){
            return e;
        }
        e = e->next;
    }

    return NULL;
}

void ShowGraph(Graph graph,int VertexNumber){
    if(graph == NULL){
        printf("ShowGraph error\n");
        return NULL;
    }

    printf("vertex number = %d\n",VertexNumber);

    int i;
    for(i = 1;i <= VertexNumber;i++){
        printf("vertex = %d\n",i);
        
        Edge e = graph[i];    
        while(e){
            printf("adjacent = %d weights = %d\n",e->vertex,e->weights);
            e = e->next;
        }
    }
}

Table Dijkstra(Graph graph,int source,int vertexNumber){
    Queue Q = CreateQueue();
    Table table = calloc(vertexNumber + 1,sizeof(struct TableRecord)); 
    table[source].dist = 0;
    table[source].preVertex = 0;
    Enqueue(Q,source);
    
    int curVertex;
    int adjVertex;
    int curDist;

    Edge edgeRecord;

    while(Q->size){
        curVertex = Dequeue(Q);
        curDist = table[curVertex].dist;
        edgeRecord = graph[curVertex];

        while(edgeRecord){
            adjVertex = edgeRecord->vertex;
            
            if(adjVertex != source){
                if(table[adjVertex].dist == 0){
                    Enqueue(Q,adjVertex);
                    table[adjVertex].dist = edgeRecord->weights + curDist;
                    table[adjVertex].preVertex = curVertex;
                }
                
                if(table[adjVertex].dist > edgeRecord->weights + curDist){
                    table[adjVertex].dist = edgeRecord->weights + curDist;
                    table[adjVertex].preVertex = curVertex;
                }
            }

            edgeRecord = edgeRecord->next;
        }
    }
    return table;            
}

void ShowTable(Table table,int length){
    int i;
    printf("vertex  pre     dist\n");
    for(i = 1;i <= length;i++){
        printf("%d      %d      %d\n",i,table[i].preVertex,table[i].dist);
    }
}

void PrintPath(Table table,int v,int w){
    if(table == NULL){
        printf("table is null,print path error\n");
        return;
    }

    if(v == w){
        printf("%d ",v);
        return;
    }
   
    PrintPath(table,v,table[w].preVertex);
    printf("-> %d",w);
}
