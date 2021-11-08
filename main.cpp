#include <iostream>
#include <string>
#include <vector>
#include <windows.h>

using std::cout;
using std::cin;
using std::string;
using std::vector;

struct furnitureItem {
    int id;

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
    int spaceCounter = 0;
    int itemsCounter = 0;
    short int ruinedObjectsCount = 0;


    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    int k = 1;
    getline(cin, itemInfoString);
    for(int i = 0; i < itemInfoString.length(); i++){
        if(itemInfoString.at(i) == ' ') spaceCounter++;
        if(spaceCounter == 1 && itemInfoString.at(i) == ' '){
            itemsCounter++;
            ItemsArray.resize(itemsCounter);

            tempChar = itemInfoString.at(i + k);
            do{
                temp += tempChar;
                k++;
                tempChar = itemInfoString.at(i + k);
            }while(tempChar != ')');

            int idFromString = std::stoi(temp);
            if(idFromString < 0) ItemsArray.at(itemsCounter - 1).isCorrect = false;

            ItemsArray.at(itemsCounter - 1).id = idFromString;

            temp = "";
        }

        if(spaceCounter == 2 && itemInfoString.at(i) == ' '){
            tempChar = itemInfoString.at(i + k);
            do{
                temp += tempChar;
                k++;
                tempChar = itemInfoString.at(i + k);
            }while(tempChar != ' ');

            ItemsArray.at(itemsCounter - 1).name = temp;

            temp = "";
        }

        if(spaceCounter == 5 && itemInfoString.at(i) == ' '){
            tempChar = itemInfoString.at(i + k);
            do{
                temp += tempChar;
                k++;
                tempChar = itemInfoString.at(i + k);
            }while(tempChar != ';');

            ItemsArray.at(itemsCounter - 1).color = temp;

            temp = "";
        }

        if(spaceCounter == 8 && itemInfoString.at(i) == ' '){
            tempChar = itemInfoString.at(i + k);
            do{
                temp += tempChar;
                k++;
                tempChar = itemInfoString.at(i + k);
            }while(tempChar != ' ');

            double widthFromstring = std::stod(temp);
            if(widthFromstring < 0) ItemsArray.at(itemsCounter - 1).isCorrect = false;

            ItemsArray.at(itemsCounter - 1).width = widthFromstring;

            temp = "";
        }

        if(spaceCounter == 12 && itemInfoString.at(i) == ' '){
            tempChar = itemInfoString.at(i + k);
            do{
                temp += tempChar;
                k++;
                tempChar = itemInfoString.at(i + k);
            }while(tempChar != ' ');

            double lengthFromString = std::stod(temp);
            if(lengthFromString < 0) ItemsArray.at(itemsCounter - 1).isCorrect = false;

            ItemsArray.at(itemsCounter - 1).length = lengthFromString;

            temp = "";
        }

        if(spaceCounter == 16 && itemInfoString.at(i) == ' '){
            tempChar = itemInfoString.at(i + k);
            do{
                temp += tempChar;
                k++;
                tempChar = itemInfoString.at(i + k);
            }while(tempChar != ' ');

            double heightFromString = std::stod(temp);
            if(heightFromString < 0) ItemsArray.at(itemsCounter - 1).isCorrect = false;

            ItemsArray.at(itemsCounter - 1).height = heightFromString;

            temp = "";
        }

        k = 1;
        if(!ItemsArray.at(itemsCounter - 1).isCorrect) ruinedObjectsCount++;
    }


    //шаблон для вывода инфы об объекте
    cout << "<--------------------->\n";
    cout << "Id: " << ItemsArray.at(itemsCounter - 1).id << "\n";
    cout << "Model: " << ItemsArray.at(itemsCounter - 1).name << '\n';
    cout << "Color: " << ItemsArray.at(itemsCounter - 1).color << '\n';
    cout << "Width: " << ItemsArray.at(itemsCounter - 1).width << '\n';
    cout << "Length: " << ItemsArray.at(itemsCounter - 1).length << '\n';
    cout << "Height: " << ItemsArray.at(itemsCounter - 1).height << '\n';
    cout << "Correct: " << ItemsArray.at(itemsCounter - 1).isCorrect << '\n';



}
