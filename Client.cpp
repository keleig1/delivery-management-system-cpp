#include "Client.h"
#include "Exceptions.h"
#include <ostream>

Client::Client(
    const string& name,
    const string& phone,
    const string& email,
    const string& cpf,
    const Address& homeAddress
)
    : User(name, phone, email), cpf(cpf), homeAddress(homeAddress){
    if(cpf.empty()){
        throw ValidationException("CPF CANNOT BE EMPTY.");
    }
    if(!homeAddress.isValid()){
        throw ValidationException("client address is invalid.");
    }
}
const string& Client::getCpf()const{
    return cpf;
}
const Address& Client::getHomeAddress()const{
    return homeAddress;
}
void Client::setHomeAddress(const Address& address){
    if(!address.isValid()){
        throw ValidationException("Client address is invalid.");
    }
    homeAddress = address;
}
int Client::getRequesterId()const{
    return getId();
}
const string& Client::getRequesterName()const{
    return getName();
}
const Address& Client::getDefaultPickupAddress()const{
    return homeAddress;
}
UserType Client::getType()const{
    return UserType::Client;
}
void Client::display(std::ostream& output)const{
    output << "[client]";
    printCommonData(output);
    output << "| CPF: " << cpf  
           << "| Address: " << homeAddress.toString();
}