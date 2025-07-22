// subject: giao dien hoac lop truu tuong dinh nghia cac phuong thuc co ban
// observer: tuong tu subject dinh nghia phuong thuc update hoac display
// concrete subject: lop cu the trien khai dao dien cua subject
// sub va concrete sub: thuc hien thong bao cho cac observer]
// sub va observer: cung cap cach de dang ki observer hoac huy
// concrete subject va observer: cung cap du lieu cho cac observer cu the


// 4 class chinh 1 subject/observer; 1 trien khai cua chung
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class DisplayElement
{
    public:
        virtual void display() = 0;
        virtual ~DisplayElement(){}
};
class Subject 
{
    public: 
        virtual void registerObserver(DisplayElement* observer) = 0;
        virtual void removeObserver(DisplayElement* observer) = 0;
        virtual void notifyObservers() = 0;
        virtual ~Subject(){}
};

class WeatherData : public Subject
{
    private:
        vector<DisplayElement*> observers; // vector quan ly thanh phan doi tuong
        float temp;
        float humi;
        float pressure;
    public:
        WeatherData() : temp(0), humi(0), pressure(0){}

        void registerObserver(DisplayElement* observer) override
        {
            observers.push_back(observer);
        }
        void removeObserver(DisplayElement* observer) override {
            for (auto it = observers.begin(); it != observers.end(); ++it) {
                if (*it == observer) {
                    observers.erase(it);
                    break;
                }
            }    
        }

        void notifyObservers() override
        {
            for(DisplayElement* observer : observers)
            {
                observer->display();
                cout << "Update: " << observer << endl;
            }
        }

        void measurementChanged()
        {
            notifyObservers();
        }

        void setMeasurements(float temp_, float humi_, float pressure_)
        {
            temp = temp_;
            humi = humi_;
            pressure = pressure_;
            measurementChanged(); // goi ham thay cap nhat gia tri trong toan bo mau quan sat
        }

        float getTemp() {return temp;}
        float getHumi() {return humi;}
        float getPressure() {return pressure;}
};

class ConditionsDisplay : public DisplayElement
{
    private:
        float temp1;
        float humi1;
        float pressure1;
        WeatherData* weatherData;

    public:
        ConditionsDisplay(WeatherData* wd) : weatherData(wd), temp1(0), humi1(0), pressure1(0)
        {
            weatherData->registerObserver(this); // dang ki observer cua WeatherData
        }

        virtual void display() override
        {
            temp1 = weatherData->getTemp();
            humi1 = weatherData->getHumi();
            pressure1 = weatherData->getPressure();
            cout << "T: " << temp1 << "H: " << humi1 << "P: " << pressure1 << endl;
        }
};


int main()
{
    WeatherData weatherData;
    ConditionsDisplay currentDisplay(&weatherData);

    weatherData.setMeasurements(25.0, 65.0, 1013.0);
    weatherData.setMeasurements(26.0, 70.0, 1012.0);

}