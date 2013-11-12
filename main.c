#include<stdio.h>
#include "queue.h"
#include "graph.h"

int main(){
    /*
    int a,b,c,d,e,f,g,h;
    
    scanf("%d,%d,%d,%d",&a,&b,&c,&d);
    getchar();

    Queue Q = CreateQueue();

    Enqueue(Q,a);
    Enqueue(Q,b);
    Enqueue(Q,c);
    Enqueue(Q,d);

    e = Dequeue(Q);
    printf("%d\n",e);
    f = Dequeue(Q);
    printf("%d\n",f);
    g = Dequeue(Q);
    printf("%d\n",g);
    h = Dequeue(Q);
    printf("%d\n",h);    

    printf("%d,%d,%d,%d\n",e,f,g,h);
    getchar();
    */
        
    int vertexNumber = 0;
    int vertex;
    int weights;
    int i;
    int f;
    Table table;

    printf("Create graph:\n");
    printf("Input vertex number:");
    scanf("%d",&vertexNumber);
    getchar();

    printf("Graph initing...\n");
    Graph graph = CreateGraph(vertexNumber);
    if(graph == NULL){
        printf("Graph init failed\n");
        return 0;
    }
    
    for(i = 1;i <= vertexNumber;i++){
        printf("Vertex:%d\nHas adjavent?[1/0]:",i);
        scanf("%d",&f);
        getchar();
        
        while(f){
            printf("adjacent:");
            scanf("%d",&vertex);
            getchar();

            printf("weights:");
            scanf("%d",&weights);
            getchar();

            printf("continue?[1/0]:");
            scanf("%d",&f);
            getchar();

            AddEdge(graph,i,vertex,weights);
        }
    }    

    ShowGraph(graph,vertexNumber);

    printf("input source:");
    scanf("%d",&i);
    getchar();

    table = Dijkstra(graph,i,vertexNumber);

    ShowTable(table,vertexNumber);
    PrintPath(table,i,2);
    
    printf("hello linux c\n");

    return 0;
}
