#ifndef DELIVERY_SYSTEM_USER_H
#define DELIVERY_SYSTEM_USER_H
#include "Enums.h"
#include <iosfwd>
#include <string>
using std::string;
class User{
    private:
        static int nextId;
        int id;
        string name;
        string phone;
        string email;
        static void requireNotEmpty(
            const string& value,
            const string& fieldName
        );
    protected:
        User(
            int id,
            const string& name,
            const string& phone,
            const string& email
        );
        void printCommonData(std::ostream& output) const;
    public:
        User(
            const string& name,
            const string& phone,
            const string& email
        );
        virtual ~User();
        User(const User&) = delete;
        User& operator=(const User&) = delete;

        int getId() const;
        const string& getName() const;
        const string& getPhone() const;
        const string& getEmail() const;

        void setName(const string& name);
        void setPhone(const string& phone);
        void setEmail(const string& email);

        virtual UserType getType() const = 0;
        virtual void display(std::ostream& output) const = 0;
};
#endif