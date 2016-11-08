#include <iostream>
//linear regression
//gradient descent method

class interpolation
{
public:
	double a = 0;
	double b = 0;
	double c = 0;
	double getY(const double X)
	{
		//return a*X + b;

		return a*X*X + b*X + c;
	}

};
const double learning_rate = 0.01; //experimentaly used
void main()
{
	double study_time[3] = { 0,1,2 };
	double score[3] = { 0,3,7.5 };
	interpolation study;

	for (int r = 0; r < 1000; r++)
	{

		for (int i = 0; i < 3; i++)
		{

			const double error = score[i] - study.getY(study_time[i]);
			const double sqr_error = error*error;
			//differentiate
		/*	const double d_error_over_d_a = 2.0*-error*study_time[i];
			const double d_error_over_d_b = 2.0*-error*1.0;*/
			const double d_error_over_d_a = 2.0*-error*study_time[i]* study_time[i];
			const double d_error_over_d_b = 2.0*-error*study_time[i];
			const double d_error_over_d_c = 2.0*-error*1.0;

			//study.a -= d_error_over_d_a*learning_rate;
			//study.b -= d_error_over_d_b*learning_rate;
			study.a -= d_error_over_d_a*learning_rate;
			study.b -= d_error_over_d_b*learning_rate;
			study.c -= d_error_over_d_c*learning_rate;
			std::cout << score[i] << " " << study.getY(study_time[i]) << std::endl;
		
		}
	}//(0,0)(1,3)(2,7.5)

	std::cout << study.getY(1.5) << std::endl;
}
