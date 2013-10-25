#include"pos.h";

namespace gp2{
	pos::pos(int x, int y){
		this->x = x;
		this->y = y;
	}
	pos::pos(){
		x = -1;
		y = -1;
	}
	pos::~pos(){
	}
	void pos::setpos(int x, int y){
		this->x = x;
		this->y = y;
	}
	void pos::getpos(int& x, int& y){
		x = this->x;
		y = this->y;
	}
	int pos::getx(){
		return x;
	}
	int pos::gety(){
		return y;
	}
}