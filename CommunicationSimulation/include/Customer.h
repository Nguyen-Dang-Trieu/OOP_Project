#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <string>
#include <iostream>
#include <sstream>
#include <exception>
#include <iomanip>
#include "../include/Bill.h"
#include "../include/Operator.h"

using namespace std;

class Bill;     // Forward declaration
class Operator; // Forward declaration

class Customer
{
private:
    // ID of the customer.
    int ID;

    // Name of the customer.
    string name;

    // Age of the customer.
    int age;

    // Operator of the customer.
    Operator* operator_; // khai báo là con trỏ bởi bởi vì operator có thể đổi bất cứ lúc nào

    // Bill of the customer.
    Bill* bill;

    // *** Extra Fields ***

    // Total amount of time the customer has spent for talking over the course of simulation.
    int totalSpentTalkingTime;

    // Total number of messages the customer has sent over the course of simulation.
    int totalSentMessages;

    // Total amount of Internet usage of the customer in terms of MB over the course of simulation.
    double totalInternetUsage;

public:
    /**
     * A constructor with five parameters.
     * @param ID ID of the customer.
     * @param name Name of the customer.
     * @param age Age of the customer.
     * @param operator Operator of the customer.
     * @param limitingAmount Limiting amount of the bill of the customer.
     */
    Customer(int ID, string name, int age, Operator *operator_, double limitingAmount);

    ~Customer();

    /**
     * For customers to talk via the operator.
     * @param minute Duration of the call in minutes.
     * @param other Another customer, mainly the second customer.
     */
    void talk(int minute, Customer* other);

    /**
     * For customers to send message.
     * @param quantity Number of messages to be sent.
     * @param other Another customer, mainly the second customer.
     */
    void message(int quantity, Customer* other);

    /**
     * For customers to connect the Internet.
     * @param amountMBs Number of data as MB.
     */
    void connection(double amountMBs);

    /**
     * Getter method for age.
     * @return Age of the customer.
     */
    int getAge();

    /**
     * Setter method for age.
     * Throws an exception if the given age is negative.
     * @param age New age of the customer.
     */
    void setAge(int age);

    /**
     * Getter method for operator.
     * @return Operator of the customer.
     */
    Operator* getOperator();

    /**
     * Setter method for operator.
     * @param operator New operator of the customer.
     */
    void setOperator(Operator* operator_);

    /**
     * Getter method for bill.
     * @return Bill of the customer.
     */
    Bill* getBill();

    /**
     * Setter method for bill.
     * @param bill New bill of the customer.
     */
    void setBill(Bill *bill);

    // *** Extra Methods ***

    /**
     * Getter method for ID.
     * @return ID of the customer.
     */
    int getID();

    /**
     * Getter method for name.
     * @return Name of the customer.
     */
    string getName();

    /**
     * Getter method for totalSpentTalkingTime.
     * @return Total amount of time the customer has spent for talking over the course of simulation.
     */
    int getTotalSpentTalkingTime();

    /**
     * Getter method for totalSentMessages.
     * @return Total number of messages the customer has sent over the course of simulation.
     */
    int getTotalSentMessages();

    /**
     * Getter method for totalInternetUsage.
     * @return Total amount of Internet usage of the customer in terms of MB over the course of simulation.
     */
    double getTotalInternetUsage();

};

#endif