#include <gui/gamescreen1_screen/GameScreen1View.hpp>
#include <gui/gamescreen1_screen/GameScreen1Presenter.hpp>
#include <gui/model/Model.hpp>

GameScreen1Presenter::GameScreen1Presenter(GameScreen1View& v)
    : view(v)
{

}

void GameScreen1Presenter::activate()
{
	model = Model();

}

void GameScreen1Presenter::deactivate()
{

}

void GameScreen1Presenter::blockClicked(int row, int column)
{

	// 現在の状態を保存
	CurrentViewSave();


	// ブロッククリック時の処理
	if((!model.isFlagMode) && (!model.firstOpened))
	{
		// 初めて開いた場合はボムと数字をセット
		model.setBombsWithout(row,column);
		model.setNumbers();
		model.firstOpened = true;
	}

	if(!model.isFlagMode)
	{
		// 入力による状態の変更
		model.openBlock(row,column);
	}
	else
	{
		model.toggleFlag(row,column);
	}

	// 表示の更新
	ViewUpdate();

}

void GameScreen1Presenter::resetClicked(void)
{
	// 現在の状態の保持
	CurrentViewSave();

	// ブロッククリック時の処理
	model.gameReset();

	// 表示の更新
	ViewUpdate();
}


void GameScreen1Presenter::CurrentViewSave(void)
{
	model.saveCurrentBlockMatrix();
}

void GameScreen1Presenter::ViewUpdate(void)
{
	for(int row=1;row<=model.getRowMax();row++)
	{
		for(int column=1;column<=model.getColumnMax();column++)
		{
			if(model.diffPresentBlock(row,column))
			{
				view.updateBlockImage(row, column, GetBlockState(model.getBlock(row,column)));
			}
		}
	}
}

GameScreen1Presenter::BlockState GameScreen1Presenter::GetBlockState(Model::Block block)
{
	if(!block.isOpen)
	{
		if(!block.hasFlag) return GameScreen1Presenter::BlockState::Close;
		else return GameScreen1Presenter::BlockState::CloseWithFlag;
	}
	else
	{
		if(block.hasBomb) return GameScreen1Presenter::BlockState::OpenBomb;
		switch(block.number)
		{
		case 0: return GameScreen1Presenter::BlockState::OpenNumber0;
		case 1: return GameScreen1Presenter::BlockState::OpenNumber1;
		case 2: return GameScreen1Presenter::BlockState::OpenNumber2;
		case 3: return GameScreen1Presenter::BlockState::OpenNumber3;
		case 4: return GameScreen1Presenter::BlockState::OpenNumber4;
		case 5: return GameScreen1Presenter::BlockState::OpenNumber5;
		case 6: return GameScreen1Presenter::BlockState::OpenNumber6;
		case 7: return GameScreen1Presenter::BlockState::OpenNumber7;
		case 8: return GameScreen1Presenter::BlockState::OpenNumber8;
		case 9: return GameScreen1Presenter::BlockState::OpenNumber9;
		default: return GameScreen1Presenter::BlockState::OpenNumber0;
		}
	}
}

void GameScreen1Presenter::modeToggleClicked(void)
{
	if(model.isFlagMode) model.isFlagMode = false;
	else model.isFlagMode = true;
}

bool GameScreen1Presenter::checkFlagMode(void)
{
	return model.isFlagMode;
}

