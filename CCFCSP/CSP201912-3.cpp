#include <cstdio>
#include <cstring>

using namespace std;

char str[1005];

int nums[27][27];

void elementSingle(int l, int r, int left, int coef, int coef2) {
    if (l > r) return;
    int e1, e2 = 0;
    e1 = str[l] - 'A' + 1;  // [1,26]
    if (l < r && !(str[l + 1] >= '0' && str[l + 1] <= '9')) e2 = str[l + 1] - 'a' + 1;
    int mid = l + 1;
    if (e2 != 0) ++mid;
    int co = 0;
    while (mid <= r) co = co * 10 + str[mid++] - '0';
    if (co == 0) co = 1;
    nums[e1][e2] += left * coef * coef2 * co;
}

void element(int l, int r, int left, int coef, int coef2) {
    if (l > r) return;
    // printf("%d %d %d ", left, coef, coef2);
    // for (int i = l; i <= r; ++i) printf("%c", str[i]); printf("\n");
    int mid = l + 1;
    for (; mid <= r && !(str[mid] >= 'A' && str[mid] <= 'Z'); ++mid);
    if (mid <= r) {
        elementSingle(l, mid - 1, left, coef, coef2);
        element(mid, r, left, coef, coef2);
    } else elementSingle(l, r, left, coef, coef2);
}

void formula(int l, int r, int left, int coef, int coef2) {
    if (l > r) return;
    int lb = -1, rb = -1, lmore = 0;
    for (int i = l; i <= r; ++i) {
        if (str[i] == '(') {
            ++lmore;
            if (lb == -1) lb = i;
        }
        if (str[i] == ')') {
            --lmore;
            if (lmore == 0 && rb == -1) rb = i;
        }
        if (rb != -1) break;
    }
    if (rb == -1) element(l, r, left, coef, coef2); else {
        int co = 0, mid = rb + 1;
        for (; mid <= r && str[mid] >= '0' && str[mid] <= '9'; ++mid) co = co * 10 + str[mid] - '0';
        if (co == 0) co = 1;
        element(l, lb - 1, left, coef, coef2);
        formula(lb + 1, rb - 1, left, coef, coef2 * co);
        formula(mid, r, left, coef, coef2);
    }
}

void exprSingle(int l, int r, int left) {
    if (l > r) return;
    int coef = 0, mid = l;
    for (; mid <= r && str[mid] >= '0' && str[mid] <= '9'; ++mid) coef = coef * 10 + str[mid] - '0';
    if (coef == 0) coef = 1;
    formula(mid, r, left, coef, 1);
}

void expr(int l, int r, int left) {
    if (l > r) return;
    int mid = l;
    for (; mid <= r && str[mid] != '+'; ++mid);
    if (mid <= r) {
        exprSingle(l, mid - 1, left);
        expr(mid + 1, r, left);
    } else exprSingle(l, r, left);
}

// [l,r]
void equation(int l, int r) {
    if (l > r) return;
    int mid = l;
    for (; str[mid] != '='; ++mid);
    expr(l, mid - 1, 1);
    expr(mid + 1, r, -1);
}

int main() {
    int n;
    scanf("%d", &n);
    for (int _ = 0; _ < n; ++_) {
        scanf("%s", str);
        memset(nums, 0, sizeof(nums));
        equation(0, strlen(str) - 1);
        bool flag = true;
        for (int i = 1; i <= 26; ++i) {
            for (int j = 0; j <= 26; ++j) {
                if (nums[i][j] != 0)
                    flag = false;
            }
        }
        if (flag) printf("Y\n");
        else printf("N\n");
    }
    return 0;
}
