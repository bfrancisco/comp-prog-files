#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

template <class T>
struct trie {
  struct node {
    map<T, node*> children;
    int prefixes, words;
    node() { prefixes = words = 0; } };
  node* root;
  trie() : root(new node()) {  }
  template <class I>
  void insert(I begin, I end) {
    node* cur = root;
    while (true) {
      cur->prefixes++;
      if (begin == end) { cur->words++; break; }
      else {
        T head = *begin;
        typename map<T, node*>::const_iterator it;
        it = cur->children.find(head);
        if (it == cur->children.end()) {
          pair<T, node*> nw(head, new node());
          it = cur->children.insert(nw).first;
        } begin++, cur = it->second; } } }
  template<class I>
  int countMatches(I begin, I end) {
    node* cur = root;
    while (true) {
      if (begin == end) return cur->words;
      else {
        T head = *begin;
        typename map<T, node*>::const_iterator it;
        it = cur->children.find(head);
        if (it == cur->children.end()) return 0;
        begin++, cur = it->second; } } }
  template<class I>
  int countPrefixes(I begin, I end) {
    node* cur = root;
    while (true) {
      if (begin == end) return cur->prefixes;
      else {
        T head = *begin;
        typename map<T, node*>::const_iterator it;
        it = cur->children.find(head);
        if (it == cur->children.end()) return 0;
        begin++, cur = it->second; } } } };

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n; cin >> n;
    trie<char> db;
    int good = 1;
    string bad = "";
    vector<string> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    for (auto s : a){
        for (int i = 0; i < s.size(); i++){
            if (db.countMatches(&s[0], &s[i]) > 0){
                good = 0;
                bad = s;
                break;
            }
        }
        if (db.countPrefixes(s.begin(), s.end()) > 0){
            good = 0;
            bad = s;
        }
        if (!good) break;
        db.insert(s.begin(), s.end());
    }

    if (good) cout << "GOOD SET" << endl;
    else cout << "BAD SET\n" << bad << endl;

    
    return 0;
}