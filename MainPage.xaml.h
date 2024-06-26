﻿#pragma once

#include "MainPage.g.h"

namespace App1
{
	/// <summary>
	/// 자체적으로 사용하거나 프레임 내에서 탐색할 수 있는 빈 페이지입니다.
	/// </summary>
	public ref class MainPage sealed
	{
	public:
		MainPage();

	private:
		void TextBox_TextChanged(Platform::Object^ sender, Windows::UI::Xaml::Controls::TextChangedEventArgs^ e);
		void OnClicked(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
	};
}