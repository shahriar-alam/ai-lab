#include<iostream>
#include<stack>
using namespace std;

stack <int> a1;
stack <int> a2;
int flag = 0;

int dfs_visit(int u, int a[][100], int c[], int d[], int f[], int p[], int n, int &tm, int st, int g)
{
    c[u] = 1;
    d[u] = ++tm;
    a1.push(u);
    for(int v=1; v<=n; v++)
    {
        if(flag != 1)
        {
            if(a[u][v] == 1)
            {
                if(c[v] == 0)
                {
                    if(v != g)
                    {
                        p[v] = u;
                        dfs_visit(v, a, c, d, f, p, n, tm,st,g);
                        if(!a1.empty())
                            a1.pop();
                    }
                    else
                    {
                        p[v] = u;
                        flag = 1;
                        a1.push(v);
                        while(!a1.empty())
                        {
                            a2.push(a1.top());
                            a1.pop();
                        }
                        break;
                    }
                }
            }
        }
//        if(a[u][v] == 1)
//        {
//            if(c[v] == 0)
//            {
//                if(v != g)
//                {
//                    p[v] = u;
//                    dfs_visit(v, a, c, d, f, p, n, tm,st,g);
//                    if(!a1.empty())
//                        a1.pop();
//                }
//                else
//                {
//                    p[v] = u;
//                    flag = 1;
//                    a1.push(v);
//                    while(!a1.empty())
//                    {
//                        a2.push(a1.top());
//                        a1.pop();
//                    }
//                    break;
//                }
//            }
//        }
    }
    c[u] = 2;
    f[u] = ++tm;
}

int main()
{
    int n, e, x, y, a[100][100], c[100], d[100], f[100], p[100];
    int tm = 0;
    for(int i = 0; i<100; i++)
    {

        f[i] = d[i] = 0;
        p[i] = -1;
        c[i] = 0;
        for(int j=0; j<100; j++)
        {
            a[i][j] = 0;
        }
    }
    cout<<"Enter number of node and edges: ";
    cin>>n>>e;
    cout<<"Enter the edges: "<<endl;
    for(int i=1; i<=e; i++)
    {
        cin>>x>>y;
        a[x][y]=1;
    }
    cout<<"Adjancency matrix:"<<endl;
    for(int i = 1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            cout<<a[i][j]<<' ';
        }
        cout<<endl;
    }
    cout<<"Enter the start and end node"<<endl;
    int st, g;
    cin>>st>>g;
    dfs_visit(st, a, c, d, f, p, n, tm, st, g);
    if(flag == 1)
    {
        cout<<"Goal found"<<endl;
        cout<<"The path is: ";
        while(!a2.empty())
        {
            cout<<a2.top();
            a2.pop();
            if(!a2.empty())
                cout<<"->";
        }
        cout<<endl;
    }
    else
        cout<<"Goal not found"<<endl;

    return 0;
}

/*
5 6
1 0
1 3
4 3
0 3
0 2
2 3
*/
