// #include<bits/stdc++.h>
// using namespace std;

// #define int long long

// int n,mx1,mx2;

// signed main(){
//     cin>>n;
//     while(n--){
//         int a; scanf("%lld",&a);
//         if(a<=0)continue;
//         if(a>=mx1){mx2 = mx1,mx1 = a;}
//         else {
//             if(a>=mx2){mx2=a;}
//         }
//     }
//     cout<<mx1+mx2<<endl;
//     return 0;
// }
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int num[100000];
    for(int i=0;i<n;i++)
    {
        cin>>num[i];
    }
    sort(num,num+n,[](int left,int right)->bool{
        return left>right;
    });
    cout<<max(num[0],0)+max(num[1],0);
    return 0;
}