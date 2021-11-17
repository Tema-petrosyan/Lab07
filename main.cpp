#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>

using std::cout;
using std::cin;
using std::string;
using std::vector;
using std::ifstream;

struct furnitureItem {
    string id;

    string name;
    string color;

    double width;
    double length;
    double height;

    double volume;

    bool isCorrect = true;
};

void consoleSolution();

void fileSolution();

double str_to_double(const std::string& str)
{
    std::stringstream ss;
    ss << str;

    double result;
    ss >> result;

    return result;
}

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    setlocale(LC_ALL, "");

    size_t menu = 0;

    bool goodChoice = false;
    while(!goodChoice){
        cout << "�������� ������ ����� ������:\n";
        cout << "1. ������ �������.\n" << "2. ������ �� �����.\n";
        cin >> menu;
        if(!cin.good() || menu > 2 || menu < 1){
            cin.ignore(225,'\n');
            cin.clear();

            cout << "������ �����, ���������� ��� ���.\n";
        }
        else goodChoice = true;
    }

    switch(menu){
        case 1: consoleSolution(); break;
        case 2: fileSolution(); break;
    }
}

void fileSolution() {
    string temp[17];
    vector<furnitureItem> ItemsArray;
    int itemArraySize = 0;
    short int ruinedObjectsCount = 0;
    double maxShelfVolume = 0;

    ifstream fin;
    string path;

    cout << "������� ���� � ����� � ������� ��� ��� ��� � ���������� � ����������.\n";
    cin >> path;

    fin.open(path);
    while(!fin.is_open()){
        cout << "���� �� ������. ������� ���� ��� ���.\n";
        cin.clear(); cin >> path;
    }
    cout << "���� ������� ������.\n";

    while(!fin.eof()){
        itemArraySize++;
        ItemsArray.resize(itemArraySize);

        for(auto & i: temp) fin >> i;
        temp[0].erase(temp[0].find(')'), 1);
        if(std::stoi(temp[0]) < 0) ItemsArray.at(itemArraySize - 1).isCorrect = false;
        ItemsArray.at(itemArraySize - 1).id = temp[0];

        ItemsArray.at(itemArraySize - 1).name = temp[1];

        temp[4].erase(temp[4].find(';'), 1);
        ItemsArray.at(itemArraySize - 1).color = temp[4];

        double tempWidth = str_to_double(temp[7]);
        if(tempWidth < 0) ItemsArray.at(itemArraySize - 1).isCorrect = false;
        ItemsArray.at(itemArraySize - 1).width = tempWidth;

        double tempLength = str_to_double(temp[11]);
        if(tempLength < 0) ItemsArray.at(itemArraySize - 1).isCorrect = false;
        ItemsArray.at(itemArraySize - 1).length = tempLength;

        double tempHeight = str_to_double(temp[15]);
        if(tempHeight < 0) ItemsArray.at(itemArraySize - 1).isCorrect = false;
        ItemsArray.at(itemArraySize - 1).height = tempHeight;

        ItemsArray.at(itemArraySize - 1).volume = ItemsArray.at(itemArraySize - 1).length * ItemsArray.at(itemArraySize - 1).width * ItemsArray.at(itemArraySize - 1).height;
        if(ItemsArray.at(itemArraySize - 1).isCorrect && ItemsArray.at(itemArraySize - 1).volume > maxShelfVolume && ItemsArray.at(itemArraySize - 1).name == "����") maxShelfVolume = ItemsArray.at(itemArraySize - 1).volume;
        if(!ItemsArray.at(itemArraySize - 1).isCorrect) ruinedObjectsCount++;
    }

    string maxVolumeShelfString;
    for(auto & i : ItemsArray){
        if(i.isCorrect && i.name == "����"){
            if(i.volume == maxShelfVolume)
                maxVolumeShelfString.string::append(i.id + ' ');
        }
    }

    if(maxVolumeShelfString.empty()) cout << "� �������� ������� �� ���� �� ������ �����.\n";
    else {
        cout << "\nId ������ � ���������� �������: ";
        cout << maxVolumeShelfString << '\n';
    }

    if(ruinedObjectsCount != 0){
        char confirm;
        cout << "��������� �������(" << ruinedObjectsCount << ") ���� ������� �������, � �� ����������� � �������. ������� ������ � ���? y/n - ";
        cin >> confirm;
        if(confirm == 'Y' || confirm == 'y')
            for(auto & i : ItemsArray)
                if(!i.isCorrect){
                    cout << "<------------------->\n";
                    cout << "Id: " << i.id << "\n";
                    cout << "Model: " << i.name << '\n';
                    cout << "Color: " << i.color << '\n';
                    cout << "Width: " << i.width << '\n';
                    cout << "Length: " << i.length << '\n';
                    cout << "Height: " << i.height << '\n';
                }
    }
}

void consoleSolution() {
    string temp[17];
    vector<furnitureItem> ItemsArray;
    int itemArraySize;
    short int ruinedObjectsCount = 0;
    double maxShelfVolume = 0;

    cout << "������� ���������� ������� ������� ������ ����������.\n k - ";
    cin >> itemArraySize;
    ItemsArray.resize(itemArraySize);

    cout << "������� ������ � �������:\n\t _id)_name_����_-_color;_������_-_width_��;_�����_-_length_��;_������_-_height_��\n";

    for(auto & i : ItemsArray){
        for(auto & j : temp) cin >> j;

        temp[0].erase(temp[0].find(')'), 1);
        if(std::stoi(temp[0]) < 0) i.isCorrect = false;
        i.id = temp[0];

        i.name = temp[1];

        temp[4].erase(temp[4].find(';'), 1);
        i.color = temp[4];

        double tempWidth = str_to_double(temp[7]);
        if(tempWidth < 0) i.isCorrect = false;
        i.width = tempWidth;

        double tempLength = str_to_double(temp[11]);
        if(tempLength < 0) i.isCorrect = false;
        i.length = tempLength;

        double tempHeight = str_to_double(temp[15]);
        if(tempHeight < 0) i.isCorrect = false;
        i.height = tempHeight;

        i.volume = i.length * i.width * i.height;
        if(i.isCorrect && i.volume > maxShelfVolume && i.name == "����") maxShelfVolume = i.volume;
        if(!i.isCorrect) ruinedObjectsCount++;
    }


    string maxVolumeShelfString;
    for(auto & i : ItemsArray){
        if(i.isCorrect && i.name == "����"){
            if(i.volume == maxShelfVolume)
                maxVolumeShelfString.string::append(i.id + ' ');
        }
    }

    if(maxVolumeShelfString.empty()) cout << "� �������� ������� �� ���� �� ������ �����.\n";
    else {
        cout << "\nId ������ � ���������� �������: ";
        cout << maxVolumeShelfString << '\n';
    }

    if(ruinedObjectsCount != 0){
        char confirm;
        cout << "��������� �������(" << ruinedObjectsCount << ") ���� ������� �������, � �� ����������� � �������. ������� ������ � ���? y/n - ";
        cin >> confirm;
        if(confirm == 'Y' || confirm == 'y')
            for(auto & i : ItemsArray)
                if(!i.isCorrect){
                    cout << "<------------------->\n";
                    cout << "Id: " << i.id << "\n";
                    cout << "Model: " << i.name << '\n';
                    cout << "Color: " << i.color << '\n';
                    cout << "Width: " << i.width << '\n';
                    cout << "Length: " << i.length << '\n';
                    cout << "Height: " << i.height << '\n';
                }
    }
}