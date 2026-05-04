#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long long> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    long long k;
    cin >> k;

    // Step 1: Sort array
    sort(arr.begin(), arr.end());

    // Step 2: Choose median
    long long median = arr[n / 2];

    long long operations = 0;

    // Step 3: Calculate operations
    for (int i = 0; i < n; i++) {
        long long diff = abs(arr[i] - median);

        // If not divisible by k ? impossible
        if (diff % k != 0) {
            cout << -1 << endl;
            return 0;
        }

        operations += diff / k;
    }

    cout << operations << endl;

    return 0;
}
