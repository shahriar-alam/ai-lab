#include<iostream>
using namespace std;

int fibonacci(int x, int y, int z)
{
    if(z == 26)
        return 1;
    else
    {
        int sum = x + y;
        cout<<sum<<' ';
        x = y;
        y = sum;
        z++;
        fibonacci(x,y,z);
    }
}

int main()
{
    int a = 0, b = 1;

    cout<<a<<' '<<b<<' ';

    fibonacci(a,b,3);

}
