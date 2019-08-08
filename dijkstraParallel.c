#include<stdio.h>

#include <omp.h>

#define INFINITY 999
#define MAX 100
 
void dijkstra(int G[MAX][MAX],int n,int startnode, int targetnode);
 
int main()
{
    int graph[MAX][MAX]; //the graph, in the form of an adjacency matrix.
    int i;
    int j;
    int amountOfNodes = 20;
    int startNode = 0;
    int targetNode = 17;

    int c;
    char *input = "matrix.txt";
    FILE *input_file;

    input_file = fopen(input, "r");

    int rowcount = 0;
    int colcount = 0;
    while ((c = fgetc(input_file)) != EOF )
    {
        if (isdigit(c)){
            int digit = c-48;

            graph[rowcount][colcount] = graph[rowcount][colcount] = digit;

            colcount++;
        }
        if(c == 10) {
            rowcount++;
            colcount = 0;
        }
    }

    for(int i = 0;i<amountOfNodes;i++){
        for(int j = 0;j<amountOfNodes;j++){
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }

    #pragma omp barrier
    dijkstra(graph,amountOfNodes,startNode, targetNode);
	
	return 0;
}
 
void dijkstra(int G[MAX][MAX],int n,int startnode, int targetnode)
{
 
	int cost[MAX][MAX],distance[MAX],pred[MAX];
	int visited[MAX],count,mindistance,nextnode,i,j;
	
	//pred[] stores the predecessor of each node
	//count gives the number of nodes seen so far
	//create the cost matrix
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			if(G[i][j]==0)
				cost[i][j]=INFINITY;
			else
				cost[i][j]=G[i][j];
	
	//initialize pred[],distance[] and visited[]
	for(i=0;i<n;i++)
	{
		distance[i]=cost[startnode][i];
		pred[i]=startnode;
		visited[i]=0;
	}
	
	distance[startnode]=0;
	visited[startnode]=1;
	count=1;
	
	while(count<n-1)
	{
		mindistance=INFINITY;
		
        //nextnode gives the node at minimum distance
        #pragma omp parallel default(shared)
        {
            #pragma omp for reduction(min:mindistance) nowait schedule(dynamic)
            for(i=0;i<n;i++)
                if(distance[i]<mindistance&&!visited[i])
                {
                    mindistance=distance[i];
                    nextnode=i;
                }
                
                //check if a better path exists through nextnode			
                visited[nextnode]=1;
                for(i=0;i<n;i++)
                    if(!visited[i])
                        if(mindistance+cost[nextnode][i]<distance[i])
                        {
                            distance[i]=mindistance+cost[nextnode][i];
                            pred[i]=nextnode;
                        }
        }
		
		count++;
	}
 
    //print the path and distance of each node
    count = 0;
    if(i!=startnode){
        printf("\nDistance of node%d=%d",targetnode,distance[targetnode]);
        printf("\nPath=%d",targetnode);
        
        j=targetnode;
        do{
            j=pred[j];
            printf("<-%d",j);
            count++;
            count ++;
            if(count > n){
                printf("<-INF LOOP\n");
                break;
            }
        }while(j!=startnode);
    }
}
    