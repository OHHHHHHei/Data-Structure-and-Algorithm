#include <stdio.h>
#include <stdlib.h>

long sum_of_factorials(int n) {
    long sum = 0;  // 最终的总和
    long fact = 1; // 用来在循环中计算当前的 i!

    for (int i = 1; i <= n; i++) {
        fact = fact * i;  // fact 现在等于 i!
        sum = sum + fact; // 将 i! 累加到总和中
    }
    return sum;
}