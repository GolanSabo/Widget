#include "ComboBox.h"

ComboBox::ComboBox(int width, vector<string> items):LabelContainer(width, items, false),_openFlag(false)
{
}

void ComboBox::SetSelectedIndex(int index)
{
	SwapItems(0, index);
}

void ComboBox::SwapItems(int index1, int index2)
{
	string str = _widgetList[index1]->GetText();
	_widgetList[index1]->SetText(_widgetList[index2]->GetText());
	_widgetList[index2]->SetText(str);
}

int ComboBox::GetSelectedIndex()
{
	return 0;
}

void ComboBox::Draw(Graphics g, int x, int y, int layer)
{
	
	if (_openFlag)
	{
		SetHeight(_numberOfWidgets);
		LabelContainer::Draw(g, x, y, layer);
	}
	else
	{
		SetHeight(1);
		if (layer <= GetLayer())
			Widget::Draw(g, x, y, layer);
		_widgetList[0]->Draw(g, GetX() + x, GetY() + y, layer);
	}
}

void ComboBox::MousePressed(int x, int y, bool isLeft)
{
	y -= GetY();
	if (y >= 0 && _openFlag)
	{
		SwapItems(0, y);
		_openFlag = false;
	}
	else
	{
		_openFlag = true;
		SetHeight(_numberOfWidgets);
	}
}


void ComboBox::KeyDown(int keyCode, char character)
{

}
ComboBox::~ComboBox()
{
}
