#include<iostream>
using namespace std;

void find_neighbours(int a[][100], int n, int v)
{
    cout<<"The neighbours of "<<n<<" are: ";
    for(int i = 1; i <= v; i++)
    {
        if(a[n][i] == 1)
        {
            cout<<i<<' ';
        }
    }
}

int main()
{
    int v, e,x, y, a[100][100];
    cout<<"Enter the number of vertices: ";
    cin>>v;
    cout<<"Enter the number of edges: ";
    cin>>e;
    cout<<"Enter the edges:"<<endl;

    for(int i = 1; i <= v; i++)
    {
        for(int j = 1; j <= v; j++)
        {
            a[i][j] = 0;
        }
    }

    for(int i = 1; i <= e; i++)
    {
        cin>>x>>y;
        a[x][y] = 1;
    }

    for(int i = 1; i<=v; i++)
    {
        for(int j = 1; j<=v; j++)
        {
            cout<<a[i][j]<<' ';
        }
        cout<<endl;
    }
    int n;
    cout<<"Enter the node: ";
    cin>>n;

    find_neighbours(a, n, v);

}
