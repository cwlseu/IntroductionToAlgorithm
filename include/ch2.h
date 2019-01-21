#ifndef ALGORITHM_CH1_H_
#define ALGORITHM_CH1_H_
#include <util.h>
// Describe O(nlgn) time algorithm that, given a set S of n integers and another integer x, 
// determines whether or not there exist two elements in S whose sum is exactly x
bool find_target_sum(int* arr, const int size, int t_sum);

#endif
