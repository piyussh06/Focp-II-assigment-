#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;  // number of test cases
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        // Sort in descending order
        sort(arr.begin(), arr.end(), greater<int>());

        long long alex_total = 0, bob_total = 0;
        set<int> alex_seen, bob_seen;

        for (int i = 0; i < n; i++) {
            int chocolates = arr[i];
            if (i % 2 == 0) { // Alex's turn
                if (alex_seen.count(chocolates) == 0) {
                    alex_total += chocolates;
                    alex_seen.insert(chocolates);
                }
            } else { // Bob's turn
                if (bob_seen.count(chocolates) == 0) {
                    bob_total += chocolates;
                    bob_seen.insert(chocolates);
                }
            }
        }

        if (alex_total > bob_total) {
            cout << "Alex\n";
        } else {
            cout << "Bob\n";
        }
    }

    return 0;
}
