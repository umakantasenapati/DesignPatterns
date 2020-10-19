#include <iostream>
#include <typeinfo>
using namespace std;

template <typename T>
class Car
{
    public:
     void startCar()
     {
         static_cast<T*>(this)->start();
     }
     void start()
     {
         cout<<"Base class Car start method called"<<endl;
     }
};

class Honda:public Car<Honda>
{
    public:
        void start()
        {
            cout<<"Honda car started"<<endl;
        }
};
class Toyota:public Car<Toyota>
{
    public:
        void start()
        {
            cout<<"Toyota car started"<<endl;
        }
};
class BMW:public Car<BMW>
{
};

template<typename T>
void startCar(Car<T> carObj)
{

    carObj.startCar();
}

int main()
{
    BMW objBMW;
    startCar(objBMW);
    cout<<"Object type is "<<typeid(objBMW).name()<<endl;

    Honda objHonda;
    startCar(objHonda);

    Toyota objToyota;
    startCar(objToyota);

    return 0;
}
