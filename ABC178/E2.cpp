#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int manhat(int a, int b, int c, int d){
    return abs(a-c) + abs(b-d);
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n,a,b;
    cin >> n;
    int bnd = 2000000001;
    
    for (int i = 0; i < n; i++){
        cin >> a >> b;
    }


    return 0;
}