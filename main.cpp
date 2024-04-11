#include <iostream>
#include <fstream>
using namespace std;

#define RED_TEXT "\033[1;31m"
#define GREEN_TEXT "\033[1;32m"
#define YELLOW_TEXT "\033[1;33m"
#define BLUE_TEXT "\033[1;34m"
#define RESET_TEXT "\033[0m"


class linkedlistforqueue;


class queue{
public:
    string name_of_customer;//name of customer
    queue *next= nullptr;
};


class node {
public:
    string nameofbook;//name of book
    node*next= nullptr;
    queue *first_bkqueue= nullptr;
    linkedlistforqueue *myque;
    ~node(){


        while(first_bkqueue!= nullptr) {
            queue *temp = first_bkqueue;
            first_bkqueue = first_bkqueue->next;
            delete temp;
        }

        delete myque;
    }

};

class linkedlistforqueue{
    node* mybook;
    //first in book queue
    queue *last_bkqueue;//last in book queue
public:
    node* returnmybook(){
     return mybook;
    }

    linkedlistforqueue(){
        last_bkqueue= nullptr;
    }
    void setbook(node * book){
        this->mybook=book;
    }

    bool isempty(){
        return( mybook->first_bkqueue== nullptr);
    }

    int counter(){
        queue *temp = mybook->first_bkqueue;
        int count=0;
        while(temp!= nullptr)     {
            count++;
            temp=temp->next;

        }
        return count;

    }


    void ENQUEUE(string noc) //noc FOR name of customer
    {
        queue *newque=new queue;
        newque->name_of_customer=noc;
        if( mybook->first_bkqueue== nullptr){
            mybook->first_bkqueue=last_bkqueue=newque;
            newque->next= nullptr;
        }
        else{
            last_bkqueue->next=newque;
            last_bkqueue=newque;
            newque->next= nullptr;
        }
    }
    void DEQUEUE(){
        if(isempty()){
            cout <<RED_TEXT<<"Queue is already empty\n"<<RESET_TEXT;
        }

        else {
            queue *temp = mybook->first_bkqueue;
            mybook->first_bkqueue = mybook->first_bkqueue->next;
            cout << "Customer: " << BLUE_TEXT << temp->name_of_customer << RESET_TEXT << " finished using the book"
                 << endl;
            delete temp;


            if (isempty()) {
                cout << "NO one left in the queue\n";
            } else
                cout << "Next in queue is: " << BLUE_TEXT << mybook->first_bkqueue->name_of_customer << RESET_TEXT
                     << endl;
        }
    }


    void whoami(){
        if(mybook->first_bkqueue!= nullptr) {
            cout << "The current person who is using the book is: " << BLUE_TEXT
                 << mybook->first_bkqueue->name_of_customer << RESET_TEXT << endl;
        }
        else cout <<RED_TEXT<<"NO ONE IN QUEUE\n"<<RESET_TEXT;

    }


    void getstatus(){
        if(isempty()){
            cout <<"No one is reserving this book right now !\n"<<YELLOW_TEXT<<"You can reserve it from the main menu\n"<<RESET_TEXT;
        }
        else  cout<<RED_TEXT<<"Sorry but looks like there's a queue for this book\n"<<RESET_TEXT<<GREEN_TEXT<<counter()<<RESET_TEXT<<" person/s in the queue\n";

    }


    void whenismyturn(string myname){
        if(mybook->first_bkqueue->name_of_customer==myname){
            cout<<RED_TEXT<<"ARE YOU KIDDING ME YOU SHOULD BE THE ONE WHO HAS THE BOOK RIGHT NOW\nDID YOU LOSE IT !!\n"<<RESET_TEXT;
        }
        else {
            queue *temp=mybook->first_bkqueue->next;
            int count=1;
            while( temp!= nullptr && temp->name_of_customer!=myname){
                temp=temp->next;
                count++;
            }
            if(temp== nullptr){
                cout<<RED_TEXT <<"Your name is not found in the queue\n"<<RESET_TEXT<<"Are you sure that you added yourself?\n";
            }
            else{ cout<<GREEN_TEXT<<count<<RESET_TEXT<<" person/s ahead of you\n";
            }
        }

    }

};

class linkedlistforbooks {
public:
    node* head;
    linkedlistforbooks(){
        head= nullptr;
    }

    void forbookdata(){

        ifstream input("DATASET_BOOKS.txt");
        string nob;
        if(!input.fail()) {
            while (!input.eof()) {

                getline(input, nob);
                insertlast(nob);

            }
        }

        else {
            cout <<RED_TEXT<<"FAILED TO READ DATA\n"<<RESET_TEXT;
            exit(-5);
        }
        input.close();
    }

    bool isempty(){
        return(head== nullptr);
    }


    void insertfirst(string nob){
        node *newnode= new node;
        newnode->nameofbook=nob;
        newnode->myque= new linkedlistforqueue;
        newnode->myque->setbook(newnode);

        if(isempty()){

            newnode->next= nullptr;
            head=newnode;
        }
        else{
            newnode->next=head;
            head=newnode;
        }
    }

    void display(){
        node*temp=head;
        if(temp!= nullptr){
            while(temp!= nullptr)     {
                cout << YELLOW_TEXT << temp->nameofbook<<endl<<RESET_TEXT; // check it back1
                temp=temp->next;

            }
        }
        else {cout<<RED_TEXT<<"THERE ARE NO BOOKS\n"<<RESET_TEXT;}

    }

    int counter(){
        int counter=0;
        node*temp=head;
        while(temp!= nullptr)     {
            counter++;
            temp=temp->next;

        }
        return counter;
    }

    void returnnumObook(string key){
        node*temp=head;
        int counter=0;
        while(temp!= nullptr)     {
            counter++;
            if(temp->nameofbook==key) {
                cout <<"The number of "<<GREEN_TEXT<<temp->nameofbook<<RESET_TEXT<<" is: "<<GREEN_TEXT<<counter<<RESET_TEXT<<endl;
                break;
            }
            temp=temp->next;
        }

        if(temp== nullptr){
            string YESORNO;
            cout <<RED_TEXT<<"DIDN'T FIND THIS BOOK\n"<<RESET_TEXT<<"Do you want to add it?\npress "<<"1 FOR "<<GREEN_TEXT<<"YES\n"<<RESET_TEXT<<"any other button for "<<RED_TEXT<<"NO\n"<<RESET_TEXT;
            cin >> YESORNO;
            if(YESORNO=="1"){
                insertlast(key);
            }
        }
    }

    void insertlast(string nob) {
        node* newnode= new node;
        newnode->nameofbook= nob;
        newnode->myque= new linkedlistforqueue;
        newnode->myque->setbook(newnode);
        if(head == nullptr) {
            insertfirst(nob);
        }

        else{
            node* temp=head;

            while(temp->next!= nullptr) {
                temp = temp->next;
            }
            temp->next= newnode;
            newnode->next= nullptr;
        }

    }

    void insertmiddle(string nob, int pos) {
        if (pos == 1) { insertfirst(nob); }

        else if (pos <=counter()) {
            node *newnode = new node;
            newnode->nameofbook = nob;
            newnode->myque = new linkedlistforqueue;

            newnode->myque->setbook(newnode);
            node *temp = head;
            for (int i = 1; i < pos; i++) {
                temp = temp->next;
            }
            newnode->next = temp;
            node *temp0 = head; // to catch before the position node
            for (int i = 1; i < pos - 1; i++) {
                temp0 = temp0->next;
            }
            temp0->next = newnode;
        } else {
            cout <<GREEN_TEXT << "Position passed the parameter\n"<<"(AUTO INSERT IN LAST POSITION)\n"<<RESET_TEXT;
            insertlast(nob);
        }
    }
    void deletefirst() {
        if(head== nullptr){
            cout << RED_TEXT <<" Book list is empty !\n\n"<<RESET_TEXT;
        }
        else {
            node *temp = head;
            head = head->next;
            delete temp;
        }


    }

    void deletelast() {
        node *temp = head;
        if(counter()==1){
            deletefirst();
        }
        else if(counter()==0){
            cout << RED_TEXT <<"No Books to delete\n" <<RESET_TEXT;
        }
        else {
            while (temp->next->next != nullptr) {
                temp = temp->next;
            }
            delete temp->next;
            temp->next = nullptr;
        }
    }


    void deletemiddle( int pos) {
        if(pos==1){deletefirst();}
        else{ node* temp =head;
            node* tempdel =head;

            for(int i=1;i<pos; i++) {
                tempdel=tempdel->next;
            }

            for(int i=1;i<pos-1; i++) {
                temp=temp->next;
            }

            temp->next=temp->next->next;

            delete tempdel;}

    }


    void deletebyname(string nameofbook)
    {
        node* delptr=head;
        if (isempty())
            cout<< RED_TEXT << "List is empty"<<endl<<RESET_TEXT;
        if(head->nameofbook==nameofbook)
        {
            head=head->next;
            delete delptr;
        }
        else
        {
            node* prev= nullptr;
            while (delptr!= nullptr && delptr->nameofbook!=nameofbook)
            {
                prev=delptr;
                delptr=delptr->next;
            }
            if(delptr!= nullptr){
                prev->next=delptr->next;
                delete delptr;}
            else {
                cout << RED_TEXT <<"Book is not found\n" << RESET_TEXT;
            }
        }
    }


    node* returnbook(int pos) {
        if (pos > 0 && pos <= counter()) {
            node *temp=head;
            for (int i = 1; i < pos; i++) {
                temp = temp->next;
            }
            return temp;
        }

        else return nullptr;
    }

    node* returnbook(string book) {
        if(head->nameofbook==book){
            return head;
        }

        else {
            node *temp=head->next;
            while (temp != nullptr && temp->nameofbook!= book  ) {
                temp = temp->next;
            }
            return temp;
        }
    }



    ~linkedlistforbooks(){
        node*temp=head;
        ofstream input("DATASET_BOOKS.txt");
        while(temp->next!= nullptr)     {

            input <<  temp->nameofbook<<endl;
            temp=temp->next;

        }

        input<<temp->nameofbook;
        input.close();




        while (head!= nullptr){
            deletelast();}
        delete head;
    }


// stopped here
};









void insertoptionsforbook(linkedlistforbooks*books){
    int choice;
    string nameofbook;


    // cout<<RED_TEXT <<"NOTE: PLEASE CHOOSE BY NUMBER\n"<< RESET_TEXT;
    // cout << "-1 INSERT IN FIRST POSITION\n2- INSERT IN LAST POSITION\n3- INSERT IN A CHOSEN POSITION\nPRESS 0 TO RETURN TO THE MAIN MENU\n";
    // R option for cout ascii without escaping any characters as a row
    cout<<R"(
+------------------------------------+
| NOTE: PLEASE CHOOSE BY NUMBER      |
+------------------------------------+
| -1 Insert in First Position        |
| -2 Insert in Last Position         |
| -3 Insert in a chosen Position     |
| PRESS 0 TO RETURN TO THE MAIN MENU |
+------------------------------------+
)"<<endl;
    cin >> choice;

    switch (choice){
        case 1:  cout << "Please enter the name of the book: ";
            getline(cin>>ws,nameofbook);

            books->insertfirst(nameofbook);
            break;
        case 2:  cout << "Please enter the name of the book: ";
            getline(cin>>ws,nameofbook);

            books->insertlast(nameofbook);
            break;
        case 3:  cout << "Please enter the name of the book: ";
            getline(cin>>ws,nameofbook);

            cout << "Please choose the position: ";
            int pos;
            cin >>pos;
            books->insertmiddle(nameofbook,pos);

        case 0: break;
    }


}

void deleteoptionsforbook(linkedlistforbooks*books) {
    int choice;
    // cout << "NOTE: PLEASE CHOOSE BY NUMBER\n";
    // cout<< "-1 DELETE THE FIRST BOOK\n2- DELETE THE LAST BOOK\n3- DELETE A CHOSEN BOOK\nPRESS 0 TO RETURN TO THE MAIN MENU\n";
    cout<<R"(
+------------------------------------+
| NOTE: PLEASE CHOOSE BY NUMBER      |
+------------------------------------+
| -1 Delete the firsrt book          |
| -2 Delete the last book            |
| -3 Delete a chosen book            |
| PRESS 0 TO RETURN TO THE MAIN MENU |
+------------------------------------+
)"<<endl;
    cin >> choice;

    switch (choice) {
        case 1:
            books->deletefirst();
            break;
        case 2:
            books->deletelast();
            break;
        case 3: {
            int ch;
            cout <<"\n\n1- Delete by position\n2- Delete by the name of the book\n";
            cin >>ch;
            if(ch==1){
                int pos;
                cout << "Please choose the position: ";
                cin >> pos;
                books->deletemiddle(pos);
                break; }
            else if(ch==2) {
                string nameofbook;
                cout << "Please enter the name of the book: ";
                getline(cin >>ws,nameofbook);
                books->deletebyname(nameofbook);
                break;}
            else {
                cout<<RED_TEXT << "Invalid Input !\n"<<RESET_TEXT;
                break;
            }

        }


        default: break;
    }
}
void QUEUE(linkedlistforqueue *queue,int &choice){


    // cout << "                                                  QUEUE                                                          \n";
    // cout << "1- RESERVE A BOOK\n2- FINISH USING THE BOOK\n3- CHECK QUEUE\n4- CHECK MY POSITION IN THE WAITING LIST\n5- CURRENT USER OF THE BOOK\nPRESS ANYTHING TO RETURN\n";
    cout<<R"(
+------------------------------------------+
|                  QUEUE                   |
+------------------------------------------+
| -1 Reserve a book                        |
| -2 Finish using the book                 |
| -3 Check queue                           |
| -4 Check my position in the waiting list |
| -5 Current user of the book              |
| PRESS 0 TO RETURN TO THE MAIN MENU       |
+------------------------------------------+
)"<<endl;
    cin >>choice;
    switch (choice) {
        case 1:{
            cout<<"Please enter your name: ";
            string name;
            getline(cin >>ws ,name);
            queue->ENQUEUE(name);
            break;
        }
        case 2:
            queue->DEQUEUE();
            break;
        case 3:
            queue->getstatus();
            break;
        case 4:{
            cout<<"Please enter your name: ";
            string name;
            cin >>name;
            queue->whenismyturn(name);
            break;
        }
        case 5:
            queue->whoami();
            break;
        default:
            break;

    }



}






void mainmenu(linkedlistforbooks*books,int &choice) {
    // cout << "                                                  MAIN MENU                                                           \n";
    // cout << "1- Insert Options\n";
    // cout << "2- Delete Options\n";
    // cout << "3- View the books\n";
    // cout << "4- Count the books\n";
    // cout << "5- Queue for the books\n";
    // cout << "PRESS 0 TO EXIT THE PROGRAM\n";
    cout<<R"(
+=========================================+
|                MAIN MENU                |
+=========================================+
| 1- Insert Options                       |
| 2- Delete Options                       |
| 3- View the books                       |
| 4- Count the books                      |
| 5- Find number of a book                |
| 6- Queue for the books                  |
| PRESS 0 TO EXIT THE PROGRAM             |
+-----------------------------------------+
)"<<endl;
    cin >> choice;
    switch (choice) {
        case 1:
            insertoptionsforbook(books);
            break;
        case 2:
            deleteoptionsforbook(books);
            break;
        case 3: books->display();
            break;
        case 4:cout<<  books->counter()<<endl; break;
        case 5:{
            string bookname;
            cout <<"ENTER THE NAME OF THE BOOK: ";
            getline(cin >>ws,bookname);
            books->returnnumObook(bookname);


        }
            break;
        case 6:{


            cout <<"Please choose way to set the book\n1- Set by position\n2- Set by name\n";
            int choicenum;
            cin >>choicenum;

            switch (choicenum) {
                case 1:{cout <<"Enter the position: ";
                    int pos;
                    cin >>pos;
                    node* mybook=books->returnbook(pos);

                    if(mybook!= nullptr){
                        cout<<"\nOpening queue for: "<<GREEN_TEXT<<mybook->nameofbook<<endl<<RESET_TEXT;
                        int term=1;
                        while (term){
                        QUEUE(mybook->myque,term);
                        }
                    }
                    else{
                        cout<<RED_TEXT <<"Invalid position\n"<<RESET_TEXT;
                    }
                    break;
                }

                case 2: {
                    cout<< "Enter the name of the book: ";
                    string name;
                    cin.clear();
                    getline(cin >> ws,name);
                    node *mybook = books->returnbook(name);
                    if(mybook!= nullptr){
                        cout<<"\nOpening queue for: "<<GREEN_TEXT<<mybook->nameofbook<<endl<<RESET_TEXT;
                        int term=1;
                        while (term){
                            QUEUE(mybook->myque,term);
                        }
                    }
                    else{
                        cout<<RED_TEXT <<"Book is not found, Please check if there is a mistype\n"<<RESET_TEXT;
                    }

                    break;
                }
                default:
                    cout<<RED_TEXT <<"Invalid input,Book not set !\n"<<RESET_TEXT;
                    break;
            }


            break;   }
        case 0:

            break;

    }
}



int main() {
    linkedlistforbooks x;
    x.forbookdata();
    int terminator;
    terminator=1;
    cout<<BLUE_TEXT<<R"(
                                      ███╗   ███╗   ██╗  ███████╗            ██╗     ██╗██████╗ ██████╗  █████╗ ██████╗ ██╗   ██╗
                                      ████╗ ████║   ██║  ╚══███╔╝            ██║     ██║██╔══██╗██╔══██╗██╔══██╗██╔══██╗╚██╗ ██╔╝
                                      ██╔████╔██║████████╗ ███╔╝             ██║     ██║██████╔╝██████╔╝███████║██████╔╝ ╚████╔╝
                                      ██║╚██╔╝██║██╔═██╔═╝███╔╝              ██║     ██║██╔══██╗██╔══██╗██╔══██║██╔══██╗  ╚██╔╝
                                      ██║ ╚═╝ ██║██████║ ███████╗            ███████╗██║██████╔╝██║  ██║██║  ██║██║  ██║   ██║
                                      ╚═╝     ╚═╝╚═════╝ ╚══════╝            ╚══════╝╚═╝╚═════╝ ╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝   ╚═╝

)"<<RESET_TEXT<<endl<<endl;
    while(terminator) {
        mainmenu(&x, terminator);
    }




    return 0;
}




