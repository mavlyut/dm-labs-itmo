#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> vi;
 
vi fib = { 1, 1 };
int n;
 
string toFib(int a) {
    string ans = "";
    for (int i = n - 1; i >= 0; i--) {
        if (a >= fib[i]) {
            a -= fib[i];
            ans += "1";
        }
        else {
            ans += "0";
        }
    }
    return ans + '\n';
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int tmp = fib.size() - 1;
        fib.push_back(fib[tmp] + fib[tmp - 1]);
    }
    vi(fib.begin() + 1, fib.end()).swap(fib);
 
    cout << fib[n] << endl;
    for (int i = 0; i < fib[n]; i++) {
        cout << toFib(i);
    }
 
    return 0;
}
