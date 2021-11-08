#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::cin;
using std::string;
using std::vector;

struct furnitureItem{
    size_t id = 0;
    string name;
    string color;
    double width = 0;
    double length = 0;
    double height = 0;
};

//bool isNextValue(int spaceIndex){
//    switch (spaceIndex) {
//        default: return false;
//        case 1: return true;
//        case 2: return true;
//        case 5: return true;
//        case 8: return true;
//        
//    }
//}

int main() {
    string itemInfoString;
    string temp;
    char tempChar = ' ';
    vector<furnitureItem> ItemsArray;
    int spaceCounter = 0;
    int itemsCounter = 0;

    bool nextValueFlag = false;
    int k = 1;
    getline(cin, itemInfoString);
    for(int i = 0; i < itemInfoString.length(); i++){
        if(itemInfoString.at(i) == ' ') spaceCounter++;
        if(spaceCounter == 1){
            itemsCounter++;
            ItemsArray.resize(itemsCounter);

            tempChar = itemInfoString.at(i + k);
            do{
                temp += tempChar;
                k++;
                tempChar = itemInfoString.at(i + k);
            }while(tempChar != ')');

            ItemsArray.at(itemsCounter - 1).id = std::stoi(temp);

            tempChar = ' '; temp = "";
        }

//        if(spaceCounter == 2){
//            tempChar = itemInfoString.at(i + k);
//            while(tempChar != ' '){
//                temp += tempChar;
//                k++;
//                tempChar = itemInfoString.at(i + k);
//            }
//
//            ItemsArray.at(itemsCounter - 1).name = temp;
//
//            tempChar = ' '; temp = "";
//        }
//        k = 1;
    }

    cout << ItemsArray.at(itemsCounter).id << ItemsArray.at(itemsCounter).name << '\n';

}
