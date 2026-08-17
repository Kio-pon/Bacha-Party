#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

// ----- Base class -----
class Question // Parent Question Class
{
private: // two data members to define a general behavior of this question class
   string text;
   string answer;
public:
   Question() {}
   
   void set_text(string question_text) 
      { text = question_text; }
   
   void set_answer(string correct_response) 
      { answer = correct_response; }

   bool check_answer(string response) const 
      { return response == answer; }

   void display() const 
      { cout << text << endl; }

    ~Question() {}
};


// ----- Derived class 1 -----
class ChoiceQuestion : public Question // Dervied class no.1 which is basically defining a specialized version of QuestionClass
{
private:
   vector<string> choices; // only declare additional data members 

public:
   ChoiceQuestion() {}

   void add_choice(string choice, bool correct)
   {
      choices.push_back(choice);
      if (correct)
         set_answer(to_string(choices.size())); // store correct choice index
   }

   void display()
   {
      Question::display();
      for (int i = 0; i < choices.size(); i++)
      {
         cout << i + 1 << ": " << choices[i] << endl;
      }
   }
};

// ----- Derived class 2 -----
class NumericQuestion : public Question // a second derived class from the Question Class
{
private:

   double expected;

public:
   void set_answer(double correct_response)
      {expected = correct_response;
      }

   bool check_answer(string response) const
      {
         double value = stod(response);
         return fabs(value - expected) < 1E-3; // tolerance for rounding
      }

   void display() const
      {
         Question::display();
         cout << "Enter a number." << endl;
      }
};

int main(){

   ChoiceQuestion cq; // an object of ChoiceQuestion class

   cq.set_text("Which language is used for system programming?");
   cq.add_choice("Python", false);
   cq.add_choice("C++", true);
   cq.add_choice("HTML", false);
   cq.add_choice("JS", false);

   cq.display();

   cout << "Enter a choice number";

   int choiceResponse;

   cin >> choiceResponse;

   if (cq.check_answer(to_string(choiceResponse))){

      cout << "Correct" <<endl;
   }
   else{
      cout << "Incorrect" <<endl;
   }

   cout <<endl;

   return 0;
}
