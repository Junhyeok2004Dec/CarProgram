//
// App.xaml.cpp
// App 클래스의 구현입니다.
//

#include "pch.h"
#include "MainPage.xaml.h"
#include "BlankPage.xaml.h"

using namespace App1;

using namespace Platform;
using namespace Windows::ApplicationModel;
using namespace Windows::ApplicationModel::Activation;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Controls::Primitives;
using namespace Windows::UI::Xaml::Data;
using namespace Windows::UI::Xaml::Input;
using namespace Windows::UI::Xaml::Interop;
using namespace Windows::UI::Xaml::Media;
using namespace Windows::UI::Xaml::Navigation;

App::App()
{
    InitializeComponent();
    Suspending += ref new SuspendingEventHandler(this, &App::OnSuspending);
}

void App::OnLaunched(Windows::ApplicationModel::Activation::LaunchActivatedEventArgs^ e)
{
    auto rootFrame = dynamic_cast<Frame^>(Window::Current->Content);


    if (rootFrame == nullptr)
    {
        rootFrame = ref new Frame();

        rootFrame->NavigationFailed += ref new Windows::UI::Xaml::Navigation::NavigationFailedEventHandler(this, &App::OnNavigationFailed);

        if (e->PreviousExecutionState == ApplicationExecutionState::Terminated)
        {

        }

        if (e->PrelaunchActivated == false)
        {
            if (rootFrame->Content == nullptr)
            {
                rootFrame->Navigate(TypeName(MainPage::typeid), e->Arguments);
            }
            // 현재 창에 프레임 넣기
            Window::Current->Content = rootFrame;
            Window::Current->Activate();
        }
    }
    else
    {
        if (e->PrelaunchActivated == false)
        {
            if (rootFrame->Content == nullptr)
            {
                // 탐색 스택이 복원되지 않으면 첫 번째 페이지로 돌아가고
                // 필요한 정보를 탐색 매개 변수로 전달하여 새 페이지를
                // 구성합니다.
                rootFrame->Navigate(TypeName(MainPage::typeid), e->Arguments);
            }
            // 현재 창이 활성 창인지 확인
            Window::Current->Activate();
        }
    }
}

void App::OnSuspending(Object^ sender, SuspendingEventArgs^ e)
{
    (void) sender; 
    (void) e;   

}

void App::OnNavigationFailed(Platform::Object ^sender, Windows::UI::Xaml::Navigation::NavigationFailedEventArgs ^e)
{
    throw ref new FailureException("Failed to load Page " + e->SourcePageType.Name);
}