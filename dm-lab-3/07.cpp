#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> vi;
 
int n;
vi a, used;
 
void gen(int p) {
    if (p == n) {
        for (int i : a) {
            cout << i << " ";
        } cout << endl;
    }
    for (int i = 1; i <= n; i++) {
        if (!used[i - 1]) {
            used[i - 1] = 1;
            a[p] = i;
            gen(p + 1);
            used[i - 1] = 0;
        }
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    a.resize(n);
    used.resize(n);
    gen(0);
 
    return 0;
}
