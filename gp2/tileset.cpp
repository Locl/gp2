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
		// 行数が超過している場合
		if(this->row <= linenum){
			throw std::runtime_error("row error");
		}

		// 先頭から順に行の内容を走査
		for(int i = 0; tile_line[i]!='\0'; i++){
			// 文字数が多すぎる場合
			if(column <= i){
				throw std::runtime_error("column error");
			}
			// 正しくない文字がある場合
			if(!(tile_line[i]==RTILE||tile_line[i]==BTILE||tile_line[i]==MAN)){
				throw std::runtime_error("charactor error");
			}
			if(tile_line[i] == MAN){
				// 複数@がある場合
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
		// @がない場合
		if(man_pos.getx() < 0){
			throw std::runtime_error("no exist man error");
		}
		bool reached[CMAX][RMAX];
		reachabletiles = 0;

		for(int i = 0; i < column; i++){
			for(int j = 0; j < row; j++){
				reached[i][j] = false;
			}
		}
		searchProcess(reached);
	}

	void tileset::searchProcess(bool reached[CMAX][RMAX]){
		// スタックに初期値として@の座標を格納
		std::stack<pos> searchlist;
		searchlist.push(man_pos);
		while(!searchlist.empty()){
			int x = searchlist.top().getx();
			int y = searchlist.top().gety();
			searchlist.pop();
			reached[x][y] = true;
			reachabletiles++;
			// 各方向について到達可能であるかを判断し、
			// 到達可能かつ未発見の座標ならその座標をスタックに格納し、
			// 到達済みであるという印をつける

			// 上
			if(y-1 >= 0){
				if(room[x][y-1] == BTILE && reached[x][y-1] == false){
					pos* temp = new pos(x, y-1);
					searchlist.push(*temp);
					reached[x][y-1] = true;
					delete temp;
				}
			}
			// 右
			if(x+1 < column){
				if(room[x+1][y] == BTILE && reached[x+1][y] == false){
					pos* temp = new pos(x+1, y);
					searchlist.push(*temp);
					reached[x+1][y] = true;
					delete temp;
				}
			}
			// 下
			if(y+1 < row){
				if(room[x][y+1] == BTILE && reached[x][y+1] == false){
					pos* temp = new pos(x, y+1);
					searchlist.push(*temp);
					reached[x][y+1] = true;
					delete temp;
				}
			}
			// 左
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