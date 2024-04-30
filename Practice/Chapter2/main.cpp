#include "CCD.h"
#include "HeatIndexDisplay.h"

int main()
{
	WeatherData* weatherdata = new WeatherData;

	CCD* ccd = new CCD(weatherdata);
	HID* hid = new HID(weatherdata);

	weatherdata->setMeasurements(80, 65, 30.4f);
	weatherdata->setMeasurements(82, 70, 29.2f);
	weatherdata->setMeasurements(78, 90, 29.2f);
}