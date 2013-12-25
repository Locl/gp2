#include "pline.h"
#include <algorithm>

namespace gp2{
	/* 折れ線を構成する座標の数の上限を設定
	*
	*  @param num 設定する値
	*/
	void pLine::setPointNum(unsigned int num){
		// 折れ線を構成する座標の数の上限が正しくない場合
		if(num < POINTNUM_MIN || POINTNUM_MAX < num)
			throw std::runtime_error("PointNum range error");
		this->pointNum = num;
	}

	/* 折れ線に座標を追加
	*
	*  @param point 追加する座標
	*/
	void pLine::addPoint(pos point){
		// 折れ線を構成する座標の数の上限が設定されていない場合
		if(this->pointNum == 0)throw std::runtime_error("PointNum not set");
		// 折れ線を構成する座標の数が上限を超えた場合
		if(this->point.size() >= this->pointNum)throw std::runtime_error("Point over set");
		this->point.push_back(point);
	}

	/* 折れ線を構成する座標の数の上限を取得
	*
	*  @return 折れ線を構成する座標の数の上限
	*/
	int pLine::getPointNum(){
		return pointNum;
	}

	/* 折れ線を構成する座標をすべて取得
	*
	*  @return 折れ線を構成する座標
	*/
	std::vector<pos> pLine::getPoint(){
		return point;
	}

	/*`折れ線を構成する座標の順番と正負を反転
	*/
	void pLine::reversePoint(){
		std::reverse(point.begin(),point.end());
		for(std::vector<pos>::iterator it = point.begin(); it != point.end(); it++){
			it->setpos(-(it->getx()),-(it->gety()));
		}
	}

	pLine::pLine(){
		pointNum = 0;
	}

	pLine::~pLine(){
	}
}