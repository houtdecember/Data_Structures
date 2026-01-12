#include<iostream>
#include<iomanip>
bool check=true;
using namespace std;
class Employee{
private:
    /* data */
    int id;
    string name;
    string gender;
    float salary;
public:
    Employee(){
        this->id=0;
        this->name="Hout";
        this->gender="Male";
        this->salary=0.0;
    }
    Employee(int id ,string name, string gender ,float salary){
        this->id=id;
        this->name=name;
        this->gender=gender;
        this->salary=salary;
    }
    // setter
    void setId(int id){
        this->id=id;
    }
    void setName(string name){
        this->name=name;
    }
    void setGender(string gender){
        this->gender=gender;
    }
    void setSalary(float salary){
        this->salary=salary;
    }
    // getter
    int getId(){
        return id;
    }
    string getName(){
        return name;
    }
    string getGender(){
        return gender;
    }
    float getSalary(){
        return salary;
    }
    void input(){
        cout<<"Input ID :" ;cin>>id;
        cout<<"Input Name :" ;cin>>name;
        cout<<"Input Gender :" ;cin>>gender;
        cout<<"Input Salary :" ;cin>>salary;
    }
    void output(){
        cout<<setw(10)<<id<<setw(10)<<name<<setw(10)<<gender<<setw(10)<<salary<<endl;
    }
    void Header(){
        cout<<setw(10)<<"ID"<<setw(10)<<"Name"<<setw(10)<<"Gender"<<setw(10)<<"Salary"<<endl;

    }
};

int main(){
    Employee emp[10];
    int size,op;
    do
    {
        /* code */
        cout<<"========================"<<endl;
        cout<<"|        1.Input       |"<<endl;
        cout<<"|        2.Output      |"<<endl;
        cout<<"|        3.Search      |"<<endl;
        cout<<"|        4.Update      |"<<endl;
        cout<<"|        5.Delete      |"<<endl;
        cout<<"|        6.Add         |"<<endl;
        cout<<"|        7.Sort        |"<<endl;
        cout<<"|        0.Exit        |"<<endl;
        cout<<"========================"<<endl;
        cout<<"Input Your Option :";cin>>op;
        switch (op){
            case 1:{
                cout<<"Input Size Of Employee :";cin>>size;
                for(int i=0 ;i<size ;i++){
                    cout<<"Enter Employee "<<i+1<<endl;
                    emp[i].input();
                }
            }break;
            case 2:{
                emp[0].Header();
                for(int i=0 ;i<size ;i++){
                    emp[i].output();
                }
            }break;
            case 3: {
                int s;
                cout << "Input ID To Search : ";
                cin >> s;
                emp[0].Header();

                for (int i = 0; i < size; i++) {
                    if (s == emp[i].getId()) {
                        emp[i].output();   
                        check = false; 
                        break;  
                    }
                }

                if (check) {
                    cout << "Not Found" << endl;
                }
                break;
            }
            case 4:{
                int u;
                string key;
                string newname;
                string newgender;
                float newsalary;  
                cout<<"Input ID To Update :";cin>>u;               
                for(int i=0 ;i<size ;i++){
                    if(u==emp[i].getId()){
                        cout<<"Old Name :"<<emp[i].getName()<<endl;
                        cout<<"Answer if U 1 2 Change Name (yes/no):";cin>>key;
                        if(key=="yes"){
                            cout<<"Input New Name :";cin>>newname;
                           emp[i].setName(newname);
                        }
                        cout<<"Old Gender :"<<emp[i].getGender()<<endl;
                        cout<<"Answer if U 1 2 Change Gender (yes/no):";cin>>key;
                        if(key=="yes"){
                            cout<<"Input New Gender :";cin>>newgender;
                           emp[i].setGender(newgender);
                        }
                        cout<<"Old Salary :"<<emp[i].getSalary()<<endl;
                        cout<<"Answer if U 1 2 Change Salary (yes/no):";cin>>key;
                        if(key=="yes"){
                            cout<<"Input New Salary :";cin>>newsalary;
                           emp[i].setSalary(newsalary);
                        }
                        check=false;                      
                    }
                }break;
                if (check==true){
                    cout<<"++++++ Id Not Found ++++++"<<endl;
                }                
            }
            case 5:{
                int d;
                cout<<"Input ID To Delete :";cin>>d;
                for(int i=0 ;i<size ;i++){
                    if(emp[i].getId()==d){
                        for(int j=i ;j<size ;j++){
                            emp[j]=emp[j+1];
                            
                        }
                        size--;
                        cout<<"==== Delete Success===="<<endl;
                        check=false;
                    }
                }break;
                if(check==true){
                    cout<<"+++++ ID Not Found +++++"<<endl;
                }
            }
            case 6:{
                int new_size;
                cout<<"Input New size :";cin>>new_size;
                for(int i=size ;i<size+new_size ;i++){
                    emp[i].input();
                }
                size=size+new_size;
                cout<<"*****Add Success*****"<<endl;
            }
            case 7:{
                for(int i=0 ;i<size ;i++){
                    for(int j=i+1 ;j<size ;j++){
                        if(emp[i].getId()>emp[j].getId()){
                            swap(emp[i],emp[j]);
                            
                        }
                    }
                }
                cout<<"===== Sort Success ====="<<endl;
            }
        default:
            break;
        }
    } while (op!=0);
    
};
