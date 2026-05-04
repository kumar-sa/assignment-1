 #include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    int n = s.length();

    // Make string circular
    string doubled = s + s;

    unordered_set<char> st;

    int left = 0;
    int sum = 0, maxSum = 0;

    for (int right = 0; right < 2 * n; right++) {
        char ch = doubled[right];
        int val = ch - 'a' + 1;

        // Remove duplicates or extra length
        while (st.count(ch) || (right - left + 1) > n) {
            char leftChar = doubled[left];
            sum -= (leftChar - 'a' + 1);
            st.erase(leftChar);
            left++;
        }

        st.insert(ch);
        sum += val;

        maxSum = max(maxSum, sum);
    }

    cout << maxSum << endl;

    return 0;
}
