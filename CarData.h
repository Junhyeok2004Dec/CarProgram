#include <vector>

#pragma once
class CarData
{

private:


	int ID;
	int BATTERY;
	float wheel_velocity;
	std::vector<float> GPS_velocity;
	std::vector<int> UTM_position;  // UTM 좌표계를 10ⁿ배수하여 정수로 치환했음.
	//...




	


public:
	
	int getID();
	int getBATTERY(); // 소수점 절삭을 위해 84.4%이면 844로 표시
	float wheel_velocity();
	std::vector<float> getVelocityGPS();
	std::vector<int> getUTM_POS;

	
};



