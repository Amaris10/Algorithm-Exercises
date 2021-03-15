#include<iostream>
#include<iomanip>
#include<math.h>

using namespace std;

int main() {
    int p, t;
    int g1, g2, g3, g4;

    while (scanf("%d%d%d%d%d%d", &p, &t, &g1, &g2, &g3, &g4) != EOF){
        double score;
        if (abs(g1 - g2) <= t)
            score = (double) (g1 + g2) / 2;
        else {
            if (abs(g3 - g1) <= t && abs(g3 - g2) > t)
                score = (double) (g3 + g1) / 2;
            else if (abs(g3 - g2) <= t && abs(g3 - g1) > t)
                score = (double) (g3 + g2) / 2;
            else if (abs(g3 - g2) <= t && abs(g3 - g1) <= t) {
                int temp = g3 > g2 ? g3 : g2;
                score = temp > g1 ? temp : g1;
            } else score = g4;
        }
        printf("%0.1f\n", score);
    }
    return 0;
}