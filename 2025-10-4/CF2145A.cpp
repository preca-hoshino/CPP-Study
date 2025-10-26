#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        if(n%3==0)
        {
            cout<<0;
        }
        else
        {

            cout<<(n/3+1)*3-n<<endl;
        }
    }
    return 0;
}