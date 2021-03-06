// copyright
#include<iostream>
#include<vector>

void solve(const int& n, const std::vector<int>& w) {
    // DP[le][ri] = [le, ri)の最大スコア
    std::vector<std::vector<int>> DP(n+1, std::vector<int>(n+1, 0));

    for (int cnt = 0; cnt <= n; cnt++) {
        for (int le = 0; le <= n - cnt; le++) {
            int ri = le + cnt;
            if (cnt == 0) {
                DP[le][ri] = 0;
                continue;
            }

            // 1. leとri-1を落とす
            if (abs(w[le]-w[ri-1]) <= 1) {
                if (DP[le+1][ri-1] == cnt-2) {
                    DP[le][ri] = cnt;
                    continue;
                }
            }

            // 2. [le, sep), [sep, ri)を落とす
            for (int sep = le; sep <= ri; sep++) {
                DP[le][ri] = std::max(DP[le][ri], DP[le][sep] + DP[sep][ri]);
            }
        }
    }

    auto ans = DP[0][n];
    std::cout << ans << std::endl;
}

int main() {
    while (true) {
        int n;
        std::cin >> n;
        if (n == 0) {
            break;
        }
        std::vector<int> w(n);
        for (int i = 0; i < n; i++) {
            std::cin >> w[i];
        }

        solve(n, w);
    }
    return 0;
}