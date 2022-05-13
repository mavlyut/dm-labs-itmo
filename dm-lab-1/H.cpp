#include <iostream>
#include <string>
#include <sstream>
using namespace std;

void f(int n) {
    if (n == 0) {
        cout << "((A0|B0)|(A0|B0))";
    } else {
        cout << "((";
        f(n - 1);
        stringstream ss;
        ss << n;
        string s = ss.str();
        cout << "|((A" + s + "|A" + s + ")|(B" + s + "|B" + s + ")))|(A" + s + "|B" + s + "))";
    }
}

int main() {
    int n;
    cin >> n;
    f(n - 1);

    return 0;
}