// copyright
#include<iostream>
#include<vector>

// DP[val] = 現在の値がvalの時の、差の二乗和の最小値
int main() {
    while (true) {
        int64_t n, m;
        std::cin >> n >> m;

        if (n == 0 && m == 0) {
            break;
        }

        std::vector<int64_t> C(m, 0);
        for (int64_t i = 0; i < m; i++) {
            std::cin >> C[i];
        }

        std::vector<int64_t> x_list(n, 0);
        for (int64_t i = 0; i < n; i++) {
            std::cin >> x_list[i];
        }

        int64_t inf = 2147483647;
        std::vector<int64_t> DP(256, inf);
        DP[128] = 0;

        for (auto x : x_list) {
            std::vector<int64_t> new_DP(256, inf);
            for (int64_t pre_val = 0; pre_val < 256; pre_val++) {
                if (DP[pre_val] == inf) {
                    continue;
                }
                for (auto c : C) {
                    int64_t cur_val = c+pre_val;
                    if (cur_val > 255) {
                        cur_val = 255;
                    }
                    if (cur_val < 0) {
                        cur_val = 0;
                    }
                    // cur_val = std::min(cur_val, 255);
                    // cur_val = std::max(cur_val, 0);
                    new_DP[cur_val] = std::min(
                                    new_DP[cur_val],
                                    DP[pre_val] + (x-cur_val)*(x-cur_val));
                }
            }
            for (int64_t val = 0; val < 256; val++) {
                DP[val] = new_DP[val];
            }
        }

        int64_t ans = inf;
        for (int64_t val = 0; val < 256; val++) {
            ans = std::min(ans, DP[val]);
        }
        std::cout << ans << std::endl;
    }
    return 0;
}
