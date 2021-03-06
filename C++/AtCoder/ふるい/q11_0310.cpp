// copyright
#include<iostream>
#include<vector>
#include<string>

std::string roman(int n) {
    std::vector<std::pair<int, std::string>> roman_list = {
        {1000, "M"},
        {900, "CM"},
        {500, "D"},
        {400, "CD"},
        {100, "C"},
        {90, "XC"},
        {50, "L"},
        {40, "XL"},
        {10, "X"},
        {9, "IX"},
        {5, "V"},
        {4, "IV"},
        {1, "I"}
    };
    std::string result = "";
    for (auto roman_pair : roman_list) {
        auto [num, str] = roman_pair;
        while (n >= num) {
            result += str;
            n -= num;
        }
    }
    return result;
}

int main() {
    int n;
    std::cin >> n;
    auto ans = roman(n);
    std::cout << ans << std::endl;
}