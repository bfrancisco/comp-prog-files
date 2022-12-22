#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  const int N = 200010;
  int n, q, a, b, c, d;
  cin >> n >> q;

  pair<int, int> db[N];         // id: val, kinder
  multiset<int> sets[N];        // kinder, multisets
  multiset<int> highs;          // multiset of strongest infants
 
  for (int i = 1; i <= n; i++){
    cin >> a >> b;
    db[i] = make_pair(a, b);
    //cout << db[i].first << " " << db[i].second << " ";
    sets[b].insert(a);
    //cout << *sets[b].rbegin() << " ";
    //cout << i << endl;
  }
  
  for (int i = 1; i < N; i++){
    if (!sets[i].empty()){
      highs.insert(*sets[i].rbegin());
    }
  }

  int val, kinder;
  while (q--){
    cin >> c >> d;
    val = db[c].first;
    kinder = db[c].second;

    if (kinder == d){
      continue;
    }

    //remove
    highs.erase(highs.find(*sets[kinder].rbegin()));
    if (!sets[d].empty()){
      highs.erase(highs.find(*sets[d].rbegin()));
    }

    sets[kinder].erase(sets[kinder].find(val));
    sets[d].insert(val);

    if (!sets[kinder].empty()){
      highs.insert(*sets[kinder].rbegin());
    }
    highs.insert(*sets[d].rbegin());

    db[c].second = d;
    // out lowest in highs
    cout << *highs.begin() << endl;
  }
  
  return 0;
}