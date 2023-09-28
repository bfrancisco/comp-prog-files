#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

void p(auto leftq, auto rightq){
    while (!leftq.empty()){
        cout << leftq.rbegin() << " ";
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
    
    if (k==1){
        for (auto e : a) cout << e << " ";
        cout << endl;
        return 0;
    }
    else if (k==2){
        for (int i = 1; i < n; i++)
            cout << min(a[i-1], a[i]) << " ";
        cout << endl;
        return 0;
    }
    vector<pair<int, int>> srtk(k);
    for (int i = 0; i < k; i++){
        srtk[i] = {a[i], i};
    }
    sort(srtk.begin(), srtk.end());
    // for (auto e : srtk) cout << e << " "; cout << endl;
    set<pair<int, int>> leftq; // top is where median is
    set<pair<int, int>> rightq;

    // for (int i = 0; i <= (k%2 ? k/2 : k/2 - 1); i++){
    //     leftq.insert(srtk[i]);
    // }
    for (int i = 0; i < k/2 + (k%2); i++){
        leftq.insert(srtk[i]);
    }
    for (int i = k/2 + (k%2); i < k; i++){
        rightq.insert(srtk[i]);
    }


    cout << (*leftq.rbegin()).first << " ";
    // p(leftq,rightq);
    for (int i = 0, j = k; j < n; i++, j++){
        // cout << i << " " << j << endl;
        if (leftq.find(make_pair(a[i], i)) != leftq.end())
            leftq.erase(make_pair(a[i], i));
        else
            rightq.erase(make_pair(a[i], i));
        
        if (a[j] >= (*leftq.rbegin()).first)
            rightq.insert({a[j], j});
        else
            leftq.insert({a[j], j});

        while (leftq.size() < rightq.size()){
            leftq.insert(*rightq.begin());
            rightq.erase(*rightq.begin());
        }
        while (leftq.size() - rightq.size() > k%2){
            rightq.insert(*leftq.rbegin());
            leftq.erase(*leftq.rbegin());
        }

        cout << (*leftq.rbegin()).first << " ";
    }
    cout << endl;
    return 0;
}
