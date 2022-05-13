#include <iostream>
#include <set>
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    string tmp = "";
    for (int i = 0; i < n; i++) {
        tmp += '0';
    }
    set<string> w;
    while (true) {
        cout << tmp + '\n';
        w.insert(tmp);
        tmp = tmp.substr(1, n);
        if (w.find(tmp + '1') != w.end()) {
            if (w.find(tmp + '0') != w.end()) {
                break;
            }
            tmp += '0';
        }
        else {
            tmp += '1';
        }
    }
 
    return 0;
}
