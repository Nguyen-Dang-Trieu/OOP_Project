#ifndef OPERATOR_H
#define OPERATOR_H

#include <string>
#include "../include/Customer.h"

class Customer; // Forward declaration


class Operator
{
private:
    // ID of the operator.
    int ID;

    // Talking charge of the operator per minute.
    double talkingCharge;

    // Message cost of the operator per message.
    double messageCost;

    // Network charge of the operator per MB.
    double networkCharge;

    // Discount rate of the operator as percentage.
    int discountRate;

    // *** Extra Fields ***
    // Total amount of time the operator has serviced for talking over the course of simulation.
    int totalSpentTalkingTime;

    // Total number of messages sent via the operator over the course of simulation.
    int totalSentMessages;

    // Total amount of Internet usage in terms of MB the operator has provided over the course of simulation.
    double totalInternetUsage;

public:
    // Default Constructor
    Operator();

    /**
     * A constructor with 5 parameters.
     * @param ID ID of the operator.
     * @param talkingCharge Talking charge of the operator per minute.
     * @param messageCost Message cost of the operator per message.
     * @param networkCharge Network charge of the operator per MB.
     * @param discountRate Discount rate of the operator as percentage.
     */
    Operator(int ID, double talkingCharge, double messageCost, double networkCharge, int discountRate);


    /**
     * For calculating the total amount to pay for talking.
     * @param minute Duration of the call in minutes.
     * @param customer Customer who is making the call.
     * @return Talking cost.
     */
    double calculateTalkingCost(int minute, Customer &customer);

    /**
     * For calculating the total amount to pay for messaging.
     * @param quantity Number of messages to be sent.
     * @param customer Customer who is sending the message.
     * @param other Customer who is receiving the message.
     * @return Messaging cost.
     */
    double calculateMessageCost(int quantity, Customer &customer, Customer* other);

    /**
     * For calculating the total amount to pay for connecting to the Internet.
     * @param amount Number of data as MB.
     * @return Network cost.
     */
    double calculateNetworkCost(double amount);

    /**
     * Getter method for talkingCharge.
     * @return Talking charge of the operator per minute.
     */
    double getTalkingCharge();

    /**
     * Setter method for talkingCharge.
     * Throws an exception if the given talking charge is negative.
     * @param talkingCharge New talking charge of the operator per minute.
     */
    void setTalkingCharge(double talkingCharge);

    /**
     * Getter method for MessageCost.
     * @return Message cost of the operator per message.
     */
    double getMessageCost();

    /**
     * Setter method for MessageCost.
     * Throws an exception if the given message cost is negative.
     * @param messageCost New message cost of the operator per message.
     */
    void setMessageCost(double messageCost);

    /**
     * Getter method for networkCharge.
     * @return Network charge of the operator per MB.
     */
    double getNetworkCharge();

    /**
     * Setter method for networkCharge.
     * Throws an exception if the given network charge is negative.
     * @param networkCharge New network charge of the operator per MB.
     */
    void setNetworkCharge(double networkCharge);

    /**
     * Getter method for discountRate.
     * @return Discount rate of the operator as percentage.
     */
    int getDiscountRate();

    /**
     * Setter method for discountRate.
     * Throws an exception if the given discount rate is higher than 100 or lower than 0.
     * @param discountRate New discount rate of the operator as percentage.
     */
    void setDiscountRate(int discountRate);

    // *** Extra Methods ***

    /**
     * Getter method for ID.
     * @return ID of the operator.
     */
    int getID();

    /**
     * Getter method for totalSpentTalkingTime.
     * @return Total amount of time the operator has serviced for talking over the course of simulation.
     */
    int getTotalSpentTalkingTime();

    /**
     * Getter method for totalSentMessages.
     * @return Total number of messages sent via the operator over the course of simulation.
     */
    int getTotalSentMessages();

    /**
     * Getter method for totalInternetUsage.
     * @return Total amount of Internet usage in terms of MB the operator has provided over the course of simulation.
     */
    double getTotalInternetUsage();

    /**
     * Adds to the total spent talking time.
     * @param minute Duration of the call in minutes.
     */
    void addTalkingTime(int minute);

    /**
     * Adds to the total number of sent messages.
     * @param quantity Number of messages to be sent.
     */
    void addSentMessages(int quantity);

    /**
     * Adds to the total Internet usage.
     * @param amount Number of data as MB.
     */
    void addInternetUsage(double amount);
};

#endif