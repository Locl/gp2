#include"mcxiSum.h"

namespace gp2{
	void McxiSum::Start(){
		if(sumRepNum == 0){
			std::cin >> sumRepNum;
		}
		for(int i = 0; i < sumRepNum; i++){
			Mcxi a,b;
			std::string s;

			std::cin >> s;
			a.SetMcxi(s);
			std::cin >> s;
			b.SetMcxi(s);
			a += b;

			std::cout << a.GetMcxi() << std::endl;
		}
	}

	McxiSum::McxiSum(){
		sumRepNum = 0;
	}

	McxiSum::McxiSum(int n){
		sumRepNum = n;
		Start();
	}

	McxiSum::~McxiSum(){
	}
}