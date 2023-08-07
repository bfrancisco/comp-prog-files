#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

// for hopscotch, not used

struct segtree {
    vector<unordered_set<int>> tree;
    segtree(){
        tree.resize(4*n);
    }

    void initalize(vector<int> &arr){
        build(arr, 1, 0, n-1);
    }

    void build(vector<int> &arr, int node, int left, int right){
        if (left == right){
            tree[node].insert(arr[left]);
            return;
        }
        int mid = (left + right) / 2;
        build(arr, 2 * node, left, mid);
        build(arr, 2 * node + 1, mid+1, right);

        tree[node].insert(tree[2 * node].begin(), tree[2 * node].end());
        tree[node].insert(tree[2 * node + 1].begin(), tree[2 * node + 1].end());
    }

    bool findrestrict(int L, int R, int target){
        // restrict L-R from find
        // 0-based indexing L R
        int l1=0, r1=L-1, l2=R+1, r2=n-1;
        return find(1, 0, n-1, l1, r1, target) || find(1, 0, n-1, l2, r2, target);
    }

    bool find(int node, int left, int right, int qLeft, int qRight, int target){
        if (right < left) return false;

        if (qLeft <= left && right <= qRight){
            return tree[node].find(target) != tree[node].end();
        }

        int mid = (left + right) / 2;
        bool leftRes = find(2*node, left, mid, qLeft, qRight, target);
        bool rightRes = find(2*node, mid+1, right, qLeft, qRight, target);

        return leftRes || rightRes;
    }

};