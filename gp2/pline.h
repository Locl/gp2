#ifndef GP2_PLINE_H
#define GP2_PLINE_H

#include "pos.h"
#include <vector>

namespace gp2{
	class pLine{
	private:
		const static int POINTNUM_MIN = 3;
		const static int POINTNUM_MAX = 10;
		unsigned int pointNum;				// 折れ線を構成する座標の数の上限
		std::vector<pos> point;				// 折れ線を構成する座標
	public:
		void setPointNum(unsigned int);
		void addPoint(pos);
		int getPointNum();
		std::vector<pos> getPoint();
		void reversePoint();
		pLine();
		~pLine();
	};
}

#endif //GP2_PLINE_H