#include <vector>

#pragma once
class Packet
{

private:


	int ID;
	int BATTERY;
	float wheel_velocity;
	std::vector<float> GPS_velocity;
	std::vector<int> UTM_position;  // UTM ��ǥ�踦 10������Ͽ� ������ ġȯ����.

	std::string packet[];
	
};

