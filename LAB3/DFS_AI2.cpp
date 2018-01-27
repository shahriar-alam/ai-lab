#include<iostream>
using namespace std;
#define WHITE -1
#define GREY 0
#define BLACK 1
int vertices,color[1000],time,d[1000],p[1000],f[1000];
int Graph[1000][1000];
int c;
int flag = 0, start, goal;
int GraphT[1000][1000],index[1000];
void DFS();
void DFS_Visit(int u);
int main()
{
    cout<<"How many verticses: "<<endl;
    cin>>vertices;
    int i,j;
    cout<<"Enter adjacency matrix : "<<endl;
    for( i=1; i<=vertices; i++)
    {
        for( j=1; j<=vertices; j++)
        {
            cin>>Graph[i][j];
        }
    }
    cin>>start>>goal;
    DFS();
}
void DFS_Visit(int u)
{
    color[u] = GREY;
    time = time+1;
    d[u] = time;
        for(int v=1; v<=vertices; v++)
        {
            if(flag != 1)
            {
                if(Graph[u][v] == 1 &&color[v] == WHITE)
                {
                    if(v != goal)
                        DFS_Visit(v);
                    else
                    {
                        cout<<"Goal Found"<<endl;
                        flag = 1;
                    }
                }
            }
        }

        color[u] = BLACK;
        time = time+1;
        f[u] = time;

}
void DFS()
{
    for(int u=1; u<=vertices; u++)
    {
        color[u] = WHITE;
    }

    time = 0;

    if(color[start] == WHITE)
        DFS_Visit(start);

}
