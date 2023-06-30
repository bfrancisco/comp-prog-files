#include<bits/stdc++.h>
using namespace std;typedef long long int ll;int main(){ll n,x,a=0,b,r;cin>>n;x=sqrt(n);for(r=1;r<=x;r++)a+=r*(r+n/r)*(n/r+1-r)/2;b=x*(x+1)*(2*x+1)/6;cout<<2*a-b<<endl;} 