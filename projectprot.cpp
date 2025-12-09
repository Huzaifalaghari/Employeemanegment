#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
using namespace std ;
string login (){
    fstream file;
    const int maxattemp = 3;
    int attemp = 0;
    bool login = false ;
    string  userT;
    do {
        string name , username , user_type , password , userpassword ;
        cout << "Enter your user name : \n";
        getline (cin , username);
        cout << "Enter you password : \n";
        getline (cin , userpassword);
        file.open ("login.txt",ios :: in );
        if (!file){
            cout << "Coudnt open file \n";
        }
        string line ;
        while (getline (file , line )){
            stringstream ss(line);
            getline (ss , name,',' );
            getline (ss , password , ',');
            getline (ss , user_type , ',');

            if (name [0] == ' ')name.erase (0,1);
            if (password [0] == ' ')password.erase (0,1);
            if (user_type [0] == ' ')user_type.erase (0,1);  

            if (name == username && password == userpassword){
                login = true ;
                userT = user_type;
                break;
            }
        }
        file.close();

        if (login){
            cout << "Login succesful \n";
            return userT;
        }else {
            cout << "INVALIDE CREDENTIALS "<<maxattemp - attemp<<" ATEMPS LEFT \n";

        }
        attemp++;

    }while (attemp <= maxattemp);
    cout << "Max atemps reached \n";
    return "";
}

int main (){
    string usertype = login ();
    return 0 ;
}
