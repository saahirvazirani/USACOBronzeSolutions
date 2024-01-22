// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int main() {
ios::sync_with_stdio(false);
cin.tie(nullptr);
freopen("cowqueue.in", "r", stdin);
freopen("cowqueue.out", "w", stdout);
	int n; cin >> n; 
	vector<pair<int, int>> cows;
	for (int i = 0; i < n; i++) {
		int a, b; cin >> a >> b;
		cows.push_back({a, b});
	}
	sort(cows.begin(), cows.end());
	int time = 0;
	time += cows[0].first;
	time += cows[0].second;
	for (int i = 1; i < n; i++) {
		if (cows[i].first > time){ 
			time += cows[i].first - time;
			time += cows[i].second;
		}
		else if (cows[i].first <= time) {
			time += cows[i].second;
		}
	}
	cout << time << endl;
	return 0;
}
