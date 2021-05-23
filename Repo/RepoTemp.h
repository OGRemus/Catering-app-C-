#include "..//Entitites/Entity.h"
#include <vector>
#include <fstream>
#include "../Entitites/EntityType.h"
#include "../Entitites/Courier.h"
#include "../Entitites/Order.h"
#include "../Entitites/Restaurant.h"
#include "../Entitites/Client.h"
#include <string>


using namespace std;



template<class T, entityType type>
class RepoTemp {
private:
    vector<T> elements;
    string fileName;
public:
    RepoTemp();

    RepoTemp(const string& fileName);

    ~RepoTemp();

    string getFileName();

    void setFileName(const string& fileName);

    vector<T> getAll();

    int getSize();

    void addElem(const T &s);

    void updateElem(const T &oldElem, const T &newElem);

    void deleteElem(const T &elem);

    T getById(int id);

    void loadFromFile();

    void saveToFile();

    void clearFile();

    void clearData();

    void setData(vector<T> replace);

};

template<class T, entityType type>
RepoTemp<T, type>::RepoTemp() {
    this->fileName = "";
}

template<class T, entityType type>
RepoTemp<T, type>::RepoTemp(const string& fileName) {
    this->fileName = fileName;
}

template<class T, entityType type>
RepoTemp<T, type>::~RepoTemp() {
    this->elements.clear();
}

template<class T, entityType type>
string RepoTemp<T, type>::getFileName() {
    return this->fileName;
}

template<class T, entityType type>
void RepoTemp<T, type>::setFileName(const string& fileName) {
    this->fileName = fileName;
}

template<class T, entityType type>
void RepoTemp<T, type>::addElem(const T &s) {
    this->elements.push_back(s);
    this->saveToFile();
}

template<class T, entityType type>
void RepoTemp<T, type>::updateElem(const T &oldElem, const T &newElem) {
    typename vector<T, entityType>::iterator it;
    it = find(this->elements.begin(), this->elements.end(), oldElem);
    if (it != this->elements.end()) {
        *it = newElem;
    }
    this->saveToFile();
}

template<class T, entityType type>
void RepoTemp<T, type>::deleteElem(const T &elem) {
    typename vector<T, entityType>::iterator it;
    it = find(this->elements.begin(), this->elements.end(), elem);
    if (it != this->elements.end()) {
        this->elements.erase(it);
    }
    this->saveToFile();
}

template<class T, entityType type>
void RepoTemp<T, type>::loadFromFile() {
    if (this->fileName != "") {
        this->elements.clear();
        ifstream f(this->fileName);
        T t;

        while (f >> t) {
            this->elements.push_back(t);
        }
        f.close();
    }
}

template<class T, entityType type>
void RepoTemp<T, type>::saveToFile() {
    if (this->fileName != "") {
        ofstream f(this->fileName);
        for (int i = 0; i < this->elements.size(); i++) {
            f << this->elements[i] << endl;
        }
        f.close();
    }
}

template<class T, entityType type>
vector<T> RepoTemp<T, type>::getAll() {
    return this->elements;
}

template<class T, entityType type>
int RepoTemp<T, type>::getSize() {
    return this->elements.size();
}

template<class T, entityType type>
T RepoTemp<T, type>::getById(int id) {
    for (auto &i: elements)
        if (static_cast<Entity<type>>(i).getId() == id)
            return i;

    return T();
}

template<class T, entityType type>
void RepoTemp<T, type>::clearFile() {
    ofstream f(this->filename);
    f.close();
}

template<class T, entityType type>

void RepoTemp<T, type>::clearData() {
    elements.clear();
}

template<class T, entityType type>
void RepoTemp<T, type>::setData(vector<T> replace) {
    this->clearData();
    this->clearFile();
    this->elements = replace;
    saveToFile();

}

typedef RepoTemp<Client, entityType_Client> clientRepo;
typedef RepoTemp<Courier, entityType_Courier> courierRepo;
typedef RepoTemp<Order, entityType_Order> orderRepo;
typedef RepoTemp<Restaurant, entityType_Restaurant> restaurantRepo;