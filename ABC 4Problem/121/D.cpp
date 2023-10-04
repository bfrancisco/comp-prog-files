#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    ll a, b; 
    cin >> a >> b;
    ll one = 1;
    if (a==b)
        {cout << a;
        return 0;}

    ll x = 0;
    if (a%2){
        x = (x ^ a);
        a++;
    }
    if (b%2==0){
        x = (x ^ b);
        b--;
    }

    ll dif = ((b-a)+ one)/2;

    if (dif%2)
        x = (x ^ one);
    
    cout << x;


    return 0;
}