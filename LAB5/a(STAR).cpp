#include<iostream>
#include<queue>

using namespace std;

int node, edge, a[1000][1000], pathcost[1000], parent[100], root, goal, path[1000], he[1000], total[1000];

void input()
{
    cout<<"Enter number of nodes & edges: ";
    cin >> node >> edge;
    cout<<"Enter the edges and cost:"<<endl;
    for( int i = 1; i <= edge; i++ )
    {
        int u, v, cost;
        cin >> u >> v >> cost;
        a[u][v] = cost;
    }
    cout<<"Enter the heuristics value: "<<endl;
    for( int i = 1; i <= node; i++ )
    {
        cout<<i<<": ";
        cin>>he[i];
    }
}
void output()
{
    cout<< "Cost = " << total[goal] << endl;

    int i=0;
    while(true)
    {
        path[i] = goal;
        goal = parent[goal];
        if(root==path[i])
            break;
        i++;
    }

    cout<<"Path = ";
    while(i>=0)
    {
        cout << path[i] << " ";
        i--;
    }
}

void initiate()
{
    for( int i = 0; i < 1000; i++ )
    {
        parent[i] = -1;
        pathcost[i] = 1000;
        for( int j = 0; j < 1000; j++ )
        {
            a[i][j] = 0;
        }
    }
    for( int i = 1; i <= 100; i++ )
    {
        he[i] = 0;
        total[i] = 0;
    }
}

void ucs()
{
    pathcost[root] = 0;
    total[root] = 0;

    pair <int, int> p;
    priority_queue < pair<int, int> > pq;

    p.first = 0;
    p.second = root;

    pq.push( p );

    while( !pq.empty() )
    {
        p = pq.top();
        pq.pop();

        int u = p.second;

        for( int v = 1; v <= node; v++ )
        {
            if( a[u][v] != 0  && pathcost[v] > total[u] + a[u][v] + he[v])
            {
                pathcost[v] = total[u] + a[u][v] + he[v];
                total[v] = total[u] + a[u][v];
                parent[v] = u;
                p.first = pathcost[v];
                p.second = v;
                pq.push( p );
            }
        }
    }
}

int main()
{
    initiate();
    input();
    cout << "Enter start node: ";
    cin >> root;
    cout << "Enter goal node: ";
    cin >> goal;
    ucs();
    output();

    return 0;
}

/*
5 7
1 2 1
1 3 4
2 3 2
2 4 5
2 5 12
3 4 2
4 5 3
7
6
2
1
0
1
5
*/








