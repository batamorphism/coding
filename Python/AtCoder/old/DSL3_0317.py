# スライド最小値
import heapq


def main():
    n, k = map(int, input().split())
    A = list(map(int, input().split()))

    que = []
    ans = []
    for i in reversed(range(n)):
        a_i = A[i]
        heapq.heappush(que, (a_i, i))
        while que[0][1] >= i + k:
            heapq.heappop(que)
        ans.append(que[0][0])
    ans = ans[::-1]

    print(*ans[:n-k+1])


main()
