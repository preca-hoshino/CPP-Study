#include <bits/stdc++.h>
using namespace std;
map<tuple<long long, long long, long long>, int> ram;
int f(long long a, long long b, long long c)
{
    auto index=make_tuple(a, b, c);
    auto it = ram.find(index);
    int tmp;
    if (it != ram.end())
    {
        return it->second;
    }
    else if (a <= 0 || b <= 0 || c <= 0)
    {
        return 1;
    }
    else if(a>20 || b>20 || c>20)
    {
        tmp= f(20,20,20);
    }
    else if(a<b && b<c)
    {
        tmp= f(a,b,c-1)+f(a,b-1,c-1)-f(a,b-1,c);
    }
    else
    {
        tmp= f(a-1,b,c)+f(a-1,b-1,c)+f(a-1,b,c-1)-f(a-1,b-1,c-1);
    }
    ram[index]=tmp;
    return tmp;
}
int main()
{
    long long tmp1, tmp2, tmp3;
    int ans;
    while (1)
    {
        cin >> tmp1 >> tmp2 >> tmp3;
        if (tmp1 == -1 && tmp2 == -1 && tmp3 == -1)
        {
            break;
        }
        ans = f(tmp1, tmp2, tmp3);
        cout<<"w("<<tmp1<<", "<<tmp2<<", "<<tmp3<<") = "<<ans<<'\n';
    }
    return 0;
}