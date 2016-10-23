//polymolphism

#include <iostream>
#include <string>

class geo
{
public:
	virtual void draw()
	{

	}
};


class line : public geo
{
public:
	virtual void draw()
	{
		std::cout << "line" << std::endl;
	}
};

class box : public geo
{
public:

	void draw()
	{
		std::cout << "box" << std::endl;
	}
};
geo* judge(const std::string &name) //factory pattern
{
	if (name == "Box")
		return new box;
	else if (name == "line")
		return new line;
}
int main()
{
	geo **my_geo = new geo*[10];

	for (int i = 0; i < 10; i++)
	{
		my_geo[i] = new box;
		//my_geo[i] = judge("Box");
		my_geo[i]->draw();
	}
	return 0;
}