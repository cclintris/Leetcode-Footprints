#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * I: s = "aa", p = "a"
 * O: false
 * Explanation: "a" does not match the entire string "aa".
 *
 * I: s = "aa", p = "*"
 * O: true
 * Explanation: '*' matches any sequence.
 *
 * I: s = "cb", p = "?a"
 * O: false
 * Explanation: '?' matches 'c', but the second letter is 'a', which does not match 'b'.
 */

bool isMatch(char *s, char *p);

int main(int argc, char const *argv[]) {
    char *s = "cb";
    char *p = "?a";
    printf("%d\n", isMatch(s, p));
    return 0;
}

/*
s = xaylmz, p = x?y*z

    0 1 2 3 4 5
      x ? y * z
0   T F F F F F
1 x F T F F F F
2 a F F T F F F
3 y F F F T T F
4 l F F F F T F
5 m F F F F T F
6 z F F F F T T
*/

bool isMatch(char *s, char *p) {
    int sL = strlen(s), sP = strlen(p);
    bool dp[sL + 1][sP + 1];
    memset(dp, false, sizeof(bool) * ((sL + 1) * (sP + 1)));
    dp[0][0] = true;
    for (int i = 1; i <= sP; i++) {
        if (p[i - 1] == '*')
            dp[0][i] = dp[0][i - 1];
    }
    for (int i = 1; i <= sL; i++) {
        for (int j = 1; j <= sP; j++) {
            if ((s[i - 1] == p[j - 1] || p[j - 1] == '?') && dp[i - 1][j - 1])
                dp[i][j] = true;
            else if (p[j - 1] == '*' && (dp[i][j - 1] || dp[i - 1][j]))
                dp[i][j] = true;
        }
    }

    return dp[sL][sP];
}
