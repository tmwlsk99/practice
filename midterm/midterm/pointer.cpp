#include <iostream>

class Test
{
public:
	void(*callback_)(void) = nullptr;

};

void drawbox()
{
		std::cout << "box" << std::endl;
}

void drawcircle()
{
		std::cout << "circle" << std::endl;
	
}

int main()
{
	Test my_circle;
	my_circle.callback_ = &drawcircle;
	Test my_box;
	my_box.callback_ = &drawbox;

	(*my_circle.callback_)();
}