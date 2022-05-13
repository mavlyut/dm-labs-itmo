#include <iostream>
#include <vector>
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> a = { 1 };
    for (int i = 1; i <= n; i++) {
        a.push_back(a[a.size() - 1] * 2);
    }
     
    for (int i = 0; i < a[n]; i++) {
        for (int j = n - 1; j >= 0; j--) {
            cout << (i % a[j + 1]) / a[j];
        }
        cout << '\n';
    }
 
    return 0;
}
