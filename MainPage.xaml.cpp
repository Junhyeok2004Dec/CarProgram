

#include "pch.h"
#include "MainPage.xaml.h"
#include "BlankPage.xaml.h"

using namespace App1;

using namespace Platform;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Controls::Primitives;
using namespace Windows::UI::Xaml::Data;
using namespace Windows::UI::Xaml::Input;
using namespace Windows::UI::Xaml::Media;
using namespace Windows::UI::Xaml::Navigation;


MainPage::MainPage()
{
	InitializeComponent();
	

}


void App1::MainPage::TextBox_TextChanged(Platform::Object^ sender, Windows::UI::Xaml::Controls::TextChangedEventArgs^ e)
{

}

void App1::MainPage::OnClicked(Object^ sender, RoutedEventArgs^ e)
{
    auto carManagementWindow = ref new BlankPage();
    Windows::UI::Xaml::Window::Current->Content = carManagementWindow;
    Windows::UI::Xaml::Window::Current->Activate();
}

void App1::MainPage::Button_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{

}
