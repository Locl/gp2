#ifndef GP2_POS_H
#define GP2_POS_H

namespace gp2 {
	class pos {
	private:
		int x;
		int y;
	public:
		explicit pos(int x, int y);
		pos();
		~pos();
		void setpos(int x, int y);
		void getpos(int& x, int& y);
		int getx();
		int gety();
	};
}

#endif //GP2_POS_H