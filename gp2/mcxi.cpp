#include"mcxi.h"
#include<stdexcept>

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
			// �����������ł��邩�𒲂ׂ�
			if(NumCheck(s.at(i),freeNum,DEFFREENUM))continue;
			validChar = false;
			// ������mcxi�̂ǂꂩ�ł��邩�𒲂ׂ�
			for(int j = 0; j < MCXIMAX; j++){
				if(CharactorCheck(s.at(i),j,freeNum,lastChar,validChar,DEFFREENUM))break;
			}
			if(validChar == false){
				throw std::runtime_error("Sintax error:Invalid charactor");
			}
		}

		if(freeNum != DEFFREENUM){
			throw std::runtime_error("Sintax error:Last charactor is number");
		}
	}

	bool Mcxi::NumCheck(char c, int& freeNum, const int DEFFREENUM){
		if(c >= '2' && c <= '9'){
			if(freeNum == DEFFREENUM){
				freeNum = c - 0x30;
				return true;
			}
			else{
				throw std::runtime_error("Sintax error:Continuous number");
			}
		}
		return false;
	}

	bool Mcxi::CharactorCheck(char c, int x, int& freeNum, int& lastChar, bool& validChar, const int DEFFREENUM){
		if(c == CHARMCXI[x]){
			if(lastChar > MULMCXI[x]){
				mcxi += MULMCXI[x] * freeNum;
				freeNum = DEFFREENUM;
				lastChar = MULMCXI[x];
				validChar = true;
				return true;
			}
			else{
				throw std::runtime_error("Sintax error:Invalid " + CHARMCXI[x]);
			}
		}
		return false;
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
			throw std::runtime_error("mcxi out of range");
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
			throw std::runtime_error("mcxi not set");
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