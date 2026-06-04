#include <iostream>
using namespace std;

// Abstraction (Interface)
class Database {
public:
    virtual void save(string data) = 0; // Pure virtual function
};

// MySQL implementation (Low-level module)
class MySQLDatabase : public Database {
public:
    void save(string data) override {
        cout << "Executing SQL Query: INSERT INTO users VALUES('" << data << "');" << endl;
    }
};

// MongoDB implementation (Low-level module)
class MongoDBDatabase : public Database {
public:
    void save(string data) override {
        cout << "Executing MongoDB Function: db.users.insert({name: '" << data << "'})" << endl;
    }
};

// High-level module (Now loosely coupled)
class UserService {
private:
    Database* db;  // Dependency Injection

public:
    UserService(Database* database) {  
        db = database;
    }
    
    void storeUser(string user) {
        db->save(user);
    }
};

int main() {
    MySQLDatabase mysql;
    MongoDBDatabase mongodb;

    UserService service1(&mysql);
    service1.storeUser("Aditya");

    UserService service2(&mongodb);
    service2.storeUser("Rohit");
}


// class Database {
// public:
//     virtual void save() = 0;
// };

// class MySQLDatabase : public Database {

// public:
//     void save() {
//         cout << "Saving to MySQL" << endl;
//     }

// };



// class MongoDatabase : public Database {
// public:
//     void save() {
//         cout << "Saving to MongoDB" << endl;
//     }

// };



// class UserService {

// private:

//     Database* db;
// same thing(object) as the one in the main class, client calls the user service

// public:

//     UserService(Database* db) {

//         this->db = db;

//     }
//     void saveUser() {

//         db->save();

//     }

// };



// int main() {

//     Database* db = new MySQLDatabase();//client

//     UserService* user = new UserService(db);

//     user->saveUser();



//     return 0;

// }