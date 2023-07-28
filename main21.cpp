#include <iostream>
#include <limits>
#include <vector>
#include <sstream>
#include <fstream>
#include <string> 
using namespace std;

string Dev_tasks[] = {"Taska", "Taskb", "Taskc","OverallRating"};
string Dsg_tasks[] = {"Taskh", "Taskg", "Taskf","OverallRating"};
string Arc_tasks[] = {"Taskp", "Taskq", "Taskr","OverallRating"};

class TeamMember {
public:
    TeamMember(string name) : name(name) {}

    virtual ~TeamMember() {}

    virtual TeamMember* clone() const = 0;

    virtual void inputSelfRatings() = 0;
    //virtual void inputManagerRatings() = 0;
    //virtual void inputHRRatings()=0;

    void printSelfRatings() const {
        for (int i = 0; i < 4; i++) {
            cout << getTaskName(i) << "\t" << Selfratings[i] << "\n";
            
        }
    }
    void printManagerRatings() const {
        for (int i = 0; i < 4; i++) {
            cout << getTaskName(i) << "\t" << managerRatings[i] << "\n";
            
        }
    }
    void printHRRatings() const {
        for (int i = 0; i < 4; i++) {
            cout << getTaskName(i) << "\t" << HRRatings[i] << "\n";
            
        }
    }


    string getName() const {
        return name;
    }
    string name;
    int Selfratings[3];
    int managerRatings[3];
    int HRRatings[3];
    virtual string getTaskName(int i) const = 0;

};

class Developer : public TeamMember {
public:
    Developer(string name) : TeamMember(name) {}

    TeamMember* clone() const override {
        return new Developer(*this);
    }

    void inputSelfRatings() override {
        for (int i = 0; i < 3; i++) {
            cout << "Enter rating for " << getTaskName(i) << ": ";
            cin >> Selfratings[i];
        }
        cout << "Enter overall rating: ";
        cin >> Selfratings[3];
    }

    void printRatings(const vector<TeamMember*>& employees) {
        cout << "Ratings for Developers:\n";
        for (const auto& employee : employees) {
            Developer* dev = dynamic_cast<Developer*>(employee);
            if (dev) {
                cout << "Developer: " << dev->getName() << endl;
                dev->TeamMember::printSelfRatings(); // Call base class function to print ratings
                cout << endl;
            } else {
                cout << "Developer: " << employee->getName() << " (Ratings not assigned)\n";
            }
        }
    }

private:
    string getTaskName(int i) const override {
        return Dev_tasks[i];
    }
};

class Designer : public TeamMember {
public:
    Designer(string name) : TeamMember(name) {}

    TeamMember* clone() const override {
        return new Designer(*this);
    }

    void inputSelfRatings() override {
        for (int i = 0; i < 3; i++) {
            cout << "Enter rating for " << getTaskName(i) << ": ";
            cin >> Selfratings[i];
        }
        cout << "Enter overall rating: ";
        cin >> Selfratings[3];
    }
    void printRatings(const vector<TeamMember*>& employees) {
        cout << "Ratings for Designers:\n";
        for (const auto& employee : employees) {
            Designer* dev = dynamic_cast<Designer*>(employee);
            if (dev) {
                cout << "Designer: " << dev->getName() << endl;
                dev->TeamMember::printSelfRatings(); // Call base class function to print ratings
                cout << endl;
            } else {
                cout << "Designer: " << employee->getName() << " (Ratings not assigned)\n";
            }
        }
    }

private:
    string getTaskName(int i) const override {
        return Dsg_tasks[i];
    }
};

class Architect : public TeamMember {
public:
    Architect(string name) : TeamMember(name) {}

    TeamMember* clone() const override {
        return new Architect(*this);
    }

    void inputSelfRatings() override {
        for (int i = 0; i < 3; i++) {
            cout << "Enter rating for " << getTaskName(i) << ": ";
            cin >> Selfratings[i];
        }
        cout << "Enter overall rating: ";
        cin >> Selfratings[3];
    }
    void printRatings(const vector<TeamMember*>& employees) {
        cout << "Ratings for Architects:\n";
        for (const auto& employee : employees) {
            Architect* dev = dynamic_cast<Architect*>(employee);
            if (dev) {
                cout << "Architect: " << dev->getName() << endl;
                dev->TeamMember::printSelfRatings(); // Call base class function to print ratings
                cout << endl;
            } else {
                cout << "Architect: " << employee->getName() << " (Ratings not assigned)\n";
            }
        }
    }

private:
    string getTaskName(int i) const override {
        return Arc_tasks[i];
    }
};

class Manager : public TeamMember {
public:
    Manager(string name, vector<TeamMember*>& employees) : TeamMember(name), employees(employees) {}

    TeamMember* clone() const override {
        return new Manager(*this);
    }
    void inputSelfRatings(){};
    void inputManagerRatings() {
        cout << "Select employee:\n";
        for (size_t i = 0; i < employees.size(); i++) {
            cout << i + 1 << ". " << employees[i]->getName() << endl;
        }
        cout << "Enter choice: ";
        int empno;
        cin >> empno;
        if (empno >= 1 && empno <= static_cast<int>(employees.size())) {
            TeamMember* selectedEmployee = employees[empno - 1];
            for (int i = 0; i < 3; i++) {
                cout << "Enter rating for " << selectedEmployee->getTaskName(i) << ": ";
                cin >> selectedEmployee->managerRatings[i];
            }
            cout << "Enter overall rating: ";
            cin >> selectedEmployee->managerRatings[3];
        } else {
            cout << "Invalid employee choice.\n";
        }
    }

    void printManagerRatings(){
        cout << "Ratings for Employees under " << getName() << ":\n";
        for (const auto& employee : employees) {
            cout << "Employee: " << employee->getName() << endl;
            employee->printManagerRatings(); // Call printRatings() of derived classes
            cout << endl;
        }
    }

private:
    vector<TeamMember*>& employees;

    string getTaskName(int i) const override {
        // Managers can provide ratings for their employees, not for themselves.
        return "Employee " + to_string(i + 1);
    }
};
class HR : public TeamMember {
public:
    HR(string name, vector<TeamMember*>& employees) : TeamMember(name), employees(employees) {}

    TeamMember* clone() const override {
        return new HR(*this);
    }

    void inputSelfRatings() override {
        cout << "As HR, you cannot input self-ratings.\n";
    }

    void inputHRRatings() {
        // cout << "Select employee:\n";
        // for (size_t i = 0; i < employees.size(); i++) {
        //     cout << i + 1 << ". " << employees[i]->getName() << endl;
        // }
        // cout << "Enter choice: ";
        // int empno;
        // cin >> empno;
        //if (empno >= 1 && empno <= static_cast<int>(employees.size())) {
        for(int j=1;j<=employees.size();j++){
            TeamMember* selectedEmployee = employees[j - 1];
            for (int i = 0; i < 3; i++) {
                cout << "Enter HR rating for " <<selectedEmployee->name<<" for "<< selectedEmployee->getTaskName(i) << ": ";
                cin >> selectedEmployee->HRRatings[i];
            }
            cout << "Enter overall HR rating for "<<selectedEmployee->name<<": ";
            cin >> selectedEmployee->HRRatings[3];
            for(int i=0;i<4;i++){cout<<selectedEmployee->HRRatings[i]<<endl;}  
        }
        if (!checkConstraints()) {
                cout << "Constraints violated for this department. Please reassign ratings.\n";
                inputHRRatings(); // Recursive call to reassign ratings
            } 
    }

    void printHRRatings() {
         cout<<"--------------------------\n";
        cout << "HR Ratings for Employees:\n";
         cout<<"--------------------------\n";
        for (const auto& employee : employees) {
            cout << "Employee: " << employee->getName() << endl;
            employee->printHRRatings(); // Call printHRRatings() of derived classes
            cout << endl;
        }
    }

private:
    vector<TeamMember*>& employees;

    string getTaskName(int i) const override {
        // HR can provide ratings for their employees, not for themselves.
        return "Employee " + to_string(i + 1);
    }
    bool checkConstraints() {
    bool constraintMet5 = true;
    bool constraintMet1 = true;
    int totalEmployees = employees.size();
    int countRating5 = 0;
    int countRating1 = 0;

    for (const auto& employee : employees) {
        if (employee->HRRatings[3] == 5) {
            countRating5++;
        }
        if (employee->HRRatings[3] == 1) {
            countRating1++;
        }
    }

    // Check constraint for HR rating of 5
    if (countRating5 > (totalEmployees * 0.1)) {
        constraintMet5 = false;
    }

    // Check constraint for HR rating of 1
    if (countRating1 >= (totalEmployees * 0.1)) {
        constraintMet1 = false;
    }

    return (constraintMet5 && constraintMet1);
}

};


vector<TeamMember*> deepCopyVector(const vector<TeamMember*>& sourceVector) {
    vector<TeamMember*> deepCopiedVector;

    for (const auto& tm : sourceVector) {
        deepCopiedVector.push_back(tm->clone());
    }

    return deepCopiedVector;
}
void printDepartmentRatings(const string& departmentName, const vector<TeamMember*>& employees) {
    
    double excellentPercent = 0.0, veryGoodPercent = 0.0, goodPercent = 0.0, averagePercent = 0.0, poorPercent = 0.0;

    int totalEmployees = employees.size();
    int excellentCount = 0, veryGoodCount = 0, goodCount = 0, averageCount = 0, poorCount = 0;

    for (const auto& employee : employees) {
        int overallRating = employee->HRRatings[3];
        if (overallRating == 5) {
            excellentCount++;
        } else if (overallRating == 4) {
            veryGoodCount++;
        } else if (overallRating == 3) {
            goodCount++;
        } else if (overallRating == 2) {
            averageCount++;
        } else if (overallRating == 1) {
            poorCount++;
        }
    }

    excellentPercent = (static_cast<double>(excellentCount) / totalEmployees) * 100;
    veryGoodPercent = (static_cast<double>(veryGoodCount) / totalEmployees) * 100;
    goodPercent = (static_cast<double>(goodCount) / totalEmployees) * 100;
    averagePercent = (static_cast<double>(averageCount) / totalEmployees) * 100;
    poorPercent = (static_cast<double>(poorCount) / totalEmployees) * 100;

    // Print percentages for the department
    cout << departmentName << " Department Ratings Percentage:\n";
    cout << "Excellent: " << excellentPercent << "%\n";
    cout << "Very Good: " << veryGoodPercent << "%\n";
    cout << "Good: " << goodPercent << "%\n";
    cout << "Average: " << averagePercent << "%\n";
    cout << "Poor: " << poorPercent << "%\n\n";
    ofstream file("CEO.csv", ios::app);
    if (!file.is_open()) {
        cerr << "Error: Unable to open the file for writing." << endl;
    }
    file << departmentName << fixed << excellentPercent << veryGoodPercent << goodPercent << averagePercent << poorPercent << endl;
    file.close();
}
int main() {
    vector<TeamMember*> deemployees;
 

    deemployees.push_back(new Developer("Alice"));
    deemployees.push_back(new Developer("Bob"));
    deemployees.push_back(new Developer("Ryan"));
    vector<TeamMember*> dsemployees;
    dsemployees.push_back(new Designer("Alex"));
    dsemployees.push_back(new Designer("Bobby"));
    dsemployees.push_back(new Designer("Ron"));
    vector<TeamMember*> aremployees;
    aremployees.push_back(new Architect("Ally"));
    aremployees.push_back(new Architect("Brown"));
    aremployees.push_back(new Architect("Rick"));

    vector<TeamMember*> managers;
    Manager m1("Dev Manager", deemployees),m2("Design Manager", dsemployees),m3("Architect Manager", aremployees);
    
    
    //managers.push_back(new Manager());
    //managers.push_back(new Manager("Design Manager", employees));
    //managers.push_back(new Manager("Architect Manager", employees));

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

        if (choice == 1) {
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
            //mgr_choice==1 ? mgr_arr.assign(devmgr.begin(), devmgr.end()) : mgr_choice==2 ? mgr_arr.assign(dsgmgr.begin(), dsgmgr.end()) : mgr_arr.assign(arcmgr.begin(), arcmgr.end());
            Manager* selectedManager = nullptr;
            if (mgr_choice == 1) {
                selectedManager = &m1;
            } else if (mgr_choice == 2) {
                selectedManager = &m2;
            } else if (mgr_choice == 3) {
                selectedManager = &m3;
            }
        

            if (selectedManager != nullptr) {
                selectedManager->inputManagerRatings();
            }
            // for (int i = 0; i < 3; i++)
            //     {
            //         cout << selectedManager->name << ":\n";
            //         selectedManager->printEmployeesRatings();
            //     }

            // }
        } else if (choice == 2) {
                cout << "Select name:\n";
                for (size_t i = 0; i < deemployees.size(); i++) {
                    cout << i + 1 << ". " << deemployees[i]->getName() << endl;
                }
                cout << deemployees.size() + 1 << ". Exit\n";
                cout << "Enter choice: ";
                int empno;
                cin >> empno;
                if (empno == deemployees.size() + 1) break;
                if (empno >= 1 && empno <= static_cast<int>(deemployees.size())) {
                    Developer* selectedDeveloper = dynamic_cast<Developer*>(deemployees[empno - 1]);
                    if (selectedDeveloper) {
                        selectedDeveloper->inputSelfRatings();
                    } else {
                        cout << "Invalid developer selected.\n";
                    }
                    //selectedDeveloper->printRatings(deemployees);
                } else {
                    cout << "Invalid Input.....Redirecting to Main Menu......\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
   
        } else if (choice == 3) {
            cout << "Select name:\n";
                for (size_t i = 0; i < dsemployees.size(); i++) {
                    cout << i + 1 << ". " << dsemployees[i]->getName() << endl;
                }
                cout << dsemployees.size() + 1 << ". Exit\n";
                cout << "Enter choice: ";
                int empno;
                cin >> empno;
                if (empno == dsemployees.size() + 1) break;
                if (empno >= 1 && empno <= static_cast<int>(dsemployees.size())) {
                    Designer* selectedDesigner = dynamic_cast<Designer*>(dsemployees[empno - 1]);
                    if (selectedDesigner) {
                        selectedDesigner->inputSelfRatings();
                    } else {
                        cout << "Invalid designer selected.\n";
                    }
                    selectedDesigner->printRatings(dsemployees);
                } else {
                    cout << "Invalid Input.....Redirecting to Main Menu......\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
        } else if (choice == 4) {
            cout << "Select name:\n";
                for (size_t i = 0; i < aremployees.size(); i++) {
                    cout << i + 1 << ". " << aremployees[i]->getName() << endl;
                }
                cout << aremployees.size() + 1 << ". Exit\n";
                cout << "Enter choice: ";
                int empno;
                cin >> empno;
                if (empno == aremployees.size() + 1) break;
                if (empno >= 1 && empno <= static_cast<int>(aremployees.size())) {
                    Architect* selectedArch = dynamic_cast<Architect*>(aremployees[empno - 1]);
                    if (selectedArch) {
                        selectedArch->inputSelfRatings();
                    } else {
                        cout << "Invalid Architect selected.\n";
                    }
                    selectedArch->printRatings(aremployees);
                } else {
                    cout << "Invalid Input.....Redirecting to Main Menu......\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');}
        } else if (choice == 5) {
            cout << "Pick a team to view scores and provide normalized ratings.\n";
            cout << "1. Developer\n";
            cout << "2. Designer\n";
            cout << "3. Architect\n";
            cout << "4. Exit\n";
            cout << "Enter choice: ";
            int hr_choice;
            cin >> hr_choice;

            if (hr_choice == 1) {
                cout << "Here is a list of all the development team members and their ratings.\n";
                cout << "Self ratings\n";
                cout<<"----------------\n";
                for (const auto& developer : deemployees) {
                    cout<<"Employee :"<<developer->getName()<<endl;
                    developer->printSelfRatings();
                    cout<<endl; // Call printRatings() of Developer class
                }

                cout << "Manager ratings\n";
                cout<<"----------------\n";
                m1.printManagerRatings(); // Call printRatings() of Manager class for developers
                HR hr("HR Name", deemployees); // Create an instance of HR class
                hr.inputHRRatings();
                hr.printHRRatings();
            }
            else if (hr_choice == 2) {
                cout << "Here is a list of all the design team members and their ratings.\n";
                cout << "Self ratings\n";
                cout<<"----------------\n";
                for (const auto& designer : dsemployees) {
                    cout<<"Employee :"<<designer->getName()<<endl;
                    designer->printSelfRatings();
                    cout<<endl;
                }

                cout << "Manager ratings\n";
                cout<<"----------------\n";
                m2.printManagerRatings(); // Call printRatings() of Manager class for developers
                HR hr("HR Name",dsemployees);
                hr.inputHRRatings();
                hr.printHRRatings();
            }
            else if (hr_choice == 3) {
                cout << "Here is a list of all the architecture team members and their ratings.\n";
                cout << "Self ratings\n";
                cout<<"----------------\n";
                for (const auto& architect : aremployees) {
                    cout<<"Employee :"<<architect->getName()<<endl;
                    architect->printSelfRatings();
                    cout<<endl;
                }

                cout << "Manager ratings\n";
                cout<<"----------------\n";
                m3.printManagerRatings();
                HR hr("HR Name",aremployees);
                hr.inputHRRatings();
                hr.printHRRatings();
            }
            else if (hr_choice == 4) {
                break;
            }
            else {
                cout << "Invalid Input.....Redirecting to Main Menu......\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

 
        } 
        else if (choice == 6) {
            cout << "Pick a department to view scores and view reports.\n";
            cout << "1. Developer\n";
            cout << "2. Designer\n";
            cout << "3. Architect\n";
            cout << "4. Exit\n";
            cout << "Enter choice: ";
            int ceo_choice;
            cin >> ceo_choice;
            
            if(ceo_choice == 1){
                printDepartmentRatings("Developer", deemployees);
            }
            else if(ceo_choice == 2){
                printDepartmentRatings("Designer", dsemployees);
                
                }
            else if(ceo_choice==3){
                printDepartmentRatings("Architect", dsemployees);
            }
            
            else if(ceo_choice==4) break;  
            else {
                    cout << "Invalid Input.....Redirecting to Main Menu......\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');}
        } else if (choice == 7) {
            break;
        } else {
            cout << "Incorrect Input. Please choose a valid number!\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }


    return 0;
}
