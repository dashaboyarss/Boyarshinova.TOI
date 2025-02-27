﻿
#include <iostream>
#include <string>
using namespace std;

struct Athlete
{
    string surname;
    string name;
    int dateOfBirth;
    int medals;
    int goldMedals;
    string sport;
    int number;
};


struct Pair
{
    int index;
    string surname;
};

struct PairMedal
{
    int index;
    int medals;
};

struct ElemSurname
{
    int index;
    string surname;
    ElemSurname* next;
};

struct ElemMedals 
{
    int index;
    int medals;
    ElemMedals* next;
};

struct TreeSurname 
{
    int index;
    string surname;
    TreeSurname* left;
    TreeSurname* right;
};

struct TreeMedals 
{
    int index;
    int medals;
    TreeMedals* left;
    TreeMedals* right;
};

void PrintMenu(string message) {
    std::cout << message;
    if (message == "Choose the action:\n") std::cout << "1) Print the data\n2) Find the element\n3) Edit the element\n4) Delete the element\n5) Exit\n";
    if (message == "Choose the print mode:\n") std::cout << "1) In the order of input\n2) Sorted by surname\n3) Sorted by total number of medals\n";
    if (message == "Choose the search mode: \n" ) std::cout << "1) By surname\n2) By medals\n";
    if (message == "Choose the attribute you want to edit:\n") std::cout << "1) Surname\n2) Name\n3) Year of birth\n4) Total number of medals\n5) Number of gold medals\n6) Kind of sport\n";
    if (message == "Choose what you want to work with: \n") std::cout << "1) Index-array\n2) Binary tree\n3) List\n4) Exit\n";
    if (message == "Choose the action with the list:\n") std:: cout << "1) Print elements\n2) Find an element\n3) Delete an elemnet from the list\n4) Add a new element\n5) Exit\n";
    if (message == "Choose sorting mode:\n") std::cout << "1) From the start of the list\n2) From the end of the list\n";
    if (message == "Choose the action with the tree:\n") std::cout << "1) Print sorted tree\n2) Find an element\n3)Delete an element\n4)Exit";

}

int ParseInt(string message) {
    int number;
    bool isConverted = false;
    do {
        cin >> number;
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits < std::streamsize >::max(), '\n');
        }
        else isConverted = true;

        if (message == "Choose the action:\n") {
            if (number < 1 || number >6) isConverted = false;
        }
        else if (message == "Enter the year of birth : ") {
            if (number < 1500 || number > 2025) isConverted = false;
        }
        else if (message == "Enter the total number of medals: " || message == "Enter the number of gold medals: " ||
            message == "Enter the total number of medals of the athlete you looking for: " || message == "Enter a total number of medals of the element you want to delete: ") {
            if (number < 0) isConverted = false;
        }
        else if (message == "Choose the print mode:\n") {
            if (number < 1 || number > 3) isConverted = false;
        }
        else if (message == "Choose the search mode: \n" || message == "Choose sorting mode:\n") {
            if (number < 1 || number > 2) isConverted = false;
        }
        else if (message == "Choose what you want to work with: " || message == "Choose the action with the tree:\n") {
            if (number < 1 || number > 4) isConverted = false;
        }
        else if (message == "Choose the action with the list:\n") {
            if (number < 1 || number > 5) isConverted = false;
        }
        else if (message == "Choose the attribute you want to edit:\n") {
            if (number < 1 || number > 6) isConverted = false;
        }

        if (!isConverted) {
            if (message == "Choose the attribute you want to edit:\n") std::cout << "Attribute is incorrect! Please, choose thr number from 1 to 6\n";
            if (message == "Enter the year of birth: ") std::cout << "The year of birth is incorrect. Please, enter the number from 1500 to 2025\n";
            if (message == "Enter the total number of medals: " || message == "Enter the number of gold medals: " || 
                message == "Enter the total number of medals of the athlete you looking for: " || message == "Enter a total number of medals of the element you want to delete: ") std::cout << "The number of medals is incorrect. Please, enter the number from zero\n";
            if (message == "Choose the print mode:\n") std::cout << "Print mode is incorrect! Please, choose the number from 1 to 3\n";
            if (message == "Choose sorting mode:\n" || message == "Choose the search mode: \n") std::cout << "Choice is incorrect! Please? choose the number from 1 to 2\n";
            if (message == "Choose what you want to work with: ") std::cout << "Choice is incorrect! Please, enter the number from 1 to 4\n";
            if (message == "Choose the action:\n" || message == "Choose the action with the list:\n") std::cout << "Action is incorrect! Please, enter the number from 1 to 5!\n";
        }
    } while (!isConverted);
    return number;
}

string ParseString(string message)
{
    string word;
    string alpha = " QWERTYUIOPASDFGHJKLZXCVBNMqwertyuiopasdfghjklzxcvbnm";
    bool isConverted;
    do
    {
        std::cout << message;
        isConverted = true;
        cin >> word;
        for (int i = 0; i < word.length(); i++)
        {
            if (alpha.find(word[i]) == std::string::npos)
            {
                isConverted = false;
                std::cout << "Last name, name and year of birth should only consist of english letters!\n";
                break;
            }
        }
    } while (!isConverted);
    return word;
}

Athlete* Create(int size) {
    Athlete* arr = new Athlete[size];
    int index = 0;
    do {
        string surname = ParseString("Enter the athlete's last name: ");
        string name = ParseString("Enter the athlete's name: ");
        std::cout << "Enter the year of birth: ";
        int dateOfBirth = ParseInt("Enter the year of birth: ");
        std::cout << "Enter the total number of medals: ";
        int medals = ParseInt("Enter the total number of medals: ");
        std::cout << "Enter the number of gold medals: ";
        int goldMedals = ParseInt("Enter the number of gold medals: ");
        string sport = ParseString("Enter the kind of sport: ");
        arr[index].name = name;
        arr[index].dateOfBirth = dateOfBirth;
        arr[index].medals = medals;
        arr[index].goldMedals = goldMedals;
        arr[index].sport = sport;
        arr[index].surname = surname;
        arr[index].number = index + 1;
        index++;

    } while (index < size);
    std::cout << "Data entered\n";
    return arr;
}

void Print(Athlete* arr, int size) {
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i].number << " " << arr[i].surname << " " << arr[i].name << " " << 
            arr[i].dateOfBirth << " year " << " " << arr[i].medals << " medals in total " << 
            " " << arr[i].goldMedals << " gold medals " << " " << arr[i].sport << "\n";
    }
}

void Print(Pair* indexArr, Athlete* arr, int size)
{

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (arr[j].number == indexArr[i].index)
            {
                std::cout << arr[j].number << " " << arr[j].surname << " " << arr[j].name << " " << 
                    arr[j].dateOfBirth << " year " << " " << arr[j].medals << " medals in total " <<
                    " " << arr[j].goldMedals << " gold medals " << " " << arr[j].sport << "\n";
                break;
            }
        }
    }
}

void Print(PairMedal* indexArr, Athlete* arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (arr[j].number == indexArr[i].index)
            {
                std::cout << arr[j].number << " " << arr[j].surname << " " << arr[j].name <<
                    " " << arr[j].dateOfBirth << " year " << " " << arr[j].medals << 
                    " medals in total " << " " << arr[j].goldMedals << " gold medals " << " " << arr[j].sport << "\n";
                break;
            }
        }
    }
}

void PrintFromFirst(ElemMedals* head, Athlete* arr)
{
    while (head != nullptr)
    {
        std::cout << arr[head->index - 1].number << ". " << arr[head->index - 1].surname << " " <<
            arr[head->index - 1].name << " " << arr[head->index - 1].dateOfBirth << " year " << arr[head->index - 1].medals <<
            " medals in total " << arr[head->index - 1].goldMedals << " gold medals " << arr[head->index - 1].sport << "\n";

        head = head->next;
    }

}

void PrintFromFirst(ElemSurname* head, Athlete* arr)
{
    while (head != nullptr)
    {
        std::cout << arr[head->index - 1].number << ". " << arr[head->index - 1].surname <<
            " " << arr[head->index - 1].name << " " << arr[head->index - 1].dateOfBirth <<
            " year " << arr[head->index - 1].medals << " medals in total " << arr[head->index - 1].goldMedals <<
            " gold medals " << arr[head->index - 1].sport << "\n";

        head = head->next;
    }

}

void PrintFromLast(ElemSurname* head, Athlete* arr) 
{
    if (head != nullptr) 
    {
        PrintFromLast(head->next, arr);
        std::cout << arr[head->index - 1].number << ". " << arr[head->index - 1].surname <<
            " " << arr[head->index - 1].name << " " << arr[head->index - 1].dateOfBirth <<
            " year " << arr[head->index - 1].medals << " medals in total " << arr[head->index - 1].goldMedals <<
            " gold medals " << arr[head->index - 1].sport << "\n";
    }
}

void PrintFromLast(ElemMedals* head, Athlete* arr)
{
    if (head != nullptr)
    {
        PrintFromLast(head->next, arr);
        std::cout << arr[head->index - 1].number << ". " << arr[head->index - 1].surname << " " << arr[head->index - 1].name << " " << arr[head->index - 1].dateOfBirth << " year " << arr[head->index - 1].medals << " medals in total " << arr[head->index - 1].goldMedals << " gold medals " << arr[head->index - 1].sport << "\n";
    }
}

PairMedal* SortMedal(Athlete* arr, int size)
{
    PairMedal* indexArr = new PairMedal[size];
    for (int i = 0; i < size; i++)
    {
        indexArr[i].index = arr[i].number;
        indexArr[i].medals = arr[i].medals;
    }

    int left = 0;
    int right = size - 1;
    int tempMedals;
    int tempIndex;
    while (left <= right)
    {
        for (int i = left; i <= right - 1; i++) {
            if (indexArr[i].medals < indexArr[i + 1].medals)
            {
                tempMedals = indexArr[i].medals;
                tempIndex = indexArr[i].index;
                indexArr[i].medals = indexArr[i + 1].medals;
                indexArr[i].index = indexArr[i + 1].index;
                indexArr[i + 1].index = tempIndex;
                indexArr[i + 1].medals = tempMedals;
            }
        }
        right--;
        for (int i = right; i >= left + 1; i--)
        {
            if (indexArr[i].medals > indexArr[i - 1].medals)
            {
                tempMedals = indexArr[i].medals;
                tempIndex = indexArr[i].index;
                indexArr[i].medals = indexArr[i - 1].medals;
                indexArr[i].index = indexArr[i - 1].index;
                indexArr[i - 1].index = tempIndex;
                indexArr[i - 1].medals = tempMedals;
            }
        }
        left++;
    }
    return indexArr;
}

Pair* SortSurname(Athlete* arr, int size) {
    Pair* indexArr = new Pair[size];
    for (int i = 0; i < size; i++) {
        indexArr[i].index = arr[i].number;
        indexArr[i].surname = arr[i].surname;
    }

    int left = 0;
    int right = size - 1;
    string tempSurname;
    int tempIndex;
    while (left <= right)
    {
        for (int i = left; i <= right - 1; i++) {
            if (indexArr[i].surname > indexArr[i + 1].surname)
            {
                tempSurname = indexArr[i].surname;
                tempIndex = indexArr[i].index;
                indexArr[i].surname = indexArr[i + 1].surname;
                indexArr[i].index = indexArr[i + 1].index;
                indexArr[i + 1].index = tempIndex;
                indexArr[i + 1].surname = tempSurname;
            }
        }
        right--;
        for (int i = right; i >= left + 1; i--)
        {
            if (indexArr[i].surname < indexArr[i - 1].surname)
            {
                tempSurname = indexArr[i].surname;
                tempIndex = indexArr[i].index;
                indexArr[i].surname = indexArr[i - 1].surname;
                indexArr[i].index = indexArr[i - 1].index;
                indexArr[i - 1].index = tempIndex;
                indexArr[i - 1].surname = tempSurname;
            }
        }
        left++;
    }
    return indexArr;
}


int BinarySearch(Athlete* arr, Pair* indexArr, int size) //search by surname
{
    string searchingSurname;
    int left = 0;
    int right = size - 1;
    int middle;
    bool isFound = false;
    searchingSurname = ParseString("Enter the last name of the athlete you want to find: ");
    while (left <= right)
    {
        middle = (left + right) / 2;
        if (indexArr[middle].surname == searchingSurname)
        {
            std::cout << "Element number " << indexArr[middle].index << "was found" << "\n";
            int j = indexArr[middle].index - 1;
            std::cout << arr[j].number << " " << arr[j].surname << " " << arr[j].name << " " <<
                arr[j].dateOfBirth << " year " << " " << arr[j].medals << " medals in total" <<
                " " << arr[j].goldMedals << " gold medals" << " " << arr[j].sport << "\n";
            isFound = true;
            return j;
        }
        else if (indexArr[middle].surname < searchingSurname) left = middle + 1;
        else right = middle - 1;
    }
    if (!isFound) std::cout << "Element with the entered attribute doesn't exist\n";
    return -1;
}


int BinarySearch(Athlete* arr, PairMedal* indexArr, int left, int right, int searchingMedals) //search by medals
{
    if (right >= left) {
        int middle = left + (right - left) / 2;

        if (indexArr[middle].medals == searchingMedals)
        {
            std::cout << "Element number " << indexArr[middle].index << " was found" << "\n";
            int j = indexArr[middle].index - 1;
            std::cout << arr[j].number << " " << arr[j].surname << " " << arr[j].name << " " <<
                arr[j].dateOfBirth << " year " << " " << arr[j].medals << " medals in total " <<
                " " << arr[j].goldMedals << " gold medals " << " " << arr[j].sport << "\n";
            return j;
        }


        if (indexArr[middle].medals > searchingMedals) return BinarySearch(arr, indexArr, middle + 1, right, searchingMedals);

        return BinarySearch(arr, indexArr, left, middle - 1, searchingMedals);
    }

    std::cout << "Element with the entered attribute doesn't exist\n";
    return -1;
}


Athlete* Delete(Athlete* arr, int size, int deleteIndex) {
    Athlete* newArr = new Athlete[size - 1];
    int num = 0;
    if (size - 1 == 0)
    {
        std::cout << "The last element was deleted\n";
        return newArr;
    }
    else
    {
        for (int i = 0; i < size; i++)
        {
            if (i != deleteIndex)
            {
                newArr[num].number = arr[i].number;
                newArr[num].surname = arr[i].surname;
                newArr[num].name = arr[i].name;
                newArr[num].dateOfBirth = arr[i].dateOfBirth;
                newArr[num].medals = arr[i].medals;
                newArr[num].goldMedals = arr[i].goldMedals;
                newArr[num].sport = arr[i].sport;
                num++;
            }
        }
        std::cout << "Element was deleted\n";
        return newArr;
    }
}

Athlete* Edit(Athlete* arr, int size, Pair* indexArr)
{
    int searchingIndex;
    int editedItem;
    string surname;
    string name;
    int dateOfBirth;
    int medals;
    int goldMedals;
    string sport;
    searchingIndex = BinarySearch(arr, indexArr, size);
    if (searchingIndex != -1)
    {
        PrintMenu("Choose the attribute you want to edit:\n");
        editedItem = ParseInt("Choose the attribute you want to edit:\n");
        switch (editedItem)
        {
        case 1: //surname
            surname = ParseString("Enter new last name: ");
            arr[searchingIndex].surname = surname;
            break;

        case 2: //name
            name = ParseString("Enter new name: ");
            arr[searchingIndex].name = name;
            break;

        case 3: //year of birth
            std::cout << "Enter new date of birth: ";
            dateOfBirth = ParseInt("Enter new date of birth: ");
            arr[searchingIndex].dateOfBirth = dateOfBirth;
            break;

        case 4: //total number of medals
            std::cout << "Enter new total number of medals: ";
            medals = ParseInt("Enter new total number of medals: ");
            arr[searchingIndex].medals = medals;
            break;

        case 5: //number of gold medals
            std::cout << "Enter new number of gold medals: ";
            goldMedals = ParseInt("Enter new number of gold medals: ");
            arr[searchingIndex].goldMedals = goldMedals;
            break;

        case 6: //kind of sport
            sport = ParseString("Enter new kind of sport: ");
            arr[searchingIndex].sport = sport;
            break;
        }
        std::cout << "Data was edited\n";
        return arr;
    }
    else
    {
        std::cout << "Element with the entered attribute doesn't exist!\n";
        return arr;
    }
}

Athlete* Edit(Athlete* arr, int size, int searchingIndex)
{
    int editedItem;
    string surname;
    string name;
    int dateOfBirth;
    int medals;
    int goldMedals;
    string sport;
    if (searchingIndex != -1)
    {
        PrintMenu("Choose the attribute you want to edit:\n");
        editedItem = ParseInt("Choose the attribute you want to edit:\n");
        switch (editedItem)
        {
        case 1: //surname
            surname = ParseString("Enter new last name: ");
            arr[searchingIndex].surname = surname;
            break;

        case 2: //name
            name = ParseString("Enter new name: ");
            arr[searchingIndex].name = name;
            break;

        case 3: //year of birth
            dateOfBirth = ParseInt("Enter new date of birth: ");
            arr[searchingIndex].dateOfBirth = dateOfBirth;
            break;

        case 4: //number of medals
            medals = ParseInt("Enter new total number of medals: ");
            arr[searchingIndex].medals = medals;
            break;

        case 5: //number of gold medals
            goldMedals = ParseInt("Enter new number of gold medals: ");
            arr[searchingIndex].goldMedals = goldMedals;
            break;

        case 6: //kind of sport
            sport = ParseString("Enter new kind of sport: ");
            arr[searchingIndex].sport = sport;
            break;
        }
    std::cout << "Data was edited\n";
        return arr;
    }
    else
    {
        std::cout << "Element with the entered attribute doesn't exist!\n";
        return arr;
    }
}

int SearchList(ElemSurname* head, string surname) 
{
    while (head != nullptr) 
    {
        if (head->surname == surname) 
        {
            return head->index - 1;
        }
        head = head->next;
    }
    return -1;
}

int SearchList(ElemMedals* head, int medals)
{
    while (head != nullptr)
    {
        if (head->medals == medals)
        {
            return head->index - 1;
        }
        head = head->next;
    }
    return -1;
}


Athlete Add(int size) 
{
    Athlete newEl;
    string surname = ParseString("Enter the athlete's last name: ");
    string name = ParseString("Enter the athlete's name: ");
    std::cout << "Enter the year of birth: ";
    int dateOfBirth = ParseInt("Enter the year of birth: ");
    std::cout << "Enter the total number of medals: ";
    int medals = ParseInt("Enter the total number of medals: ");
    std::cout << "Enter the number of gold medals: ";
    int goldMedals = ParseInt("Enter the number of gold medals: ");
    string sport = ParseString("Enter the kind of sport: ");
    newEl.name = name;
    newEl.dateOfBirth = dateOfBirth;
    newEl.medals = medals;
    newEl.goldMedals = goldMedals;
    newEl.sport = sport;
    newEl.surname = surname;
    newEl.number = size + 1;
    return newEl;
}

void AddTree(TreeSurname* root, Athlete* athletes, int size) 
{
    TreeSurname* rootNow = nullptr;;
    TreeSurname* newEl;
    bool isFound;
    for (int i = 0; i < size; i++) 
    {
        rootNow = root;
        newEl = new TreeSurname;
        newEl->surname = athletes[i].surname;
        newEl->index = athletes[i].number;
        newEl->right = nullptr;
        newEl->left = nullptr;
        isFound = false;
        if (i == 0) 
        {
            root = newEl;
        }
        else 
        {
            do 
            {
                if (newEl->surname < rootNow->surname)
                {
                    if (rootNow->left == nullptr)
                    {
                        rootNow->left = newEl;
                        isFound = true;
                    }
                    else
                    {
                        rootNow = rootNow->left;
                    }
                }
                if (newEl->surname > rootNow->surname) 
                {
                    if (rootNow->right == nullptr) 
                    {
                        rootNow->right = newEl;
                        isFound = true;
                    }
                    else 
                    {
                        rootNow = rootNow->right;
                    }
                }
            } while (!isFound);
            
        }
    }
}

void PrintFromFirst(TreeSurname* Root, Athlete* arr) 
{
    TreeSurname* rootNow = Root;

    if (rootNow != nullptr) 
    {
        PrintFromFirst(rootNow->left, arr);
        std::cout << arr[rootNow->index - 1].number << " " << arr[rootNow->index - 1].surname << 
            " " << arr[rootNow->index - 1].name << " " << arr[rootNow->index - 1].dateOfBirth << 
            " year " << " " << arr[rootNow->index - 1].medals << " medals in total " << " " <<
            arr[rootNow->index - 1].goldMedals << " gold medals " << " " << arr[rootNow->index - 1].sport << "\n";
        PrintFromFirst(rootNow->right, arr);
    }
}

void PrintFromLast(TreeMedals* Root, Athlete* arr) 
{
    TreeMedals* rootNow = Root;
    if (rootNow != nullptr)
    {
        PrintFromLast(rootNow->right, arr);
        std::cout << arr[rootNow->index - 1].number << " " << arr[rootNow->index - 1].surname <<
            " " << arr[rootNow->index - 1].name << " " << arr[rootNow->index - 1].dateOfBirth << 
            " year " << " " << arr[rootNow->index - 1].medals << " medals in total " << " " << 
            arr[rootNow->index - 1].goldMedals << " gold medals " << " " << arr[rootNow->index - 1].sport << "\n";
        PrintFromLast(rootNow->left, arr);
    }
}

int TreeSearch(TreeSurname* Root, string surname) 
{

    TreeSurname* rootNow = Root;
    while (rootNow != nullptr) 
    {
        if (rootNow->surname == surname) 
        {
            return rootNow->index;
        }
        else if (rootNow->surname > surname) 
        {
            rootNow = rootNow->left;
        }
        else if (rootNow->surname < surname) 
        {
            rootNow = rootNow->right;
        }
    }
    return -1;
}

int TreeSearch(TreeMedals* Root, int medals) 
{
    TreeMedals* rootNow = Root;
    while (rootNow != nullptr) 
    {
        if (rootNow->medals == medals)
        {
            return rootNow->index;
        }
        else if (rootNow->medals > medals)
        {
            rootNow = rootNow->left;
        }
        else if (rootNow->medals < medals)
        {
            rootNow = rootNow->right;
        }
    }
    return -1;
}



void FixIndex(ElemSurname* head, int index, string surname) 
{
    ElemSurname* headNow = head;
    while (headNow != nullptr) 
    {
        if (headNow->surname == surname) 
        {
            headNow->index = index;
            break;
        }

        else if (headNow->surname < surname) headNow = headNow->next;
    }
}

void FixIndex(ElemMedals* head, int index, int medals)
{
    ElemMedals* headNow = head;
    while (headNow != nullptr)
    {
        if (headNow->medals == medals)
        {
            headNow->index = index;
            break;
        }

        else if (headNow->medals < medals) headNow = headNow->next;
    }
}

void FixIndex(TreeSurname* root, int index, string surname)
{
    TreeSurname* rootNow = root;
    while (rootNow != nullptr)
    {
        if (rootNow->surname == surname) {
            rootNow->index = index;
            break;
        }
        else if (rootNow->surname > surname) rootNow = rootNow->left;
        else if (rootNow->surname < surname) rootNow = rootNow->right;
    }
}

void FixIndex(TreeMedals* root, int index, int medals) 
{
    TreeMedals* rootNow = root;
    while (rootNow != nullptr)
    {
        if (rootNow->medals == medals) {
            rootNow->index = index;
            break;
        }
        else if (rootNow->medals > medals) rootNow = rootNow->left;
        else if (rootNow->medals < medals) rootNow = rootNow->right;
    }
}

TreeSurname* Delete(TreeSurname* Root, string searchingSurname) 
{
    TreeSurname* rootNow = Root;
    TreeSurname* c = nullptr;
    TreeSurname* node = nullptr;
    TreeSurname*  newRoot = nullptr;
    bool isFound = false;
    while (rootNow != nullptr)
    {
        if (rootNow->surname == searchingSurname)
        {
            if (c == nullptr)
            {
                if (rootNow->left == nullptr && rootNow->right == nullptr)
                {
                    Root = nullptr;
                    isFound = true;
                }

                else if (rootNow->left == nullptr)
                {
                    Root = Root->right;
                    isFound = true;
                }
                else if (rootNow->right == nullptr)
                {
                    Root = Root->left;
                    isFound = true;
                }
                else if (!(rootNow->left == nullptr || rootNow->right == nullptr))
                {
                    newRoot = rootNow->right;
                    Root = Root->right;
                    node = rootNow->left;
                    do
                    {
                        if (node->surname > newRoot->surname)
                        {
                            if (newRoot->right == nullptr)
                            {
                                newRoot->right = node;
                                isFound = true;
                            }
                            else newRoot = newRoot->right;
                        }
                        else if (node->surname < newRoot->surname)
                        {
                            if (newRoot->left == nullptr)
                            {
                                newRoot->left = node;
                                isFound = true;
                            }
                            else newRoot = newRoot->left;
                        }
                    } while (!isFound);
                }


            }
            else if (c->left == rootNow)
            {
                if (rootNow->left == nullptr && rootNow->right == nullptr)
                {
                    c->left = nullptr;
                    isFound = true;
                }
                else if (rootNow->left == nullptr)
                {
                    c->left = rootNow->right;
                    isFound = true;
                }
                else if (rootNow->right == nullptr)
                {
                    c->left = rootNow->left;
                    isFound = true;
                }
                else if (rootNow->left != nullptr && rootNow->right != nullptr)
                {
                    node = rootNow->right;
                    newRoot = rootNow->left;
                    do
                    {
                        if (node->surname > newRoot->surname)
                        {
                            if (newRoot->right == nullptr)
                            {
                                newRoot->right = node;
                                isFound = true;
                            }
                            else newRoot = newRoot->right;

                        }
                        else if (node->surname < newRoot->surname)
                        {
                            if (newRoot->left == nullptr)
                            {
                                newRoot->left = node;
                                isFound = true;
                            }
                            else newRoot = newRoot->left;
                        }
                    } while (!isFound);
                    c->left = rootNow->left;

                }
            }

            else if (c->right == rootNow)
            {
                if (rootNow->left == nullptr && rootNow->right == nullptr)
                {
                    c->right = nullptr;
                    isFound = true;
                }
                else if (rootNow->left == nullptr)
                {
                    c->right = rootNow->right;
                    isFound = true;
                }
                else if (rootNow->right == nullptr)
                {
                    c->right = rootNow->left;
                    isFound = true;
                }
                else if (rootNow->left != nullptr && rootNow->right != nullptr)
                {
                    node = rootNow->right;
                    newRoot = rootNow->left;

                    do
                    {
                        if (node->surname > newRoot->surname)
                        {
                            if (newRoot->right == nullptr)
                            {
                                newRoot->right = node;
                                isFound = true;
                            }
                            else newRoot = newRoot->right;

                        }
                        else if (node->surname < newRoot->surname)
                        {
                            if (newRoot->left == nullptr)
                            {
                                newRoot->left = node;
                                isFound = true;
                            }
                            else newRoot = newRoot->left;
                        }
                    } while (!isFound);
                    c->right = rootNow->left;
                }
            }

            delete rootNow;
            rootNow = nullptr;

        }
        else if (rootNow->surname > searchingSurname)
        {
            c = rootNow;
            rootNow = rootNow->left;
        }
        else if (rootNow->surname < searchingSurname)
        {
            c = rootNow;
            rootNow = rootNow->right;
        }
    }
    if (!isFound) std::cout << "Element with the entered index doesn't exist\n";
    return Root;
}

TreeMedals* Delete(TreeMedals* RootMedals, int searchingMedals) 
{
    TreeMedals* rootNowMedals = RootMedals;
    TreeMedals* c1 = nullptr;
    TreeMedals* nodeMedals = nullptr;
    TreeMedals* newRootMedals = nullptr;
    bool isFound = false;
    while (rootNowMedals != nullptr)
    {
        if (rootNowMedals->medals == searchingMedals)
        {
            if (c1 == nullptr)
            {
                if (rootNowMedals->left == nullptr && rootNowMedals->right == nullptr)
                {
                    RootMedals = nullptr;
                }

                else if (rootNowMedals->left == nullptr)
                {
                    RootMedals = RootMedals->right;

                }
                else if (rootNowMedals->right == nullptr)
                {
                    RootMedals = RootMedals->left;
                }
                else if (!(rootNowMedals->left == nullptr || rootNowMedals->right == nullptr))
                {
                    newRootMedals = rootNowMedals->right;
                    RootMedals = RootMedals->right;
                    nodeMedals = rootNowMedals->left;
                    do
                    {
                        if (nodeMedals->medals > newRootMedals->medals)
                        {
                            if (newRootMedals->right == nullptr)
                            {
                                newRootMedals->right = nodeMedals;
                                isFound = true;
                            }
                            else newRootMedals = newRootMedals->right;
                        }
                        else if (nodeMedals->medals < newRootMedals->medals)
                        {
                            if (newRootMedals->left == nullptr)
                            {
                                newRootMedals->left = nodeMedals;
                                isFound = true;
                            }
                            else newRootMedals = newRootMedals->left;
                        }
                    } while (!isFound);
                }


            }
            else if (c1->left == rootNowMedals)
            {
                if (rootNowMedals->left == nullptr && rootNowMedals->right == nullptr)
                {
                    c1->left = nullptr;
                    isFound = true;
                }
                else if (rootNowMedals->left == nullptr)
                {
                    c1->left = rootNowMedals->right;
                    isFound = true;
                }
                else if (rootNowMedals->right == nullptr)
                {
                    c1->left = rootNowMedals->left;
                    isFound = true;
                }
                else if (rootNowMedals->left != nullptr && rootNowMedals->right != nullptr)
                {
                    nodeMedals = rootNowMedals->right;
                    newRootMedals = rootNowMedals->left;
                    do
                    {
                        if (nodeMedals->medals > newRootMedals->medals)
                        {
                            if (newRootMedals->right == nullptr)
                            {
                                newRootMedals->right = nodeMedals;
                                isFound = true;
                            }
                            else newRootMedals = newRootMedals->right;

                        }
                        else if (nodeMedals->medals < newRootMedals->medals)
                        {
                            if (newRootMedals->left == nullptr)
                            {
                                newRootMedals->left = nodeMedals;
                                isFound = true;
                            }
                            else newRootMedals = newRootMedals->left;
                        }
                    } while (!isFound);
                    c1->left = rootNowMedals->left;

                }
            }

            else if (c1->right == rootNowMedals)
            {
                if (rootNowMedals->left == nullptr && rootNowMedals->right == nullptr)
                {
                    c1->right = nullptr;
                    isFound = true;
                }
                else if (rootNowMedals->left == nullptr)
                {
                    c1->right = rootNowMedals->right;
                    isFound = true;
                }
                else if (rootNowMedals->right == nullptr)
                {
                    c1->right = rootNowMedals->left;
                    isFound = true;
                }
                else if (rootNowMedals->left != nullptr && rootNowMedals->right != nullptr)
                {
                    nodeMedals = rootNowMedals->right;
                    newRootMedals = rootNowMedals->left;

                    do
                    {
                        if (nodeMedals->medals > newRootMedals->medals)
                        {
                            if (newRootMedals->right == nullptr)
                            {
                                newRootMedals->right = nodeMedals;
                                isFound = true;
                            }
                            else newRootMedals = newRootMedals->right;

                        }
                        else if (nodeMedals->medals < newRootMedals->medals)
                        {
                            if (newRootMedals->left == nullptr)
                            {
                                newRootMedals->left = nodeMedals;
                                isFound = true;
                            }
                            else newRootMedals = newRootMedals->left;
                        }
                    } while (!isFound);
                    c1->right = rootNowMedals->left;
                }
            }

            delete rootNowMedals;
            rootNowMedals = nullptr;

        }
        else if (rootNowMedals->medals > searchingMedals)
        {
            c1 = rootNowMedals;
            rootNowMedals = rootNowMedals->left;
        }
        else if (rootNowMedals->medals < searchingMedals)
        {
            c1 = rootNowMedals;
            rootNowMedals = rootNowMedals->right;
        }
    }
    if (!isFound) std::cout << "Element with the entered index doesn't exist\n";
    return RootMedals;
}

ElemSurname* Delete(ElemSurname* HeadNow, int index)
{
    ElemSurname* h = HeadNow;
    ElemSurname* c = nullptr;
    int deleteIndex;
    while (h != nullptr)
    {
        if (h->index != index + 1)
        {
            c = h;
            h = h->next;
        }
        else
        {
            deleteIndex = index + 1;
            if (h == HeadNow)
            {
                HeadNow = h->next;
                break;
            }
            if (h->next == nullptr) {
                c->next = nullptr;
                break;
            }
            else
            {
                c->next = h->next;
                break;
            }

        }
    }
    delete h;
    h = nullptr;
    return HeadNow;
}

ElemMedals* Delete(ElemMedals* HeadNow, int index)
{
    ElemMedals* h = HeadNow;
    ElemMedals* c = nullptr;
    int deleteIndex;
    while (h != nullptr)
    {
        if (h->index != index + 1)
        {
            c = h;
            h = h->next;
        }
        else
        {
            deleteIndex = index + 1;
            if (h == HeadNow)
            {
                HeadNow = h->next;
                break;
            }
            if (h->next == nullptr) 
            {
                c->next = nullptr;
                break;
            }
            else
            {
                c->next = h->next;
                break;
            }

        }
    }
    delete h;
    h = nullptr;
    return HeadNow;
}

TreeSurname* CreateTreeSurname(Athlete* athletes, int size) //creating binary tree sorted by surname
{
    TreeSurname* rootNow = nullptr; 
    TreeSurname* newEl;
    TreeSurname* Root = nullptr;
    bool isFound;
    for (int i = 0; i < size; i++)
    {
        rootNow = Root;
        newEl = new TreeSurname;
        newEl->surname = athletes[i].surname;
        newEl->index = athletes[i].number;
        newEl->right = nullptr;
        newEl->left = nullptr;
        isFound = false;
        if (i == 0)
        {
            Root = newEl;
        }
        else
        {
            do
            {
                if (newEl->surname < rootNow->surname)
                {
                    if (rootNow->left == nullptr)
                    {
                        rootNow->left = newEl;
                        isFound = true;
                    }
                    else
                    {
                        rootNow = rootNow->left;
                    }
                }
                if (newEl->surname > rootNow->surname)
                {
                    if (rootNow->right == nullptr)
                    {
                        rootNow->right = newEl;
                        isFound = true;
                    }
                    else
                    {
                        rootNow = rootNow->right;
                    }
                }
            } while (!isFound);
        }
    }
    return Root;
}

TreeMedals* CreateTreeMedals(Athlete* athletes, int size) //creating tree sorted by medals
{
    bool isFound;
    TreeMedals* rootNowMedals = nullptr;
    TreeMedals* RootMedals = nullptr;;
    TreeMedals* newElMedals;
    for (int i = 0; i < size; i++)
    {
        rootNowMedals = RootMedals;
        newElMedals = new TreeMedals;
        newElMedals->medals = athletes[i].medals;
        newElMedals->index = athletes[i].number;
        newElMedals->right = nullptr;
        newElMedals->left = nullptr;
        isFound = false;
        if (i == 0)
        {
            RootMedals = newElMedals;
        }
        else
        {
            do
            {
                if (newElMedals->medals < rootNowMedals->medals)
                {
                    if (rootNowMedals->left == nullptr)
                    {
                        rootNowMedals->left = newElMedals;
                        isFound = true;
                    }
                    else
                    {
                        rootNowMedals = rootNowMedals->left;
                    }
                }
                if (newElMedals->medals > rootNowMedals->medals)
                {
                    if (rootNowMedals->right == nullptr)
                    {
                        rootNowMedals->right = newElMedals;
                        isFound = true;
                    }
                    else
                    {
                        rootNowMedals = rootNowMedals->right;
                    }
                }
            } while (!isFound);

        }
    }
    return RootMedals;
}

ElemSurname* CreateListSurname(Athlete* athletes, int size)
{
    ElemSurname* NewNode = nullptr;
    ElemSurname* c = nullptr;
    ElemSurname* h = nullptr;
    ElemSurname* HeadNow = nullptr;
    int count = 0;

    do {
        NewNode = new ElemSurname;
        NewNode->surname = athletes[count].surname;
        NewNode->index = athletes[count].number;
        NewNode->next = nullptr;

        if (HeadNow == nullptr) 
        {
            NewNode->next = nullptr;
            HeadNow = NewNode;
            count++;
        }
        else
        {
            h = HeadNow;
            for (int i = 0; i < count; i++)
            {
                if (NewNode->surname > h->surname)
                {
                    if (h->next == nullptr)
                    {
                        h->next = NewNode;
                        count++;
                    }
                    else {
                        c = h;
                        h = h->next;
                    }
                }
                else
                {
                    NewNode->next = h;
                    if (h == HeadNow)
                    {
                        HeadNow = NewNode;
                    }
                    else
                    {
                        c->next = NewNode;
                    }

                    count++;
                    break;
                }
            }
        }
    } while (count != size);
    return HeadNow;
}

ElemMedals* CreateListMedals(Athlete* athletes, int size) 
{
    ElemMedals* NewNode = nullptr;
    ElemMedals* c = nullptr;
    ElemMedals* h = nullptr;
    ElemMedals* HeadNow = nullptr;
    int count = 0;

    do {
        NewNode = new ElemMedals;
        NewNode->medals = athletes[count].medals;
        NewNode->index = athletes[count].number;
        NewNode->next = nullptr;

        if (HeadNow == nullptr) 
        {
            NewNode->next = nullptr;
            HeadNow = NewNode;
            count++;
        }
        else
        {
            h = HeadNow;
            for (int i = 0; i < count; i++)
            {
                if (NewNode->medals > h->medals)
                {
                    if (h->next == nullptr)
                    {
                        h->next = NewNode;
                        count++;
                    }
                    else {
                        c = h;
                        h = h->next;
                    }
                }
                else
                {
                    NewNode->next = h;
                    if (h == HeadNow)
                    {
                        HeadNow = NewNode;
                    }
                    else
                    {
                        c->next = NewNode;
                    }

                    count++;
                    break;
                }
            }
        }
    } while (count != size);
    return HeadNow;
}

ElemSurname* Add(ElemSurname* HeadNow, ElemSurname* newElem) 
{
    ElemSurname* c = nullptr;
    ElemSurname* h = HeadNow;

    while (h != nullptr)
    {
        if (h->surname < newElem->surname)
        {
            if (h->next == nullptr) 
            {
                h->next = newElem;
                h->next->next = nullptr;
                break;
            }
            else 
            {
                c = h;
                h = h->next;
            }
        }
        else
        {
            if (c == nullptr)
            {
                newElem->next = HeadNow;
                HeadNow = newElem;
                break;
            }
            else
            {
                newElem->next = h;
                c->next = newElem;
                break;
            }
        }
    }
    return HeadNow;
}

ElemMedals* Add(ElemMedals* HeadNow, ElemMedals* newElem)
{
    ElemMedals* c = nullptr;
    ElemMedals* h = HeadNow;

    while (h != nullptr)
    {
        if (h->medals < newElem->medals)
        {
            if (h->next == nullptr)
            {
                h->next = newElem;
                h->next->next = nullptr;
                break;
            }
            else
            {
                c = h;
                h = h->next;
            }
        }
        else
        {
            if (c == nullptr)
            {
                newElem->next = HeadNow;
                HeadNow = newElem;
                break;
            }
            else
            {
                newElem->next = h;
                c->next = newElem;
                break;
            }
        }
    }
    return HeadNow;
}

int main()
{
    int size = 3;
    Athlete* athletes = new Athlete[size];
    Pair* indexSurname = new Pair[size];
    PairMedal* indexMedal = new PairMedal[size];
    Athlete* tempAthletes;
    ElemSurname* NewNode = nullptr;
    ElemSurname* HeadNow = nullptr;
    ElemMedals* HeadNowMedals = nullptr;
    TreeSurname* Root = nullptr;
    TreeMedals* RootMedals = nullptr;
    int action;
    bool isEmpty = true;
    int printMode;
    int sortMode;
    int searchMode;
    int deleteMode;
    int deleteIndex;
    int searchingMedals;
    string searchingSurname;
    athletes = Create(size);
    isEmpty = false;
    int index;
    indexSurname = SortSurname(athletes, size);
    indexMedal = SortMedal(athletes, size);
    do {
        PrintMenu("Choose what you want to work with: \n");
        sortMode = ParseInt("Choose what you want to work with: ");
        switch (sortMode) {
        case 1://index-array
            do
            {
                PrintMenu("Choose the action:\n");
                action = ParseInt("Choose the action:\n");
                switch (action)
                {
                case 1://print
                    if (isEmpty) {
                        std::cout << "Data wasn't entered\n";
                        break;
                    }
                    else {
                        PrintMenu("Choose the print mode:\n");
                        printMode = ParseInt("Choose the print mode:\n");
                        switch (printMode) {
                        case 1://in the order of input
                            Print(athletes, size);
                            break;

                        case 2://sorted by last name
                            Print(indexSurname, athletes, size);
                            break;

                        case 3://sorted by total number of medals
                            Print(indexMedal, athletes, size);
                            break;
                        }
                    }
                    break;
                case 2://search
                    if (isEmpty)
                    {
                        std::cout << "Data wasn't entered\n";
                        break;
                    }
                    else
                    {
                        PrintMenu("Choose the search mode: \n");
                        searchMode = ParseInt("Choose the search mode: \n");
                        int searchingMedals;
                        switch (searchMode) {
                        case 1://surname
                            BinarySearch(athletes, indexSurname, size);
                            break;
                        case 2: //medals
                            std::cout << "Enter the total number of medals of the athlete you looking for: ";
                            searchingMedals = ParseInt("Enter the total number of medals of the athlete you looking for: ");
                            BinarySearch(athletes, indexMedal, 0, size, searchingMedals);
                            break;
                        }
                    }
                    break;

                case 3://edit
                    if (isEmpty)
                    {
                        std::cout << "Data wasn't entered\n";
                        break;
                    }
                    else
                    {
                        PrintMenu("Choose the search mode: \n");
                        int editMode = ParseInt("Choose the search mode: \n");
                        int searchingIndex;
                        int searchingMedals;
                        switch (editMode)
                        {
                        case 1://by surname
                            searchingIndex = BinarySearch(athletes, indexSurname, size);
                            break;

                        case 2://by medals
                            std::cout << "Enter the total number of medals of the athlete you looking for: ";
                            searchingMedals = ParseInt("Enter the total number of medals of the athlete you looking for: ");
                            searchingIndex = BinarySearch(athletes, indexMedal, 0, size, searchingMedals);
                            break;
                        }
                        athletes = Edit(athletes, size, searchingIndex);
                        switch (editMode)
                        {
                        case 1:
                            indexSurname = SortSurname(athletes, size);
                            break;
                        case 2:
                            indexMedal = SortMedal(athletes, size);
                            break;
                        }
                        RootMedals = CreateTreeMedals(athletes, size);
                        Root = CreateTreeSurname(athletes, size);
                        HeadNow = CreateListSurname(athletes, size);
                        HeadNowMedals = CreateListMedals(athletes, size);
                    }
                    break;

                case 4://delete
                    if (isEmpty) std::cout << "Data wasn't entered\n";
                    else
                    {
                        PrintMenu("Choose the search mode: \n");
                        deleteMode = ParseInt("Choose the search mode: \n");
                        deleteIndex = -1;
                        int searchingMedals;
                        do
                        {
                            switch (deleteMode)
                            {
                            case 1://surname
                                deleteIndex = BinarySearch(athletes, indexSurname, size);
                                break;
                            case 2://medals
                                std::cout << "Enter the total number of medals of the athlete you looking for: ";
                                searchingMedals = ParseInt("Enter the total number of medals of the athlete you looking for: ");
                                deleteIndex = BinarySearch(athletes, indexMedal, 0, size, searchingMedals);
                                break;
                            }
                            if (deleteIndex == -1) std::cout << "Element with the entered attribute doesn't exist! Please, enter existing attribute";
                        } while (deleteIndex == -1);

                        if (HeadNow != nullptr) 
                        {
                            HeadNowMedals = Delete(HeadNowMedals, deleteIndex);
                            HeadNow = Delete(HeadNow, deleteIndex);
                        }
                        if (Root != nullptr) 
                        {
                            RootMedals = Delete(RootMedals, searchingMedals);
                            Root = Delete(Root, searchingSurname);
                        }
                        searchingMedals = athletes[deleteIndex].medals;
                        searchingSurname = athletes[deleteIndex].surname;
                        
                        athletes = Delete(athletes, size, deleteIndex);

                        size--;
                        if (size == 0) 
                        {
                            std::cout << "The last element was deleted\n";
                            isEmpty = true;
                        }
                        else
                        {
                            for (int i = 0; i < size; i++)
                            {
                                athletes[i].number = i + 1;
                            }
                            indexSurname = SortSurname(athletes, size);
                            indexMedal = SortMedal(athletes, size);
                            std::cout << "The element was deleted\n";
                        }

                        for (int i = 0; i < size; i++)
                        {
                            FixIndex(Root, i + 1, athletes[i].surname);
                            FixIndex(RootMedals, i + 1, athletes[i].medals);
                            FixIndex(HeadNow, i + 1, athletes[i].surname);
                            FixIndex(HeadNowMedals, i + 1, athletes[i].medals);
                        }
                    }
                    break;
                }
            } while (action != 5);
            break;

        case 2://Binary tree
            if (isEmpty)
            {
                std::cout << "Data wasn't entered\n";
                break;
            }
            else 
            {
                Root = CreateTreeSurname(athletes, size);

                RootMedals = CreateTreeMedals(athletes, size);
                std::cout << "Tree was created\n";
            }

            do {
                PrintMenu("Choose the action with the tree:\n");
                action = ParseInt("Choose the action with the tree:\n");
                switch (action) 
                {
                case 1://print
                    if (isEmpty) std::cout << "Data wasn't entered\n";
                    else {
                        PrintMenu("Choose the print mode:\n");
                        printMode = ParseInt("Choose the print mode:\n");
                        switch (printMode)
                        {
                        case 1:// in order of input
                            Print(athletes, size);
                            break;
                        case 2: //sorted by surname
                            PrintFromFirst(Root, athletes);
                            break;
                        case 3:// sorted by medals
                            PrintFromLast(RootMedals, athletes);
                            break;
                        }
                    }
                    break;
                case 2: //search
                    if (isEmpty) std::cout << "Data wasn't entered\n";
                    else {
                        PrintMenu("Choose the search mode: \n");
                        searchMode = ParseInt("Choose the search mode: \n");
                        switch (searchMode)
                        {
                        case 1:// by surname
                            searchingSurname = ParseString("Enter a surname of the searching element: ");
                            index = TreeSearch(Root, searchingSurname);
                            if (index == -1) std::cout << "Element with the entered attribute doesn't exist";
                            else
                            {
                                std::cout << "The element with number " << index << " is found\n";
                                std::cout << athletes[index - 1].number << ". " << athletes[index - 1].surname << " " << athletes[index - 1].name << " " << athletes[index - 1].dateOfBirth << " year" << " " << athletes[index - 1].medals << " medals in total" << " " << athletes[index - 1].goldMedals << " gold medals" << " " << athletes[index - 1].sport << "\n";
                            }
                            
                            break;
                        case 2:// by medals
                            std::cout << "Enter new total number of medals: ";
                            searchingMedals = ParseInt("Enter new total number of medals: ");
                            index = TreeSearch(RootMedals, searchingMedals);
                            if (index == -1) std::cout << "Element with the entered attribute doesn't exist\n";
                            else
                            {
                                std::cout << "The element with number " << index << " is found\n";
                                std::cout << athletes[index - 1].number << ". " << athletes[index - 1].surname << " " << athletes[index - 1].name << " " << athletes[index - 1].dateOfBirth << " year" << " " << athletes[index - 1].medals << " medals in total" << " " << athletes[index - 1].goldMedals << " gold medals" << " " << athletes[index - 1].sport << "\n";
                            }
                            break;
                        }
                        
                    }
                    
                    break;
                case 3: // delete
                    if (isEmpty) std::cout << "Data wasn't entered\n";
                    else {
                        PrintMenu("Choose the search mode: \n");
                        deleteMode = ParseInt("Choose the search mode: \n");

                        switch (deleteMode) 
                        {
                        case 1://by surname
                            searchingSurname = ParseString("Enter a surname of the element you want to delete: ");
                            deleteIndex = TreeSearch(Root, searchingSurname) - 1;
                            searchingMedals = athletes[deleteIndex].medals;
                            Root = Delete(Root, searchingSurname);
                            RootMedals = Delete(RootMedals, searchingMedals);
                            HeadNow = Delete(HeadNow, deleteIndex);
                            HeadNowMedals = Delete(HeadNowMedals, deleteIndex);
                           
                                athletes = Delete(athletes, size, deleteIndex);

                                size--;
                                if (size == 0) 
                                {
                                    isEmpty = true;
                                    std::cout << "The last element was deleted";
                                }
                                else
                                {
                                    for (int i = 0; i < size; i++)
                                    {
                                        athletes[i].number = i + 1;
                                    }
                                    indexSurname = SortSurname(athletes, size);
                                    indexMedal = SortMedal(athletes, size);
                                    for (int i = 0; i < size; i++) 
                                    {
                                        FixIndex(Root, i + 1, athletes[i].surname);
                                        FixIndex(RootMedals, i + 1, athletes[i].medals);
                                        FixIndex(HeadNow, i + 1, athletes[i].surname);
                                        FixIndex(HeadNowMedals, i + 1, athletes[i].medals);
                                    }
                                    std::cout << "The element was deleted";
                                }
                            
                            break;
                        case 2:// by medals
                            std::cout << "Enter a total number of medals of the element you want to delete: ";
                            searchingMedals = ParseInt("Enter a total number of medals of the element you want to delete: ");
                            deleteIndex = TreeSearch(RootMedals, searchingMedals) - 1;
                            searchingSurname = athletes[deleteIndex].surname;
                            RootMedals = Delete(RootMedals, searchingMedals);
                            Root = Delete(Root, searchingSurname);
                            HeadNow = Delete(HeadNow, deleteIndex);
                            HeadNowMedals = Delete(HeadNowMedals, deleteIndex);
                            athletes = Delete(athletes, size, deleteIndex);
                            size--;
                            if (size == 0) 
                            {
                                std::cout << "The last element was deleted";
                                isEmpty = true;
                            }
                            else
                            {
                                for (int i = 0; i < size; i++)
                                {
                                    athletes[i].number = i + 1;
                                }
                                indexSurname = SortSurname(athletes, size);
                                indexMedal = SortMedal(athletes, size);
                                for (int i = 0; i < size; i++)
                                {
                                    FixIndex(Root, i + 1, athletes[i].surname);
                                    FixIndex(RootMedals, i + 1, athletes[i].medals);
                                    FixIndex(HeadNow, i + 1, athletes[i].surname);
                                    FixIndex(HeadNowMedals, i + 1, athletes[i].medals);
                                }
                                std::cout << "The element was deleted";
                            }
                            break;
                        }
                    }
                   
                    break;
                }
            } while (action != 4);
            break;

        case 3: //List
            HeadNow = CreateListSurname(athletes, size);
            HeadNowMedals = CreateListMedals(athletes, size);
            std::cout << "List was created\n";
            
            do {
                PrintMenu("Choose the action with the list:\n");
                action = ParseInt("Choose the action with the list:\n");
                switch (action)
                {
                case 1: //print
                    if (isEmpty)
                    {
                        std::cout << "Data wasn't entered\n";
                        break;
                    }
                    else
                    {
                        PrintMenu("Choose the print mode:\n");
                        printMode = ParseInt("Choose the print mode:\n");
                        switch (printMode)
                        {
                        case 1://in the order of input
                            Print(athletes, size);
                            break;

                        case 2://sorted by surname
                            PrintMenu("Choose sorting mode:\n");
                            sortMode = ParseInt("Choose sorting mode:\n");
                            switch (sortMode) 
                            {
                            case 1:
                                PrintFromFirst(HeadNow, athletes);
                                break;

                            case 2:
                                PrintFromLast(HeadNow, athletes);
                                break;
                            }
                            break;

                        case 3://sorted by medals
                            PrintMenu("Choose sorting mode:\n");
                            sortMode = ParseInt("Choose sorting mode:\n");
                            switch (sortMode)
                            {
                            case 1:
                                PrintFromFirst(HeadNowMedals, athletes);
                                break;

                            case 2:
                                PrintFromLast(HeadNowMedals, athletes);
                                break;
                            }
                            break;
                        }
                    }
                    break;

                case 2: //search
                    if (isEmpty)
                    {
                        std::cout << "Data wasn't entered\n";
                        break;
                    }
                    else 
                    {
                        PrintMenu("Choose the search mode: \n");
                        searchMode = ParseInt("Choose the search mode: \n");
                        switch (searchMode)
                        {
                        case 1://surname
                            searchingSurname = ParseString("Enter the surname you are looking for: ");
                            index = SearchList(HeadNow, searchingSurname);
                            if (index == -1) std::cout << "Element with the entered attribute doesn't exist\n";
                            else
                            {
                                std::cout << "Element with number " << index + 1 << " is found\n";
                                std::cout << athletes[index].number << " " << athletes[index].surname << " " << athletes[index].name << " " << athletes[index].dateOfBirth << " year" << " " << athletes[index].medals << " medals in total" << " " << athletes[index].goldMedals << " gold medals" << " " << athletes[index].sport << "\n";
                            }
                            break;

                        case 2://medals
                            std::cout << "Enter new total number of medals: ";
                            searchingMedals = ParseInt("Enter new total number of medals: ");
                            index = SearchList(HeadNowMedals, searchingMedals);
                            if (index == -1) std::cout << "Element with the entered attribute doesn't exist\n";
                            else
                            {
                                std::cout << "Element with number " << index + 1 << " is found\n";
                                std::cout << athletes[index].number << " " << athletes[index].surname << " " << athletes[index].name << " " << athletes[index].dateOfBirth << " year" << " " << athletes[index].medals << " medals in total" << " " << athletes[index].goldMedals << " gold medals" << " " << athletes[index].sport << "\n";
                            }
                            break;
                        }
                    }
                    
                    break;

                case 3: //delete
                    if (isEmpty)
                    {
                        std::cout << "Data wasn't entered\n";
                        break;
                    }
                    else 
                    {
                        PrintMenu("Choose the search mode: \n");
                        searchMode = ParseInt("Choose the search mode: \n");
                        switch (searchMode)
                        {
                        case 1://surname
                            searchingSurname = ParseString("Enter the surname you are looking for: ");
                            index = SearchList(HeadNow, searchingSurname);
                            deleteIndex = -1;
                            if (index == -1) std::cout << "Element with the entered attribute doesn't exist";
                            else
                            {
                                HeadNow = Delete(HeadNow, index);
                                HeadNowMedals = Delete(HeadNowMedals, index);
                                if (Root != nullptr) Root = Delete(Root, athletes[index].surname);
                                if (RootMedals != nullptr) RootMedals = Delete(RootMedals, athletes[index].medals);
                                deleteIndex = index + 1;

                                athletes = Delete(athletes, size, deleteIndex - 1);

                                size--;
                                if (size == 0) 
                                {
                                    isEmpty = true;
                                    std::cout << "The last element was deleted";
                                }
                                else
                                {
                                    for (int i = 0; i < size; i++)
                                    {
                                        athletes[i].number = i + 1;
                                    }
                                    indexSurname = SortSurname(athletes, size);
                                    indexMedal = SortMedal(athletes, size);
                                    for (int i = 0; i < size; i++)
                                    {
                                        FixIndex(HeadNow, i + 1, athletes[i].surname);
                                        FixIndex(HeadNowMedals, i + 1, athletes[i].medals);
                                        FixIndex(Root, i + 1, athletes[i].surname);
                                        FixIndex(RootMedals, i + 1, athletes[i].medals);
                                    }
                                }
                            }
                            break;

                        case 2://medals
                            std::cout << "Enter a total number of medals of the element you want to delete: ";
                            searchingMedals = ParseInt("Enter a total number of medals of the element you want to delete: ");
                            index = SearchList(HeadNowMedals, searchingMedals);
                            deleteIndex = -1;
                            if (index == -1) std::cout << "Element with the entered attribute doesn't exist";
                            else 
                            {
                                HeadNowMedals = Delete(HeadNowMedals, index);
                                HeadNow = Delete(HeadNow, index);
                                if (Root!=nullptr) Root = Delete(Root, athletes[index].surname);
                                if (RootMedals!=nullptr) RootMedals = Delete(RootMedals, athletes[index].medals);

                                deleteIndex = index + 1;

                                std::cout << "Element was deleted\n";

                                athletes = Delete(athletes, size, deleteIndex - 1);

                                size--;
                                if (size == 0) 
                                {
                                    isEmpty = true;
                                    std::cout << "The last element was deleted";
                                }

                                else
                                {
                                    for (int i = 0; i < size; i++)
                                    {
                                        athletes[i].number = i + 1;
                                    }
                                    indexSurname = SortSurname(athletes, size);
                                    indexMedal = SortMedal(athletes, size);
                                    for (int i = 0; i < size; i++)
                                    {
                                        FixIndex(HeadNowMedals, i + 1, athletes[i].medals);
                                        FixIndex(HeadNow, i + 1, athletes[i].surname);
                                        FixIndex(Root, i + 1, athletes[i].surname);
                                        FixIndex(RootMedals, i + 1, athletes[i].medals);
                                    }
                                }
                            }
                            break;
                        }
                    }
                    break;

                case 4://add
                    if (isEmpty)
                    {
                        std::cout << "Data wasn't entered\n";
                        break;
                    }
                    else 
                    {
                        tempAthletes = new Athlete[size];
                        for (int i = 0; i < size; i++)
                        {
                            tempAthletes[i].number = athletes[i].number;
                            tempAthletes[i].surname = athletes[i].surname;
                            tempAthletes[i].name = athletes[i].name;
                            tempAthletes[i].dateOfBirth = athletes[i].dateOfBirth;
                            tempAthletes[i].medals = athletes[i].medals;
                            tempAthletes[i].goldMedals = athletes[i].goldMedals;
                            tempAthletes[i].sport = athletes[i].sport;
                        }
                        Athlete newEl = Add(size);
                        size++;
                        athletes = new Athlete[size];

                        for (int i = 0; i < size - 1; i++)
                        {
                            athletes[i].number = tempAthletes[i].number;
                            athletes[i].surname = tempAthletes[i].surname;
                            athletes[i].name = tempAthletes[i].name;
                            athletes[i].dateOfBirth = tempAthletes[i].dateOfBirth;
                            athletes[i].medals = tempAthletes[i].medals;
                            athletes[i].goldMedals = tempAthletes[i].goldMedals;
                            athletes[i].sport = tempAthletes[i].sport;
                        }
                        athletes[size - 1].number = newEl.number;
                        athletes[size - 1].surname = newEl.surname;
                        athletes[size - 1].name = newEl.name;
                        athletes[size - 1].dateOfBirth = newEl.dateOfBirth;
                        athletes[size - 1].medals = newEl.medals;
                        athletes[size - 1].goldMedals = newEl.goldMedals;
                        athletes[size - 1].sport = newEl.sport;
                        indexSurname = SortSurname(athletes, size);
                        indexMedal = SortMedal(athletes, size);

                        ElemSurname* newElem = new ElemSurname;
                        ElemMedals* newElemMedals = new ElemMedals;
                        newElem->surname = athletes[size - 1].surname;
                        newElem->index = athletes[size - 1].number;
                        newElemMedals->medals = athletes[size - 1].medals;
                        newElemMedals->index = athletes[size - 1].number;

                        HeadNow = Add(HeadNow, newElem);
                        HeadNowMedals = Add(HeadNowMedals, newElemMedals);

                        Root = CreateTreeSurname(athletes, size);
                        RootMedals = CreateTreeMedals(athletes, size);
                        std::cout << "New element was added\n";
                    }
                   
                    break;

                }
            } while (action != 5);
            break;
        }
    } while (sortMode != 4);



}




