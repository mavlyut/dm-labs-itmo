#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
 
vvi c;
int C(int n, int k) {
    if (k < 0 || n < 0 || n < k) return 0;
    if (c[n][k] == -1) {
        if (k == 0) c[n][k] = 1;
        else c[n][k] = C(n - 1, k) + C(n - 1, k - 1);
    }
    return c[n][k];
}
 
int n, k, m;
 
void gen() {
    vi ans;
    int a = 1;
    while (k > 0) {
        if (m < C(n - 1, k - 1)) {
            ans.push_back(a);
            k--;
        }
        else {
            m -= C(n - 1, k - 1);
        }
        n--;
        a++;
    }
    for (int i : ans) {
        cout << i << " ";
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
 
    cin >> n >> k >> m;
    c = vvi(n + 1, vi(n + 1, -1));
    gen();
 
    return 0;
}
