#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n];
    set<int> nums;
    for(auto &i:a)
    {
        cin>>i;
        nums.insert(i);
    }
    set<int> result;
    for(auto i:a)
    {
        for(auto j:a)
        {
            if(i==j)
            {
                continue;
            }
            int tmp=i+j;
            if(nums.count(tmp))
            {
                result.insert(tmp);
            }
        }
    }
    cout<<result.size();
    return 0;
}