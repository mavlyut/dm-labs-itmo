#include <iostream>
#include <vector>
#include <set>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef pair<ll, ll> pll;

void dfs(int u, vector<vl> g, vl& depth) {
    for (ll v : g[u]) {
        depth[v] = depth[u] + 1;
        dfs(v, g, depth);
    }
}

int main() {
    int n, ind;
    vector <ll> p, depth;
    set<pll> a;
    vector<vl> huffman;
    cin >> n;
    p.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    n = p.size();
    huffman.resize(3 * n);
    depth.resize(3 * n);
    ind = n;
    for (int i = 0; i < n; i++) {
        a.insert({p[i], i});
    }
    while (true) {
        if (a.size() == 1) {
            break;
        }
        pll m1 = *a.begin();
        a.erase(a.begin());
        pll m2 = *a.begin();
        a.erase(a.begin());
        huffman[ind].push_back(m1.second);
        huffman[ind].push_back(m2.second);
        a.insert({m1.first + m2.first, ind} );
        ind++;
    }
    depth[ind - 1] = 0;
    dfs(ind - 1, huffman, depth);
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        sum += p[i] * depth[i];
    }
    cout << sum;

    return 0;
}