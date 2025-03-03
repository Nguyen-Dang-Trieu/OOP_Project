#include "../include/Operator.h"

Operator::Operator() : ID(0), totalSpentTalkingTime(0), totalSentMessages(0), totalInternetUsage(0.0) {}

Operator::Operator(int ID, double talkingCharge, double messageCost, double networkCharge, int discountRate)
{
    this->ID = ID;
    setTalkingCharge(talkingCharge);
    setMessageCost(messageCost);
    setNetworkCharge(networkCharge);
    setDiscountRate(discountRate);

    totalSpentTalkingTime = 0;
    totalSentMessages = 0;
    totalInternetUsage = 0.0;
}

double Operator::calculateTalkingCost(int minute, Customer &customer)
{
    // Talking cost must be the amount of minutes times the operator’s talking charge per minute.
    double cost = minute * talkingCharge;

    // Apply discount if the customer’s age is below age 18 (18 is excluded) or higher than 65 (65 is excluded).
    if (customer.getAge() < 18 || customer.getAge() > 65)
    {
        double costAfterDiscount = cost * (static_cast<double>(100 - discountRate) / 100);
        cost = costAfterDiscount;
    }
    return cost;
}

double Operator::calculateMessageCost(int quantity, Customer &customer, Customer* other)
{
    double cost = quantity * messageCost;

    // Customer 1st will receive a discount if customer 2nd is from the same operator.
    if (customer.getOperator()->getID() == other->getOperator()->getID())
    {
        double costAfterDiscount = cost * (static_cast<double>(100 - discountRate) / 100);
        cost = costAfterDiscount;
    }
    return cost;
}

double Operator::calculateNetworkCost(double amount)
{
    // Connection cost must be the amount of MBs times the network cost per MB.
    double cost = amount * networkCharge;

    return cost;
}

double Operator::getTalkingCharge()
{
    return talkingCharge;
}

void Operator::setTalkingCharge(double talkingCharge)
{
    try
    {
        if (talkingCharge < 0.0)
            throw std::invalid_argument("Talking charge must be non-negative.");

        this->talkingCharge = talkingCharge;
    }
    catch (const std::invalid_argument &e)
    {
        std::cout << e.what() << std::endl;
    }
}

double Operator::getMessageCost()
{
    return messageCost;
}

void Operator::setMessageCost(double messageCost)
{
    try
    {
        if (messageCost < 0.0)
            throw std::invalid_argument("Message cost must be non-negative.");

        this->messageCost = messageCost;
    }
    catch (const std::invalid_argument &e)
    {
        std::cout << e.what() << std::endl;
    }
}

double Operator::getNetworkCharge()
{
    return networkCharge;
}

void Operator::setNetworkCharge(double networkCharge)
{
    try
    {
        if (networkCharge < 0.0)
            throw std::invalid_argument("Network charge must be non-negative.");

        this->networkCharge = networkCharge;
    }
    catch (const std::invalid_argument &e)
    {
        std::cout << e.what() << std::endl;
    }
}

int Operator::getDiscountRate()
{
    return discountRate;
}

void Operator::setDiscountRate(int discountRate)
{
    try
    {
        if (discountRate < 0 || discountRate > 100)
            throw std::invalid_argument("Discount rate must be between 0-100.");

        this->discountRate = discountRate;
    }
    catch (const std::invalid_argument &e)
    {
        std::cout << e.what() << std::endl;
    }
}

int Operator::getID()
{
    return ID;
}

int Operator::getTotalSpentTalkingTime()
{
    return totalSpentTalkingTime;
}

int Operator::getTotalSentMessages()
{
    return totalSentMessages;
}

double Operator::getTotalInternetUsage()
{
    return totalInternetUsage;
}

void Operator::addTalkingTime(int minute)
{
    totalSpentTalkingTime += minute;
}

void Operator::addSentMessages(int quantity)
{
    totalSentMessages += quantity;
}

void Operator::addInternetUsage(double amount)
{
    totalInternetUsage += amount;
}

