#include <bits/stdc++.h>
using namespace std;
int num[500001];
long long ans;
int n;
void merge_sort(int left, int right)
{
    int tmp_num[500001];
    if (left == right)
    {
        return;
    }
    int mid_index = (left + right) / 2;
    int tmp_left = left, tmp_right = mid_index + 1;
    int tmp_index=left;
    merge_sort(left, mid_index);
    merge_sort(tmp_right, right);
    for (; tmp_left <= mid_index && tmp_right <= right;)
    {
        if (num[tmp_left] <= num[tmp_right])
        {
            tmp_num[tmp_index]=(num[tmp_left]);
            tmp_left++;
            tmp_index++;
        }
        else
        {
            ans += mid_index - tmp_left + 1;
            tmp_num[tmp_index]=(num[tmp_right]);
            tmp_right++;
            tmp_index++;
        }
    }
    for(;tmp_left <= mid_index;)
    {
        tmp_num[tmp_index]=(num[tmp_left]);
        tmp_left++;
        tmp_index++;
    }
    for(;tmp_right <= right;)
    {
        tmp_num[tmp_index]=(num[tmp_right]);
        tmp_right++;
        tmp_index++;
    }
    for(int i=left;i<=right;i++)
    {
        num[i]=tmp_num[i];
    }
    return;
}
int main()
{
    cin >> n;
    for (int i = 1; i <=n; i++)
    {
        cin >> num[i];
    }
    merge_sort(1, n);
    cout << ans;
    return 0;
}