#include "tileset.h"
#include "pos.h"
#include<stack>
#include<stdexcept>
//#include<iostream>

namespace gp2{
	tileset::tileset(int column, int row){
		this->column = column;
		this->row = row;
		linenum = 0;
		for(int i = 0; i < column; i++){
			for(int j = 0; j < row; j++){
				room[i][j] = RTILE;
			}
		}
		reachabletiles = 0;
	}

	tileset::~tileset(){
	}

	void tileset::add(const std::basic_string<char>& tile_line){
		if(this->row <= linenum){
			throw std::runtime_error("row error");
		}

		for(int i = 0; tile_line[i]!='\0'; i++){
			if(column <= i){
				throw std::runtime_error("column error");
			}
			if(!(tile_line[i]==RTILE||tile_line[i]==BTILE||tile_line[i]==MAN)){
				throw std::runtime_error("charactor error");
			}
			if(tile_line[i] == MAN){
				if(man_pos.getx() >= 0){
					throw std::runtime_error("multi men error");
				}
				man_pos.setpos(i, linenum);	
				//std::cout << "man_pos set(" << man_pos.getx() << ","
				//	<< man_pos.gety() << ")" << std::endl;
			}
			room[i][linenum] = tile_line[i];
		}

		linenum++;
	}

	void tileset::calculate(){
		if(man_pos.getx() < 0){
			throw std::runtime_error("no exist man error");
		}
		bool reached[CMAX][RMAX];
		std::stack<pos> searchlist;
		reachabletiles = 0;

		for(int i = 0; i < column; i++){
			for(int j = 0; j < row; j++){
				reached[i][j] = false;
			}
		}
		searchlist.push(man_pos);
		while(!searchlist.empty()){
			int x = searchlist.top().getx();
			int y = searchlist.top().gety();
			searchlist.pop();
			reached[x][y] = true;
			reachabletiles++;
			if(y-1 >= 0){
				if(room[x][y-1] == BTILE && reached[x][y-1] == false){
					pos* temp = new pos(x, y-1);
					searchlist.push(*temp);
					reached[x][y-1] = true;
					delete temp;
				}
			}
			if(x+1 < column){
				if(room[x+1][y] == BTILE && reached[x+1][y] == false){
					pos* temp = new pos(x+1, y);
					searchlist.push(*temp);
					reached[x+1][y] = true;
					delete temp;
				}
			}
			if(y+1 < row){
				if(room[x][y+1] == BTILE && reached[x][y+1] == false){
					pos* temp = new pos(x, y+1);
					searchlist.push(*temp);
					reached[x][y+1] = true;
					delete temp;
				}
			}
			if(x-1 >= 0){
				if(room[x-1][y] == BTILE && reached[x-1][y] == false){
					pos* temp = new pos(x-1, y);
					searchlist.push(*temp);
					reached[x-1][y] = true;
					delete temp;
				}
			}
		}
	}

	int tileset::reachable_count() const{
		return reachabletiles;
	}
}