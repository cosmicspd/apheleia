#include <iostream>
#include <vector>
#include <limits>
using namespace std;

void wipeCin() { // clear the stdin stream; should use after every cin
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ty for the help stack overflow <3
}

int main() {

    struct Section {
        string name;
        vector<string> tasks;
    };

    int selection;
    vector<Section> sectionVec;
    Section currentSection;

    int sectionCount; // START of addition section
    do {
        cout << "How many sections do you want?: ";
        cin >> sectionCount;
        wipeCin();
        if (sectionCount <= 0) {
            cout << "Please type a valid number larger than 0." << endl;
        }
    } while (sectionCount <= 0); // do while checks if the section count is a valid number and if it isn't then it will ask again

    for (int i = 0; i < sectionCount; i++) {
        if(!currentSection.name.empty()) { // checks if the currentSection name is empty and if it isn't then it will make it empty
            currentSection.name = "";
        }

        cout << "What is the name of section #" << i + 1 << "?: ";
        getline(cin, currentSection.name); // asks the user for the name of the section and stores it

        if (!currentSection.tasks.empty()) { // clears tasks array if not already cleared
            currentSection.tasks.clear();
        }

        int taskCount;
        cout << "How many tasks are in section #" << i + 1 << "?: ";
        cin >> taskCount; // asks the user for the amount of tasks and stores it
        wipeCin();

        for (int j = 0; j < taskCount; j++) {
            string currentTask;
            cout << "What is task #" << j + 1 << "?: ";
            getline(cin, currentTask);
            currentSection.tasks.push_back(currentTask); // asks the user for the task and adds it to the end of the vector in currentSection.tasks
        }
        sectionVec.push_back(currentSection); // adds the current section to the sectionVec vector
    } // END of addition section

    cout << "Name: " + currentSection.name;
    for (int i = 0; i < currentSection.tasks.size(); i++) { // temporary debugging code, will remove later
        cout << "\nTask #" << i + 1 << ": " << currentSection.tasks.at(i);
    }

    cout << endl;

    selection = 0; // START of removal section

    do {
        cout << "Would you like to remove a section (type '1') or a task from a section (type '2')?: ";
        cin >> selection;
        wipeCin();
        if (selection != 1 && selection != 2) {
            cout << "Please choose a valid option." << endl;
        }
    } while (selection != 1 && selection != 2);

    if (selection == 1) { // remove section choice
        int sectionChosen;

        for (int i = 0; i < sectionVec.size(); i++) {
            cout << "Section #" << i + 1 << ": " << sectionVec.at(i).name << endl;
        }

        do {
            cout << "Which section would you like to remove?: ";
            cin >> sectionChosen;
            wipeCin(); // asks what section the user would like to remove and removes it
            if (sectionChosen < 1 || sectionChosen > sectionVec.size()) {
                cout << "Please choose a valid number that corresponds to a section." << endl;
            }
        } while (sectionChosen < 1 || sectionChosen > sectionVec.size()); // loops until the number is a valid section

        sectionVec.erase(sectionVec.begin() + (sectionChosen - 1)); // erases the section at the given index
    }
    else if (selection == 2) { // remove task choice
        int sectionChosen;

        for (int i = 0; i < sectionVec.size(); i++) {
            cout << "Section #" << i + 1 << ": " << sectionVec.at(i).name << endl;
        }

        do {
            cout << "Which section would you like to remove a task from?: ";
            cin >> sectionChosen;
            wipeCin();
            if (sectionChosen < 1 || sectionChosen > sectionVec.size()) { // code of section selection from earlier
                cout << "Please choose a valid number that corresponds to a section." << endl;
            }
        } while (sectionChosen < 1 || sectionChosen > sectionVec.size());

        if (sectionVec.at(sectionChosen - 1).tasks.empty()) { // if the task number is empty then it will short circuit the code
            cout << "This section has no tasks." << endl;
        }
        else {
            int taskChosen;

            for (int i = 0; i < sectionVec.at(sectionChosen - 1).tasks.size(); i++) {
                cout << "Task #" << i + 1 << ": " << sectionVec.at(sectionChosen - 1).tasks.at(i) << endl;
            }

            do {
                cout << "Which task would you like to remove?: ";
                cin >> taskChosen;
                wipeCin(); // selects task and repeats until the task is valid
                if (taskChosen < 1 || taskChosen > sectionVec.at(sectionChosen - 1).tasks.size()) {
                    cout << "Please choose a valid number that corresponds to a task." << endl;
                }
            } while (taskChosen < 1 || taskChosen > sectionVec.at(sectionChosen - 1).tasks.size());
            sectionVec.at(sectionChosen - 1).tasks.erase(sectionVec.at(sectionChosen - 1).tasks.begin() + (taskChosen - 1)); // removes the task at the given index
        }
    } // END of removal section

    if (sectionVec.empty()) { // START of viewing section
        cout << "There are no sections to view." << endl;
    }
    else {
        for (int i = 0; i < sectionVec.size(); i++) {
            cout << "Section #" << i + 1 << ": " << sectionVec.at(i).name << endl;
        }

        int sectionChosen;

        do {
            cout << "Which section would you like to view?: ";
            cin >> sectionChosen;
            wipeCin(); // select section to view
            if (sectionChosen < 1 || sectionChosen > sectionVec.size()) {
                cout << "Please choose a valid number that corresponds to a section." << endl;
            }
        } while (sectionChosen < 1 || sectionChosen > sectionVec.size());

        for (int i = 0; i < sectionVec.at(sectionChosen - 1).tasks.size(); i++) {
            cout << "Task #" << i + 1 << ": " << sectionVec.at(sectionChosen - 1).tasks.at(i) << endl; // print all tasks in the section
        }
    } // END of viewing section

    selection = 0; // START of renaming section

    do {
        cout << "Would you like to rename a section (type '1') or a task from a section (type '2')?: ";
        cin >> selection;
        wipeCin();
        if (selection != 1 && selection != 2) {
            cout << "Please choose a valid option." << endl;
        }
    } while (selection != 1 && selection != 2);

    if (selection == 1) { // rename section choice
        if (sectionVec.empty()) {
            cout << "There are no sections to rename." << endl;
        }
        else {
            int sectionChosen;

            for (int i = 0; i < sectionVec.size(); i++) {
                cout << "Section #" << i + 1 << ": " << sectionVec.at(i).name << endl;
            }

            do {
                cout << "Which section would you like to rename?: ";
                cin >> sectionChosen;
                wipeCin(); // select section for renaming
                if (sectionChosen < 1 || sectionChosen > sectionVec.size()) {
                    cout << "Please choose a valid number that corresponds to a section." << endl;
                }
            } while (sectionChosen < 1 || sectionChosen > sectionVec.size());

            cout << "What would you like to rename the section to?: ";
            getline(cin, sectionVec.at(sectionChosen - 1).name); // grab the new name and replace it
        }
    }
    else if (selection == 2) { // rename task choice

        for (int i = 0; i < sectionVec.size(); i++) {
            cout << "Section #" << i + 1 << ": " << sectionVec.at(i).name << endl;
        }

        int sectionChosen;

        do {
            cout << "Which section has a task that you would like to rename?: ";
            cin >> sectionChosen;
            wipeCin(); // select section for renaming
            if (sectionChosen < 1 || sectionChosen > sectionVec.size()) {
                cout << "Please choose a valid number that corresponds to a section." << endl;
            }
        } while (sectionChosen < 1 || sectionChosen > sectionVec.size());

        int taskChosen;

        for (int i = 0; i < sectionVec.at(sectionChosen - 1).tasks.size(); i++) {
            cout << "Task #" << i + 1 << ": " << sectionVec.at(sectionChosen - 1).tasks.at(i) << endl;
        }

        do {
            cout << "Which task do you want to rename?: ";
            cin >> taskChosen;
            wipeCin(); // select section for renaming
            if (taskChosen < 1 || taskChosen > sectionVec.at(sectionChosen - 1).tasks.size()) {
                cout << "Please choose a valid number that corresponds to a task." << endl;
            }
        } while (taskChosen < 1 || taskChosen > sectionVec.at(sectionChosen - 1).tasks.size());

        cout << "What would you like to rename the task to?: ";
        getline(cin, sectionVec.at(sectionChosen - 1).tasks.at(taskChosen - 1)); // grab the new name and replace it

    } // END of renaming section

    // TODO:
    //  - save to file
    //  - ability to cancel at any time
    //  - add deadlines??
    //  - work with curses.h to make it better
    //  - possible imgui implementation?

    return 0;

}