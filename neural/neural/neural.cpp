#include <iostream>

#include "NeuralNetwork.h"

void main()
{
	VectorND<VectorND<D>> x_input_array;
	x_input_array.initalize(2);
	x_input_array[0].initalize(2);
	x_input_array[0][0]=0.0;
	x_input_array[0][1] = 0.0;

	x_input_array[1].initalize(2);
	x_input_array[1][0] = 0.5;
	x_input_array[1][1] = 1.0;


	VectorND<VectorND<D>> y_target_array(2);
	y_target_array[0].initalize(2);
	y_target_array[0][0] = 0.1f;
	y_target_array[0][1] = 0.5f;

	y_target_array[1].initalize(2);
	y_target_array[1][0] = 0.8f;
	y_target_array[1][1] = 0.9f;

	VectorND<D> y_temp(2);

	NeuralNetwork nn_;
	nn_.initialize(2, 2, 1); //�Է� 2�� ��� 2��
	nn_.alpha_ = 0.1;
	//�Է� 0 0 �� ���Ͽ� 0.1 0.5 ���
	//�Է� 0.5 1.0 �� ���Ͽ� 0.8 0.9 ���
	for(int i=0; i<100; i++)
		for (int e = 0; e < 2; e++)
		{
			nn_.setInputVector(x_input_array[e]);
			nn_.propForward();

			nn_.copyOutputVector(y_temp);
			std::cout << y_target_array[e]<<"!!!"<<y_temp << std::endl;

			nn_.propBackward(y_target_array[e]);
		}

	//test data �׽�Ʈ��Ű�� ���������� �߷�
	VectorND<D> test_data(2);
	test_data[0] = 0.2f;
	test_data[1] = 0.5f;

	nn_.setInputVector(test_data);
	nn_.propForward();

	nn_.copyOutputVector(y_temp);
	std::cout << y_temp << std::endl;
}