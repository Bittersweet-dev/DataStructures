#pragma once
#ifndef ALGORITHM_H
#define ALGORITHM_H

#include <vector>

/*
 * @brief 정수로 구성된 조합(Combination) 배열을 재귀적으로 작성하는 함수.
 * @details 정수로 구성된 조합(Combination) 배열을 재귀적으로 작성하는 함수이다.
 * 이 때, 조합은 from 으로부터 n 개의 정수 중 r 개를 선택한 배열들로 구성된다.
 * 수학적으로 nCr = (n-1)C(r-1) + (n-1)C(r) 임이 증명되었음을 이용한다.
 */
void Combination(vector<vector<int>> & result, vector<int> & cur,
                int from, int n, int r);


#endif