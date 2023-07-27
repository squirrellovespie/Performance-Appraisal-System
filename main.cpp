#include <iostream>
#include <limits>
#include <vector>

using namespace std;

string Dev_tasks[] = {"Taska","Taskb","Taskc"};
string Dsg_tasks[] = {"Taskh","Taskg","Taskf"};
string Arc_tasks[] = {"Taskp","Taskq","Taskr"};

struct TeamMember
{
    string name;
    int ratings[4];
};

struct nRating
{
    string name;
    int r;
};

void copyArray(string source[], string destination[], int size) 
{
    for (int i = 0; i < size; i++) 
    {
        destination[i] = source[i];
    }
}

vector<TeamMember> deepCopyVector(const vector<TeamMember>& sourceVector) 
{
    vector<TeamMember> deepCopiedVector;

    for (TeamMember tm : sourceVector) 
    {
        deepCopiedVector.push_back(tm);
    }

    return deepCopiedVector;
}

int inputRatings(vector<TeamMember>& members, int type)
{
    cout << "Select name:\n";
    for (size_t i = 0; i < members.size(); i++) 
    {
        cout << i + 1 << ". " << members[i].name << endl;
    }
    cout << "4. Exit\n";
    cout << "Enter choice: ";
    int empno;
    cin >> empno;
    string arr[3];
    type==1 ? copyArray(Dev_tasks,arr,3) : type==2 ? copyArray(Dsg_tasks,arr,3) : copyArray(Arc_tasks,arr,3);
    if (empno == 1)
    {
        for (int i = 0; i < 3; i++) 
        {
            cout << "Enter rating for " << arr[i] << ": ";
            int r;
            cin >> r;
            members[0].ratings[i] = r;
        }
        cout << "Enter overall rating: ";
        int o;
        cin >> o;
        members[0].ratings[3] = o;
    }
    else if (empno == 2)
    {
        for (int i = 0; i < 3; i++) 
        {
            cout << "Enter rating for " << arr[i] << ": ";
            int r;
            cin >> r;
            members[1].ratings[i] = r;
        }
        cout << "Enter overall rating: ";
        int o;
        cin >> o;
        members[1].ratings[3] = o;
    }
    else if (empno == 3)
    {
        for (int i = 0; i < 3; i++) 
        {
            cout << "Enter rating for " << arr[i] << ": ";
            int r;
            cin >> r;
            members[1].ratings[i] = r;
        }
        cout << "Enter overall rating: ";
        int o;
        cin >> o;
        members[2].ratings[3] = o;
    }
    else if (empno == 4)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    return 2;
}

void printRatings(TeamMember tm, int type)
{
    string arr[3];
    type==1 ? copyArray(Dev_tasks,arr,3) : type==2 ? copyArray(Dsg_tasks,arr,3) : copyArray(Arc_tasks,arr,3);
    for (int i = 0; i < 3; i++)
    {
        cout << arr[i] << "\t" << tm.ratings[i] << "\n";
    }
}

int main ()
{
    //HARD CODED
    vector<TeamMember> developers;
    TeamMember tm1;
    tm1.name = "Alice";
    developers.push_back(tm1);
    TeamMember tm2;
    tm2.name = "Bob";
    developers.push_back(tm2);
    TeamMember tm3;
    tm3.name = "Ryan";
    developers.push_back(tm3);

    vector<TeamMember> devmgr = deepCopyVector(developers);
    vector<nRating> devhr;
    nRating m1,m2,m3;
    m1.name = tm1.name;
    m2.name = tm2.name;
    m3.name = tm3.name;
    devhr.push_back(m1);
    devhr.push_back(m2);
    devhr.push_back(m3);


    vector<TeamMember> designers;
    TeamMember tm4;
    tm4.name = "Alisha";
    designers.push_back(tm4);
    TeamMember tm5;
    tm5.name = "Bobby";
    designers.push_back(tm5);
    TeamMember tm6;
    tm6.name = "Ron";
    designers.push_back(tm6);

    vector<TeamMember> dsgmgr = deepCopyVector(designers);
    vector<nRating> dsghr;
    nRating m4,m5,m6;
    m4.name = tm4.name;
    m5.name = tm5.name;
    m6.name = tm6.name;
    dsghr.push_back(m4);
    dsghr.push_back(m5);
    dsghr.push_back(m6);

    vector<TeamMember> architects;
    TeamMember tm7;
    tm7.name = "Ally";
    architects.push_back(tm7);
    TeamMember tm8;
    tm8.name = "Brown";
    architects.push_back(tm8);
    TeamMember tm9;
    tm9.name = "Rick";
    architects.push_back(tm9);

    vector<TeamMember> arcmgr = deepCopyVector(architects);
    vector<nRating> archr;
    nRating m7,m8,m9;
    m7.name = tm7.name;
    m8.name = tm8.name;
    m9.name = tm9.name;
    archr.push_back(m7);
    archr.push_back(m8);
    archr.push_back(m9);


    while (true) {
        cout << "PERFORMANCE APPRAISAL SYSTEM\n";
        cout << "1. Manager\n";
        cout << "2. Developer\n";
        cout << "3. Designer\n";
        cout << "4. Architect\n";
        cout << "5. HR\n";
        cout << "6. CEO\n";
        cout << "7. Exit\n";
        cout << "Enter choice: ";
        int choice;
        cin >> choice;

        if (choice == 1)
        {
            cout << "Which team manager are you?\n";
            cout << "1. Developer\n";
            cout << "2. Designer\n";
            cout << "3. Architect\n";
            cout << "4. Exit\n";
            cout << "Enter choice: ";
            int mgr_choice;
            cin >> mgr_choice;
            if (mgr_choice == 4) break;
            if (!(mgr_choice>=1 && mgr_choice<=4)) continue;
            vector<TeamMember> mgr_arr;
            int mgr_type;
            mgr_choice==1 ? mgr_arr.assign(devmgr.begin(), devmgr.end()) : mgr_choice==2 ? mgr_arr.assign(dsgmgr.begin(), dsgmgr.end()) : mgr_arr.assign(arcmgr.begin(), arcmgr.end());
            mgr_choice==1 ? mgr_type=1 : mgr_choice==2 ? mgr_type=2 : mgr_type=3;
            int out = inputRatings(mgr_arr, mgr_type);
            if (out == 2) cout << "Ratings Updated!\n";
            else if (out == 1) break;
            else if (out == 0) 
            {
                cout << "Invalid Input.....Redirecting to Main Menu......\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            
        }
        else if (choice == 2)
        {
            cout << "Who are you?\n";
            int out = inputRatings(developers, 1);
            if (out == 2) cout << "Ratings Updated!\n";
            else if (out == 1) break;
            else if (out == 0) 
            {
                cout << "Invalid Input.....Redirecting to Main Menu......\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }
        else if (choice == 3)
        {
            int out = inputRatings(designers, 2);
            if (out == 2) cout << "Ratings Updated!\n";
            else if (out == 1) break;
            else if (out == 0) 
            {
                cout << "Invalid Input.....Redirecting to Main Menu......\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }
        else if (choice == 4)
        {
            int out = inputRatings(architects, 3);
            if (out == 2) cout << "Ratings Updated!\n";
            else if (out == 1) break;
            else if (out == 0) 
            {
                cout << "Invalid Input.....Redirecting to Main Menu......\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }
        else if (choice == 5)
        {
            cout << "Pick a team to view scores and provide normalised ratings.\n";
            cout << "1. Developer\n";
            cout << "2. Designer\n";
            cout << "3. Architect\n";
            cout << "4. Exit\n";
            cout << "Enter choice: ";
            int hr_choice;
            cin >> hr_choice;
            if (hr_choice == 1)
            {
                cout << "Here is a list of all the development team members and their ratings.\n";
                cout << "Self ratings\n";
                for (int i = 0; i < 3; i++)
                {
                    cout << developers[i].name << ":\n";
                    printRatings(developers[i],1);
                }
                cout << "Manager ratings\n";
                for (int i = 0; i < 3; i++)
                {
                    cout << devmgr[i].name << ":\n";
                    printRatings(developers[i],1);
                }
            }
            else if (hr_choice == 2)
            {
                cout << "Here is a list of all the design team members and their ratings.\n";
                cout << "Self ratings\n";
                for (int i = 0; i < 3; i++)
                {
                    cout << designers[i].name << ":\n";
                    printRatings(designers[i],1);
                }
                cout << "Manager ratings\n";
                for (int i = 0; i < 3; i++)
                {
                    cout << dsgmgr[i].name << ":\n";
                    printRatings(designers[i],1);
                }
            }
            else if (hr_choice == 3)
            {
                cout << "Here is a list of all the architecture team members and their ratings.\n";
                cout << "Self ratings\n";
                for (int i = 0; i < 3; i++)
                {
                    cout << architects[i].name << ":\n";
                    printRatings(architects[i],1);
                }
                cout << "Manager ratings\n";
                for (int i = 0; i < 3; i++)
                {
                    cout << arcmgr[i].name << ":\n";
                    printRatings(architects[i],1);
                }
            }
            else if (hr_choice == 4) break;
            else
            {
                cout << "Invalid Input.....Redirecting to Main Menu......\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }
        else if (choice == 6)
        {
            cout << "working\n";//CEO MENU AND LOGIC
        }
        else if (choice == 7)
        {
            break;
        }
        else
        {
            cout << "Incorrect Input. Please choose a valid number!\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}
