def main():
    v, a, b, c = map(int, input().split())

    while True:
        v -= a
        if v < 0:
            print('F')
            return
        v -= b
        if v < 0:
            print('M')
            return
        v -= c
        if v < 0:
            print('T')
            return


main()
