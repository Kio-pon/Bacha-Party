#include <iostream>
#include <string>
using namespace std;

// Exercise 2.3 [40 points]: Payment class hierarchy with polymorphic
// paymentDetails().
class Payment
{
private:
    double amount;

public:
    Payment(double amt = 0.0) : amount(amt) {}

    double getAmount() { return amount; }
    void setAmount(double amt) { amount = amt; }

    virtual void paymentDetails()
    {
        cout << "The payment amount is $" << amount << "." << endl;
    }
};

// Cash Payment Class: redefine paymentDetails() to indicate a cash payment.
class CashPayment : public Payment
{
public:
    CashPayment(double a) : Payment(a) {}

    void paymentDetails() override
    {
        // TODO: print the cash payment amount
    }
};

// Credit Card Payment Class: adds name/expirationDate/creditCardNumber and
// redefines paymentDetails() to include them.
class CreditCardPayment : public Payment
{
private:
    string name, expirationDate, creditCardNumber;

public:
    CreditCardPayment(double a, string n, string exp, string ccNum)
        : Payment(a), name(n), expirationDate(exp), creditCardNumber(ccNum)
    {
    }

    void paymentDetails() override
    {
        // TODO: print amount, name, expiration date and card number
    }
};

int main()
{
    CashPayment cp1(75.25);
    CashPayment cp2(36.95);
    CreditCardPayment ccp1(95.15, "Smith", "12/21/2009", "321654987");
    CreditCardPayment ccp2(45.75, "James", "10/30/2008", "963852741");

    cout << "Details of Cash #1..." << endl;
    cp1.paymentDetails();

    cout << "\nDetails of Cash #2..." << endl;
    cp2.paymentDetails();

    cout << "\nDetails of Credit Card #1..." << endl;
    ccp1.paymentDetails();

    cout << "\nDetails of Credit Card #2..." << endl;
    ccp2.paymentDetails();

    return 0;
}
