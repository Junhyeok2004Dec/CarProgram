//
// BlankPage.xaml.h
// Dsafeitemname$ 클래스의 선언
//

#pragma once

#include "BlankPage.g.h"

namespace App1
{
	/// <summary>
	/// 자체적으로 사용하거나 프레임 내에서 탐색할 수 있는 빈 페이지입니다.
	/// </summary>
	[Windows::Foundation::Metadata::WebHostHidden]
	public ref class BlankPage sealed
	{
	public:
		BlankPage();

	private:
		void OnSliderValueChanged(Platform::Object^ sender, Windows::UI::Xaml::Controls::Primitives::RangeBaseValueChangedEventArgs^ e);
		void DrawGaugeArc();  // DrawGaugeArc 함수 선언 추가
		void UpdateGaugeNeedle(double value);
	};
}
