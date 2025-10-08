#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    string num[n];
    for(auto &i:num)
    {
        cin>>i;
    }
    string ans_num;
    sort(num,num+n,[](string left,string right)->bool{
        return (left+right>right+left)?1:0;
    });
    for(auto i:num)
    {
        ans_num+=i;
    }
    cout<<ans_num<<flush;
    return 0;
}