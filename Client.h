#ifndef DELIVERY_SYSTEM_CLIENT_H
#define DELIVERY_SYSTEM_CLIENT_H

#include "Address.h"
#include "DeliveryRequester.h"
#include "User.h"

#include <iosfwd>
#include <string>
using std::string;
class Client : public User, public DeliveryRequester {
    private:
        string cpf;
        Address homeAddress;
    public:
        Client(
            const string& name,
            const string& phone,
            const string& email,
            const string& cpf,
            const Address& homeAddress
        );
        const string& getCpf()const;
        const Address& getHomeAddress()const;
        void setHomeAddress(const Address& address);

        int getRequesterId() const override;
        const string& getRequesterName() const override;
        const Address& getDefaultPickupAddress() const override;

        UserType getType() const override;
        void display(std::ostream& output) const override;
};
#endif