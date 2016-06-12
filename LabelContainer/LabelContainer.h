#pragma once
#include "../Panel/Panel.h"
#include "../Label/Label.h"
#include "../Button/Button.h"
#include <vector>
class LabelContainer: public Panel
{
protected:
	virtual void AddItem(string item, int width);

public:
	LabelContainer(int width, vector<string> items, bool markable = true);
	virtual void OnFocusEvent();
	virtual void SetSelectedIndex(int index) = 0;
	
	~LabelContainer();
};

