#include "Panel.h"



Panel::Panel(int width, int height):Widget(width,height),_widgetList(),_numberOfWidgets(0)
{
}

void Panel::AddWidget(Widget& widget, int x, int y)
{
	//widget.SetLayer(GetLayer() /*+ 1*/);
	widget.SetX(x + GetX());
	widget.SetY(y + GetY());
	_widgetList.push_back(&widget);
	++_numberOfWidgets;
}

void Panel::MousePressed(int x, int y, bool isLeft)
{
	for (int i = 0; i < _numberOfWidgets; ++i)
	{
		if (_widgetList[i]->CheckPosition(x - GetX(), y - GetY()))
		{
			Widget::SetFocus(*_widgetList[i]);
			_widgetList[i]->MousePressed(x - GetX(), y - GetY(), isLeft);
			break;
		}
	}
}
void Panel::KeyDown(int keyCode, char character)
{
}

void Panel::Draw(Graphics g, int x, int y, int layer)
{
	if (layer <= GetLayer())
		Widget::Draw(g, x, y, layer);

	for (int i = 0; i < _numberOfWidgets; ++i)
	{
		_widgetList[i]->Draw(g, GetX() + x,GetY() + y, layer);
	}
}

void Panel::OnFocusEvent()
{
	for (int i = 0; i < _numberOfWidgets; ++i)
		_widgetList[i]->OnFocusEvent();
}

void Panel::SetLayer(int layer)
{
	for (int i = 0; i < _numberOfWidgets; ++i)
		_widgetList[i]->SetLayer(layer /*+ 1*/);
	Widget::SetLayer(layer);
}

Panel::~Panel()
{
}
