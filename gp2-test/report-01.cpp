#include "../gp2/mcxi.h"
#include <iostream>
#include <queue>

int main(){
	int repeatNum;
	std::queue<gp2::Mcxi> ans;

	std::cin >> repeatNum;

	for(int i = 0; i < repeatNum; i++){
		gp2::Mcxi a,b;
		std::string s;

		std::cin >> s;
		a.SetMcxi(s);
		std::cin >> s;
		b.SetMcxi(s);
		ans.push(a + b);
	}

	for(int i = 0; i < repeatNum; i++){
		std::cout << ans.front().GetMcxi() << std::endl;
		ans.pop();
	}

	return 0;
}