#pragma once
#include "../../GUI/GUIBox.h"

class TextField : public GUIBox
{
private:
	friend class GUILayer;
	std::string text; 
	Text txt;   
	//Sprite sprite;
	GUIStyle gst;
	RectangleShape field;
protected:
	TextField(RenderWindow* renderWindow_, float x, float y, float width, float height, std::string text, TextStyle *tstyle, GUIStyle *gstyle);
	bool focus;
public:
	virtual void Draw() override;
	virtual void Recalc() override;

	Text DisplayText();
	void ReText(char);     //формирует текст в  TextField
	bool Select();
	bool Select(Vector2i); //проверка фокуса
	
};