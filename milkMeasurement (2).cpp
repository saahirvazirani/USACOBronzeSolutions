#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
using namespace std;

int main() {
ios::sync_with_stdio(false);
cin.tie(nullptr);
freopen("measurement.in", "r", stdin);
freopen("measurement.out", "w", stdout);
	vector<pair<int, int>> buckets(3);
    int N;
    cin >> N;

    vector<pair<int, pair<string, int>>> logs(N);
    for (int i = 0; i < N; i++) {
        cin >> logs[i].first >> logs[i].second.first >> logs[i].second.second;
    }

    // Sort the logs by day
    sort(logs.begin(), logs.end());

    map<string, int> milkOutput;
    set<string> currentLeaders;
    int displayChanges = 0;

    // Initialize milk output for all cows to 7 gallons
    for (auto &log : logs) {
        milkOutput[log.second.first] = 7;
    }
    for (auto &cow : milkOutput) {
        currentLeaders.insert(cow.first);
    }

    for (auto &log : logs) {
        // Update milk output
        milkOutput[log.second.first] += log.second.second;

        // Find current leaders
        set<string> newLeaders;
        int maxOutput = 0;
        for (auto &cow : milkOutput) {
            if (cow.second > maxOutput) {
                newLeaders.clear();
                maxOutput = cow.second;
            }
            if (cow.second == maxOutput) {
                newLeaders.insert(cow.first);
            }
        }

        // Compare with previous leaders
        if (newLeaders != currentLeaders) {
            displayChanges++;
            currentLeaders = newLeaders;
        }
    }

    cout << displayChanges << endl;
    return 0;
}

