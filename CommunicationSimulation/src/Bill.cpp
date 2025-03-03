#include "../include/Bill.h"

Bill::Bill(double limitingAmount)
{
    if (limitingAmount < 0.0)
    {
        throw std::invalid_argument("Limiting amount must be non-negative.");
    }
    this->limitingAmount = limitingAmount;
    currentDebt = 0.0;
    totalMoneySpent = 0.0;
}

bool Bill::check(double amount) const
{
    return (currentDebt + amount) <= limitingAmount;  // if((currentDebt + amount) <= limitingAmount) 
}

void Bill::add(double amount)
{
    currentDebt += amount;
}

void Bill::pay(double amount)
{
    if (amount < currentDebt)
    {
        currentDebt -= amount;
        totalMoneySpent += amount;
    }
    else
    {
        totalMoneySpent += currentDebt;
        currentDebt = 0.0; // There is no negative debt.
    }
}

void Bill::changeTheLimit(double amount)
{
    limitingAmount = amount;
}

double Bill::getLimitingAmount() const
{
    return limitingAmount;
}

double Bill::getCurrentDebt() const
{
    return currentDebt;
}

double Bill::getTotalMoneySpent() const
{
    return totalMoneySpent;
}