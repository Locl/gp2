#ifndef GP2_PRIME_H
#define GP2_PRIME_H

/* ------------------------------------------------------------------------- */
/*
 *  nth_prime
 *
 *  与えられた正整数 a と d と n に対して、この等差数列に含まれる n 番目の
 *  素数を返します。
 *
 *  TODO: この nth_prime 関数を実装して下さい。必要であれば他に関数や
 *  ファイルを作成しても構いません。
 */
 /* ------------------------------------------------------------------------- */
int nth_prime(unsigned int a, unsigned int d, unsigned int n);

int nth_not_prime(unsigned int a, unsigned int d, unsigned int n);

int gcd(unsigned int m, unsigned int n);

#endif