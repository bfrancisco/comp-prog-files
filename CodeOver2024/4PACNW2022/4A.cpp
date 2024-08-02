#include<bits/stdc++.h>
using namespace std;

int N;
vector<string> words;
vector<char> letters;

int main(){

    cin >> N;
    words.resize(N);

    set<char> distinct;
    for (int i = 0; i < N; i++){
        cin >> words[i];
        for (char c : words[i]){
            distinct.insert(c);
        }
    }
    
    for (auto c : distinct) letters.push_back(c);

    // rb();



    return 0;
}