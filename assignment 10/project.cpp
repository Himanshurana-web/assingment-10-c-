#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Item
{
    int id;
    string name;
    string type;
    string location;
    string owner;
};

Item items[100];
int n = 0;

// 1. Student Login
int login()
{
    string user, pass;

    cout << "\n===== STUDENT LOGIN =====\n";
    cout << "Username: ";
    cin >> user;
    cout << "Password: ";
    cin >> pass;

    if (user == "student" && pass == "1234")
    {
        cout << "Login Successful!\n";
        return 1;
    }

    cout << "Invalid Login!\n";
    return 0;
}

// 2. Report Lost Item
void reportLost()
{
    items[n].id = n + 1;
    items[n].type = "Lost";

    cout << "\nEnter item name: ";
    cin >> items[n].name;

    cout << "Enter location: ";
    cin >> items[n].location;

    cout << "Enter owner name: ";
    cin >> items[n].owner;

    n++;

    cout << "Lost item reported successfully!\n";
}

// 3. Report Found Item
void reportFound()
{
    items[n].id = n + 1;
    items[n].type = "Found";

    cout << "\nEnter item name: ";
    cin >> items[n].name;

    cout << "Enter location: ";
    cin >> items[n].location;

    cout << "Enter finder name: ";
    cin >> items[n].owner;

    n++;

    cout << "Found item reported successfully!\n";
}

// 4. Search Item
void searchItem()
{
    string name;
    int found = 0;

    cout << "\nEnter item name: ";
    cin >> name;

    for (int i = 0; i < n; i++)
    {
        if (items[i].name == name)
        {
            cout << "\nID: " << items[i].id;
            cout << "\nType: " << items[i].type;
            cout << "\nLocation: " << items[i].location;
            cout << "\nName: " << items[i].owner << endl;

            found = 1;
        }
    }

    if (found == 0)
        cout << "Item not found.\n";
}

// 5. Auto Match Lost & Found
void autoMatch()
{
    int found = 0;

    cout << "\n===== MATCHED ITEMS =====\n";

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (items[i].name == items[j].name &&
                items[i].location == items[j].location &&
                items[i].type != items[j].type)
            {
                cout << "Match Found: "
                     << items[i].name << " at "
                     << items[i].location << endl;

                found = 1;
            }
        }
    }

    if (found == 0)
        cout << "No matching items found.\n";
}

// 6. View All Records
void viewRecords()
{
    if (n == 0)
    {
        cout << "\nNo records available.\n";
        return;
    }

    for (int i = 0; i < n; i++)
    {
        cout << "\nID: " << items[i].id;
        cout << "\nItem: " << items[i].name;
        cout << "\nType: " << items[i].type;
        cout << "\nLocation: " << items[i].location;
        cout << "\nName: " << items[i].owner << endl;
    }
}

// 7. Delete Record
void deleteRecord()
{
    int id, found = 0;

    cout << "\nEnter ID to delete: ";
    cin >> id;

    for (int i = 0; i < n; i++)
    {
        if (items[i].id == id)
        {
            for (int j = i; j < n - 1; j++)
                items[j] = items[j + 1];

            n--;
            found = 1;

            cout << "Record deleted successfully!\n";
            break;
        }
    }

    if (found == 0)
        cout << "Record not found.\n";
}

// 8. Item Statistics
void statistics()
{
    int lost = 0, found = 0;

    for (int i = 0; i < n; i++)
    {
        if (items[i].type == "Lost")
            lost++;
        else
            found++;
    }

    cout << "\n===== ITEM STATISTICS =====\n";
    cout << "Lost Items: " << lost << endl;
    cout << "Found Items: " << found << endl;
    cout << "Total Records: " << n << endl;
}

// 9. Export Report
void exportReport()
{
    ofstream file("LostFoundReport.txt");

    for (int i = 0; i < n; i++)
    {
        file << items[i].id << " "
             << items[i].name << " "
             << items[i].type << " "
             << items[i].location << " "
             << items[i].owner << endl;
    }

    file.close();

    cout << "\nReport exported successfully!\n";
}

// Main Function
int main()
{
    int loginStatus = 0;
    int choice = 0;

    loginStatus = login();

    if (loginStatus == 0)
        return 0;

    while (choice != 10)
    {
        cout << "\n===== SMART CAMPUS LOST & FOUND =====\n";

        cout << "1. Report Lost Item\n";
        cout << "2. Report Found Item\n";
        cout << "3. Search Item\n";
        cout << "4. Auto Match Lost & Found\n";
        cout << "5. View All Records\n";
        cout << "6. Delete Record\n";
        cout << "7. Item Statistics\n";
        cout << "8. Export Report\n";
        cout << "9. Sort Records\n";
        cout << "10. Exit\n";

        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            reportLost();
            break;

        case 2:
            reportFound();
            break;

        case 3:
            searchItem();
            break;

        case 4:
            autoMatch();
            break;

        case 5:
            viewRecords();
            break;

        case 6:
            deleteRecord();
            break;

        case 7:
            statistics();
            break;

        case 8:
            exportReport();
            break;

        case 9:
            for (int i = 0; i < n - 1; i++)
            {
                for (int j = i + 1; j < n; j++)
                {
                    if (items[i].name > items[j].name)
                    {
                        Item temp = items[i];
                        items[i] = items[j];
                        items[j] = temp;
                    }
                }
            }

            cout << "Records sorted successfully!\n";
            break;

        case 10:
            cout << "\nThank you!\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }
    }

    return 0;
}