#ifndef MODEL_HPP
#define MODEL_HPP

class ModelListener;

class Model
{
public:
    Model();

    void bind(ModelListener* listener)
    {
        modelListener = listener;
    }

    void tick();

    struct Block{
    	bool isOpen;
    	bool hasFlag;
    	bool hasBomb;
    	int number;
    };

    void saveCurrentBlockMatrix(void);
	bool diffPresentBlock(int row,int column);
	Block getBlock(int row,int column);
	bool openBlock(int row,int column);
	int getRowMax(void);
	int getColumnMax(void);

protected:
	static const int bomb_number = 25;
    static const int row_size = 7;
    static const int column_size = 9;
    Block matrix[row_size][column_size];
    Block preMatrix[row_size][column_size];

    void blockInit(int row , int column);
	Block getPreBlock(int row,int column);

    ModelListener* modelListener;
};

#endif // MODEL_HPP
