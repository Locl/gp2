#include "prime.h"
#include <iostream>

using namespace std;

int nth_prime(unsigned int a, unsigned int d, unsigned int n){
	unsigned int m=0;
	for(unsigned int i = 0;; i += d){
		bool flag = true;
		if(a+i < 2)flag=false;
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

int nth_not_prime(unsigned int a, unsigned int d, unsigned int n){
	unsigned int m=0;

	if(gcd(a,d)==1)return -2;

	for(unsigned int i = 0;; i += d){
		bool flag = false;
		if(a+i < 2)flag=true;
		for(unsigned int j = 2; j < (a+i)/2; j++){
			if((a+i)%j == 0){
				flag = true;
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

int gcd(unsigned int m, unsigned int n){
	int tmp;

	if(m<n){
		tmp = m;
		m = n;
		n = tmp;
	}
	while(true){
		if(n==0)return m;
		tmp = n;
		n = m%n;
		m = tmp;
	}
}