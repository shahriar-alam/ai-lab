#include<iostream>
using namespace std;

int main()
{
    int array1[8][8], check[8], flag = 0;
    for(int i = 0; i <= 7; i++)
    {
        for(int j = 0; j <= 7; j++)
        {
            array1[i][j] = 0;
            check[i] = -1;
        }
    }


    for(int i = 0; i <= 7; i++)
    {
        for(int j = 0; j <= 7; j++)
        {
            flag = 0;
            if(array1[i][j] != 1)
            {
                if(check[i] != i)
                {
                    for(int k = 0; k < 8; k++)
                    {
                        if(check[k] == j)
                            flag = 1;
                    }
                    if(flag != 1)
                    {
                        array1[i][j] = 1;
                        check[i] = j;
                    }
                }
            }
        }
    }

    for(int i = 0; i <= 7; i++)
    {
        for(int j = 0; j <= 7; j++)
        {
            cout<<array1[i][j]<<' ';
        }
        cout<<endl;
    }
}
