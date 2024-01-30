#include <iostream>
#include <vector>
using namespace std;

void processCurrentLocation(int& power, int& direction, int& brokenTargets, vector<int>& qi, vector<int>& vi, vector<bool>& broken, int S) {
    if (qi[S] == 1 && power >= vi[S] && !broken[S]) {
        brokenTargets++;
        broken[S] = true;
    }
    else if (qi[S] == 0) {
        power += vi[S];
        direction *= -1; // Change direction
    }
}

int main() {
    int N, S;
    cin >> N >> S;

    vector<int> qi(N + 1), vi(N + 1);
    vector<bool> broken(N + 1, false); // Track broken targets
    for (int i = 1; i <= N; ++i) {
        cin >> qi[i] >> vi[i];
    }

    int power = 1, direction = 1, brokenTargets = 0;
    
    // Process initial location
    processCurrentLocation(power, direction, brokenTargets, qi, vi, broken, S);

    while (true) {
        int nextPosition = S + direction * power;

        // Check if Bessie leaves the number line
        if (nextPosition < 1 || nextPosition > N) break;

        S = nextPosition;
        processCurrentLocation(power, direction, brokenTargets, qi, vi, broken, S);
    }

    cout << brokenTargets << endl;
    return 0;
}
