#include "../include/Customer.h"


Customer::Customer(int ID, string name, int age, Operator *operator_, double limitingAmount)
{
    this->ID = ID;
    this->name = name;
    this->age = age;
    this->operator_ = operator_;

    bill = new Bill(limitingAmount);

    totalSpentTalkingTime = 0;
    totalSentMessages = 0;
    totalInternetUsage = 0.0;
}

Customer::~Customer()
{
    delete bill;
}

void Customer::talk(int minute, Customer* other)
{
    try
    {
        if (minute < 0)
            throw invalid_argument("Duration of the call must be non-negative.");

        if (ID != other->ID)
        {
            double cost = operator_->calculateTalkingCost(minute, *this);

            if (bill->check(cost))
            {
                bill->add(cost);
                operator_->addTalkingTime(minute);
                other->operator_->addTalkingTime(minute);
                totalSpentTalkingTime += minute;
                other->totalSpentTalkingTime += minute;
            }
        }
    }
    catch (const invalid_argument &error)
    {
        cout << error.what() << endl;
    }
}

void Customer::message(int quantity, Customer* other)
{
    try
    {
        if (quantity < 0)
            throw std::invalid_argument("Number of messages to be sent must be non-negative.");

        if (ID != other->ID)
        { // A customer cannot message him/herself.
            double cost = operator_->calculateMessageCost(quantity, *this, other);

            if (bill->check(cost))
            {
                bill->add(cost); // Add the messaging cost to the bill.
                operator_->addSentMessages(quantity);
                totalSentMessages += quantity;
            }
        }
    }
    catch (const std::invalid_argument &error)
    {
        cout << error.what() << endl;
    }
}

void Customer::connection(double amountMBs)
{
    try
    {
        if (amountMBs < 0.0)
            throw std::invalid_argument("Number of data must be non-negative.");

        double cost = operator_->calculateNetworkCost(amountMBs);

        if (bill->check(cost))
        {
            bill->add(cost);
            operator_->addInternetUsage(amountMBs);
            totalInternetUsage += amountMBs;
        }
    }
    catch (const std::invalid_argument &error)
    {
        cout << error.what() << endl;
    }
}

int Customer::getAge()
{
    return age;
}

void Customer::setAge(int age)
{
    try
    {
        if (age < 0)
            throw std::invalid_argument("Age must be non-negative.");

        this->age = age;
    }
    catch (const std::invalid_argument &error)
    {
        cout << error.what() << endl;
    }
}

Operator* Customer::getOperator()
{
    return operator_;
}

void Customer::setOperator(Operator *operator_)
{
    this->operator_ = operator_;
}

Bill *Customer::getBill()
{
    return bill;
}

void Customer::setBill(Bill *bill)
{
    this->bill = bill;
}

int Customer::getID()
{
    return ID;
}

string Customer::getName()
{
    return name;
}

int Customer::getTotalSpentTalkingTime()
{
    return totalSpentTalkingTime;
}

int Customer::getTotalSentMessages()
{
    return totalSentMessages;
}

double Customer::getTotalInternetUsage()
{
    return totalInternetUsage;
}
