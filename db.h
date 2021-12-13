class Db{
public:
    Db(){
        db = "firstdb";
        server = "localhost";
        user = "root";
        password = "123456";
    }
    const char* getdb(){
        return db;
    }
    const char* getserver(){
        return server;
    }
    const char* getuser(){
        return user;
    }
    const char* getpassword(){
        return password;
    }
private:
    const char* db = 0, *server = 0, *user = 0, *password = "";
};

