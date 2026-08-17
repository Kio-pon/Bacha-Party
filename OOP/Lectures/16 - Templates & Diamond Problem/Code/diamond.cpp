#include<iostream>
using namespace std;
class Asset
{
    public:
        Asset(){cout << "Asset CTOR\n";}
        virtual void greeting() {cout << "Asset Hello\n";}
      virtual  ~Asset() { cout << "Asset Destroyed\n";}
};
class Vehicle: virtual public Asset
{       public:
        Vehicle(){cout << "Vehicle CTOR\n";}
         void greeting() override {cout << "Vehicle Hello\n";}
          ~Vehicle() { cout << "Vehicle Destroyed\n";}
};

class House : virtual public Asset
{       public: 
            House() {cout << "House CTOR\n";}
           void greeting(){cout << "House Hello\n";}
            ~House() { cout << "House Destroyed\n";}
};

class RV : public Vehicle , public House
{
    public:
    RV(){cout << "RV CTOR\n";}
    void greeting(){cout << "RV Hello\n";}
     ~RV() { cout << "RV Destroyed\n";}


};
int main()
{
//     RV r1;
//    // r1.greeting();
//    House h1 ;
//    Vehicle v1 ;
//    v1.greeting();//vehicle class
//    h1.greeting(); // house classs
//    Asset* a  = new RV();
//     a->greeting(); // 

    Asset** assets = new Asset*[5];
    assets[0] = new RV();
    assets[1] = new Vehicle();
    assets[2] = new House();
    assets[3] = new House();
    assets[4] = new RV();

    for (int i =0 ; i< 5 ; i++)
    {
        assets[i]->greeting();
    }
     for (int i =0 ; i< 5 ; i++)
    {
        delete assets[i];
    }
    delete[] assets;




    return 0;
}
