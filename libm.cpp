#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

int lin_search(string a[], int size, string n) {

    for (int i = 0; i < size; i++) {

        if (a[i] == n) {
            return i;
        }
    }

    return -1;
}

class Main_page
{
public:
    int n;
    string name;

    void display()
    {
        cout << "Choose option: \n"
             << "1. Admin login \n"
             << "2. Student login \n"
             << "3. exit" << endl;
        cin >> n;
    }
    void show_book()
    {
        ifstream File1("LDB.txt");
        if (!File1)
        {
            cout << "File not found" << endl;
            return;
        }
        string line;

        while (getline(File1, line))
        {
            std::cout << line << '\n';
        }
        File1.close();
    }

protected:
    int password;
};

class admin : public Main_page
{
public:
    string books[5];
    int i = 0;

    void login()
    {
        cout << "Enter password: " << endl;
        cin >> password;
        while (password != 111)
        {
            cout << "Incorrect password. Try again: " << endl;
            cin >> password;
        }
    }

    void add_book()
    {
        ifstream File1("LDB.txt");

        string line;
        while (getline(File1, line))
        {
            if (!line.empty() && i < 5)
            {
                books[i] = line;
                i++;
            }
        }
        File1.close();
        std::ofstream File2("LDB.txt", std::ios::app);
        if (i == 5)
        {
            cout << "Library is full. Cannot add more books." << endl;
        }
        else
        {
            string newBook;
            cout << "Enter book name: ";
            cin.ignore();
            getline(cin, newBook);
            File2 << newBook << endl;
            books[i] = newBook;
            i++;
        }
        File2.close();
    }

    void delete_book()
    {
        int n;
        ifstream File1("LDB.txt");
        if (!File1)
        {
            cout << "File not found" << endl;
            return;
        }
        vector<string> lines{};
        string line;

        while (getline(File1, line))
        {
            lines.push_back(line);
        }

        for (auto b : lines)
        {

            cout << b << endl;
        }
        cout << "Enter the number of book you wish to remove: ";
        cin >> n;
        vector<string> newLines;
        for (int j = 0; j < lines.size(); j++)
        {
            if (j == n - 1)
            {
            }
            else
            {
                newLines.push_back(lines[j]);
            }
        }
        File1.close();
        ofstream File2("LDB.txt");
        for (int j = 0; j < newLines.size(); j++)
        {
            File2 << newLines[j] << endl;
        }
        File2.close();
    }
};

class student : public Main_page
{
public:
    void S_login()
    {
        cout << "Enter your student ID: ";
        cin >> password;
        while (password != 2111)
        {
            cout << "incorrect Id. try again!";
            cin >> password;
        }
    }

    void borrow_book()
    {
        string c;
        cout << "What book would you like to request? \n";
        cin.ignore();
        getline(cin,c);
        ifstream file("LDB.txt");
        string list[50];
        int i=0;
        while(getline(file,list[i])){
            i++;
        }
        
       int r= lin_search(list, i, c);
       if(r==-1){
        cout<<"Sorry, the book isn't available right now. but you can always make a request!";
       }
       else{
        cout<<"Book is avilable! Sending the PDF on your email linked with account!";
       }
    
}
};

int main()
{

    admin m;
    char a;
    int u;
    student s;
    m.display();
    if (m.n == 1)
    {
        m.login();
        cout << "What do you wish to do? \n"
             << "a. Add Book \n"
             << "b. Check all the books \n"
             << "c. Delete a book \n"
             << endl;
        cin >> a;

        if (a == 'a' || a == 'A')
        {
            m.add_book();
        }
        else if (a == 'b' || a == 'B')
        {
            m.show_book();
        }
        else if (a == 'c' || a == 'C')
        {
            m.delete_book();
        }
    }
    else if (m.n == 2)
    {
        s.S_login();
        cout << "What do you wish to do?!\n"
             << "1. Check available books \n"
             << "2. Request a book \n"
             << "3. borrow the avaiable book's online pdf \n"
             << endl;
        cin >> u;

        if (u == 1)
        {
            s.show_book();
        }
        else if(u==2){

        }
        else if(u==3){
            s.borrow_book();
        }
        else{
            cout<<"Operation doesn't exist: Exit";
        }
    }

    else
    {
        cout << "Thanks for visiting!";
    }

    return 0;
}