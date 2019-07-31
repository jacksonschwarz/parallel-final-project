/* Dijkstra's Algorithm in C */
#include<stdio.h>
#include<string.h>
#include<math.h>

#define INF 99
#define N 5
int dijkstra(int cost[][N], int source, int target);
int main(){
    int cost[N][N];
    int i,j;
    int w;
    int ch;
    int co;
    int source;
    int target;
    int x;
    int y;

    for(i=1;i< N;i++){
        for(j=1;j< N;j++){
            cost[i][j] = INF; //constructs an N by N matrix, setting all costs to INF   
        }
        
    } 

    //put the text file processing here. The "weights" are just areas of the code that are not zero.

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

            if(digit  == 0){
                cost[rowcount][colcount] = cost[rowcount][colcount] = INF;                            
            }
            else{
                cost[rowcount][colcount] = cost[rowcount][colcount] = digit;
            }

            colcount++;
        }
        if(c == 10) {
            rowcount++;
            colcount = 0;
        }
    }

    for(int i = 0;i<5;i++){
        for(int j = 0;j<5;j++){
            printf("%d ", cost[i][j]);
        }
        printf("\n");
    }
    printf("Finished file reading");
    fclose(input_file);
    
    // for(x=1;x<N;x++)
    // {
    //     for(y=x+1;y< N;y++)
    //     {
    //         printf("Enter the weight of the path between nodes %d and %d: ",x,y);
    //         scanf("%d",&w);
    //         if(w == 0) w = INF;
    //         cost [x][y] = cost[y][x] = w;
    //     }
    //     printf("\n");
    // }
    

    scanf("%d", &source);

    scanf("%d", &target);

    co = dijsktra(cost,source-1,target-1);
}
int dijsktra(int cost[][N],int source,int target)
{
    printf("Reaches the top of the function");
    int dist[N] = {0}; //an array of distances between nodes
    int prev[N] = {0}; //the previous node's cost.
    int selected[N]={0}; //if a node is selected, and its adjacent edges are being checked. 
    int minIndex; //the index of the node with the minimum amount of cost.
    int min; //the minimum cost between nodes. 
    int start; //starting point
    int d; //the distance between nodes
    int i; //iterator
    int j; //iterator
    char path[N]; //a string containing the path of nodes. 1 = A, 2 = B, etc.

    
    for(i=1;i< N;i++)
    {
        dist[i] = INF; //set all distances to infinite
        prev[i] = -1;

    }

    start = source; //the starting location of the code.
    selected[start]=1; //a boolean value stating that selected[i] is currently being looked it.

    dist[start] = 0; //the beginning distance 
    while(selected[target] == 0)
    {
        min = INF; //set the minimum to infinity at first to guarentee the chance of the minimum occuring
        minIndex = 0; //the index of the minimum item, set that to be the first element regardless of what it will become

        for(i=1;i< N;i++)
        {
            d = dist[start] + cost[start][i]; //add the first distance to the current adjacent node to the node with the current minimum index.
            if(d < dist[i] && selected[i] == 0) //if the distance "d" is less than the current distance, and this node has not yet been selected...
            {
                dist[i] = d; //set the current distance to the calculated distance
                prev[i] = start; //set the previous element to the minimum index. 
            }
            if(min > dist[i] && selected[i] == 0) //If the minimum is greater than the distance and the node has not yet been selected...
            {
                min = dist[i]; //set the minimum to the current distance.
                minIndex = i; //set the minimum index to the current index.
            }
        }
        start = minIndex; //set the start to the minimum index.
        selected[start] = 1; //set that particular node to "Selected"
    }
    start = target; //in the end, the "Start" variable will just be the target.

    j = 0;
    while(start != -1)
    {
        path[j++] = start+64; //take the "start" variable and convert it to an alphabetical character. Then, add it to the path string
        start = prev[start]; //set the 
    }

    path[j]='\0';
    printf("%s", path);
    return dist[target];
}
