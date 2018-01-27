#include<iostream>
#include<cstdlib>
#include<math.h>
#include<queue>
using namespace std;

pair <int,int> p;
priority_queue < pair <int,int> > pq;
int popu[1000][1000], deci[1000], offspring [1000], iter = 1, bin[8] , flag = 0, target;
float fitness [1000];

int convert_decimal(int i)
{
    int sum = 0;
    for( int j = 4; j >= 0; j--)
    {
        sum = sum + popu[i][j] * pow(2, (4-j));
    }
    return sum;
}

int convert_binary(int dec)
{
    for(int i = 0; i < 5 ; i++)
    {
        bin[i] = 0;
    }
    int res = dec, rem = 0, i = 4;

    while(res != 0)
    {
        res = dec / 2;
        rem = dec % 2;
        dec = res;
        bin[i] = rem;
        i--;
    }
}

int fitness_function(int x)
{
    return x*x;
}

float averege(int st, int s)
{
    float sum = 0;
    for(int i = 1; i <= s; i++)
    {
        sum = sum + fitness_function(deci[st]);
        st++;
    }
    return (sum/s);
}

int random_number(int s, int e)
{
    int ran = rand() % e + s;
    return ran;
}


int crossover(int first, int second)
{
    int ran = random_number(0, 3);
    int temp;
    for(int i = ran; i <= 4; i++)
    {
        temp = popu[first][i];
        popu[first][i] = popu[second][i];
        popu[second][i] = temp;
    }
}

int mutate(int index)
{
    int ran = random_number(0, 4);
    if(popu[index][ran] == 1)
        popu[index][ran] = 0;
    else
        popu[index][ran] = 1;
}

int partner(int st, int s)
{
    for(int i = st; i < s; i++)
    {
        crossover(i, i+1);
        i++;
    }
}

int genetic(int st, int s)
{
    cout<<"iteration: "<<iter<<endl;
    int temp = st;
    int found_index = 0;
    for(int i = 1; i <= s; i++)
    {
        deci[temp] = convert_decimal(temp);
        if(deci[temp] >= target)
            {
                flag = 1;
                found_index = temp;
                break;
            }
        temp++;
    }
    float favg = averege(st, s);
    temp = st;
    for(int i = 1; i <= s; i++)
    {
        fitness[temp] = fitness_function(deci[temp]) / favg;
        offspring[temp] = round(fitness[temp]);
        p.first = offspring[temp];
        p.second = deci[temp];
        pq.push(p);
        temp++;
    }
    if(flag == 1)
    {
        cout<<"Found!! on iteration "<< iter<<endl;
        cout<<"Decimal: "<<deci[found_index]<<endl;
        cout<<"Binary number: ";
        for(int j = 0; j < 5; j++)
        {
            cout<<popu[found_index][j]<<' ';
        }
        cout<<endl;
    }
    else
    {
        temp = st;
        for(int i = 1; i <= s; i++)
        {
            cout<<temp<<" decimal: "<<deci[temp]<<endl;
            cout<<"Fitness function value: "<<fitness_function(deci[temp])<<endl;;
            cout<<"Offspring number fitness: "<<fitness[temp]<<endl;;
            cout<<"Actual offspring number: "<<offspring[temp]<<endl;;
            temp++;
        }
        cout<<"Average: "<<averege(st, s)<<endl;;
        p = pq.top();
        cout<<"Maximum: "<<fitness_function(p.second)<<endl;;
        for(int i = 1; i <= s; i++)
        {
            p = pq.top();
            pq.pop();
            convert_binary(p.second);
            for(int j = 0; j < 5; j++)
            {
                popu[i][j] = bin[j];
            }
        }
        partner(st, s);
        cout<<"After Crossover......."<<endl;
        for(int i = 1; i <= s; i++)
        {
            cout<<"New child "<<i<<" = ";
            for(int j = 0; j <= 4; j++)
            {
                cout<<popu[i][j]<<' ';
            }
            cout<<endl;
        }
        for(int i = 1; i <= s; i++)
        {
            mutate(i);
        }
        cout<<"After mutate......."<<endl;
        for(int i = 1; i <= s; i++)
        {
            cout<<"New child "<<i<<" = ";
            for(int j = 0; j < 5; j++)
            {
                cout<<popu[i][j]<<' ';
            }
            cout<<endl;
        }
        iter++;
        genetic(1, s);
    }
}

int main()
{
    cout<<"Enter the size of population: ";
    int x;
    cin>>x;

    for(int i = 1; i <= x; i++)
    {
        cout<<"Enter the "<<i<<" population: ";
        for(int j = 0; j < 5; j++)
        {
            cin>>popu[i][j];
        }
    }
    cout<<"Enter the minimum target: ";
    cin>>target;
    genetic(1, x);

    return 0;

}

/*
2
0 1 1 0 1
0 1 0 0 0
28
*/
