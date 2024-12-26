#define max 50
#include<stdio.h>
void bfs(int adjmax[max][max],int visited[],int start,int m){
    int queue[max],front=-1,rear=-1,i,j;
    for(i=0;i<max;i++)
        visited[i]=0;
    front++;
    rear++;
    queue[rear]=start;
    visited[start]=1;
    while(rear>=front){
        start=queue[front];
        printf("%d ",start);
        front++;
        for(j=0;i<m;j++){
            if(adjmax[start][j]==1 && visited[j]==0){
                rear++;
                queue[rear]=j;
                visited[j]=1;
            }
        }
    }


}
void main(){
    int visited[max]={0};
    int adj[max][max],i,j,n,s;
    printf("Enter the number of nodes :");
    scanf("%d",&n);
    printf("Enter the adjacency matrix :");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("adj[%d][%d] : ",i,j);
            scanf("%d",&adj[i][j]);
        }
    }
    printf("Enter the starting node :");
    scanf("%d",&s);
    bfs(adj,visited,s,n);
}