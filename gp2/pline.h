#ifndef GP2_PLINE_H
#define GP2_PLINE_H

#include "pos.h"
#include <vector>

namespace gp2{
	class pLine{
	private:
		const static int POINTNUM_MIN = 3;
		const static int POINTNUM_MAX = 10;
		unsigned int pointNum;				// �܂�����\��������W�̐��̏��
		std::vector<pos> point;				// �܂�����\��������W
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