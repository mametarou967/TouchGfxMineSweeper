#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>
#include <cstring>
#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include <chrono>
#include <algorithm>



Model::Model() : modelListener(0)
{
	gameReset();
}

void Model::tick()
{

}

int Model::getRowMax(void)
{
	return row_size;
}

int Model::getColumnMax(void)
{
	return column_size;
}

void Model::blockInit(int row , int column)
{
	Block* block;

	if(row > row_size) return;
	if(column > column_size) return;

	int row_index = row - 1;
	int column_index = column - 1;

	block = &matrix[row_index][column_index];
	block->isOpen = false;
	block->hasFlag = false;
	block->hasBomb = false;
	block->number = 0;
}


void Model::gameReset(void)
{
	firstOpened = false;
	isFlagMode = false;
	isGameEnded = false;
	// 値の初期化
    for (int row = 1; row <= row_size; ++row) {
        for (int column = 1; column <= column_size; ++column) {
        	blockInit(row,column);  // 全ての要素を0に初期化
        }
    }
}

int Model::getFlagNumber(void)
{
	int result = 0;

    for (int row = 1; row <= row_size; ++row) {
        for (int column = 1; column <= column_size; ++column) {
        	if(matrix[row-1][column-1].hasFlag) result++;
        }
    }

    return result;
}

void Model::saveCurrentBlockMatrix(void)
{
	memcpy(preMatrix,matrix,sizeof(preMatrix));
}

bool Model::diffPresentBlock(int row,int column)
{
	if(row > row_size) return false;
	if(column > column_size) return false;

	Block block = getBlock(row,column);
	Block preBlock = getPreBlock(row,column);

	if(block.isOpen != preBlock.isOpen) return true;
	if(block.hasFlag != preBlock.hasFlag) return true;
	if(block.hasBomb != preBlock.hasBomb) return true;
	if(block.number != preBlock.number) return true;

	return false;
}

Model::Block Model::getBlock(int row,int column)
{
	int row_index = row - 1;
	int column_index = column - 1;

	return matrix[row_index][column_index];
}

Model::Block Model::getPreBlock(int row,int column)
{
	int row_index = row - 1;
	int column_index = column - 1;

	return preMatrix[row_index][column_index];
}


bool Model::hasBomb(int row,int column)
{
	int row_index = row - 1;
	int column_index = column - 1;

	if(row_index < 0) return false;
	if(column_index < 0) return false;
	if(row_index >= row_size) return false;
	if(column_index >= column_size ) return false;

	if(matrix[row_index][column_index].hasBomb) return true;

	return false;
}
void Model::setNumber(int row,int column,int number)
{
	int row_index = row - 1;
	int column_index = column - 1;

	matrix[row_index][column_index].number = number;
}


bool Model::openBlock(int row,int column)
{
	bool result;
	int row_index = row - 1;
	int column_index = column - 1;

	// ゲームが終了している場合には開けない
	if(isGameEnded) return false;
	// 該当場所にフラグが立っている場合には開けない
	if(matrix[row_index][column_index].hasFlag) return false;

	// まだ開いていなければ開く
	if(matrix[row_index][column_index].isOpen)
	{
		result = false;
	}
	else
	{
		matrix[row_index][column_index].isOpen = true;

		// 開いた場所がBOMBだった場合には、プレイヤーに他のBOMBの場所も教えてあげるためにすべてのBOMNの位置を開く
		// また、状態としてはゲーム終了とする
		if(matrix[row_index][column_index].hasBomb)
		{
		    for (int row = 1; row <= row_size; ++row) {
		        for (int column = 1; column <= column_size; ++column) {
		        	if(matrix[row-1][column-1].hasBomb && !(matrix[row-1][column-1].isOpen) && !(matrix[row-1][column-1].hasFlag)){
		        		matrix[row-1][column-1].isOpen = true;
		        	}
		        }
		    }

		    isGameEnded = true;
		}


		result = true;
	}

	return result;
}

bool Model::toggleFlag(int row,int column)
{
	int row_index = row - 1;
	int column_index = column - 1;

	if(matrix[row_index][column_index].hasFlag) matrix[row_index][column_index].hasFlag = false;
	else  matrix[row_index][column_index].hasFlag = true;

	return true;
}


void Model::setBombsWithout(int row, int column)
{
    // シードをより高精度なものに変更
    std::random_device rd;
    std::mt19937 generator(rd());

    // すべての可能な位置を一度リストにする
    std::vector<int> positions(row_size * column_size);
    std::iota(positions.begin(), positions.end(), 0);

    // クリックされた位置とその周囲8マスを避ける
    for (int r = row - 1; r <= row + 1; ++r) {
        for (int c = column - 1; c <= column + 1; ++c) {
            if (r >= 1 && r <= row_size && c >= 1 && c <= column_size) {
                int index = (r - 1) * column_size + (c - 1);
                positions.erase(std::remove(positions.begin(), positions.end(), index), positions.end());
            }
        }
    }

    // リストをシャッフル
    std::shuffle(positions.begin(), positions.end(), generator);

    // 最初のbomb_number個の位置に爆弾を配置
    for (int i = 0; i < bomb_number; ++i) {
        int randomIndex = positions[i];
        int row_index = randomIndex / column_size;
        int column_index = randomIndex % column_size;

        matrix[row_index][column_index].hasBomb = true;
    }
}

void Model::setNumbers(void)
{
    for (int row = 1; row <= row_size; ++row) {
        for (int column = 1; column <= column_size; ++column) {
        	int aroundBombNumber = 0;
        	// まわりのボムの数を数える
        	if(hasBomb( row + 1 , column + 1 )) aroundBombNumber++;
        	if(hasBomb( row + 1 , column     )) aroundBombNumber++;
        	if(hasBomb( row + 1 , column - 1 )) aroundBombNumber++;
        	if(hasBomb( row     , column + 1 )) aroundBombNumber++;
        	if(hasBomb( row     , column - 1 )) aroundBombNumber++;
        	if(hasBomb( row - 1 , column + 1 )) aroundBombNumber++;
        	if(hasBomb( row - 1 , column     )) aroundBombNumber++;
        	if(hasBomb( row - 1 , column - 1 )) aroundBombNumber++;

        	// 数字をセット
        	setNumber( row ,column , aroundBombNumber );
        }
    }
}
