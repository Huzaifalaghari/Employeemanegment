#include <iostream>
#include <fstream>
#include <string>
using namespace std;
void maneger();
int autoidgenrater();
void Viewattandanve();
void Employeereport();
void admin(){
    fstream file , filemang;
    bool login_success = false ;
    string user_name , password , admin_name , admin_password ;
    char choice = 'A' ;
    while (choice != 'Q' && choice != 'q' ){
    cout<<"Enter Admin Username : \n" ;
    cin.ignore();
    getline (cin , admin_name) ;
    cout << "Enter Password : \n";
    cin >> admin_password;
    file.open ("adminpassword.txt", ios::in ) ;
    login_success = false;

    while ( file >> password){
        getline(file >> ws , user_name);
        if (user_name == admin_name && password == admin_password){
            cout<<"Login Successful \n" ;
               login_success = true ;
            break;
        }
    }
    if (!login_success){
            cout<<"Login Failed in correct credentials  \n" ;
            cout<<"Press Q to quit or any other key to try again \n" ;

            cin>>choice ;
            if (choice == 'Q' || choice == 'q'){
                return ;
            }
      }    
    if (login_success){
        break;
    }
    
    file.close();
 }  

    if (login_success){
    int choice1 ; 
    double salary ; 
    string empname,department,postion; 
    fstream file2; 
    char choice2='a'; 
    cout << "Welcome  "<<admin_name<<" as admin \n" ;
    while (choice2 == 'a' || choice2 == 'A'  ){
    cout << "1.Want to add Employee (press 1) : \n";
    cout << "2.remove an employee (Press 2)\n";
    cout << "3.View employee report (press 3) : \n";
    cout << "4.View employee attandance (press 4) : \n";
    cin >> choice1;
    if (!cin){
        cout << "Invalide input! enter a number from (1-4) \n";
        cin.clear ();
        cin.ignore(1000,'\n');
        continue;
    }

    if (choice1 == 1 ){
        cout << "Enter employee name  : \n";
        cin.ignore();
        getline (cin,empname);
        cout << "Enter Employee Department : \n";
        cin >> department ;
        cout << "Enter employee Postion :\n";
        cin >> postion;
        cout << "Enter employee Salary :\n";
        cin >> salary;
        cout << "Uploading Credentials on reccord.... \n";
        
        
        int newid = autoidgenrater();    
        filemang.open ("Employeerecord.txt",ios ::app);                                                     
        file2.open("Employeedatabase.txt" , ios :: app );

        file2 << newid << " " << department << " " << postion << " " <<salary << " " << empname<< "\n" ;
        filemang << newid << " " << empname << " ";

        filemang.close();
        file2.close();
        cout << "To go back to admin dassbooard press 'A' or any othere key to go to main page :\n";
        cin >> choice2;
        
      }
       else if(choice1 == 2){
        bool match = false ;
        fstream tempfile;
        file2.open("Employeedatabase.txt",ios :: in );
        tempfile.open ("temp.txt", ios :: out);
        double salary;
        int newid,detid;
        string empname,department;
        cout << "Enter id no. to delete Employee record : \n";
        cin >> detid;
        while (file2 >> newid >>  department >> postion >> salary  ){
            getline(file2 , empname);
            if (detid==newid){
                match = true ;
                cout << "Deleting Employee " << detid << " "<< empname << "\n";

            }else {
                tempfile << newid << " " << department << " " << postion << " " <<salary << " " << empname<< "\n" ; 
            }

         }
         if (match){
            cout << "Deleted succesfully \n";
         }else {
            cout << "Id not found \n";
         }
         tempfile.close ();
         file2.close ();
         remove ("Employeedatabase.txt");
         rename ("temp.txt","Employeedatabase.txt");
    } else {
        cout << "Invalid choice Press a to try again or Q to quit to main page : \n ";
        cin  >> choice2 ;
        if (choice2 == 'Q' || choice2 == 'q'){
            return ;
        }
    }
           
   }

 }


    
}
using namespace std;
int main (){
   
    char choice ;
    cout<<"Welcome to Employee Management System \n\n";
    while (choice != 'Q' && choice != 'q'){
    cout<<"ENTER AS : \n 1. ADMIN (press A) \n 2. Maneger (press M) \n "
         <<"3. FINANCE (press F)\n Press Q to quit programm\n" ;
    cin>>choice ;
    
    switch (choice){
        case 'A' :
        case 'a' :
            admin();
        break;
        case 'M' :
        case 'm' :
            maneger ();
        break ;
        case 'F' :
        case 'f' :
            cout<<"Finance Section \n" ;
        break ; 
        case 'Q' :
        case 'q' :
            cout<<"Exiting the system. Goodbye!\n" ;
        break ;
        default :
            cout<<"Invalid choice. Please try again.\n" ;
    }
    }
    return 0 ;
} 
int autoidgenrater(){     
    int id , maxid = 0 ;
    double salry ;
    string name , dep, postion , empname;
    fstream file;                                                                                      
    file.open("Employeedatabase.txt" , ios :: in);                                     
    while (file >> id >> dep >> postion >> salry ){
        getline (file , empname  );
        if (id > maxid ){
            maxid = id;
        }

       
        
    }
    file.close ();
    return maxid + 1; 

} 
void maneger (){
    fstream file ;
    bool login_success = false ;
    string user_name , password , maneger_name , maneger_password;
    char choice = 'A' ;
    while (choice != 'Q' && choice != 'q' ){
    cout<<"Enter maneger Username : \n" ;
    cin.ignore();
    getline (cin , maneger_name) ;
    cout << "Enter Password : \n";
    getline (cin , maneger_password);
    file.open ("manegerpassword.txt", ios::in ) ;
    
    while (file >> password){
        getline(file >> ws , user_name);
        if (maneger_name == user_name && password == maneger_password){
            cout<<"Login Successful \n" ;
               login_success = true ;
            break;
        }
    }
    if (!login_success){
            cout<<"Login Failed in correct credentials  \n" ;
            cout<<"Press Q to quit or any other key to try again \n" ;

            cin>>choice ;
            if (choice == 'Q' || choice == 'q'){
                return ;
            }
      }    
    if (login_success){
        break;
    }
    
    file.close();
 }  if (login_success){
    fstream file2,file3;
    char choice = 'A';
    char manchoice ;
    file2.open ("Employeerecord.txt" , ios :: in);
    cout <<"Welcome "<<user_name<<" as maneger \n";
    while (choice !='Q' || choice!='q'){
        cout << "1. To mark Attandance and rate employee (press A) \n";
        cout << "2. Generate employee report (press B)\n";
        cout << "3. Rate Employee performance (press C)\n";
        cin >> manchoice;
        if (manchoice == 'A' || manchoice == 'a'){
            cout << "===Employee list===\n";
            cout << "ID no.  |   name\n ";
            cout << "----------------------\n ";
            int id ;
            string name ;
            int empids [10];
            int i = 0;
            string empnames[10];
            while (file2 >> id && i < 10){
                getline (file2 >> ws , name);
                empids [i] = id;
                empnames [i] = name ;
                i++;
                cout << id << "\t" << name <<"\n";
            }
             file2.close();
             string date ;
             cout << "Enter Todays date (MM-DD-yy)\n";
             cin.ignore();
             getline (cin , date);
             file3.open ("Attandence.txt" , ios :: app );
             for (int j = 0 ; j < i ; j++){
                cout << "Employee name "<<empnames [j] <<" Emplo. id "<<empids [j]<<"\n";
                cout << "Mark (A = absent, L = late, H = half day )\n";
                char mark ;
                cin >> mark ;
                cin.ignore ();
                string remarks ;
                if (mark == 'A' || mark == 'a'){
                    cout << "Reson for absent \n";
                    getline (cin , remarks);
                }else if (mark == 'L' || mark == 'l' ){
                    cout << "late by (minutes)\n";
                    getline (cin , remarks);
                }else {
                    remarks = '_';
                }
                int rating ;
                cout << "Rate performance today (1-5) \n";
                cin >> rating;
                file3 << empids[j]<<" "<< date << " " << mark << " "<< remarks << " " << rating << "\n";

             }
             file3.close();


        }

    }

 }
}