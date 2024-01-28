#include <iostream>
#include <vector>
#include <algorithm>
#include <climits> // Include for INT_MAX
#include <set>     // Include for set
using namespace std;

bool isValid(const vector<int>& a, const vector<int>& b) {
    for (int i = 0; i < b.size(); ++i) {
        if (a[i] + a[i + 1] != b[i]) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
cin.tie(nullptr);
freopen("photo.in", "r", stdin);
freopen("photo.out", "w", stdout);

    int N;
    cin >> N;
    vector<int> b(N - 1);
    for (int i = 0; i < N - 1; ++i) {
        cin >> b[i];
    }

    vector<int> a(N), ans(N, INT_MAX);
    for (int start = 1; start <= N; ++start) {
        a[0] = start;
        set<int> used{start};
        bool valid = true;

        for (int i = 1; i < N; ++i) {
            a[i] = b[i - 1] - a[i - 1];
            if (a[i] < 1 || a[i] > N || used.count(a[i])) {
                valid = false;
                break;
            }
            used.insert(a[i]);
        }

        if (valid && isValid(a, b)) {
            ans = min(ans, a);
        }
    }

    for (int i = 0; i < N; ++i) {
        cout << ans[i] << (i < N - 1 ? ' ' : '\n');
    }

    return 0;
}
