#include "prime.h"
#include <iostream>

using namespace std;

int nth_prime(unsigned int a, unsigned int d, unsigned int n){
	unsigned int m=0;
	if(a == 1 && d == 1 && n == 1)return 2;
	for(unsigned int i = 0;; i += d){
		bool flag = true;
		for(unsigned int j = 2; j < (a+i)/2; j++){
			if((a+i)%j == 0){
				flag = false;
				break;
			}
		}
		if(flag == true){
			m++;
			if(m==n)return a+i;
		}
	}
	
	return -1;
}