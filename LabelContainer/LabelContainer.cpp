#include "LabelContainer.h"


void LabelContainer::AddItem(string item, int width)
{
	Label* l = NULL;
	l = new Label(width);
	while (item.size() < width)
		item += " ";
	l->SetText(item);
	AddWidget(*l, 0, _numberOfWidgets);
}

LabelContainer::LabelContainer(int width, vector<string> items, bool markable) :Panel(width, 1)
{
	SetHeight(items.size());
	SetFocusFlag(true);
	string str = "[ ] ";
	for (int i = 0; i < items.size(); ++i)
	{
		if (markable)
			items[i].insert(0, str);
		AddItem(items[i], width);
	}
}

void LabelContainer::OnFocusEvent()
{
	//paint you sons
	Panel::OnFocusEvent();
	//paint yourself
	//Widget::OnFocusEvent();
}

LabelContainer::~LabelContainer()
{
	for (int i = 0; i < _numberOfWidgets; ++i)
		delete _widgetList[i];
}



