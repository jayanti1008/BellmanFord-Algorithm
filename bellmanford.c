/* ============================================================
 * Mini Project: Implementation and Performance Analysis of
 *                Bellman-Ford Shortest Path Algorithm
 * Algorithm   : Bellman-Ford Algorithm
 * Author      : Jayanti  |  USN: R24EQ044
 * Date        : 18-05-2026
 * Description : Finds the shortest distance from a source
 *               vertex to all other vertices in a weighted graph
 *               and detects negative weight cycles
 * ============================================================ */

/* --- Include necessary header files --- */
#include <stdio.h>
#include <stdlib.h>

/* --- Constants and Macro Definitions --- */
#define MAX 200
#define INF 99999

/* ============================================================
 * Structure Definition for Graph Edge
 * ============================================================ */
struct Edge {
    int source;
    int destination;
    int weight;
};

/* ============================================================
 * Function : printLine()
 * Purpose  : Prints decorative separator line
 * ============================================================ */
void printLine() {
    printf("=====================================================\n");
}

/* ============================================================
 * Function : displayMenu()
 * Purpose  : Displays project menu
 * ============================================================ */
void displayMenu() {

    printLine();

    printf("\n      BELLMAN-FORD SHORTEST PATH SYSTEM\n");

    printLine();

    printf("\n1. Enter Graph Details\n");
    printf("2. Display Graph\n");
    printf("3. Execute Bellman-Ford Algorithm\n");
    printf("4. Exit\n");

    printLine();
}

/* ============================================================
 * Function : displayGraph()
 * Purpose  : Displays graph edges
 * ============================================================ */
void displayGraph(struct Edge edges[], int edgesCount) {

    int i;

    printLine();

    printf("\n\t\tGRAPH EDGES\n");

    printLine();

    printf("Source\tDestination\tWeight\n");

    for(i = 0; i < edgesCount; i++) {

        printf("  %d\t     %d\t\t   %d\n",
               edges[i].source,
               edges[i].destination,
               edges[i].weight);
    }

    printLine();
}

/* ============================================================
 * Function : bellmanFord()
 * Purpose  : Implements Bellman-Ford shortest path algorithm
 * ============================================================ */
void bellmanFord(struct Edge edges[],
                 int vertices,
                 int edgesCount,
                 int source) {

    int distance[MAX];
    int i, j;

    /* Initialize all distances as infinity */
    for(i = 0; i < vertices; i++) {
        distance[i] = INF;
    }

    /* Distance of source vertex is 0 */
    distance[source] = 0;

    printLine();

    printf("\nExecuting Bellman-Ford Algorithm...\n");

    printLine();

    /* Relax all edges (V-1) times */
    for(i = 1; i <= vertices - 1; i++) {

        printf("\nIteration %d:\n", i);

        for(j = 0; j < edgesCount; j++) {

            int u = edges[j].source;
            int v = edges[j].destination;
            int w = edges[j].weight;

            /* Update shortest distance */
            if(distance[u] != INF &&
               distance[u] + w < distance[v]) {

                distance[v] = distance[u] + w;

                printf("Updated Distance[%d] = %d\n",
                       v, distance[v]);
            }
        }
    }

    /* Check for negative weight cycle */
    for(j = 0; j < edgesCount; j++) {

        int u = edges[j].source;
        int v = edges[j].destination;
        int w = edges[j].weight;

        if(distance[u] != INF &&
           distance[u] + w < distance[v]) {

            printLine();

            printf("\nNegative Weight Cycle Detected!\n");

            printLine();

            return;
        }
    }

    /* Display shortest distances */
    printLine();

    printf("\nSHORTEST DISTANCE FROM SOURCE VERTEX %d\n",
           source);

    printLine();

    printf("Vertex\t\tDistance\n");

    for(i = 0; i < vertices; i++) {

        if(distance[i] == INF)
            printf("  %d\t\tINF\n", i);
        else
            printf("  %d\t\t%d\n", i, distance[i]);
    }

    printLine();
}

/* ============================================================
 * Main Function
 * ============================================================ */
int main() {

    int vertices, edgesCount;
    int source;
    int choice;
    int graphChoice;
    int i, k = 0;

    struct Edge edges[MAX];

    printLine();

    printf("\n DESIGN AND ANALYSIS OF ALGORITHMS MINI PROJECT\n");

    printLine();

    printf("\nProject : Bellman-Ford Shortest Path Algorithm\n");

    printf("Language : C Programming\n");

    while(1) {

        displayMenu();

        printf("\nEnter Your Choice: ");

        scanf("%d", &choice);

        switch(choice) {

            case 1:

                printLine();

                printf("\nEnter Number of Vertices: ");

                scanf("%d", &vertices);

                printf("Enter Number of Edges: ");

                scanf("%d", &edgesCount);

                printLine();

                printf("\nSelect Graph Type:\n");

                printf("1. Directed Graph\n");
                printf("2. Undirected Graph\n");

                printf("\nEnter Choice: ");

                scanf("%d", &graphChoice);

                printLine();

                printf("\nEnter Edge Details:\n");

                printf("Format: Source Destination Weight\n\n");

                k = 0;

                for(i = 0; i < edgesCount; i++) {

                    int u, v, w;

                    printf("Edge %d: ", i + 1);

                    scanf("%d %d %d", &u, &v, &w);

                    edges[k].source = u;
                    edges[k].destination = v;
                    edges[k].weight = w;

                    k++;

                    /* Add reverse edge for undirected graph */
                    if(graphChoice == 2) {

                        edges[k].source = v;
                        edges[k].destination = u;
                        edges[k].weight = w;

                        k++;
                    }
                }

                printLine();

                printf("\nGraph Input Successful!\n");

                break;

            case 2:

                displayGraph(edges, k);

                break;

            case 3:

                printf("\nEnter Source Vertex: ");

                scanf("%d", &source);

                bellmanFord(edges,
                            vertices,
                            k,
                            source);

                break;

            case 4:

                printLine();

                printf("\nProject Execution Completed Successfully!\n");

                printLine();

                exit(0);

            default:

                printLine();

                printf("\nInvalid Choice! Please Try Again.\n");

                printLine();
        }
    }

    return 0;
}