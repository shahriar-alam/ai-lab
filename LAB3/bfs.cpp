#include<iostream>
#include<queue>
using namespace std;

queue <int> a1;
queue <int> a2;

int a[100][100], c[100], p[100];

int bfs_visit(int u, int n)
{
    a2.push(u);
    for(int i = 1; i <= n; i++)
    {
        if(a[u][i] == 1)
        {
            if(c[i] == 0)
            {
                a1.push(i);
                c[i] = 1;
                p[i] = u;
            }
        }
    }
    a1.pop();
    if(!a1.empty())
        bfs_visit(a1.front(), n);
}

int bfs(int n)
{
    for(int i = 1; i <= n; i++)
    {
        if(c[i] == 0)
        {
            a1.push(i);
            bfs_visit(i, n);
        }
    }
}

int main()
{
    for(int i = 0; i < 100; i++)
    {
        for(int j = 0; j < 100; j++)
        {
            a[i][j] = 0;
        }
        c[100] = 0;
        p[100] = 0;
    }
    cout<<"Enter the number of nodes and edges: ";
    int n, e, x, y;
    cin>>n>>e;
    cout << "Enter the edges:"<<endl;
    for(int i = 1; i <= e; i++)
    {
        cin>>x>>y;
        a[x][y] = 1;
    }
    cout<<"Adjancency matrix:"<<endl;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cout<<a[i][j]<<' ';
        }
        cout<<endl;
    }
    bfs(n);
    while(!a2.empty())
    {
        cout<<a2.front()<<' ';
        a2.pop();
    }
}
