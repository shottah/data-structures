/* Dijkstra's Algorithm in C */
#include<stdio.h>
#include<conio.h>
#include<process.h>
#include<string.h>
#include<math.h>

using namespace std;

#define IN 99
#define N 6

int cost [N][N] = {
	/*v0*/	{0,1,6,'I','I','I'},
	/*v1*/	{'I',0,3,4,6,'I'},
	/*v2*/	{'I','I',0,2,2,'I'},
	/*v3*/	{'I','I','I',0,2,3},
	/*v4*/	{'I','I','I','I',0,4},
	/*v5*/	{'I','I','I','I','I',0}
};

int dijkstra(int cost[][N], int source, int target);

int main()
{
    int source, target, co;
    printf("\nEnter the source:");
    scanf("%d", &source);
    printf("\nEnter the target");
    scanf("%d", &target);
    co = dijkstra(cost,source,target);
    printf("\nThe Shortest Path: %d",co);
    
    return 0;
}

int dijkstra(int cost[][N],int source,int target)
{
    int dist[N],prev[N],selected[N]={0},i,m,min,start,d,j;
    char path[N];
    for(i=1;i< N;i++)
    {
        dist[i] = IN;
        prev[i] = -1;
    }
    start = source;
    selected[start]=1;
    dist[start] = 0;
    while(selected[target] ==0)
    {
        min = IN;
        m = 0;
        for(i=1;i< N;i++)
        {
            d = dist[start] +cost[start][i];
            if(d< dist[i]&&selected[i]==0)
            {
                dist[i] = d;
                prev[i] = start;
            }
            if(min>dist[i] && selected[i]==0)
            {
                min = dist[i];
                m = i;
            }
        }
        start = m;
        selected[start] = 1;
    }
    start = target;
    j = 0;
    while(start != -1)
    {
        path[j++] = start+65;
        start = prev[start];
    }
    path[j]='\0';
    strrev(path);
    printf("%s", path);
    return dist[target];
}
