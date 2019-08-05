#include<stdio.h>

#define INFINITY 9999
#define MAX 10
 
void dijkstra(int G[MAX][MAX],int n,int startnode, int targetnode);
 
int main()
{
    int graph[MAX][MAX]; //the graph, in the form of an adjacency matrix.
    int i;
    int j;
    int amountOfNodes;
    int startNode;
    int targetNode;
    
	printf("Enter no. of vertices:");
    scanf("%d",&amountOfNodes);
    
	// printf("\nEnter the adjacency matrix:\n");
	
	// for(i=0;i<n;i++)
	// 	for(j=0;j<n;j++)
	// 		scanf("%d",&G[i][j]);
    
    int c;
    char *input = "matrix.txt";
    FILE *input_file;

    input_file = fopen(input, "r");

    int rowcount = 0;
    int colcount = 0;
    while ((c =fgetc(input_file)) != EOF )
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

	printf("\nEnter the starting node:");
    scanf("%d",&startNode);

    printf("\nEnter the target node:");
    scanf("%d",&targetNode);

    dijkstra(graph,amountOfNodes,startNode,targetNode);
	
	return 0;
}
 
void dijkstra(int graph[MAX][MAX],int amountOfNodes,int startnode, int targetnode)
{
 
    int cost[MAX][MAX]; //the cost matrix, used to determine the minimum
    int distance[MAX]; //the amount of distance between each node
    int pred[MAX]; 
    int visited[MAX]; //a boolean array that shows if the node has been examined. 
    int count; //how many nodes have been visited in total
    int mindistance;
    int nextnode;
    int i;
    int j;
	
	//pred[] stores the predecessor of each node
	//count gives the number of nodes seen so far
	//create the cost matrix
	for(i=0;i<amountOfNodes;i++){
		for(j=0;j<amountOfNodes;j++){
            if(graph[i][j]==0){
                cost[i][j]=INFINITY; //if two nodes are not connected, then the distance is considered infinite               
            }
            else{
                cost[i][j]=graph[i][j]; //otherwise, set it to be the actual weight of the graph.               
            }
        }

    }

	
	for(i=0;i<amountOfNodes;i++)
	{
		distance[i]=cost[startnode][i];//set the distance to be the cost initially.
		pred[i]=startnode; 
		visited[i]=0; //no nodes have been visited, so set all of the "visited" nodes to 0
	}
	
	distance[startnode]=0; //set the distance of the starting node to 0
	visited[startnode]=1;  //selected the starting node
	count=1; 
	
	while(count<amountOfNodes-1) //iterate through each element in the graph
	{
		mindistance=INFINITY;
		
		//nextnode gives the node at minimum distance
        for(i=0;i<amountOfNodes;i++)
        
			if(distance[i] < mindistance && visited[i] == 0) //if the distance is less than the current minimum distance and the node has not yet been visited
			{
				mindistance=distance[i];
				nextnode=i; //next node is set to one of the surrounding nodes
			}
			
			//check if a better path exists through nextnode			
			visited[nextnode]=1; //visit the "next node"
			for(i=0;i<amountOfNodes;i++)
				if(visited[i] == 0) //if the node has not already been visited
					if(mindistance+cost[nextnode][i] < distance[i]) //if the minimum distance + the cost is less than the current distance
					{
						distance[i]=mindistance+cost[nextnode][i]; //set the new distance to that number.
						pred[i]=nextnode; //set the current path to the "next node"
					}
		count++;
	}
 
	// print the path and distance between the target and source nodes.
    if(i!=startnode){
        printf("\nDistance of node%d=%d",targetnode,distance[targetnode]);
        printf("\nPath=%d",targetnode);
        
        j=targetnode;
        do{
            j=pred[j];
            printf("<-%d",j);
        }while(j!=startnode);
    }
    printf("\n");
    
}