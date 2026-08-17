    /*
        Primitive version of Instagram
        1. Structures
        2. Classes and objects
        3. Difference between classes and objects and structures
        4. Mutator and acessor function
        5. Constructors and the initialization list
        6. Double pointers [confused :(]
        7. Destructors
    */

    #include <iostream>
    using namespace std;

    /*
        insta user -> user name, dob, status ("live laugh and love!")
    */

    struct Name{
        string first_name;
        string last_name;
    };

    struct DOB{
        int Year;
        int Month;
        int Day;
    };

    class User{
        public:
            // Member functions
            // mutator fucntions
            void setName(const string&, const string&);
            void setDOB(int, int, int);
            void setStatus(const string&);

            // accessor - getter functions
            Name getName() {return name;}
            DOB getDOB() {return dob;}
            string getStatus() {return status;}
            void addFriend(User*);
            void friendList();

            // constructor
            User(); // default constructor
            User(const string&, const string&, int, int, int, const string&);
            User(const string&, const string&);

            // destructor
            ~User();

        private:
            // Data members
            Name name;
            DOB dob;
            string status;

            User** follower;
            int follwer_count;
    };


    /*
        This is constructor with assignment/ initialization within the body of constructor
        As explained in the lecture its not efficient and only used prior to C++11
        User::User(){
            name.first_name = "-";
            name.last_name = "-";
            dob.Year = 2000;
            dob.Month = 1;
            dob.Day = 1;
            status = "Hey I am using Primitive-Insta";
        }
    
    */

    // C++17
    User::User() : dob{2000,1,1}, status("Hey there I am using primitive insta"), name{"-", "-"}
    {}

    User::User(const string& fname, const string& lname, int y, int m, int d, const string& stat) : name{fname, lname}, dob{y, m, d}, status(stat)
    {}
    // string& -> pass by reference
    User::User(const string& fname, const string& stat) : name{fname, ""}, dob{2000, 1, 1}, status(stat)
    {}

    /*
        This is a sample code for destructor, but this will not work for several reasons in this code
        we will cover this in the next lecture
        User::~User(){
            delete[] follower;  //saves us from memory leaks
            follower = nullptr; // saves us from dangling pointers
        }
    */
    

    void User::setName(const string& fname, const string& lname){
    name.first_name = fname;
    name.last_name = lname; 
    }

    void User::setDOB(int y, int m, int d){
        dob.Year = y;
        dob.Month = m;
        dob.Day = d;
    }

    void User::setStatus(const string& stat){
        status = stat;
    }

    void User::addFriend(User* f){
        User** new_friends = new User*[follwer_count + 1];

        for(int i =0; i < follwer_count; i++){
            new_friends[i] = follower[i];
        }
        new_friends[follwer_count] = f;

        delete[] follower;
        follower = new_friends;
        follwer_count++;
    }

    void User::friendList(){
        for(int i = 0; i < follwer_count; i++){
            cout << follower[i]->getName().first_name << ", ";
        }
        cout << endl;
    }

    int main(){
        User A;
        A.setName("Karim", "Ahmed");

        User B("Tauqeer", "Saleem", 1998, 4, 5, "Study C++");
        User C("Farhan", "Gilgiti");
        User D("Tanzeel", "Karachite");
        User E("Tajdar", "Mr Good boy!");

        B.addFriend(&A);
        B.addFriend(&C);
        B.addFriend(&D);
        B.addFriend(&E);

        B.friendList();
    }