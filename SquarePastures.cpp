#include <bits/stdc++.h>
#include <cmath>
#undef max  // Add this line to undefine the max macro
using namespace std;

int main() {
    int a, b, c, d, e, f, g, h;
    cin >> a >> b >> c >> d >> e >> f >> g >> h;
    int length = max({a, c, e, g}) - min({a, c, e, g});
    int width = max({b, d, f, h}) - min({b, d, f, h});
    if (pow(length, 2) > pow(width, 2)) {
        cout << pow(length, 2);
    }
    else {
        cout << pow(width, 2);
    }
}
