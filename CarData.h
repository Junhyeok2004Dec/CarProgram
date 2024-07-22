#include <vector>

#pragma once
class CarData
{

private:


	int ID;
	int BATTERY;
	float wheel_velocity;
	std::vector<float> GPS_velocity;
	std::vector<int> UTM_position;  // UTM ��ǥ�踦 10������Ͽ� ������ ġȯ����.
	//...




	


public:
	
	int getID();
	int getBATTERY(); // �Ҽ��� ������ ���� 84.4%�̸� 844�� ǥ��
	float wheel_velocity();
	std::vector<float> getVelocityGPS();
	std::vector<int> getUTM_POS;

	
};



