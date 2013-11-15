#include"mcxi.h"

namespace gp2{
	
	/** MCXI�������ݒ肷��B
	* ������string�ŗ^���邱�Ƃō\������͂��A
	* ������MCXI������ł���Γ�����MCXI�l�Ƃ��Ċi�[����B
	* MCXI�\���ɊԈႢ������Η�O�𔭐�����B
	* @param const std::string& s �ݒ肷��MCXI������
	*/
	void Mcxi::SetMcxi(const std::string& s){
		const int DEFFREENUM = 1;
		int lastChar = MULMCXI[0] + 1;
		int freeNum = DEFFREENUM;
		bool validChar;
		mcxi = 0;

		for(int i = 0; s.size() > (unsigned)i; i++){
			if(s.at(i) >= '2' && s.at(i) <= '9'){
				if(freeNum == DEFFREENUM){
					freeNum = s.at(i) - 0x30;
					continue;
				}
				else{
					throw "Sintax error:Continuous number";
				}
			}
			validChar = false;
			for(int j = 0; j < MCXIMAX; j++){
				if(s.at(i) == CHARMCXI[j]){
					if(lastChar > MULMCXI[j]){
						mcxi += MULMCXI[j] * freeNum;
						freeNum = DEFFREENUM;
						lastChar = MULMCXI[j];
						validChar = true;
						break;
					}
					else{
						throw "Sintax error:Invalid " + CHARMCXI[j];
					}
				}
			}
			if(validChar == false){
				throw "Sintax error:Invalid charactor";
			}
		}

		if(freeNum != DEFFREENUM){
			throw "Sintax error:Last charactor is number";
		}
	}

	/** string�^�Ƃ���MCXI��������o�͂���B
	* �����Ɋi�[����Ă���MCXI�l��
	* MCXI������ŕ\���ł��Ȃ��ꍇ�A��O�𔭐�������B
	* @return MCXI������
	*/
	std::string Mcxi::GetMcxi() const{
		std::string mcxiString = "";
		int testMcxi;
		
		if(mcxi > 9999 || mcxi < 0){
			throw "mcxi out of range";
		}

		for(int i = 0; i < MCXIMAX; i++){
			testMcxi = mcxi / MULMCXI[i] % 10;
			if(testMcxi >= 2){
				mcxiString += (char)(testMcxi + 0x30);
			}
			if(testMcxi > 0){
				mcxiString += CHARMCXI[i];
			}
		}

		if(mcxiString == ""){
			throw "mcxi not set";
		}

		return mcxiString;
	}

	
	Mcxi Mcxi::operator+(const Mcxi& obj){
		Mcxi tmp;
		tmp.mcxi = this->mcxi + obj.mcxi;
		return tmp;
	}

	Mcxi& Mcxi::operator+=(const Mcxi& obj){
		this->mcxi += obj.mcxi;
		return *this;
	}

	Mcxi::Mcxi(const std::string& s){
		mcxi = 0;
		SetMcxi(s);
	}

	Mcxi::Mcxi(){
		mcxi = 0;
	}

	Mcxi::~Mcxi(){
	}
	
	const int Mcxi::MULMCXI[] = {
		1000, 100, 10, 1
	};

	const char Mcxi::CHARMCXI[] = {
		'm', 'c', 'x', 'i'
	};
}