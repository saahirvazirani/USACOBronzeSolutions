#include <bits/stdc++.h>
#include <cmath>
using namespace std;

int main() {
  int b_i, b_j, l_i, l_j, r_i, r_j = 0;
	for (int i = 0; i < 10; i++) {
    string row;
    cin >> row;
    for (int j = 0; j < 10; j++) {
      if (row[j] == 'B') {
        b_i = i;
        b_j = j;
      }
      if (row[j] == 'L') {
        l_i = i;
        l_j = j;
      }
      if (row[j] == 'R') {
        r_i = i;
        r_j = j;
      }
    }
  }
    int cows = abs(b_i - l_i) + abs(b_j - l_j) -1;
    if(b_i == l_i && r_i == b_i && ((l_j < r_j && r_j < b_j) || (b_j < r_j && r_j < l_j))) {
      cows += 2;
    }
    else if(b_j == l_j && r_j == b_j && ((l_i < r_i && r_i < b_i) || (b_i < r_i && r_i < l_i))) {
      cows += 2;
    }
    cout << cows << endl;
  
	return 0;
}
