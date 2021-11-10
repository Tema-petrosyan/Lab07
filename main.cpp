#include <iostream>
#include <string>
#include <vector>
#include <windows.h>

using std::cout;
using std::cin;
using std::string;
using std::vector;

struct furnitureItem {
    string id;

    string name;
    string color;

    double width;
    double length;
    double height;

    bool isCorrect = true;
};

int main() {
    string temp[17];
    vector<furnitureItem> ItemsArray;
    int itemArraySize;
    short int ruinedObjectsCount = 0;


    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    setlocale(LC_ALL, "");

    //��� �� �������� ��������� � �����


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

        double tempWidth = std::stod(temp[7]);
        if(tempWidth < 0) i.isCorrect = false;
        i.width = tempWidth;

        if(std::stod(temp[11]) < 0) i.isCorrect = false;
        i.length = std::stod(temp[11]);

        if(std::stod(temp[15]) < 0) i.isCorrect = false;
        i.height = std::stod(temp[15]);

        if(!i.isCorrect) ruinedObjectsCount++;
    }

    double maxShelfVolume = 0;
    string maxVolumeShelfString;
    for(auto & i : ItemsArray){
        double a = i.width, b = i.length, c = i.height;
        double currentVolume = a * b * c;

        if(currentVolume > maxShelfVolume && i.name == "����" && i.isCorrect){
            maxVolumeShelfString += i.id + ' ';
            maxShelfVolume = currentVolume;
        }
    }

    if(maxShelfVolume == 0) cout << "� �������� ������� �� ���� �� ������ �����.\n";
    else cout << maxVolumeShelfString << '\n';

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
