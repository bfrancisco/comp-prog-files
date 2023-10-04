#include<bits/stdc++.h>
using namespace std;
const int maxn = 5005;
int x[maxn],y[maxn],dp[maxn];
int from[maxn],n;
int dfs(int a)
{   
    cout << "dfs: " << a << endl;
    if(dp[a])return dp[a];
    for(int i=1;i<=n;i++)
    {
        if(x[a]<x[i]&&y[a]<y[i]){
            int val = dfs(i); 
            cout << a << " " << i << endl;
            if(val+1>dp[a])
            {
                from[a]=i;
                dp[a]=dfs(i)+1;
            }
        }
    }
    return dp[a];
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<=n;i++)
        scanf("%d%d",&x[i],&y[i]);
    int ans = dfs(0);
    printf("%d\n",ans);
    for(int i=from[0];i;i=from[i])
        printf("%d ",i);
    return 0;
}