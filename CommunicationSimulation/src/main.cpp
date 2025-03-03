#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <string>
#include <limits>
#include "../include/Bill.h"
#include "../include/Customer.h"
#include "../include/Operator.h"

using namespace std;


std::vector<std::string> split(const std::string str){
    std::vector<std::string> tokens;
    size_t start = 0, end;
    start = start + 2; // vì muốn bỏ đi 2 kí tự đầu tiên: 1 kí tự để xác định tyOfOperator + 1 kí tự " "
    
    while((end = str.find(" ",start)) != std::string::npos){
        if(end > start){
            tokens.push_back(str.substr(start, end - start)); // push_back thêm phần tử vào cuối vector
        }
        start = end + 1;
    }

    // Thêm chuỗi con cuối cùng khi không còn dấu " " để tách chuỗi. Có thể xóa để xem tác dụng của đoạn code này
    if (start < str.size()) {
        tokens.push_back(str.substr(start));
    }

    return tokens;
}

// Hàm tìm customer có giá trị lớn nhất dựa trên một hàm so sánh
Customer* findMaxCustomer(Customer** customers, int size, auto getValue) {
    if (size == 0) return nullptr;

    return *std::max_element(customers, customers + size,
                           [&](Customer* a, Customer* b) {
                               if (getValue(a) < getValue(b)) return true;
                               if (getValue(a) == getValue(b) && a->getID() > b->getID()) return true;
                               return false;
                           });
}

int main()
{
    ifstream inputFile;  // file dau vao
    ofstream outputFile; // file dau ra

    // Mở file để đọc
    inputFile.open("D:\\WORK_SPACE\\OOP\\testcases\\input_5.txt", ios_base::in);
    if (!inputFile)
    {
        cerr << "Error can't open input file!" << endl;
        return 1;
    }

    int C, O, N;

    inputFile >> C >> O >> N;
    inputFile.ignore(); // xóa các kí tự còn sót lại trong buffer stream

    cout << "C: " << C << endl;
    cout << "O: " << O << endl;
    cout << "N: " << N << endl;

    Customer **customers = new Customer *[C];
    Operator **operators = new Operator *[O];

    int customerCount = 0;      // Counters for customers
    int operatorCount = 0;      // Counters for operators

    for (int i = 0; i < N; i++)  // i < N
    {
        string currentLine;
        if (!getline(inputFile, currentLine)) // getline: return true if success
        { 
            cerr << "Error reading line!" << endl;
            break;
        }

        int typeOfOperation = currentLine[0] - '0';
        std::vector <std::string> result; // dùng để chứa chuỗi sau khi tách


        switch (typeOfOperation)
        {
        case 1:{
            result = split(currentLine);
            string name = result[0];
            int age = std::stoi(result[1]);
            int idOfOperator = std::stoi(result[2]);
            int limitingAmount = std::stoi(result[3]);

            customers[customerCount] = new Customer(customerCount, name, age, operators[idOfOperator], limitingAmount);
            customerCount++;

            break;
        }

        case 2:{
            result = split(currentLine);
            float talkingCharge = std::stof(result[0]);
            float messageCost = std::stof(result[1]);
            float networkCharge = std::stof(result[2]);
            int discountRate = std::stof(result[3]);

            operators[operatorCount] = new Operator(operatorCount, talkingCharge, messageCost, networkCharge, discountRate);
            operatorCount++;
            break;
        }

        case 3:{    // Talking
            result = split(currentLine);
            int _1stCustomerID = std::stoi(result[0]);
            int _2stCustomerID = std::stoi(result[1]);
            int time = std::stoi(result[2]);

            customers[_1stCustomerID]->talk(time, customers[_2stCustomerID]);
            break;
        }
        case 4:{    // Message
            result = split(currentLine);
            int _1stCustomerID = std::stoi(result[0]);
            int _2stCustomerID = std::stoi(result[1]);
            int quantityOfMessage = std::stoi(result[2]);

            customers[_1stCustomerID]->message(quantityOfMessage, customers[_2stCustomerID]);
            break;
        }
        case 5:{    // Internet
            result = split(currentLine);
            int customerID = std::stoi(result[0]);
            double amountMBs = std::stod(result[1]);

            customers[customerID]->connection(amountMBs);
            break;
        }
        case 6:{ // Pay money
            result = split(currentLine);
            int customerID = std::stoi(result[0]);
            double payMoney = std::stod(result[1]);

            customers[customerID]->getBill()->pay(payMoney);
            break;
        }
            
        case 7:{ // change the operator
            result = split(currentLine);
            int customerID = std::stoi(result[0]);
            int operatorID = std::stoi(result[1]);

            customers[customerID]->setOperator(operators[operatorID]);

            break;
        }
        case 8:{
            result = split(currentLine);
            int customerID = std::stoi(result[0]);
            double amount = std::stod(result[1]);
            customers[customerID]->getBill()->changeTheLimit(amount);
            break;
        }
        default:
            cout << typeOfOperation << endl;
            break;
        }
    }

    inputFile.close();

    // Output
    for(int i = 0; i < O; i++){
        cout << "Operator " << i << ":" << " " << operators[i]->getTotalSpentTalkingTime() << " "
                                               << operators[i]->getTotalSentMessages() << " "
                                               << operators[i]->getTotalInternetUsage() << " "                           
        << endl;
    }
    for(int i = 0; i < C; i++){
        cout << "Customer " << i << ":" << " " << customers[i]->getBill()->getTotalMoneySpent() << " "
                                               << customers[i]->getBill()->getCurrentDebt() << " "
        << endl;
    }
    // Talking the most
    Customer* maxTalkingCustomer = findMaxCustomer(customers, C, [](Customer* c) { return c->getTotalSpentTalkingTime(); });
    if (maxTalkingCustomer) {
        std::cout << maxTalkingCustomer->getName() << ": " << maxTalkingCustomer->getTotalSpentTalkingTime() << std::endl;
    }
    // Message the most
    Customer* maxMessageCustomer = findMaxCustomer(customers, C, [](Customer* c) { return c->getTotalSentMessages(); });
    if(maxMessageCustomer){
    std::cout << maxMessageCustomer->getName() << ": " << maxMessageCustomer->getTotalSentMessages() << std::endl;
    }
    // Internet the most
    Customer* maxInternetCustomer = findMaxCustomer(customers, C, [](Customer* c) { return c->getTotalInternetUsage(); });
    if(maxInternetCustomer){
    std::cout << maxInternetCustomer->getName() << ": " << maxInternetCustomer->getTotalInternetUsage() << std::endl;
    }
 

    return 0;
}


