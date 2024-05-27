//
// CarManagement.xaml.h
// Dsafeitemname$ 클래스의 선언
//

#pragma once

#include "CarManagement.xaml.h"

namespace App1
{

		public ref class CarManagement sealed
	{
	public:
		CarManagement();

	private:

		void OnSliderValueChanged(Platform::Object^ sender, Windows::UI::Xaml::Controls::Primitives::RangeBaseValueChangedEventArgs^ e);
		void DrawGaugeArc();  // DrawGaugeArc 함수 선언 추가
		void UpdateGaugeNeedle(double value);
	};

};

