#include<iostream>
using namespace std;
//a system can have multiple classes
// classes have relationships 
//==========================
// customer has a bank account
//student - enrolls -course
// Robot "has a" posution on the screen
// TA "is a" Student // inheritance



class Position
{
        public :
            int x ,  y ;
           // void setPosition(int xx , int yy);
        
};
class Robot
{
    private :   //Gun g[5];
            //Coin c[99];
            // int x =0 , y=0 ; //location/coordinates
            Position pos;
            string face = "East";//direction
            string name ;
          
    public:
            Robot (Robot& r) // defualt copy ctor
            {
                
                pos.x = r.pos.x;
                pos.y = r.pos.y; 
                face = r.face;
                name = r.name;
                cout << "Default copy Constructor : Robot "<<name<< " created  at position : (" << pos.x << "," << pos.y <<") : Face = " << face <<"\n"; 

            }
            // combination of all overloaded constrcutor
            Robot(int  x_cord = 0, int y_cord =0  , string f = "East" , string n = "ABC") // default ctor
            {
                pos.x = x_cord;
                pos.y = y_cord; 
                face = f;
                name = n;
                cout << "Default Constructor : Robot "<<name<< " created  at position : (" << pos.x << "," << pos.y <<") : Face = " << face <<"\n"; 
            } 
            ~Robot() // default destrcutor
            {
                cout << "Robot destroyed\n";
            }
            
            void setFace(string f);
            void moveLeft()
            {
                pos.x--;
            }
            void moveRight();
            void moveUp(){ pos.y++ ;}
            void moveDown();
            void showRobot()
            {
                cout << "Robot "<<name<< " at position : (" << pos.x << "," << pos.y <<") : Face = " << face <<"\n"; 
            }
            Position getPosition()
            {
                return pos;
            }

};
int main()
{
    int x , y;
    Robot r1(7,6,"West","Danish"); // create at position (0 , 0 , 'EAST')
    Robot r2(3 , 6,"East" ,"Rubab"); // create at position (3 , 0,'EAST') , constructor with one parameter
    Robot r3(5,7 , "North", "Azyan"); // create at position (5 , 7, "East")
    Robot r4(3,8,"South" , "Anas"); // create at position (3 , 8 , "West")
    //Robot r5(,7,"North");

    // r2.showRobot();
    // r4.showRobot();
    // r4.moveLeft();
    // r4.moveUp();
    // r4.showRobot();

    Robot r5 ; // default ctor
 //game play 
    r5 = r3; // default copy assignment operator (memberwise copying the value)


    Robot r6(r1); // defualt copy constructor
    Position p = r6.getPosition();
    cout << "R6 is at "<< p.x << " " << p.y << "\n";
    // r1.showRobot();
    // r6.showRobot();
    // r6.moveLeft();
    // r6.moveUp();
    // r1.showRobot();
    // r6.showRobot();




    return 0 ;
}


  //ctor
            // Robot(){
            //     x = y = 0;
            //     face = "East";
            // }   //default constructor

            // Robot(int x_cord){
            //     x = x_cord;
            //     y =0; 
            //     face = "West";
            // } 