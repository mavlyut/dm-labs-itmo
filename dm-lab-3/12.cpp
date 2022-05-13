#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
 
vvvi gen(int n, int k) {
    if (n < k) {
        return vvvi();
    }
    if (k == 1) {
        vi res;
        for (int i = 1; i <= n; i++) {
            res.push_back(i);
        }
        return { { res } };
    }
    vvvi a = gen(n - 1, k - 1);
    vvvi b = gen(n - 1, k);
    vvvi res;
    for (vvi i : a) {
        i.push_back({ n });
        res.push_back(i);
    }
    for (vvi i : b) {
        for (int j = 0; j < i.size(); j++) {
            i[j].push_back({ n });
            res.push_back(i);
            i[j].pop_back();
        }
    }
    return res;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
 
    int n, k;
    cin >> n >> k;
    vvvi ans = gen(n, k);
    int cnt = 0;
    for (vvi i : ans) {
        for (vi j : i) {
            for (int k : j) {
                cout << k << ' ';
            }
            cout << '\n';
        }
        cout << '\n';
    }
 
    return 0;
}
