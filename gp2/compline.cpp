#include "compline.h"
#include "pos.h"

namespace gp2{
	/* 折れ線を追加
	*
	*  @param pointNum 折れ線を構成する座標の数の上限
	*/
	void CompLine::addPLine(unsigned int pointNum){
		// 折れ線の数が多すぎる場合
		if(PLINE_MAX < pLineVector.size()+1)
			throw std::runtime_error("Too many pLine num");
		pLine tmp;

		tmp.setPointNum(pointNum);
		pLineVector.push_back(tmp);
	}

	/* 折れ線を構成する座標を追加
	*
	*  @param x 折れ線のx座標
	*  @param y 折れ線のy座標
	*/
	void CompLine::addPLinePoint(int x, int y){
		// 折れ線が一つもない場合
		if(pLineVector.empty())throw std::runtime_error("No exist pLine");
		pos tmp(x,y);

		pLineVector.back().addPoint(tmp);
	}

	/* 最初の折れ線と同じ折れ線を探す
	*
	*  @return 一致した折れ線の集合
	*/
	std::vector<int> CompLine::comparePLine(){
		// 折れ線の数が少なすぎる場合
		if(pLineVector.size() < PLINE_MIN)
			throw std::runtime_error("Too few pLine num");
		std::vector<int> matchList;
		std::vector<pLine>::iterator it;
		int i;

		for(it = pLineVector.begin()+1, i = 1;
			it != pLineVector.end(); it++, i++){
				// 折れ線を構成する座標の数の上限が異なる場合、同じ折れ線ではないと判断
				if(pLineVector.front().getPointNum() != it->getPointNum())
					continue;
				// 折れ線の座標を本来の順番でたどった場合
				// もしくは逆の順番でたどった場合のどちらかの
				// 座標間の相対的なベクトルが全て一致した場合は同じ折れ線
				if(compare2PLine(pLineVector.front(),*it)
					|| compare2PLineR(pLineVector.front(),*it)){
						matchList.push_back(i);
				}
		}
		return matchList;
	}

	/* 折れ線を構成する座標を本来の順番でたどった場合に
	*  相対的なベクトルが一致するかどうかをチェック
	*
	*  @param pLine1 比較元の折れ線
	*  @param pLine2 比較先の折れ線
	*
	*  @return 相対的なベクトルが一致したかどうか
	*/
	bool CompLine::compare2PLine(pLine& pLine1, pLine& pLine2){
		std::vector<pos> point1 = pLine1.getPoint();
		std::vector<pos> point2 = pLine2.getPoint();
		
		// 折れ線を構成する座標の数が異なる場合、相対的なベクトルは一致しない
		if(point1.size() != point2.size())return false;
		// 時計回りに折れ線を90度ずつ回転させて一致するかを確認
		for(int i = 0; i < 4; i++){
			if(compare2Point(point1,point2))return true;
			if(i < 3)pointSpin(point2);
		}
		return false;
	}

	/* 折れ線を構成する座標を逆の順番でたどった場合に
	*  相対的なベクトルが一致するかどうかをチェック
	*
	*  @param pLine1 比較元の折れ線
	*  @param pLine2 比較先の折れ線
	*
	*  @return 相対的なベクトルが一致したかどうか
	*/
	bool CompLine::compare2PLineR(pLine& pLine1, pLine& pLine2){
		pLine pLine2R = pLine2;
		
		pLine2R.reversePoint();

		return compare2PLine(pLine1,pLine2R);
	}

	/* 二つの折れ線を構成する座標の相対的なベクトルがすべて一致するかをチェック
	*
	*  @param 比較元の折れ線を構成する座標の集合
	*  @param 比較先の折れ線を構成する座標の集合
	*
	*  @return 折れ線を構成する座標間のベクトルがすべて一致したかどうか
	*/
	bool CompLine::compare2Point(std::vector<pos>& point1,
									std::vector<pos>& point2){
		std::vector<pos>::iterator it1,it2;

		// 現在の座標と次の座標の間を示すベクトルがすべて一致すれば
		// その折れ線は同じ折れ線
		for(it1 = point1.begin(), it2 = point2.begin();
			it1+1 != point1.end(), it2+1 != point2.end(); it1++, it2++){
				
				// 現在の座標と次の座標の差がその二点間を示すベクトル
				// 一つでもベクトルが異なる場合は同じ折れ線とは判断できない
				if((it1+1)->getx() - it1->getx() != (it2+1)->getx() - it2->getx()
					|| (it1+1)->gety() - it1->gety() != (it2+1)->gety() - it2->gety()){
					return false;
				}
		}

		return true;
	}

	/* 折れ線を時計回りに90度回転する
	*
	*  @param point 回転したい折れ線を構成する座標の集合
	*/
	void CompLine::pointSpin(std::vector<pos>& point){
		for(std::vector<pos>::iterator it = point.begin(); it != point.end(); it++){
			int x = it->getx();
			int y = it->gety();

			// すべての座標のx値の正負を反転し、x値とy値を入れ替えると
			// 折れ線を時計回りに90度回転させたことになる
			it->setpos(y,-x);
		}
	}

	CompLine::CompLine(){
	}

	CompLine::~CompLine(){
	}
}