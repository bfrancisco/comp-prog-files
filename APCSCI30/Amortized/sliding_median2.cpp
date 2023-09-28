#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

void p(auto leftq, auto rightq){
    while (!leftq.empty()){
        cout << leftq.top() << " ";
        leftq.pop();
    }
    cout << " ";
    while (!rightq.empty()){
        cout << rightq.top() << " ";
        rightq.pop();
    }
    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    vector<int> srtk(k);
    for (int i = 0; i < k; i++){
        srtk[i] = a[i];
    }
    sort(srtk.begin(), srtk.end());
    // for (auto e : srtk) cout << e << " "; cout << endl;
    priority_queue<int> leftq; // top is where median is
    priority_queue<int, vector<int>, greater<int>> rightq;

    for (int i = 0; i <= (k%2 ? k/2 : k/2 - 1); i++){
        leftq.push(srtk[i]);
    }
    for (int i = (k%2 ? (k/2)+1 : k/2); i < k; i++){
        rightq.push(srtk[i]);
    }


    cout << leftq.top() << " ";
    // p(leftq,rightq);
    for (int i = 0, j = k; j < n; i++, j++){
        // cout << i << " " << j << endl;
        if (a[i] > leftq.top()){
            int c = 0;
            while (rightq.top() != a[i]){
                leftq.push(rightq.top());
                rightq.pop();
                c++;
            }
            rightq.pop();
            while (c--){
                rightq.push(leftq.top());
                leftq.pop();
            }
        }
        else{
            int c = 0;
            while (leftq.top() != a[i]){
                rightq.push(leftq.top());
                leftq.pop();
                c++;
            }
            leftq.pop();
            while (c--){
                leftq.push(rightq.top());
                rightq.pop();
            }
        }
        while (leftq.size() < rightq.size()){
            leftq.push(rightq.top());
            rightq.pop();
        }

        if (a[j] >= leftq.top()){
            rightq.push(a[j]);
        }
        else{
            leftq.push(a[j]);
        }

        while (leftq.size() < rightq.size()){
            leftq.push(rightq.top());
            rightq.pop();
        }
        if (k%2){
            while (leftq.size() - rightq.size() > 1){
                rightq.push(leftq.top());
                leftq.pop();
            }
        }
        else{
            while (leftq.size() - rightq.size() > 0){
                rightq.push(leftq.top());
                leftq.pop();
            }
        }

        cout << leftq.top() << " ";
        // p(leftq, rightq);
    }
    cout << endl;
    return 0;
}
