#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>
#include <cstring>
#include <iostream>
#include <vector>
#include <random>
#include <ctime>


Model::Model() : modelListener(0)
{

    for (int row = 1; row <= row_size; ++row) {
        for (int column = 1; column <= column_size; ++column) {
        	blockInit(row,column);  // 全ての要素を0に初期化
        }
    }


    std::mt19937 generator(static_cast<unsigned int>(std::time(nullptr)));
    std::uniform_int_distribution<int> distribution(0, row_size * column_size - 1);

    int bombsPlaced = 0;
    while (bombsPlaced < bomb_number) {
        int randomIndex = distribution(generator);
        int row_index = randomIndex / column_size;
        int column_index = randomIndex % column_size;

        if (!matrix[row_index][column_index].hasBomb) {
        	matrix[row_index][column_index].hasBomb = true;
            bombsPlaced++;
        }
    }
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

bool Model::openBlock(int row,int column)
{
	int row_index = row - 1;
	int column_index = column - 1;

	if(matrix[row_index][column_index].isOpen) return false;
	else
	{
		matrix[row_index][column_index].isOpen = true;
		return true;
	}
}

