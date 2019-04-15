#include "algorithm.h"

void Combination(vector<vector<int>> & result, vector<int> & cur,
                int from, int n, int r) {
    if (r == 0) {
        result.push_back(cur);
        return;
    }
    if (r == n) {
        for(int i = from; i < from + r; i++) cur.push_back(i);
        result.push_back(cur);
        for(int i = from; i < from + r; i++) cur.pop_back();
        return;
    }
    cur.push_back(from);
    Combination(result, cur, from + 1, n - 1, r - 1);
    cur.pop_back();
    Combination(result, cur, from + 1, n - 1, r);
}