// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int main() {
ios::sync_with_stdio(false);
cin.tie(nullptr);
freopen("mixmilk.in", "r", stdin);
freopen("mixmilk.out", "w", stdout);
	vector<pair<int, int>> buckets(3);
	for (int i=0; i<3; i++) {
		int a, b;
		cin >> a >> b;
		buckets[i].first = a;
		buckets[i].second = b;
	}
	for (int i = 0; i<3; i++) {	
			int a = buckets[i].second;
			int b = buckets[i-1].second;
			if (a+b > buckets[i].first) {
				buckets[i].second = buckets[i].first;
				buckets[i-1].second = max(0, a+b-buckets[i].first);
			}
			else {
				buckets[i].second = a+b;
				buckets[i-1].second = 0;
			}
		}
	int a = buckets[0].second;
	int b = buckets[1].second;
	int c = buckets[2].second;
	if (c+a > buckets[0].first) {
		buckets[0].second = buckets[0].first;
		buckets[2].second = max(0, c+a-buckets[0].first);
	}
	else {
		buckets[0].second = c+a;
		buckets[2].second = 0;
	}
	int d = buckets[0].second;
	int e = buckets[1].second;
	int f = buckets[2].second;
	if(d+e > buckets[1].first) {
		buckets[1].second = buckets[1].first;
		buckets[0].second = max(0, d+e-buckets[1].first);
	}
	else {
		buckets[1].second = d+e;
		buckets[0].second = 0;
	}

	for (int i=0; i<3; i++) {
		cout << buckets[i].second << "\n";
	}
	return 0;
}
