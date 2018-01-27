#include<iostream>
#include<string>
using namespace std;

string reflex_vacuum_agent(string location, string status)
{
    if(status == "Dirty")
        {
            return "Suck";
        }
    else if(location == "A")
        {
            return "Right";
        }
    else if (location == "B")
        {
            return "Left";
        }
}

int main()
{
    string location, status;

    cin>>location>>status;

    cout<<reflex_vacuum_agent(location, status)<<endl;

}
