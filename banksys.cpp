#include<iostream>
#include<fstream>
#include<vector>
#include<stdlib.h>
#include<string.h>

#include<iomanip>
typedef long int bal;

using namespace std;

class acc{
    private:
    string first;
    string last;
    bal blc=0;
    int accno;
    public:
    acc(){}
    acc(string f,string l,bal b, int ac){
        first = f;
        last = l;
        blc = b;
        accno = ac;
    };
    friend ostream& operator<<(ostream& c, acc& s);
    friend ifstream& operator>>(ifstream& c, acc& s);
    friend ofstream& operator<<(ofstream& c, acc& s);
    bal getbalance(){
        return blc;
    }
    void deposit(int a){
        blc+=a;
        cout<<a<<"rs deposit successfully\n"
        "Total Balance: "<<blc;
    }
    void withdraw(int a){
        blc-=a;
        cout<<a<<"rs withdraw successfully\n"
        "Total Balance: "<<blc;
    }
    int getnubr(){return accno;}
};


int main(){
    {   //banking logo
     
    cout<<"$$$$$$$\\                      $$\\       \n"
    "$$  __$$\\                     $$ |      \n"
    "$$ |  $$ | $$$$$$\\  $$$$$$$\\  $$ |  $$\\ \n"
    "$$$$$$$\\ | \\____$$\\ $$  __$$\\ $$ | $$  |\n"
    "$$  __$$\\  $$$$$$$ |$$ |  $$ |$$$$$$  / \n"
    "$$ |  $$ |$$  __$$ |$$ |  $$ |$$  _$$<  \n"
    "$$$$$$$  |\\$$$$$$$ |$$ |  $$ |$$ | \\$$\\ \n"
    "\\_______/  \\_______|\\__|  \\__|\\__|  \\__|\n"
    "                                        \n"
    " $$$$$$\\                         $$\\                               \n"
    "$$  __$$\\                        $$ |                              \n"
    "$$ /  \\__|$$\\   $$\\  $$$$$$$\\ $$$$$$$\\ $$$$$$\\  $$$$$$\\$$$$\\  \n"
    "\\$$$$$$\\  $$ |  $$ |$$  _____|   $$      $$  __$$\\ $$  _$$  _$$\\ \n"
    " \\____$$\\ $$ |  $$ |\\$$$$$$\\     $$ |    $$$$$$$$ |$$ / $$ / $$ |\n"
    "$$\\   $$ |$$ |  $$ | \\____$$\\    $$ |    $$   ____|$$ | $$ | $$ |\n"
    "\\$$$$$$  |\\$$$$$$$ |$$$$$$$  |   $$ |    \\$$$$$$$\\ $$ | $$ | $$ |\n"
    " \\______/  \\____$$ |\\_______/    \\__|     \\_______|\\__| \\__| \\__|\n"
    "          $$\\   $$ |                                            \n"
    "          \\$$$$$$  |                                            \n"
    "           \\______/                                             \n";cout<<endl; }
         
    vector<acc> listacc;
    int counter=0; //main accounts
    int nubr=0; //last bank nubr

    { //counter receiver
        ifstream file("counter.txt");
    file>>counter;
    file.close();}
    
    { //retrive accounts
        ifstream file("accl.txt");
    for(int i = 0;i<counter;i++){
        acc retriver;
        file>>retriver;
        listacc.push_back(retriver);
        if(i==counter-1){
            nubr = retriver.getnubr();
        }
    }
    file.close();
    }
    
//counter and nubr fetched

    while(1){
        int choice;
        cout<<"  7 options available\n";
        cout<<setw(9)<<"1."<<"create account\n"
        <<setw(9)<<"2."<<"Balance Enquiry\n"
        <<setw(9)<<"3."<<"Deposit\n"
        <<setw(9)<<"4."<<"Withdrawl\n"
        <<setw(9)<<"5."<<"Close Account\n"
        <<setw(9)<<"6."<<"Show All Accounts\n"
        <<setw(9)<<"7."<<"EXIT\n";
        cout<<"enter choice: ";
        cin>>choice;
        cin.ignore();
        switch(choice){
            case 1:{{   //banking logo
        cout << " ==================================================\n"
            << "|                                                  |\n"
            << "|                   CREATE ACCOUNT                 |\n"
            << "|                                                  |\n"
            << " ==================================================\n" << endl;
        }
                string first,last;bal blc;
                cout<<"enter first name: ";
                cin>>first;
                cin.ignore();
                cout<<"enter last name: ";
                cin>>last;
                cin.ignore();
                cout<<"enter balance: ";
                cin>>blc;
                listacc.push_back(acc(first,last,blc,++nubr));
                cout<<"\nAccount Create Successfully :)\nfirst name:"<<first<<"\nlast name: "<<last<<"\nbalace: "<<blc<<"\nAccount No: "<<nubr<<endl<<endl;
                    break;
                }
            case 2:{{   //banking logo
        cout << " ==================================================\n"
            << "|                                                  |\n"
            << "|                   BALANCE ENQUIRY                |\n"
            << "|                                                  |\n"
            << " ==================================================\n" << endl;
        }
                int selno;
                cout<<"enter account no: ";
                cin>>selno;
                    for(int i = 0;i<listacc.size();i++){
                        if(listacc[i].getnubr()==selno){
                            cout<<"\ncurrent balance: "<<listacc[i].getbalance()<<endl<<endl;
                            break;
                        }
                    }
                    break;
                }
            case 3:{{   //banking logo
        cout << " ==================================================\n"
            << "|                                                  |\n"
            << "|                      DEPOSIT                     |\n"
            << "|                                                  |\n"
            << " ==================================================\n" << endl;
        }
                int selno;
                cout<<"enter account no: ";
                cin>>selno;
                    for(int i = 0;i<listacc.size();i++){
                        if(listacc[i].getnubr()==selno){bal val;
                            cout<<"\nenter amount: ";cin>>val;
                            listacc[i].deposit(val);cout<<endl<<endl;
                            break;
                        }
                    }
                    break;}
            case 4:{{   //banking logo
        cout << " ==================================================\n"
            << "|                                                  |\n"
            << "|                      WITHDRAWL                   |\n"
            << "|                                                  |\n"
            << " ==================================================\n" << endl;
        }
                int selno;
                cout<<"enter account no: ";
                cin>>selno;
                    for(int i = 0;i<listacc.size();i++){
                        if(listacc[i].getnubr()==selno){bal val;
                            cout<<"\nenter amount: ";cin>>val;
                            listacc[i].withdraw(val);
                            break;
                        }
                    }cout<<endl<<endl;
                    break;}
            case 5:{{   //banking logo
        cout << " ==================================================\n"
            << "|                                                  |\n"
            << "|                    CLOSE ACCOUNT                 |\n"
            << "|                                                  |\n"
            << " ==================================================\n" << endl;
        }
                int selno;
                cout<<"enter account no: ";
                cin>>selno;
                bool fount = true;
                    for(int i = 0;i<listacc.size();i++){
                        if(listacc[i].getnubr()==selno){
                            cout<<"\nAccount deleted successfully\n\n";
                            listacc.erase(listacc.begin()+i);
                            fount = false;
                            break;
                        }
                    }
                    if(fount) cout<<"account not found"<<endl<<endl;
                    break;}
            case 6:{{   //banking logo
        cout << " ==================================================\n"
            << "|                                                  |\n"
            << "|                  SHOW ALL ACCOUNTS               |\n"
            << "|                                                  |\n"
            << " ==================================================\n" << endl;
        }
                if(!listacc.empty())
                {for(int i = 0;i<listacc.size();i++){
                    cout<<listacc[i];
                }}
                else cout<<"no account are there\n\n";
                    break;}
            case 7:{
                ofstream file("counter.txt");
                file<<listacc.size();
                file.close();
                ofstream fps("accl.txt");
                for(int i = 0;i<listacc.size();i++){
                    fps<<listacc[i];
                }
                fps.close();
                    return 0;}
            default: cout<<"try again"<<endl;break;
        }
    }
    
    return 0;
}

    ostream& operator<<(ostream& c, acc& s){
        c<<"\nAccount no. "<<s.accno<<endl;
        c<<"First name: "<<s.first<<endl;
        c<<"Last name: "<<s.last<<endl;
        c<<"Balance: "<<s.blc<<endl<<endl;
        return c;
    }
    ifstream& operator>>(ifstream& c, acc& s){
        c>>s.first;
        c>>s.last;
        c>>s.blc;
        c>>s.accno;
        return c;
    }
    ofstream& operator<<(ofstream& c, acc& s){
        c<<s.first<<endl;
        c<<s.last<<endl;
        c<<s.blc<<endl;
        c<<s.accno<<endl;
        return c;
    }