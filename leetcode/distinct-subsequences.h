/*
Given a string S and a string T, count the number of distinct subsequences of T in S.

A subsequence of a string is a new string which is formed from the original string by deleting some 
(can be none) of the characters without disturbing the relative positions of the remaining characters. 
(ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).

Here is an example:
S = "rabbbit", T = "rabbit"

Return 3.

Note:
DP alorgithm explaination, from [http://stackoverflow.com/questions/20459262/distinct-subsequences-dp-explanation]
using postfix. (we also can use prefix to slove this problem)

First, try to solve the problem yourself to come up with a naive implementation:

Let's say that S.length = m and T.length = n. Let's write S{i} for the substring of S starting at i. 
For example, if S = "abcde", S{0} = "abcde", S{4} = "e", and S{5} = "". We use a similar definition for T.

Let N[i][j] be the distinct subsequences for S{i} and T{j}. 
We are interested in N[0][0] (because those are both full strings).

There are two easy cases: N[i][n] for any i and N[m][j] for j<n. 
How many subsequences are there for "" in some string S? Exactly 1. How many for some T in ""? Only 0.

Now, given some arbitrary i and j, we need to find a recursive formula. There are two cases.

If S[i] != T[j], we know that N[i][j] = N[i+1][j] (I hope you can verify this for yourself, 
I aim to explain the cryptic algorithm above in detail, not this naive version).

If S[i] = T[j], we have a choice. 
We can either 'match' these characters and go on with the next characters of both S and T, 
or we can ignore the match (as in the case that S[i] != T[j]). Since we have both choices, 
we need to add the counts there: N[i][j] = N[i+1][j] + N[i+1][j+1].

In order to find N[0][0] using dynamic programming, we need to fill the N table. 
We first need to set the boundary of the table:

N[m][j] = 0, for 0 <= j < n
N[i][n] = 1, for 0 <= i <= m
Because of the dependencies in the recursive relation, 
we can fill the rest of the table looping i backwards and j forwards:

for (int i = m-1; i >= 0; i--) {
    for (int j = 0; j < n; j++) {
        if (S[i] == T[j]) {
            N[i][j] = N[i+1][j] + N[i+1][j+1];
        } else {
            N[i][j] = N[i+1][j];
        }
    }
}
We can now use the most important trick of the algorithm: we can use a 1-dimensional array f, 
with the invariant in the outer loop: f = N[i+1]; This is possible because of the way the table is filled. 
If we apply this to my algorithm, this gives:

f[j] = 0, for 0 <= j < n
f[n] = 1

for (int i = m-1; i >= 0; i--) {
    for (int j = 0; j < n; j++) {
        if (S[i] == T[j]) {
            f[j] = f[j] + f[j+1];
        } else {
            f[j] = f[j];
        }
    }
}
We're almost at the algorithm you gave. First of all, we don't need to initialize f[j] = 0. 
Second, we don't need assignments of the type f[j] = f[j].

Since this is C++ code, we can rewrite the snippet

if (S[i] == T[j]) {
    f[j] += f[j+1];
}
to

f[j] += (S[i] == T[j]) * f[j+1];
and that's all. This yields the algorithm:

f[n] = 1

for (int i = m-1; i >= 0; i--) {
    for (int j = 0; j < n; j++) {
        f[j] += (S[i] == T[j]) * f[j+1];
    }
}

*/

class Solution {
public:
    int numDistinct(string S, string T) {
        int m = S.length(), n = T.length();
        vector<int> match(n+1, 0);
        match[n] = 1;
        for (int i = m-1; i >= 0; i--) {
            for (int j = 0; j < n; j++) {
                if (m-i < n-j) continue;
                match[j] += (S[i]==T[j]) * match[j+1];
            }
        }
        return match[0];
    }
};