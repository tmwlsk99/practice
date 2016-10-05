#pragma once

//interface 진짜 하는일이 없다. 개념적인설계도
class GeometricObject //나를상속받은애들은 이러한일들을한다.
{
public:
	//virtula void draw()=0;
	virtual void draw()
	{
		//default draw function for all children
	}
};