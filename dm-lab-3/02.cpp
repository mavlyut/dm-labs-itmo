#include <iostream>
#include <vector>
using namespace std;
typedef vector<string> vs;
 
vs gray(int n) {
    if (n == 1) {
        return { "0", "1" };
    }
    vs gray_pred = gray(n - 1);
    vs tmp;
    for (string i : gray_pred) {
        tmp.push_back("0" + i);
    }
    for (int i = gray_pred.size() - 1; i >= 0; i--) {
        tmp.push_back("1" + gray_pred[i]);
    }
    return tmp;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vs r = gray(n);
    for (string i : r) {
        cout << i + '\n';
    }
 
    return 0;
}
