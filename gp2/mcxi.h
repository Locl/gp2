#ifndef GP2_MCXI_H
#define GP2_MCXI_H

#include <string>

namespace gp2{
	class Mcxi{
	private:
		int mcxi;
		static const int MCXIMAX = 4;
		static const int MULMCXI[MCXIMAX];
		static const char CHARMCXI[MCXIMAX];
	public:
		void SetMcxi(const std::string&);
		std::string GetMcxi() const;
		Mcxi operator+(const Mcxi&);
		Mcxi& operator+=(const Mcxi&);
		Mcxi(const std::string&);
		Mcxi();
		~Mcxi();
	};
}

#endif //GP2_MCXI_H