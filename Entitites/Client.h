//
// Created by geo_r on 22/05/2021.
//

#ifndef APLICATIELIVRARI_CLIENT_H
#define APLICATIELIVRARI_CLIENT_H
#include <string>
#include <ostream>
#include "Entity.h"
#include "EntityType.h"

using namespace std;

class Client :public Entity<entityType_Client> {
protected:
    string adress;
    string username;
    bool premium;
public:

    Client();
    Client(string adress, string username, bool premium);

    const string &getAdress() const;

    void setAdress(const string &adress);

    const string &getUsername() const;

    void setUsername(const string &username);

    bool isPremium() const;

    void setPremium(bool premium);

    friend ostream &operator<<(ostream &os, const Client &client);

    bool operator==(const Client &rhs) const;

    bool operator!=(const Client &rhs) const;

    Client& operator=(const Client& client);

    friend istream& operator>>(istream& is, Client& cl);

};


#endif //APLICATIELIVRARI_CLIENT_H
