#pragma once
#include "../LabelContainer/LabelContainer.h"
class ComboBox:public LabelContainer
{
	bool _openFlag;
	int _currentItemInFocus;
public:
	ComboBox(int width, vector<string> items);
	void SetSelectedIndex(int index);
	void SwapItems(int index1, int index2);
	int GetSelectedIndex();
	virtual void Draw(Graphics g, int x, int y, int layer);
	virtual void MousePressed(int x, int y, bool isLeft);
	virtual void KeyDown(int keyCode, char character);
	~ComboBox();
};

