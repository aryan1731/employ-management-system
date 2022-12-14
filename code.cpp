//A basic database using doubly linked list
/*---------------------------------------------------------------------*/
#include<bits/stdc++.h>

using namespace std;

struct node{              //nodes structure with basic information parameters declared as member functions
    int id;
    char name[50];
    char qua[30];
    char addrs[50];
    char city[30];
    char jobtitle[30];
    int salary;
    char date[30];
    node *prev,*next;     //declared pointer variables for doubly linked list
};

class employee{
    private:
        node *head;
        char ch;

    public:
        employee(){                  //constructor function defined
            head = NULL;
        }

        node* info(node* temp){                // info of employee

            cout<<"\n\t\t Enter Employee ID:"<<endl;
            cin>>temp->id;
            fflush(stdin);

            cout<<"\n\t\t Enter the name of the employee:"<<endl;
            cin.getline(temp->name,50);
            fflush(stdin);

            cout<<"\n\t\t Enter the qualification of the employee:"<<endl;
            cin.getline(temp->qua,30);
            fflush(stdin);

            cout<<"\n\t\t Enter the address of the employee:"<<endl;
            cin.getline(temp->addrs,50);
            fflush(stdin);

            cout<<"\n\t\t Enter the city of the employee:"<<endl;
            cin.getline(temp->city,30);
            fflush(stdin);

            cout<<"\n\t\t Enter the job title of the employee:"<<endl;
            cin.getline(temp->jobtitle,30);
            fflush(stdin);

            cout<<"\n\t\t Enter the salary of the person:"<<endl;
            cin>>temp->salary;
            fflush(stdin);

            cout<<"\n\t\t Enter the joining date of the employee:"<<endl;
            cin.getline(temp->date,30);
            fflush(stdin);

            return temp;
        }
        void add_first(){                                 //function for adding employee info at front
            node *temp = new node;
            temp = info(temp);

            temp->next = head;
            temp->prev = NULL;
            if(head!=NULL){
                head->prev = temp;

            }
            head=temp;
            cout<<"\n\t\tRecord Added successfully"<<endl;
        
        }

        void add_last(){                     //function for adding employee info at the end 
            if(head == NULL){
                cout<<"\n\t\tList is empty"<<endl;
                cout<<"\n\t\tDo you want to add a new record\n\tPress Y or N:"<<endl;
                cin>>ch;
                if(ch=='Y'|| ch == 'y'){
                    add_first();
                    return;
                }

            }
            else{
                node *temp = head;
                while(temp->next != NULL){
                    temp = temp->next;
                }
                node *newer = new node;
                newer = info(newer);

                newer->next = NULL;
                temp->next = newer;
                newer->prev = temp;
            }

        }

        void add_after(){                          //function to add employee info in between the list
            if(head==NULL){
                cout<<"\n\t\tList is Empty"<<endl;
                cout<<"\n\t\tAdd a new record\n\tPress Y or N"<<endl;
                cin>>ch;
                if(ch=='Y'||ch=='y'){
                    add_first();
                    return;
                }


            }
            else{
                int val;
                cout<<"Enter the id after which you want to add a new record:"<<endl;
                cin>>val;
                bool flag = false;
                node *temp = head;
                node *p;
                while(temp!=NULL){
                    if(temp->id == val){
                        node *newer = new node;

                        newer = info(newer);

                        if(temp->next!=NULL){
                            newer->next = temp->next;
                            newer->prev = temp;
                            p = temp->next;
                            p->prev = newer;
                            temp->next = newer;
                        }
                        else{
                            newer->next = temp->next;
                            newer->prev = temp;
                            temp->next = newer;
                        }
                        flag = true;
                        break;

                    }
                    temp = temp->next;
                }
                if(flag == false){
                    cout<<"\n\t\tId not found"<<endl;
                }
            }
        }   
 
        void del(){                                //function for node deletion; user input taken
            if(head == NULL) {
                cout<<"\n\t\tList is empty"<<endl;
                cout<<"\n\t\tAdd a new record\n\tPress Y or N:"<<endl;
                cin>>ch;
                if(ch=='y'|| ch=='Y'){
                    add_first();
                    return;
                }
            }
            else{
                int val;
                cout<<"\n\t\tEnter employee id which you want to delete:"<<endl;
                cin>>val;
                node *temp = head;
                if (temp!=NULL && temp->id==val) {
                    head = temp->next;
                    delete temp;
                }

                else {
                    while(temp != NULL && temp->id!=val) {
                        temp = temp->next;
                    }

                    if(temp == NULL){
                        cout<<"Record not found"<<endl;
                        return;
                    }
                    node *temp1,*temp2;
                    temp1 = temp->prev;
                    temp2 = temp->next;
                    temp1->next = temp2;
                    temp2->prev = temp1;

                    delete temp;
                    cout<<"Record Deleted Successfully"<<endl;
                }
            }   
        }

        void show() {                               //function to display info of all employees
            if(head == NULL){
                cout<<"\n\t\tList is empty"<<endl;
                cout<<"\n\t\tDo you want to add a record\n\tPress Y or N :"<<endl;
                cin>>ch;
                if(ch=='Y' || ch=='y'){
                    add_first();
                    return;
                }
            }
            else{
                node *temp = head;
                while(temp != NULL){
                    cout<<"\n\t\tInformation of the Employee: "<<endl;
                    cout<<"\n\t\t ID: "<<temp->id<<endl;
                    cout<<"\n\t\t Name: "<<temp->name<<endl;
                    cout<<"\n\t\tQualification: "<<temp->qua<<endl;
                    cout<<"\n\t\tJob Title: "<<temp->jobtitle<<endl;
                    cout<<"\n\t\tAddress: "<<temp->addrs<<", "<<temp->city<<endl;
                    cout<<"\n\t\tSalary: "<<temp->salary<<endl;
                    cout<<"\n\t\tStarting Date: "<<temp->date<<endl;

                    temp = temp->next;
                }
            }
        }

        void searching(){                          //function to search and display info of desired employee; user inpout taken
            if(head == NULL){
                cout<<"\n\t\tList is empty"<<endl;
                cout<<"\n\t\tDo you want to add a record\n\tPress Y or N :"<<endl;
                cin>>ch;
                if(ch=='Y' || ch=='y'){
                    add_first();
                    return;
                }

            }   
            else{
                int val;
                cout<<"Enter the ID you want to search:";
                cin>>val;
                node *temp = head;
                bool flag = false;
                while(temp != NULL){
                    if(temp->id == val){
                        cout<<"Records Are:"<<endl;

                        cout<<"\n\t\tInformation of the Employee: "<<endl;
                        cout<<"\n\t\t ID: "<<temp->id<<endl;
                        cout<<"\n\t\t Name: "<<temp->name<<endl;
                        cout<<"\n\t\tQualification: "<<temp->qua<<endl;
                        cout<<"\n\t\tJob Title: "<<temp->jobtitle<<endl;
                        cout<<"\n\t\tAddress: "<<temp->addrs<<", "<<temp->city<<endl;
                        cout<<"\n\t\tSalary: "<<temp->salary<<endl;
                        cout<<"\n\t\tJoining Date: "<<temp->date<<endl;

                        flag = true;
                        break;
                    }

                    temp  = temp->next;
                }
                if(flag == false){
                    cout<<"Record not found:"<<endl;
                }
            }
        }

        void update(){                   //function for updation of desired employee's info; user input taken 
            if(head == NULL){
                cout<<"\n\t\tList is empty"<<endl;
                cout<<"\n\t\tDo you want to add a record\n\tPress Y or N :";
                cin>>ch;
                if(ch=='Y' || ch=='y'){
                    add_first();
                    return;
                }

            }
            else{
                int val;
                cout<<"\n\t\tEnter the ID you want to update: "<<endl;
                cin>>val;
                node *temp = head;
                while(temp!=NULL){
                    if(temp->id == val){
                        temp = info(temp);
                        break;
                    }
                    temp = temp->next;
                }
            }
        }
};

int main(){
    employee e;
    int option;
    
    //menu driven database

    while(1) //for infinite looping until break selected
    {
        cout<<"------------Employee Management System-----------"<<endl;
        cout<<"Select an option: "<<endl;
        cout<<"0: Exit"<<endl;
        cout<<"1: Add employee (front of list)"<<endl;
        cout<<"2: Add employee (rear of list)"<<endl;
        cout<<"3: Add employee (in between)"<<endl;
        cout<<"4: Erase employee info"<<endl;
        cout<<"5: Show all employee info"<<endl;
        cout<<"6: Search a particular employee"<<endl;
        cout<<"7: Update employee info"<<endl;
        cout<<"------------------------------------------------"<<endl;

        cout<<"Enter your choice : ";
        cin>>option;
        switch(option){
        case 1:
            e.add_first();
            break;
        case 2:
            e.add_last();
            break;
        case 3:
            e.add_after();
            break;
        case 4:
            e.del();
            break;

        case 5:
            e.show();
            break;

        case 6:
            e.searching();
            break;

        case 7:
            e.update();
            break;

        default:
            exit(0);
        }
    } 

    return 0;
}
