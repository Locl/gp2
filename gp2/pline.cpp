#include "pline.h"
#include <algorithm>

namespace gp2{
	/* �܂�����\��������W�̐��̏����ݒ�
	*
	*  @param num �ݒ肷��l
	*/
	void pLine::setPointNum(unsigned int num){
		// �܂�����\��������W�̐��̏�����������Ȃ��ꍇ
		if(num < POINTNUM_MIN || POINTNUM_MAX < num)
			throw std::runtime_error("PointNum range error");
		this->pointNum = num;
	}

	/* �܂���ɍ��W��ǉ�
	*
	*  @param point �ǉ�������W
	*/
	void pLine::addPoint(pos point){
		// �܂�����\��������W�̐��̏�����ݒ肳��Ă��Ȃ��ꍇ
		if(this->pointNum == 0)throw std::runtime_error("PointNum not set");
		// �܂�����\��������W�̐�������𒴂����ꍇ
		if(this->point.size() >= this->pointNum)throw std::runtime_error("Point over set");
		this->point.push_back(point);
	}

	/* �܂�����\��������W�̐��̏�����擾
	*
	*  @return �܂�����\��������W�̐��̏��
	*/
	int pLine::getPointNum(){
		return pointNum;
	}

	/* �܂�����\��������W�����ׂĎ擾
	*
	*  @return �܂�����\��������W
	*/
	std::vector<pos> pLine::getPoint(){
		return point;
	}

	/*`�܂�����\��������W�̏��ԂƐ����𔽓]
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