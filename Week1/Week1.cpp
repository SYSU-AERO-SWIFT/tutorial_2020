#include<iostream>
#include<vector>
using namespace std;
string longestPalindrome(string s) {
    int n = s.size();
    string res;
    vector<vector<int>>dp(n, vector<int>(n, 0));
    for (int len = 1; len <= n; len++) {
        for (int i = 0; i + len - 1 < n; i++) {
            int j = len - 1;
            if (len == 1) {
                dp[i][i] = 1;
            }
            else if (len == 2) {
                dp[i][i + j] = (s[i] == s[i + j]) ? 2 : 0;
            }
            else {
                dp[i][i + j] = (s[i] == s[i + j]) * (dp[i + 1][i + j - 1]);
            }

            if (len > res.length() && dp[i][i + j]) {
                res = s.substr(i, len);
            }
        }

    }
    return res;
}