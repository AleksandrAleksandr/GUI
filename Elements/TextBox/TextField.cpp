#include "TextField.h"

TextField::TextField(RenderWindow* renderWindow_, float x, float y, float width, float height, std::string text_, TextStyle *tstyle, GUIStyle *gstyle) : GUIBox(renderWindow_, x, y, width, height, text_, tstyle, gstyle)
{
	text = "";
	gst = *gstyle;
	txt.setPosition(x + 2, y + 2);
	txt.setColor(Color::Black);
	txt.setCharacterSize(20);
	txt.setFont(tstyle->font);
	focus = false;
	Recalc();
}

void TextField::ReText(char _tmp)
{
	text.erase(text.size()-1);
 
	if(_tmp != 8)
	{
	text += _tmp;
	} 
	else 
	{
		if(text.size() > 0){
		text.erase(text.size()-1);
		}
 	}
	text += "|";
	txt.setString(text);
}

bool TextField::Select()
{
	return focus;
}

bool TextField::Select(Vector2i _mouse)  
{
	if((_mouse.x > GetPosition().x && _mouse.x < GetPosition().x + GetSize().x) && (_mouse.y > GetPosition().y && _mouse.y < GetPosition().y + GetSize().y)) 	//���� ����� ������ ��� �������� TextField...
		{
			focus = true;																	   	// ����� true
			text += "|";																// � ����� ������ �������� | (��� �� �������� ��� TextField � ������)
			if (text.size() > 1 && text[text.size()-1] == 124 && text[text.size()-2] == 124)
				text.erase(text.size()-1);
		} 
	else{																				//...����� ���� ������� ��������� �� ��� ��������, ��...
		if(text.size() > 0){																// �������� ���������� �������(����� ��������)
			if(text[text.size()-1] == 124){													// ���� ������ | ...
				text.erase(text.size()-1);														// ... �� ������� ���
				}
			}
			focus = false;
		}
		return focus;
}

Text TextField::DisplayText()
{
	txt.setString(text);						// ��������� � ��������� ����� ����������� �����
	return txt;
}

void TextField::Draw()
{
	renderWindow->draw(field);
}

void TextField::Recalc()
{
	Vector2f pos = GetPosition();
	Vector2f sz = GetSize();
	float posX = pos.x;
	float posY = pos.y;
	float width = sz.x;
	float height = sz.y;
	
	field.setPosition(posX, posY);
	field.setSize(Vector2f(width, height));
	field.setFillColor(Color::White);
	field.setOutlineThickness(2);					
	field.setOutlineColor(Color(66, 66, 66));	

	/*sprite.setTexture(gst.overTex);
	sprite.setScale(width, height);
	sprite.setColor(sf::Color::White);
	sprite.setPosition(posX, posY);
	sprite.setTextureRect(IntRect(0, 0, width, height));*/
	
}