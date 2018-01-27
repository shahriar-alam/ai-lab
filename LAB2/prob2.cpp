#include<iostream>
using namespace std;

string rule_action(string rule)
{
    if(rule == "Suck")
        return "Suck";
    else if(rule == "Right")
        return "Right";
    else if(rule == "Left")
        return "Left";
}

string rule_match(string state, string rule)
{
    if(rule == "Dirty")
    {
        return rule_action("Suck");
    }
    else if(state == "A")
    {
        return rule_action("Right");
    }
    else if(state == "B")
    {
        return rule_action("Left");
    }
}

string interpret_input(string location, string state)
{
    string i2, s2;
    cin>>i2>>s2;
    return rule_match(i2, s2);
}

string simple_reflex_agent(string location, string status)
{
    if(status == "Dirty")
    {
        cout<<"Suck"<<endl;
    }
   else if(location == "A")
    {
        cout<<"Right"<<endl;
    }
    else if(location == "B")
    {
        cout<<"Left"<<endl;
    }
    return interpret_input(location, status);
}


int main()
{

        string i1, s1;
        cin>>i1>>s1;
        cout<<simple_reflex_agent(i1,s1)<<endl;
}
