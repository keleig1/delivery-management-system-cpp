#ifndef DELIVERY_SYSTEM_MOTORBOY_H
#define DELIVERY_SYSTEM_MOTORBOY_H
#include "Address.h"
#include "User.h"
#include <iosfwd>
#include <string>
#include <vector>
using std::vector;

class MotorBoy : public User{
    private:
        string cpf;
        string motorcyclePlate;
        bool available;
        Address currentLocation;
        vector<int> activeDeliveryIds;
        int completedDeliveries;
        std::size_t maxActiveDeliveries;
    public:
        MotorBoy(
            const string& name,
            const string& phone,
            const string& email,
            const string& cpf,
            const string& motorcyclePlate,
            const Address& currentLocation,
            std::size_t maxActiveDeliveries = 1
        );
        const string& getCpf() const;
        const string& getMotorcyclePlate() const;
        const Address& getCurrentLocation() const;
        const std::vector<int>& getActiveDeliveryIds() const;
        int getCompledDeliveries() const;
        std::size_t getMaxActiveDeliveries()const;

        bool isAvailable()const;
        void setAvailable(bool available);
        void setCurrentLocation(const Address& address);
        void assignDelivery(int deliveryId);
        void finishDelivery(int deliveryId);

        UserType getType()const override;
        void display(std::ostream& output) const override;
};
#endif