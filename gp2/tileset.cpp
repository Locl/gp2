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
			checkCharactor(tile_line[i],i);
			room[i][linenum] = tile_line[i];
		}

		linenum++;
	}

	void tileset::checkCharactor(char c,int x){
		// 正しくない文字がある場合
		if(!(c==RTILE||c==BTILE||c==MAN)){
			throw std::runtime_error("charactor error");
		}
		if(c == MAN){
			// 複数@がある場合
			if(man_pos.getx() >= 0){
				throw std::runtime_error("multi men error");
			}
			man_pos.setpos(x, linenum);	
			//std::cout << "man_pos set(" << man_pos.getx() << ","
			//	<< man_pos.gety() << ")" << std::endl;
		}
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
			lookAhead(searchlist,reached,x,y-1);
			// 右
			lookAhead(searchlist,reached,x+1,y);
			// 下
			lookAhead(searchlist,reached,x,y+1);
			// 左
			lookAhead(searchlist,reached,x-1,y);
		}
	}

	void tileset::lookAhead(std::stack<pos>& searchlist,bool reached[CMAX][RMAX],int x,int y){
		if(x >= 0 && x < column && y >= 0 && y < row){
			if(room[x][y] == BTILE && reached[x][y] == false){
				pos* temp = new pos(x, y);
				searchlist.push(*temp);
				reached[x][y] = true;
				//std::cout << "searchlist push" << std::endl;
				delete temp;
			}
		}
	}

	int tileset::reachable_count() const{
		return reachabletiles;
	}
}