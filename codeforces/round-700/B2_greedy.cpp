//
// Created by Junjie Wu on 2021/2/17.
//
#include <bits/stdc++.h>

const int MAX_N = 1e5 + 10;

int n;
int a[MAX_N];
int nxt[MAX_N], now[MAX_N];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", a + i);
        now[i] = n + 1;
    }

    for (int i = n; i; --i) {
        nxt[i] = now[a[i]];
        now[a[i]] = i;
    }
    nxt[0] = nxt[n + 1] = n + 1;

    int X = 0, Xi = 0, Y = 0, Yi = 0, ans = n;
    for (int i = 1; i <= n; ++i) {
        if (X == Y) {
            ans -= X == a[i];
            X = a[i];
            Xi = i;
        } else if (X == a[i]) {
            --ans;
        } else if (Y == a[i]) {
            --ans;
        } else {
            while (nxt[Xi] < i) Xi = nxt[Xi];
            while (nxt[Yi] < i) Yi = nxt[Yi];
            if (nxt[Xi] < nxt[Yi]) {
                Y = a[i];
                Yi = i;
            } else {
                X = a[i];
                Xi = i;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
