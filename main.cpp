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
    string itemInfoString;
    string temp;
    char tempChar;
    vector<furnitureItem> ItemsArray;
    int itemArraySize;
    int spaceCounter = 0;
    short int ruinedObjectsCount = 0;


    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    //так же впихнуть обработку с файла


    cout << "Введите количество записей которые хотите обработать.\n k - ";
    cin >> itemArraySize;
    ItemsArray.resize(itemArraySize + 1);

    cout << "Вводите записи в формате:\n\t _id)_name_цвет_-_color;_ширина_-_width_см;_длина_-_length_см;_высота_-_height_см\n";

    int k = 1;
    for(auto & i : ItemsArray){
        getline(cin, itemInfoString);

        for(int j = 0; j < itemInfoString.length(); j++){
            if(itemInfoString.at(j) == ' ') spaceCounter++;

            if(spaceCounter == 1 && itemInfoString.at(j) == ' '){
                tempChar = itemInfoString.at(j + k);
                do{
                    temp += tempChar;
                    k++;
                    tempChar = itemInfoString.at(j + k);
                }while(tempChar != ')');

                int idFromString = std::stoi(temp);
                if(idFromString < 0) i.isCorrect = false;

                i.id = temp;

                temp = "";
            }

            if(spaceCounter == 2 && itemInfoString.at(j) == ' '){
                tempChar = itemInfoString.at(j + k);
                do{
                    temp += tempChar;
                    k++;
                    tempChar = itemInfoString.at(j + k);
                }while(tempChar != ' ');


                i.name = temp;

                temp = "";
            }

            if(spaceCounter == 5 && itemInfoString.at(j) == ' '){
                tempChar = itemInfoString.at(j + k);
                do{
                    temp += tempChar;
                    k++;
                    tempChar = itemInfoString.at(j + k);
                }while(tempChar != ';');

                i.color = temp;

                temp = "";
            }

            if(spaceCounter == 8 && itemInfoString.at(j) == ' '){
                tempChar = itemInfoString.at(j + k);
                do{
                    temp += tempChar;
                    k++;
                    tempChar = itemInfoString.at(j + k);
                }while(tempChar != ' ');

                double widthFromstring = std::stod(temp);
                if(widthFromstring < 0) i.isCorrect = false;

                i.width = widthFromstring;

                temp = "";
            }

            if(spaceCounter == 12 && itemInfoString.at(j) == ' '){
                tempChar = itemInfoString.at(j + k);
                do{
                    temp += tempChar;
                    k++;
                    tempChar = itemInfoString.at(j + k);
                }while(tempChar != ' ');

                double lengthFromString = std::stod(temp);
                if(lengthFromString < 0) i.isCorrect = false;

                i.length = lengthFromString;

                temp = "";
            }

            if(spaceCounter == 16 && itemInfoString.at(j) == ' '){
                tempChar = itemInfoString.at(j + k);
                do{
                    temp += tempChar;
                    k++;
                    tempChar = itemInfoString.at(j + k);
                }while(tempChar != ' ');

                double heightFromString = std::stod(temp);
                if(heightFromString < 0) i.isCorrect = false;

                i.height = heightFromString;

                temp = "";
            }

            k = 1;
            if(!i.isCorrect) ruinedObjectsCount++;
        }
    }


    double maxShelfVolume = 0;
    string maxVolumeShelfString;
    for(auto & i : ItemsArray){
        double a = i.width, b = i.length, c = i.height;
        double currentVolume = a * b * c;

        if(currentVolume > maxShelfVolume && i.name == "Шкаф" && i.isCorrect){
            maxVolumeShelfString += i.id + ' ';
            maxShelfVolume = currentVolume;
        }
    }

    if(maxShelfVolume == 0) cout << "В введённых записях не было ни одного шкафа.\n";
    else cout << maxVolumeShelfString << '\n';

    if(ruinedObjectsCount != 0){
        char confirm;
        cout << "Некоторые объекты(" << ruinedObjectsCount << ") были введены неверно, и не учитывались в решении. Вывести данные о них? y/n - ";
        cin >> confirm;
        if(confirm == 'Y' || confirm == 'y')
            for(auto & i : ItemsArray)
                if(!i.isCorrect){
                    cout << "<--------------------->\n";
                    cout << "Id: " << i.id << "\n";
                    cout << "Model: " << i.name << '\n';
                    cout << "Color: " << i.color << '\n';
                    cout << "Width: " << i.width << '\n';
                    cout << "Length: " << i.length << '\n';
                    cout << "Height: " << i.height << '\n';
                }
    }
}
