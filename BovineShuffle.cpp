#include <iostream>
#include <vector>
using namespace std;

int main() {
ios::sync_with_stdio(false);
cin.tie(nullptr);
freopen("shuffle.in", "r", stdin);
freopen("shuffle.out", "w", stdout);

    int N;
    cin >> N;

    vector<int> shuffle(N), cows(N), originalOrder(N);
    for (int i = 0; i < N; ++i) {
        cin >> shuffle[i];
    }
    for (int i = 0; i < N; ++i) {
        cin >> cows[i];
    }

    // Reverse-engineer the shuffle three times
    for (int s = 0; s < 3; ++s) {
        for (int i = 0; i < N; ++i) {
            // Find the position that led to the current position
            int position = -1;
            for (int j = 0; j < N; ++j) {
                if (shuffle[j] == i + 1) {
                    position = j;
                    break;
                }
            }
            originalOrder[position] = cows[i];
        }
        cows = originalOrder; // Update the cow order for the next iteration
    }

    // Output the original order of cows
    for (int i = 0; i < N; ++i) {
        cout << originalOrder[i] << endl;
    }

    return 0;
}
