#pragma once
#include "../Widget/Widget.h"
class Panel:public Widget
{
protected:
	vector<Widget*> _widgetList;
	int _numberOfWidgets;
public:
	Panel(int width = 10, int height = 10);
	void AddWidget(Widget& widget, int x, int y);
	virtual void MousePressed(int x, int y, bool isLeft);
	virtual void KeyDown(int keyCode, char character);
	virtual void Draw(Graphics g, int x, int y, int layer);
	virtual void OnFocusEvent();
	void SetLayer(int layer);
	~Panel();
};

