#include <iostream>

class Test
{
public:
	int a;
	void(Test::*callback_)(void) = nullptr;
	
	void exec()//�ɹ��Լ��϶��� ���ο��� �θ���.
	{
		(this->*callback_)();
	}

	void drawbox()
	{
		std::cout << "box"<<a << std::endl;
	}

	void drawcircle()
	{
		std::cout << "circle"<<a << std::endl;

	}
};



int main()
{
	Test my_circle;
	my_circle.Test::callback_ = &Test::drawcircle;
	Test my_box;
	my_box.callback_ = &Test::drawbox;
	my_circle.exec();
	my_box.exec();
	//(*my_circle.callback_)();
}