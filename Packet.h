#include <vector>

#pragma once
class Packet
{

private:


	int ID;
	int BATTERY;
	float wheel_velocity;
	std::vector<float> GPS_velocity;
	std::vector<int> UTM_position;  // UTM 좌표계를 10ⁿ배수하여 정수로 치환했음.

	std::string packet[];
	
};

