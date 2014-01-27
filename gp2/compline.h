#ifndef GP2_COMPLINE_H
#define GP2_COMPLINE_H

#include <vector>
#include "pline.h"

namespace gp2{
	class CompLine{
	private:
		const static int PLINE_MIN = 2;
		const static int PLINE_MAX = 51;
		std::vector<pLine> pLineVector;		// ê‹ÇÍê¸ÇÃèWçá
		bool compare2PLine(pLine&,pLine&);
		bool compare2PLineR(pLine&,pLine&);
		bool compare2Point(std::vector<pos>&,std::vector<pos>&);
		void pointSpin(std::vector<pos>&);
	public:
		void addPLine(unsigned int);
		void addPLinePoint(int,int);
		std::vector<int> comparePLine();
		CompLine();
		~CompLine();
	};
}

#endif //GP2_COMPLINE_H