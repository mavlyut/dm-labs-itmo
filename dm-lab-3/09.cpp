#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> vi;
 
int n;
 
void gen(string p, int bal) {
    if (p.length() == n * 2) {
        cout << p << '\n';
        return;
    }
    if (bal + 1 < 2 * n - p.length()) {
        gen(p + '(', bal + 1);
    }
    if (bal > 0) {
        gen(p + ')', bal - 1);
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
 
    cin >> n;
    gen("", 0);
 
    return 0;
}
