#include<iostream>
#include<fstream>
#include<string>

using namespace std;

class shopping{

    private:
        int pcode;
        float price;
        float dis;
        string pname;
    
    public:
        void menu();
        void admin();
        void buyer();
        void add();
        void edit();
        void removeitem();
        void list();
        void receipt();
};

void shopping :: menu(){

    m:
    system("CLS");
    int choises;
    string email;
    string password;

    cout<<"\n\n\n\n\n\n\n";
    cout<<"\t\t\t\t----------------------------------------\n ";
    cout<<"\t\t\t\t\tSUPERMARKET MAIN MENU\n\n";
    cout<<"\t\t\t\t        For Admin Press  1\n\n";
    cout<<"\t\t\t\t        For Buyer Press  2\n\n";
    cout<<"\t\t\t\t        To  Exit  Press  3\n\n";
    cout<<"\t\t\t\t---------------------------------------\n ";
    int op;
    cout<<"\t\t\t\t           SELECT OPTION : ";
    cin>>op;
    switch(op){ 
        case 1 : 
                 cout<<"\n\n\t\t\t\tEnter Admin Email and Password:\n";
                 cout<<"\n\t\t\t\t\t\t";
                 cin>>email;
                 cout<<"\n";
                 cout<<"\t\t\t\t\t\t";
                 cin>>password;   
                 if(email=="admin" && password=="admin"){
                    admin();
                 }
                 else{
                    cout<<"\n\t\t\t\t Invalid login credentials\n\n\n";
                    cout<<"\t\t\t\t";
                    system("PAUSE");                    
                    system("CLS");
                 }
                 break;

        case 2 :{
                        buyer();
                }
                break;
        case 3 :{
                    exit(0);
                }
        default:cout<<"\n\n\n\t\t\t\tWrong option selected\n\n";
            cout<<"\t\t\t\t";
                system("PAUSE");
                system ("CLS");
                
    }
    goto m;
}

void shopping :: admin(){
    
    m:

    system("CLS");
    int choise;
     
  
    cout<<"\n\n\n\n\n\n\n";
    cout<<"\t\t\t\t----------------------------------------\n ";
    cout<<"\t\t\t\t\t  ADMIN   MENU\n\n";
    cout<<"\t\t\t\t        To  Add   Press  1\n\n";
    cout<<"\t\t\t\t        To Modify Press  2\n\n";
    cout<<"\t\t\t\t        To Delete Press  3\n\n";
    cout<<"\t\t\t\t        To  Exit  Press  4\n\n";
    cout<<"\t\t\t\t---------------------------------------\n ";
    cout<<"\n\t\t\t\t           SELECT OPTION : ";
    cin>>choise;
    

    switch(choise){
        case 1: add();
                break;
        case 2: edit();
                break;
        case 3: removeitem();
                break;
        case 4: menu();
                break;
        default: cout<<"\n\n\t\t\t\t\tEnter correct option \n";
                    cout<<"\n\t\t\t\t\t";
                    system("PAUSE");                    
                    system("CLS");
    }
    goto m;
} 

void shopping :: buyer(){

    m:
    system("CLS");
    int c;
    cout<<"\n\n\n\n\n\n\n";
    cout<<"\t\t\t\t----------------------------------------\n ";
    cout<<"\t\t\t\t\t  BUYER   MENU\n\n";
    cout<<"\t\t\t\t        To  Buy   Press  1\n\n";
    cout<<"\t\t\t\t        To  Exit Press   2\n\n";
    cout<<"\t\t\t\t---------------------------------------\n ";
    cout<<"\n\t\t\t\t           SELECT OPTION : ";
    cin>>c;

    switch(c){
        case 1: receipt();
                break;
        case 2: menu();

        default: cout<<"\n\n\t\t\t\tInvalid Choise : ";
                 cout<<"\n\n\t\t\t\t";
                 system("PAUSE");                    
                 system("CLS");
                
    }
     goto m;
    
}

void shopping :: add(){

    m:
    system("CLS");
    fstream data;
    int c;
    int token=0;
    float p;
    float d;
    string n;
    
    cout<<"\n\n\n\n\n\n\n";
    cout<<"\t\t\t\t----------------------------------------\n ";
    cout<<"\n\t\t\t\t           ADD NEW PRODUCT\n ";
    cout<<"\t\t\t\t----------------------------------------\n ";
    cout<<"\n\t\t\t\t           Enter product code : ";
    cin>>pcode;
    cout<<"\n\t\t\t\t           Enter name of product : ";
    cin>>pname;
    cout<<"\n\t\t\t\t           Enter price of product  : ";
    cin>>price; 
    cout<<"\n\t\t\t\t           Enter discount on product : ";
    cin>>dis;

    data.open("database.txt,ios::in");

    if(!data){
        data.open("database.txt",ios::app | ios::out);
        data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
        data.close();
    }
    else{
        data>>c>>n>>p>>d;
        while(!data.eof()){
            if(c == pcode){
                token++;
            }
            data>>c>>n>>p>>d;
        }
        data.close();

    

    if(token==1){
        goto m;
    }
    else{
        data.open("database.txt",ios::app | ios::out);
        data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
        data.close();
    }
    
    }
    cout<<"\n\n\t\t\t\t\tRECORD INSERTED  ";
    cout<<"\n\n\t\t\t\t\t";
    system("PAUSE");     
}


void shopping :: edit(){
    fstream data,data1;
    int pkey;
    int token=0;
    int c;
    float p;
    float d;
    string n;
    system("CLS");
    cout<<"\n\n\n\n";
    cout<<"\t\t\t\t----------------------------------------\n ";
    cout<<"\n\t\t\t\t           RECORD MODIFY MENU\n ";
    cout<<"\t\t\t\t----------------------------------------\n ";
    cout<<"\n\t\t\t\t           Enter product code : ";
    cin>>pkey;

    data.open("database.txt",ios::in);
    if(!data){
        cout<<"\n\t\t\t\t...Database doesn't exist ";
    }
    else{
        data1.open("database1.txt",ios::app|ios::out);
        data>>pcode>>pname>>price>>dis;
        while(!data.eof()){
            if(pkey==pcode){
                cout<<"\n\t\t\t\t           Enter product code : ";
                cin>>c;
                cout<<"\n\t\t\t\t           Enter name of product : ";
                cin>>n;
                cout<<"\n\t\t\t\t           Enter price of product  : ";
                cin>>p;
                cout<<"\n\t\t\t\t           Enter discount on product : ";
                cin>>d;
                data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d;
                cout<<"\n\n\t\t\t\t\tRECORD EDITED  ";
                cout<<"\n\n\t\t\t\t\t";
                system("PAUSE");     
                token++;
               
            }
            else{
                data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis;
            }
            system("PAUSE");
            data>>pcode>>pname>>price>>dis;
        }
        data.close();
        data1.close();

        remove("database.txt");
        rename("database1.txt","database.txt");

        if(token==0){
            cout<<"\n\n\t\t\t\t\tRECORD NOT FOUND  ";
            cout<<"\n\n\t\t\t\t\t";
            system("PAUSE");         
        }
    }
}

void shopping :: removeitem(){
    
    fstream data,data1;
    int pkey;
    int token=0;
    system("CLS");
    cout<<"\t\t\t\t----------------------------------------\n ";
    cout<<"\n\t\t\t\t           DELETE RECORD MENU\n ";
    cout<<"\t\t\t\t----------------------------------------\n ";
    cout<<"\n\t\t\t\t           Enter product code : ";
    cin>>pcode;

    data.open("database.txt",ios::in);
    if(!data){
        cout<<"\n\t\t\t\t...Database doesn't exist ";
    }
    else{
        data1.open("database1.txt",ios::app|ios::out);
        data>>pcode>>pname>>price>>dis;
        while(!data.eof()){
            if(pcode==pkey){
                cout<<"\n\t\t\t\t...Product deleted successfully...\n ";
                token++;
            }
            else{
                data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
            }
            data>>pcode>>pname>>price>>dis;
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt","database.txt");

        if(token==0){
            cout<<"\n\n\t\t\t\t\tRECORD NOT FOUND  ";
            cout<<"\n\n\t\t\t\t\t";
            system("PAUSE");         
        }
    }

}

void shopping :: list(){
    system("CLS");
    fstream data;
    data.open("database.txt",ios::in);
    cout<<"\t\t\t\t----------------------------------------\n ";
    cout<<"\n\t\t\t\t\tPRODUCT CODE    NAME    PRICE        \n\n ";
    cout<<"\t\t\t\t----------------------------------------\n ";
    data>>pcode>>pname>>price>>dis;
    while(!data.eof()){
        cout<<"\n\t\t\t\t\t";
        cout<<"   "<<pcode<<"         "<<pname<<"         "<<price<<"\n";
        data>>pcode>>pname>>price>>dis;
    }
    data.close();
}

void shopping :: receipt(){

    fstream data;

    int arrc[100],arrq[100];
    char choise;
    int c=0;
    float dis=0;
    float amount=0;
    float total=0;

    cout<<"\t\t\t\t\t\t\tRECEIPT\n\n";
    data.open("database.txt",ios::in);
    if(!data){
        cout<<"\n\t\t\t\t\t\tNo product in inventory\n\n";
    }
    else{
        data.close();

        list();
        cout<<"\n\n\n";
        cout<<"\t\t\t\t----------------------------------------\n\n ";
        cout<<"\t\t\t\t\t\tPLACE ORDER\n\n";
        cout<<"\t\t\t\t---------------------------------------\n ";
    cout<<"\n\t\t\t\t           SELECT OPTION : ";
        
        do{
            cout<<"\n\n\t\t\t\t Enter Product Code : ";
            cin>>arrc[c];
            cout<<"\n\t\t\t\t Enter Quantity      : ";
            cin>>arrq[c];
            
            for(int i=0;i<c;i++){
                if(arrc[c]==arrc[i]){
                    cout<<"\n\t\t\t\tDuplicate Product Code";
                    //goto m;
                }
            }
            c++;
            cout<<"\nt\t\t\t Do yo want to buy more press y / n : ";
            cin>>choise;
        }while(choise=='y');

            system("CLS");
            cout<<"\t\t\t\t\t\t\tRECEIPT\n\n";
            cout<<"\t\t----------------------------------------------------------------------------------------------\n ";
            cout<<"\n\t\t\tPRODUCT CODE     NAME     QUANTITY    PRICE     AMOUNT     AMOUNT WITH DISCOUNT\n\n ";
            cout<<"\t\t----------------------------------------------------------------------------------------------\n ";

            for(int i=0;i<c;i++){
                data.open("database.txt",ios::in);
                data>>pcode>>pname>>price>>dis;
                while(!data.eof()){

                    if(pcode==arrc[i]){
                        amount=price*arrq[i];
                        dis= amount- (amount*dis/100);
                        total=total+dis;
                        cout<<"\n\n\t\t\t "<<pcode<<"\t\t"<<pname<<"\t\t"<<arrq[i]<<"\t\t"<<price<<"\t\t"<<amount<<"\t\t"<<dis;
                    }
                    data>>pcode>>pname>>price>>dis;
                }
            }
            data.close();

        }
        
        cout<<"\n\n\t\t-------------------------------- TOTAL AMOUNT ------------------------------------------\n ";
        cout<<"\n\n\t\t\t\t\t\t";
        cout<<total;
        cout<<" Rs.";
        cout<<"\n\n\n";
        cout<<"\t\t\t\t";
        system("PAUSE");   

    }



int main(){
    shopping s;
    s.menu();
    
return 0;
}