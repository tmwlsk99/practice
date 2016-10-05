#include <iostream>
#include "box.h"
#include "circle.h"

#include <vector>

int main()
{

	std::cout << "hello world" << std::endl;

	GeometricObject **object_list = new GeometricObject*[10];

	GeometricObject *my_box = new Box;
	GeometricObject *my_circle = new Circle;
	
	my_box->draw();
	my_circle->draw();
	return 0;
}