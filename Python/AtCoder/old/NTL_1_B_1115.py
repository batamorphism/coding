def main():
    m, n = map(int, input().split())
    mod = 10**9 + 7
    ans = pow(m, n, mod)
    print(ans)


main()
