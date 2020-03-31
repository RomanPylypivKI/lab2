#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>

using namespace std;

int main()
{
    while (true)
    {
        cout << "Show data - press 1" << endl;
        cout << "Write data - press 2" << endl;
        cout << "Exit - press 3" << endl;
        int choice;
        cin >> choice;
        if (choice == 1)
        {
            string fname;
            string lname;
            int dep;
            int price;
            int mon;
            int a = 1;
            ifstream infile;
            infile.open("File.txt");
            if (!infile)
            {
                cout << "Cannot open file" << endl;
                return -1;
            }
            cout << setw(11) << "First name" << setw(11) << "Last name" << setw(11) << "Deposit" << setw(11) << "Price" << setw(11) << "Day" << endl;
            while (!infile.eof())
            {
                infile >> fname;
                infile >> lname;
                infile >> dep;
                infile >> price;
                infile >> mon;
                if (!infile.eof())
                {
                    cout.width(11);
                    cout << fname;
                    cout.width(11);
                    cout << lname;
                    cout.width(11);
                    cout << dep;
                    cout.width(11);
                    cout << price;
                    cout.width(11);
                    cout << mon;
                    cout << endl;
                }
            }
            infile.close();
        }
        if (choice == 2)
        {
            string fname;
            string lname;
            int dep;
            int price;
            int mon;
            cout << "First name: ";
            cin >> fname;
            cout << endl;
            cout << "Last name: ";
            cin >> lname;
            cout << endl;
            cout << "Deposit: ";
            cin >> dep;
            cout << endl;
            cout << "Price per month of internet usage :";
            cin >> price;
            cout << endl;
            mon = (dep / price) * 28;
            fstream outfile("File.txt", ios::app);
            if (!outfile)
            {
                cout << "Cannot open file" << endl;
                return -1;
            }
            outfile.setf(ios::left);
            outfile.width(11);
            outfile << fname << endl;
            outfile.width(11);
            outfile << lname << endl;
            outfile.width(11);
            outfile << dep << endl;
            outfile.width(11);
            outfile << price << endl;
            outfile.width(11);
            outfile << mon << endl;
            outfile.close();
        }

        if (choice == 3)
        {
            break;
        }
    }
    system("pause");
}