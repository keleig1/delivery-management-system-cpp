#ifndef DELIVERY_SYSTEM_ADDRESS_H
#define DELIVERY_SYSTEM_ADDRESS_H
#include <string>
using std::string;
class Address{
private:
    std::string street;
    string number;
    string neighborhood;
    string city;
    string state;
    string postalCode;
    string complement;
public:
    Address();
    Address(
        const string& street,
        const string& number,
        const string& neighborhood,
        const string& city,
        const string& state,
        const string& postalCode,
        const string& complement = ""
    );
    const string& getStreet()const;
    const string& getNumber()const;
    const string& getNeighborhood()const;
    const string& getCity()const;
    const string& getState()const;
    const string& getPostalCode()const;
    const string& getComplement() const;

    bool isValid() const;
    std::string toString() const;
};
#endif