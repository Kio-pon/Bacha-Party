#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class Question
{
public:
   /**
      Constructs a question with empty text and answer.
   */
   Question();

   /**
      @param question_text the text of this question
   */
   void set_text(string question_text);

   /**
      @param correct_response the answer for this question
   */
   void set_answer(string correct_response);

   /**
      @param response the response to check
      @return true if the response was correct, false otherwise
   */
   bool check_answer(string response) const;   

   /**
      Displays this question.
   */
   void display() const;
private:
   string text;
   string answer;
};

Question::Question() 
{
}

void Question::set_text(string question_text)   
{
   text = question_text;
}

void Question::set_answer(string correct_response)
{
   answer = correct_response;
}

bool Question::check_answer(string response) const
{
   return response == answer;
}

void Question::display() const
{
   cout << text << endl;
}

int main()
{
   string response;
   cout << boolalpha; // Show Boolean values as true, false 

   Question q1;
   q1.set_text("Who was the inventor of C++?");
   q1.set_answer("Bjarne Stroustrup");

   q1.display();
   cout << "Your answer: ";
   getline(cin, response);
   cout << q1.check_answer(response) << endl;

   return 0;
}

