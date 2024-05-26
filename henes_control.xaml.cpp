#include "pch.h"
#include "henes_control.xaml.h"

using namespace GaugeApp;
using namespace Platform;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Input;
using namespace Windows::UI::Xaml::Media;
using namespace Windows::UI::Xaml::Shapes;

MainPage::MainPage()
{
    InitializeComponent();
    DrawGaugeArc();
}

void MainPage::OnSliderValueChanged(Object^ sender, RangeBaseValueChangedEventArgs^ e)
{
    UpdateGaugeNeedle(e->NewValue);
}

void MainPage::DrawGaugeArc()
{
    double startAngle = -180;
    double endAngle = 0;
    double radius = 150;

    double centerX = 150;
    double centerY = 150;

    double startX = centerX + radius * cos(startAngle * M_PI / 180.0);
    double startY = centerY + radius * sin(startAngle * M_PI / 180.0);

    double endX = centerX + radius * cos(endAngle * M_PI / 180.0);
    double endY = centerY + radius * sin(endAngle * M_PI / 180.0);

    ArcSegment^ arcSegment = ref new ArcSegment();
    arcSegment->Point = Windows::Foundation::Point(endX, endY);
    arcSegment->Size = Windows::Foundation::Size(radius, radius);
    arcSegment->IsLargeArc = false;
    arcSegment->SweepDirection = SweepDirection::Clockwise;

    PathFigure^ pathFigure = ref new PathFigure();
    pathFigure->StartPoint = Windows::Foundation::Point(startX, startY);
    pathFigure->Segments->Append(arcSegment);

    PathGeometry^ pathGeometry = ref new PathGeometry();
    pathGeometry->Figures->Append(pathFigure);

    GaugeArc->Data = pathGeometry;
}

void MainPage::UpdateGaugeNeedle(double value)
{
    double angle = (value + 20) * 180 / 40 - 180; // value to angle
    double radius = 100;

    double centerX = 150;
    double centerY = 150;

    double needleX = centerX + radius * cos(angle * M_PI / 180.0);
    double needleY = centerY + radius * sin(angle * M_PI / 180.0);

    GaugeNeedle->X2 = needleX;
    GaugeNeedle->Y2 = needleY;
}
