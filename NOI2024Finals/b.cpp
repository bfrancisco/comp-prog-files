#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

vector<vector<int>> grid;

int f(int a, int b, int c, int d){
    int x = abs(a-c), y = abs(b-d);
    if (x > y) swap(x, y);
    return x + (y-x);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    


    return 0;
}