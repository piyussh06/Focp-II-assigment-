#include <bits/stdc++.h>
using namespace std;

bool canTurnOff(string &bulbs, int n, int k, int l) {
    int ops = 0;
    int i = 0;

    while (i < n) {
        if (bulbs[i] == '1') {
            ops++;
            if (ops > k) return false;
            i += l;  // skip next l bulbs
        } else {
            i++;
        }
    }
    return true;
}

int main() {
    int n, k;
    cin >> n >> k;

    string bulbs;
    cin >> bulbs;

    int left = 1, right = n;
    int answer = n;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (canTurnOff(bulbs, n, k, mid)) {
            answer = mid;
            right = mid - 1;  // try smaller l
        } else {
            left = mid + 1;   // increase l
        }
    }

    cout << answer << endl;

    return 0;
}