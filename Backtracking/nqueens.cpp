#include <fstream>
#include <iostream>
#include <vector>
#define BOARD_SIZE 9

int rows[BOARD_SIZE];
int cols[BOARD_SIZE];

bool check_forwards(int row, int col){
	int tmp_row = row; 
	int tmp_col = col;
	while((row < BOARD_SIZE) && (col < BOARD_SIZE)){
		if(rows[row] == col)
			return true;
		row++;
		col++;
	}
	while((tmp_row >= 0) && (tmp_col < BOARD_SIZE)){
		if(rows[tmp_row] == tmp_col)
			return true;
		tmp_col++;
		tmp_row--;
	}
	return false;
}
bool check_backwards(int row, int col){
	int tmp_row = row; int tmp_col = col;
	while((row >= 0) && (col >= 0)){
		if(rows[row] == col)
			return true;
		row--;
		col--;
	}
	while((tmp_row < BOARD_SIZE) && (tmp_col >= 0)){
		if(rows[tmp_row] == tmp_col)
			return true;
		tmp_col--;
		tmp_row++;
	}
	return false;
}

bool attacked(int row, int col){
	if(cols[col] != -1) return true;
	if(rows[row] != -1) return true;
	return (check_backwards(row,col) || check_forwards(row,col));
}

void place(int row, int col){
	rows[row] = col;
	cols[col] = 1;
}

void remove(int row, int col){
	rows[row] = -1;
	cols[col] = -1;
}

void search(int col,int placed){
	if(placed == BOARD_SIZE){
		for(int i =0; i<BOARD_SIZE;i++){
			std::cout<<"row:"<<i<<" col:"<<rows[i]<<std::endl;
		}
	}
	for(int i =0; i<BOARD_SIZE; i++){
		for(int j = col; j<BOARD_SIZE; j++){
			if(!attacked(i,j)){
				place(i,j);
				search(col+1,placed+1);
				remove(i,j);
			}
		}
	}
}


int main(){
	for(int i =0; i<BOARD_SIZE; i++){
		rows[i] = -1;
		cols[i] = -1;
	}
	search(0,0);
	return 0;
}