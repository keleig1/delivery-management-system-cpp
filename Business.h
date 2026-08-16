#ifndef DELIVERY_SYSTEM_BUSINESS_H
#define DELIVERY_SYSTEM_BUSINESS_H
#include "Address.h"
#include "DeliveryRequester.h"
#include "User.h"
#include <iosfwd>
#include <string>
using std::string;
class Business : public User, public DeliveryRequester{
    private:
        std::string cnpj;
        string companyName;
        Address businessAddress;
    public:
        Business(
            const string& contactName,
            const string& phone,
            const string& email,
            const string& cnpj,
            const string& companyName,
            const Address& businessAddress
        );
};
#endif