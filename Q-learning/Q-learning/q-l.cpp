#include <iostream>


#define MAX2(a,b)             ((a)>(b) ? (a) : (b))
#define MAX3(a,b,c)           (MAX2(MAX2(a,b),(c)))
#define MAX4(a,b,c,d)         (MAX2(MAX3(a,b,c),(d)))

class CellData
{
public:
	double q_[4] = { 0.0,0.0,0.0,0.0 }; //상하좌우
	double reward_ = 0.0;

	CellData()
	{}

	double getMaxQ()
	{
		return MAX4(q_[0], q_[1], q_[2], q_[3]);
	}
};

class GridWorld
{
public:
	int i_res_, j_res_;
	CellData *q_arr2d_ = nullptr;

	GridWorld(const int& i_res, const int& j_res)
		:i_res_(i_res), j_res_(j_res)
	{
		q_arr2d_ = new CellData[i_res*j_res];
	}

	CellData& getCell(const int& i, const int& j)
	{
		return q_arr2d_[i + i_res_ * j];
	}
	bool isInside(const int& i, const int& j) // grid 에 포함되어있나
	{
		if (i < 0) return false;
		if (i >= i_res_) return false;

		if (j < 0) return false;
		if (j >= j_res_) return false;

		return true;
	}

	void printSigned(const float& v)
	{
		if (v > 0.0f) printf("+%1.1f", v);
		else if (v < 0.0f) printf("%1.1f", v);
		else
			printf(" 0.0");
	}

	void print()
	{
		for (int j = j_res_ - 1; j >= 0; j--)
		{
			for (int i = 0; i < i_res_; i++)
			{
				CellData &cell = getCell(i, j);

				printf("   ");
				printSigned(cell.q_[0]);
				printf("   "); //up
				printf("   ");

			}

			printf("\n");
			for (int i = 0; i < i_res_; i++)
			{
				CellData &cell = getCell(i, j);

				printSigned(cell.q_[2]);
				printf("  ");
			}

			for (int i = 0; i < i_res_; i++)
			{
				CellData &cell = getCell(i, j);


				printSigned(cell.q_[3]);
				printf("   ");

			}
			printf("\n");
			for (int i = 0; i < i_res_; i++)
			{
				CellData &cell = getCell(i, j);

				printf("   ");
				printSigned(cell.q_[1]);
				printf("   "); //down
				printf("   ");
			}
			printf("\n\n");

		}
	}
};

class Agent
{
public:
	int i_, j_; //position
	double reward_;

	Agent()
		:i_(0), j_(0), reward_(0.0)
	{}
};

int main()
{
	std::cout << "Hello grid world" << std::endl;

	const int world_res_i = 3, world_res_j = 2;
	GridWorld world(world_res_i, world_res_j);

	world.getCell(2, 1).reward_ = 1.0;
	world.getCell(2, 0).reward_ = -1.0;

	Agent my_agent;

	world.print();

	for (int t = 0; t < 100; t++)
	{
		const int action = rand() % 4;

		int i = my_agent.i_, j = my_agent.j_;
		int i_old = i, j_old = j;

		switch (action)
		{
		case 0:
			j++;//up
			break;
		case 1:
			j--; //down
			break;
		case 2:
			i--;//left
			break;
		case 3:
			i++;//right
			break;
		}

		if (world.isInside(i, j) == true) // move if available
		{
			

 
							 //move agent start (i,j)

							 //update reward(r_t)

							 //update q values of previous cell (q_t)

							 //reset if agent is in final cells
		}
		else
		{
			//you may give negative reward to agent
		}

		/*std::cout << "Agent status " << my_agent.i_ << " " << my_agent.j_ << std::endl;
		std::cout << "action" << action << std::endl;

		world.print();*/
	}
	world.print();
	return 0;
}