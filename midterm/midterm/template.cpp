#include <iostream>
#include <string>
#include <vector>

class box
{
public:
	void draw()
	{
		std::cout << "box" << std::endl;
	}
};

class circle

{
public:
	void draw()
	{
		std::cout << "circle" << std::endl;
	}
};


class mother
{
public:
	virtual void draw() = 0;
};


template <class T_>

class object : public mother
{
public:
	void draw()
	{
		T_ my_object;
		my_object.draw();
	}
};

int main()
{
	mother **my_mother = new mother*[5];
	for (int i = 0; i < 5; i++)
	{
		my_mother[i] = new object<box>;
		my_mother[i]->draw();
	}
	/*object<box> my_box;
	my_box.draw();
	object<circle> my_circle;
	my_circle.draw();*/
}