#include<bits/stdc++.h>
using namespace std;
int main()
{
    stack<int> s;
    int num;
    while(1)
    {
        cin>>num;
        if(num==0)
        {
            break;
        }
        else{
            s.push(num);
        }
    }
    while(!s.empty())
    {
        cout<<s.top();
        s.pop();
        if(!s.empty())
        {
            cout<<' ';
        }
    }
    return 0;
}