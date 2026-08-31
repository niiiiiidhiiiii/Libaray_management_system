#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

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
        std::ifstream File1("LDB.txt");

        string line;
        while (std::getline(File1, line))
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

int main()
{

    admin m;
    char a;
    m.display();
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

    return 0;
}
