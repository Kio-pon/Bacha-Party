#include <iostream>
using namespace std;
class Position
{
    public:
        int x , y;
};
class Robot
{
    int powers;
    public:
        Position pos; // has a  // composition /aggregration
        string name ;
        string direction;
        Robot(int xx =0 , int yy =0) 
        {
            pos.x = xx ;
             pos.y = yy;
            cin>>name;
            powers = 100;
          
            cout << "Robot object created \n";
        }

        void leftMove(){ pos.x--;}
        void showRobot()
        {
            cout <<"Robot " << name << " is at poition  " << pos.x << " " << pos.y << endl;
            cout << "Remaining Powers =  " << powers << endl;
        }
        friend ostream& operator << (ostream& o , Robot& obj)
        {
            o << "using operator overloading\n";
            o <<"Robot " << obj.name << " is at poition  " << obj.pos.x << " " <<obj.pos.y << endl;
            o << "Remaining Powers =  " << obj.powers << endl;
            return o;

        }


};
//Enemy is a Robot
class Enemy : public Robot
{
    
    public:
        int life; 
        Enemy() : Robot()
        {
            life = 3;
           // powers = 200;
            cout << "Enemy object created \n";
        }
        void showEnemy()
        {   
            showRobot();
            cout << "Life = " << life << endl;

        }
};


int main()
{

    Robot r , p;
    
   // r+p;
   // r.powers = 8;

   //operator overloading
    //insertion 
    cout << r << p; // r.showRobot(); // cout.operator <<(r)


    Enemy e; // default ctor of robot then  enemy class will be executed
    //e.powers = 88;

   e.pos.x = 8;
   e.pos.y = 4;








    return 0;
}