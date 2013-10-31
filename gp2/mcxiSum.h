#ifndef GP2_MCXISUM_H
#define GP2_MCXISUM_H

#include"mcxi.h"
#include<iostream>

namespace gp2{
	class McxiSum{
	private:
		int sumRepNum;
	public:
		void Start();
		McxiSum();
		McxiSum(int);
		~McxiSum();
	};
}

#endif //GP2_MCXISUM_H