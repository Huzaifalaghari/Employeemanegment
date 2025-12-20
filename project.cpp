#include <iostream>

#include <fstream>

#include <string>  //to handle strings 
#include <sstream>

using namespace std;

string login ();

void maneger();

int autoidgenrater();

void finance ();

void Employeereport();

void admin(){  

    char choice2='a';    

    cout << "Welcome as admin \n" ;

    do {

    int choice1 ;                                             //for user choice

    double salary ; 

    string empname,department,postion;

    fstream file2,filemang; 
    
    cout << "1.Want to add Employee (press 1) : \n";

    cout << "2.remove an employee (Press 2)\n";

    cin >> choice1;

    if (!cin){                                                     // for error handling 
        cout << "Invalide input! enter a number from (1-4) \n";

        cin.clear ();

        cin.ignore(1000,'\n');

        continue;
    }

    if (choice1 == 1 ){

        cout << "Enter employee name  : \n";

        cin.ignore();                                             //to ignore previous cin's \n
        getline (cin,empname);

        cout << "Enter Employee Department : \n";

        cin >> department ;

        cout << "Enter employee Postion :\n";

        cin >> postion;

        cout << "Enter employee base Salary :\n";

        cin >> salary; //base salary

        while (salary < 0){

            cout << "invalide salary try again : \n";

            cin >> salary;
        }
        
        cout << "Uploading Credentials on reccord.... \n";
        
        
        int newid = autoidgenrater();    

        filemang.open ("Employeerecord.txt",ios ::app);                    //made Employeerecord.txt to store only name and id (for attandance)                                                                    
        file2.open("Employeedatabase.txt" , ios :: app );

        if (!file2){

            cout << "coudn't acces file \n";

            return ;
        }

        file2 << newid << " " << department << " " << postion << " " <<salary << " " << empname<< "\n" ;   //stores all info in Employeedatabase.txt with spaces 
        filemang << newid << " " << empname << " " << "\n";                                               //stores in Employeerecord.txt with spaces

        filemang.close();
        file2.close();

        cout << "To go back to admin dassbooard press 'A' or 'Q' key to quit \n";

        cin >> choice2;

        if (choice2 == 'Q' || choice2 == 'q'){

            return ;
        }
        
      }
       else if(choice1 == 2){

        bool match = false ;

        fstream tempfile;                                 //temporary file to store 

        file2.open("Employeedatabase.txt",ios :: in );

        if (!file2){

            cout << "coudnt acces file \n";

            return ;
        }
        tempfile.open ("temp.txt", ios :: out);

        double salary;

        int newid,detid;

        string empname,department;

        cout << "Enter id no. to delete Employee record : \n";

        cin >> detid;

        while (file2 >> newid >>  department >> postion >> salary  ){ 

            getline(file2 , empname);

            if (detid==newid){                                                   //macthing id to delete
                match = true ;

                cout << "Deleting Employee " << detid << " "<< empname << "\n";


            }else {

                tempfile << newid << " " << department << " " << postion << " " <<salary << " " << empname<< "\n" ;  //stores in tempfile except the id to delete
            }

         }
         if (match){

            cout << "Deleted succesfully \n";

         }else {

            cout << "Id not found \n";

         }
         tempfile.close ();

         file2.close ();

         remove ("Employeedatabase.txt");                             //deletes Employeedatabase.txt
         rename ("temp.txt","Employeedatabase.txt");                  //renames temp with Employeedatabase.txt
    } else {

        cout << "Invalid choice Press A to try again or Q to quit to main page : \n ";

        cin  >> choice2 ;

    }
       
   }while (choice2 != 'q' && choice2 != 'Q');
    
}

int main (){

    string user1 = "admin",user2 = "maneger",user3 = "finance";

   cout << "============== WELCOME OT EMPLOYEE MANEGMENT SYSTEM =================\n";

   cout << "Login to continue   \n";

   string usertype = login ();                      //login returns user type 
   
   if (usertype == user1){

    admin ();

    }

    else if (usertype == user2){

    maneger ();

    }

    else if (usertype == user3){

    finance ();

    } 

    return 0 ;
} 

int autoidgenrater(){
                     //takes previous id from file and adds 1 in it 
    int id , maxid = 0 ;

    double salry ;

    string name , dep, postion , empname;

    fstream file;

    file.open("Employeedatabase.txt" , ios :: in);

    while (file >> id >> dep >> postion >> salry ){

        getline ( file , empname );

        if (id > maxid ){

            maxid = id;

        }
       
        
    }
    file.close ();

    return maxid + 1;  //returns after adding i plus in previous empid 

} 
void maneger (){

    fstream file2,file3;       

    char choice = 'A';

    char manchoice ;

    file2.open ("Employeerecord.txt" , ios :: in);

    cout <<"Welcome as maneger \n";

    while (choice !='Q' && choice!='q'){

        cout << "1. To mark Attandance (press A) \n";

        cout << "2. Generate employee report (press B)\n";

        cout << "3. Rate Employee performance (press C)\n";

        cout << "4. press Q to quit \n";

        cin >> manchoice;

        if (manchoice == 'A' || manchoice == 'a'){

            cout << "===Employee list===\n";

            cout << " ID no.  |   name\n ";

            cout << "----------------------\n";

            int id ;

            string name ;

            int empids [100];  //max 100 employees

            int i = 0;

            string empnames[100];

            while (file2 >> id && i < 100){

                getline (file2 >> ws , name);             //>>ws is used for spaces before name 
                empids [i] = id;

                empnames [i] = name ;

                i++;
                cout << id << "\t" << name <<"\n";                   // shows every employee in file .
            }
             file2.close();

             string date ;

             cout << "Enter Todays date (MM-DD-yy)\n";

             cin.ignore();

             getline (cin , date);

             file3.open ("Attenden.txt" , ios :: app );

             for (int j = 0 ; j < i ; j++){

                cout << "Employee name "<<empnames [j] <<" Emplo. id "<<empids [j]<<"\n";

                cout << "Mark (A = absent, L = late, H = half day , P = present)\n";

                char mark ;

                cin >> mark ;

                cin.ignore ();

                string remarks ;

                if (mark == 'A' || mark == 'a'){

                    cout << "Reson for absent \n";

                    getline (cin , remarks);

                }else if (mark == 'L' || mark == 'l' ){   

                    cout << "late by (minutes)\n";

                    getline (cin , remarks);  // used remarks twice as only one will work 

                }else {

                    remarks = '_'; // leave remarks _ in file 

                }

                file3 << empids[j]<<" "<< date << " " << mark << " "<< remarks << "\n" ;

                cout << "Entered data Press any key to mark othere employee (To quit press Q)\n";

                cin >> choice ;
                if (choice == 'Q' || choice == 'q'){
                    return ;
                }

             }

             file3.close();


        }else if (manchoice == 'B' || manchoice == 'b'){

            string name , date , remarks ,rating , atttandance , fid;

            int wq ,pd ,tw , cm;  //wq work quality , pd productive , tw , team work , cm communication 

            char choice ;

            fstream file0 , file4;

            file0.open ("Employeerating.txt" , ios :: in);

            file4.open ("Attenden.txt" , ios :: in);  

            string id , fid2;   //id to take from user fid2 to store from file .
             
            bool match  = false ;

            bool match2  = false ;

            cout << "Enter id of Employee to generate report \n";

            cin >> id;

                while (file0 >> fid2 >> wq >> pd >> tw >> cm){

                    if (fid2 == id) {  

                        match2 = true ;

                        cout << "Employee Performance rating \n";

                        cout << "Workquality \t productivity \t Team work \t communication \n";

                        cout << "\t" << wq << "\t\t" << pd << "\t\t" << tw << "    \t" << cm << "\t(out of 10 )" <<endl; 
                    }
                }
                if (!match2){

                    cout << "Didnt found Employees performance rating\n";
                }
                cout << "Enter q to quit or any key to continue \n";

                cin >> choice ;

                if (choice == 'Q' || choice == 'q'){

                     return ;
                }

                
            
            file0.close();
            file3.close ();
        }else if (manchoice == 'c' || manchoice == 'C'){

            int id ;  

            fstream file3 , file;

            int wq ,pd ,tw , cm;

            cout << "Enter employee id \n";

            cin >> id;

            cout << "Rate Employee work quality (out of 10) \n";

            cin >> wq;

            cout << "Rate employee productivity (out of 10 )\n";

            cin >> pd;

            cout << "Rate employee teamWork (out of 10 )\n";

            cin >> tw;

            cout << "Rate employee coummunication (out of 10 )\n";

            cin >> cm;

            file3.open ("Employeerating.txt" , ios :: app );

            if (!file3){                             

               cout << "File not openned \n";
            }
            while (file)
            file3 << id << " " << wq << " " << " "<< pd << " "<< tw << " "<< cm << "\n";  //stores every crdential with space.

            cout << "Entered record \n";
             
        } else if (manchoice == 'q' || manchoice == 'Q'){

            return ;
        }
        
         else {

            cout << "incorect choice!! Try again \n";
        }

    }
 
}
string login (){

    fstream file;

    const int maxattemp = 3; //for only certain max atttemps

    int attemp = 1;

    bool login = false ;

    string  ruserT ;

    do {

        string name , username , user_type , password , userpassword ;

        cout << "Enter your user name : \n";

        getline (cin , username);

        cout << "Enter you password : \n";

        getline (cin , userpassword);

        file.open ("login.txt",ios :: in );         // login.txt contains user name user type and password.

        if (!file){

            cout << "Coudnt open file \n";
        }
        string line ;

        while (getline (file , line )){     //takes compplete line til /n and store in line 

            stringstream ss(line);

            getline (ss , name,',' );  //ignore , in file 

            getline (ss , password , ',');

            getline (ss , user_type , ',');

            if (name [0] == ' ')name.erase (0,1); //to erase leading space

            if (password [0] == ' ')password.erase (0,1);

            if (user_type [0] == ' ')user_type.erase (0,1);  

            if (name == username && password == userpassword){

                login = true ;

                ruserT = user_type;

                break;
            }
        }
        file.close();

        if (login){

            cout << "Login succesful \n";

            return ruserT  ;
        }else {

            cout << "INVALIDE CREDENTIALS "<<maxattemp - attemp<<" ATEMPS LEFT \n";

        }
        attemp++;

    }while (attemp <= maxattemp);

    cout << "Max atemps reached \n";

    return "";  
}
void finance (){

    const int travedlallowance = 4000;

    const int mealallowance = 3000;

    const int medicalallowance = 5000;

    bool choice1;

    const int dedutax = 1500;

    int housingaloawance , childeduallowance ;

    int id,fid , fsalary;    //id from user fid from file // fsalary from file

    fstream file ;

    string fname , fdepart , fpost ;  //f for file

    char choice ;

    cout << "Welocome as finance \n";

    do {

    cout << "1. calculate Employee salary slip (press A)\n";

    cout << "2. Calculate net salary (press B)\n";

    cout << "Press q to quit \n";

    cin >> choice ;
    
    if (choice == 'A' || choice == 'a'){

        cout << "Enter Employee id \n";

        cin >> id ;
        
        cout << "Enter Enter employee housing Allowance \n";

        cin >> housingaloawance;

        cout << "Enter education allaowance \n";

        cin >> childeduallowance;

        file.open ("Employeedatabase.txt" , ios :: in);

        while (file >> fid >> fdepart >> fpost >> fsalary >> fname){

            if (id == fid){

                cout << fname << "'s "<<"salary slip \n";

                cout << "base salary :\t houseing alloance :\teducation alloance : \n";

                cout << fsalary <<"\t\t\t "<<housingaloawance<<"\t\t\t"<<childeduallowance << "\n";

                cout << "Medical alloance : \t meal alloance : \t Travel alloance : \t Tax duduction :\n";

                cout << medicalallowance << "\t\t\t\t" <<mealallowance << "\t\t\t" << travedlallowance << "\t\t\t" << dedutax<<"\n";

                cout << "NET SALARY : "<< fsalary+housingaloawance+childeduallowance+medicalallowance+mealallowance+travedlallowance-dedutax <<"\n";

                file.close ();
            }
        }

    }
      else if (choice == 'B' || choice == 'b'){

        int id ;

        cout << "Enter Employee ID \n";

        cin >> id ;

        cout << "Enter Enter employee housing Allowance \n";

        cin >> housingaloawance;

        cout << "Enter education allaowance \n";

        cin >> childeduallowance;

        file.open ("Employeedatabase.txt", ios :: in);

        while (file >> fid >> fdepart >> fpost >> fsalary >> fname ){

            if (id == fid){

                cout << fname <<"'s"<<" NET SALARY IS : "<<fsalary+housingaloawance+childeduallowance+medicalallowance+mealallowance+travedlallowance-dedutax;

            }
        }

    } else if (choice != 'q' && choice != 'Q' ) {

         cout << "Incorrect choice try again \n"; 
    }
   }while(choice != 'q' && choice != 'Q');
}