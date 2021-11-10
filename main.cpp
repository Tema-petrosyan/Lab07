#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
#include <sstream>

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

double str_to_double(const std::string& str)
{
    std::stringstream ss;
    ss << str;

    double result;
    ss >> result;

    return result;
}

int main() {
    string temp[17];
    vector<furnitureItem> ItemsArray;
    int itemArraySize;
    short int ruinedObjectsCount = 0;

    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    setlocale(LC_ALL, "");

    cout << "Введите количество записей которые хотите обработать.\n k - ";
    cin >> itemArraySize;
    ItemsArray.resize(itemArraySize);

    cout << "Вводите записи в формате:\n\t _id)_name_цвет_-_color;_ширина_-_width_см;_длина_-_length_см;_высота_-_height_см\n";

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

        if(!i.isCorrect) ruinedObjectsCount++;
    }

    double maxShelfVolume = 0;
    string maxVolumeShelfString;
    for(auto & i : ItemsArray){
        if(i.isCorrect){
            double a = i.width, b = i.length, c = i.height;
            double currentVolume = a * b * c;

            if(currentVolume >= maxShelfVolume && i.name == "Шкаф"){
                maxVolumeShelfString.string::append(i.id + ' ');
                maxShelfVolume = currentVolume;
            }
        }

    }

    if(maxShelfVolume == 0) cout << "В введённых записях не было ни одного шкафа.\n";
    else {
        cout << "\nId шкафов с наибольшим объёмом: ";
        cout << maxVolumeShelfString << '\n';
    }

    if(ruinedObjectsCount != 0){
        char confirm;
        cout << "Некоторые объекты(" << ruinedObjectsCount << ") были введены неверно, и не учитывались в решении. Вывести данные о них? y/n - ";
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
