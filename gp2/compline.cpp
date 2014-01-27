#include "compline.h"
#include "pos.h"

namespace gp2{
	/* �܂����ǉ�
	*
	*  @param pointNum �܂�����\��������W�̐��̏��
	*/
	void CompLine::addPLine(unsigned int pointNum){
		// �܂���̐�����������ꍇ
		if(PLINE_MAX < pLineVector.size()+1)
			throw std::runtime_error("Too many pLine num");
		pLine tmp;

		tmp.setPointNum(pointNum);
		pLineVector.push_back(tmp);
	}

	/* �܂�����\��������W��ǉ�
	*
	*  @param x �܂����x���W
	*  @param y �܂����y���W
	*/
	void CompLine::addPLinePoint(int x, int y){
		// �܂��������Ȃ��ꍇ
		if(pLineVector.empty())throw std::runtime_error("No exist pLine");
		pos tmp(x,y);

		pLineVector.back().addPoint(tmp);
	}

	/* �ŏ��̐܂���Ɠ����܂����T��
	*
	*  @return ��v�����܂���̏W��
	*/
	std::vector<int> CompLine::comparePLine(){
		// �܂���̐������Ȃ�����ꍇ
		if(pLineVector.size() < PLINE_MIN)
			throw std::runtime_error("Too few pLine num");
		std::vector<int> matchList;
		std::vector<pLine>::iterator it;
		int i;

		for(it = pLineVector.begin()+1, i = 1;
			it != pLineVector.end(); it++, i++){
				// �܂�����\��������W�̐��̏�����قȂ�ꍇ�A�����܂���ł͂Ȃ��Ɣ��f
				if(pLineVector.front().getPointNum() != it->getPointNum())
					continue;
				// �܂���̍��W��{���̏��Ԃł��ǂ����ꍇ
				// �������͋t�̏��Ԃł��ǂ����ꍇ�̂ǂ��炩��
				// ���W�Ԃ̑��ΓI�ȃx�N�g�����S�Ĉ�v�����ꍇ�͓����܂��
				if(compare2PLine(pLineVector.front(),*it)
					|| compare2PLineR(pLineVector.front(),*it)){
						matchList.push_back(i);
				}
		}
		return matchList;
	}

	/* �܂�����\��������W��{���̏��Ԃł��ǂ����ꍇ��
	*  ���ΓI�ȃx�N�g������v���邩�ǂ������`�F�b�N
	*
	*  @param pLine1 ��r���̐܂��
	*  @param pLine2 ��r��̐܂��
	*
	*  @return ���ΓI�ȃx�N�g������v�������ǂ���
	*/
	bool CompLine::compare2PLine(pLine& pLine1, pLine& pLine2){
		std::vector<pos> point1 = pLine1.getPoint();
		std::vector<pos> point2 = pLine2.getPoint();
		
		// �܂�����\��������W�̐����قȂ�ꍇ�A���ΓI�ȃx�N�g���͈�v���Ȃ�
		if(point1.size() != point2.size())return false;
		// ���v���ɐ܂����90�x����]�����Ĉ�v���邩���m�F
		for(int i = 0; i < 4; i++){
			if(compare2Point(point1,point2))return true;
			if(i < 3)pointSpin(point2);
		}
		return false;
	}

	/* �܂�����\��������W���t�̏��Ԃł��ǂ����ꍇ��
	*  ���ΓI�ȃx�N�g������v���邩�ǂ������`�F�b�N
	*
	*  @param pLine1 ��r���̐܂��
	*  @param pLine2 ��r��̐܂��
	*
	*  @return ���ΓI�ȃx�N�g������v�������ǂ���
	*/
	bool CompLine::compare2PLineR(pLine& pLine1, pLine& pLine2){
		pLine pLine2R = pLine2;
		
		pLine2R.reversePoint();

		return compare2PLine(pLine1,pLine2R);
	}

	/* ��̐܂�����\��������W�̑��ΓI�ȃx�N�g�������ׂĈ�v���邩���`�F�b�N
	*
	*  @param ��r���̐܂�����\��������W�̏W��
	*  @param ��r��̐܂�����\��������W�̏W��
	*
	*  @return �܂�����\��������W�Ԃ̃x�N�g�������ׂĈ�v�������ǂ���
	*/
	bool CompLine::compare2Point(std::vector<pos>& point1,
									std::vector<pos>& point2){
		std::vector<pos>::iterator it1,it2;

		// ���݂̍��W�Ǝ��̍��W�̊Ԃ������x�N�g�������ׂĈ�v�����
		// ���̐܂���͓����܂��
		for(it1 = point1.begin(), it2 = point2.begin();
			it1+1 != point1.end(), it2+1 != point2.end(); it1++, it2++){
				
				// ���݂̍��W�Ǝ��̍��W�̍������̓�_�Ԃ������x�N�g��
				// ��ł��x�N�g�����قȂ�ꍇ�͓����܂���Ƃ͔��f�ł��Ȃ�
				if((it1+1)->getx() - it1->getx() != (it2+1)->getx() - it2->getx()
					|| (it1+1)->gety() - it1->gety() != (it2+1)->gety() - it2->gety()){
					return false;
				}
		}

		return true;
	}

	/* �܂�������v����90�x��]����
	*
	*  @param point ��]�������܂�����\��������W�̏W��
	*/
	void CompLine::pointSpin(std::vector<pos>& point){
		for(std::vector<pos>::iterator it = point.begin(); it != point.end(); it++){
			int x = it->getx();
			int y = it->gety();

			// ���ׂĂ̍��W��x�l�̐����𔽓]���Ax�l��y�l�����ւ����
			// �܂�������v����90�x��]���������ƂɂȂ�
			it->setpos(y,-x);
		}
	}

	CompLine::CompLine(){
	}

	CompLine::~CompLine(){
	}
}