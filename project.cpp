#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int autoidgenrater();
void admin(){
    fstream file ;
    bool login_success = false ;
    string user_name , password , admin_name , admin_password ;
    char choice = 'A' ;
    while (choice != 'Q' && choice != 'q' ){
    cout<<"Enter Admin Username and Password  : \n" ;
    cin>>admin_name>>admin_password ;
    file.open ("Password.txt", ios::in ) ;
    

    while (file >> user_name >> password){
        if (user_name == admin_name && password == admin_password){
            cout<<"Login Successful \n" ;
               login_success = true ;
            break;
        }
        else {
            cout<<"Login Failed in correct credentials  \n" ;
            cout<<"Press Q to quit or any other key to try again \n" ;

            cin>>choice ;
            if (choice == 'Q' || choice == 'q'){
                return ;
            }
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
    cout << "Welcome  "<<admin_name<<" as admin \n" ;
    cout << "1.Want to add (press 1) : \n";
    cout << "2.remove an employee (Press 2)\n";
    cout << "3.View employee report (press 3) : \n";
    cout << "4.View employee attandance (press 4) : \n";
    cin >> choice1;

    char choice2='a'; 
    while (choice2 == 'a' || choice2 == 'A'  ){
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
        file2.open("Employeedatabase.txt" , ios :: app );

        file2 << newid << " " << department << " " << postion << " " <<salary << " " << empname<< "\n" ;
        file2.close();
        cout << "To enter an othere employee press 'A' or any othere key to continue :\n";
        cin >> choice2;
        
      }
      if(choice1 == 2){
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
         <<"3. FINANCE (press F)\n Press Q to quit\n" ;
    cin>>choice ;
    switch (choice){
        case 'A' :
        case 'a' :
            admin();
        break;
        case 'M' :
        case 'm' :
            cout<<"Employee Section \n" ;
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