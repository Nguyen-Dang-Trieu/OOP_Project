#ifndef BILL_H
#define BILL_H

#include <exception>
#include <iomanip>

using namespace std;

class Bill
{
private:
    //Limiting amount of the bill. If a customer would exceed the limit after the actions, then no actions occur.
    double limitingAmount;

    // Current debt of the bill.
    double currentDebt;

    // *** Extra Fields ***

    // Total amount of money the customer has spent for paying their bills over the course of simulation.
    double totalMoneySpent;

public:
    /**
     * Constructor with 1 parameter.
     * Throws an exception if the given limiting amount is negative.
     *
     * @param limitingAmount Limiting amount of the bill.
     */
    Bill(double limitingAmount);

    /**
     * Checks whether the limitingAmount is exceeded or not when a certain amount is about to be added to bill's current debt.
     * @param amount Amount to check.
     * @return TRUE if the limitingAmount is not exceeded, FALSE otherwise.
     */
    bool check(double amount) const;

    /**
     * Adds debt to the bill.
     * This method has to be called with the "boolean check(double amount)" method.
     * @param amount Amount to be added to the current debt.
     */
    void add(double amount);

    /**
     * Pays the bills with the given amount.
     * If someone tries to pay more than her debt, then she must pay the current debt she has.
     * @param amount Amount to be payed from the current debt.
     */
    void pay(double amount);

    /**
     * Changes the limitingAmount, i.e. setter method for limitingAmount.
     * If the current debt would exceed the limit after setting a new limit, then the limit remains unchanged.
     * @param amount New limiting amount of the bill.
     */
    void changeTheLimit(double amount);

    /**
     * Getter method for limitingAmount.
     * @return Limiting amount of the bill.
     */
    double getLimitingAmount() const;

    /**
     * Getter method for currentDebt.
     * @return Current debt of the bill.
     */
    double getCurrentDebt() const;

    // *** Extra Methods ***

    /**
     * Getter method for totalMoneySpent.
     * @return Total amount of money the customer has spent for paying their bills over the course of simulation.
     */
    double getTotalMoneySpent() const;
};


#endif