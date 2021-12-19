#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>

using namespace std;

struct furnitureItem
{
    string id;

    string name;
    string color;

    double width = 0;
    double length = 0;
    double height = 0;

    double volume = 0;

    bool isCorrect = true;
};

double str_to_double(const string& str)
{
    stringstream ss;
    ss << str;

    double result;
    ss >> result;

    return result;
}
furnitureItem tempStrToItem(string* str)
{
    furnitureItem result;

    str[0].erase(str[0].find(')'), 1);
    if(stoi(str[0]) < 0)
        result.isCorrect = false;
    result.id = str[0];

    result.name = str[1];

    str[4].erase(str[4].find(';'), 1);
    result.color = str[4];

    double tempWidth = str_to_double(str[7]);
    if(tempWidth < 0)
        result.isCorrect = false;
    result.width = tempWidth;

    double tempLength = str_to_double(str[11]);
    if(tempLength < 0)
        result.isCorrect = false;
    result.length = tempLength;

    double tempHeight = str_to_double(str[15]);
    if(tempHeight < 0)
        result.isCorrect = false;
    result.height = tempHeight;

    result.volume = result.length * result.width * result.height;

    return result;
}

vector<furnitureItem> fileInput();
vector<furnitureItem> consoleInput();

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    setlocale(LC_ALL, "");

    size_t menu = 0;

    bool goodChoice = false;
    while(!goodChoice)
    {
        cout << "�������� ������ ����� ������:\n";
        cout << "1. ������ �������.\n" << "2. ������ �� �����.\n";
        cin >> menu;

        if(!cin.good() || menu > 2 || menu < 1)
        {
            cin.ignore(225,'\n');
            cin.clear();

            cout << "������ �����, ���������� ��� ���.\n";
        }
        else goodChoice = true;
    }

    vector<furnitureItem> itemsArray;

    switch(menu)
    {
        case 1: itemsArray = consoleInput(); break;
        case 2: itemsArray = fileInput(); break;
    }

    size_t ruinedItemsCount = 0;
    string maxShelfVolumeString;
    double maxShelfVolume = 0;
    for(furnitureItem & i : itemsArray)
    {
        if(i.isCorrect)
        {
            if(i.volume > maxShelfVolume)
            {
                maxShelfVolume = i.volume;
                maxShelfVolumeString.string::append(i.id + ' ');
            }
        }
        else ruinedItemsCount++;
    }

    if(!maxShelfVolumeString.empty())
        cout << "Id ������ � ������������ �������:\n" << maxShelfVolumeString << '\n';
    else
        cout << "� �������� ������ �� ���� �� ������ �����, ���� ��� ������� �������.\n";

    if(ruinedItemsCount != 0)
    {
        char confirm;
        cout << "������� ���������� " << ruinedItemsCount << " ������� �������� ���������.\n������� ������ � ���? Y/N - ";
        cin >> confirm;
        if(confirm == 'Y' || confirm == 'y')
            for(furnitureItem & i : itemsArray)
                if(!i.isCorrect)
                {
                    cout << "<------------------->\n";
                    cout << "Id: " << i.id << "\n";
                    cout << "Model: " << i.name << '\n';
                    cout << "Color: " << i.color << '\n';
                    cout << "Width: " << i.width << '\n';
                    cout << "Length: " << i.length << '\n';
                    cout << "Height: " << i.height << '\n';
                }
    }

    return 0;
}

vector<furnitureItem> fileInput() {
    vector<furnitureItem> result;
    int resultSize = 0;

    fstream stream;
    string path;

    cout << "������� ������ ���� � ����� � �������.\n";
    cin >> path;

    stream.open(path);
    while (!stream.is_open()) {
        cout << "���� �� ������. ������� ���� ��� ���.\n";
        cin.clear();
        cin >> path;
    }
    cout << "���� ������� ������.\n";

    while(!stream.eof()){
        result.resize(++resultSize);

        string temp[17];
        for(string & i: temp)
            stream >> i;

        result[resultSize - 1] = tempStrToItem(temp);
    }
    stream.close();

    return result;
}

vector<furnitureItem> consoleInput()
{
    vector<furnitureItem> result;
    int resultSize = 0;

    cout << "������� ���������� ������� ������� ������ ����������.\n k - ";
    cin >> resultSize;
    result.resize(resultSize);

    cout << "������� ������ � �������:\n\t _id)_name_����_-_color;_������_-_width_��;_�����_-_length_��;_������_-_height_��\n";

    for(furnitureItem i : result)
    {
        string temp[17];
        for(string j : temp)
            cin >> j;

        result[resultSize - 1] = tempStrToItem(temp);
    }

    return result;
}