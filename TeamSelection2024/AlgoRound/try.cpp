#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    priority_queue<int, vector<int>, greater<>> q;
    q.push(1);
    q.push(2);
    q.push(3);

    while (!q.empty()){
        int x = q.top();
        q.pop();
        cout << x << endl;
    }
    

    return 0;
}