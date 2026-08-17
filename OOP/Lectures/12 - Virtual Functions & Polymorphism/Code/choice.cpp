#include <iostream>
#include <sstream>
#include <string>
#include <vector>

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

class ChoiceQuestion : public Question
{
public:
   void add_choice(string choice, bool correct);
   void display() const;
private:
   vector<string> choices;
};

void ChoiceQuestion::add_choice(string choice, bool correct)
{
   choices.push_back(choice);
   if (correct)
   {
      int choice_index = choices.size();
      string choice_string = to_string(choice_index);
      set_answer(choice_string);
   }
}

void ChoiceQuestion::display() const {
   Question::display();
   cout << "Choices>> ";
   for (const std::string& choice : choices) {
        std::cout << choice << " ";
   }
   std::cout << std::endl;
}

int main()
{
   string response;
   cout << boolalpha; // Show Boolean values as true, false 
   
   Question q1;
   q1.set_text("Who was the inventor of C++?");
   q1.set_answer("Bjarne Stroustrup");
   //q1.add_choice("Honda ABC", false);
   q1.display();
   cout << "Your answer: ";
   getline(cin, response);
   cout << q1.check_answer(response) << endl;
   
   ChoiceQuestion q2;
   q2.set_text("What is the capital city of Pakistan? ");
   q2.add_choice("Karachi", false);
   q2.add_choice("Hyderabad", false);
   q2.add_choice("Islamabad", true);
   q2.add_choice("Lahore", false);
   q2.add_choice("Peshawar", false);
   q2.add_choice("Quetta", false);
   q2.add_choice("None", false);

   q2.set_answer("Islamabad");

   q2.display();
   cout << "Your response>> ";
   getline(cin, response);
   cout << q2.check_answer(response) << endl;

   return 0;
}

