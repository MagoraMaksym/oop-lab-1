#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <iomanip>
#include "cost.h"
#include <clocale>
using namespace std;

int main() {

    setlocale(LC_ALL, "uk_UA.UTF-8");
    
    ifstream pfile("test.txt"); 
    
    if (!pfile.is_open()) {
        cout << "Помилка: Не вдалося відкрити файл test.txt!" << endl;
        return 1;
    }

    char str[150];
    Cost totalSum = {0, 0.0f};

    cout << left << setw(20) << "Товар" << setw(10) << "Ціна" << "К-сть" << endl;
    cout << "----------------------------------------------------" << endl;

    while (pfile.getline(str, 150)) 
    {
        if (strlen(str) == 0) continue;
        char* next_ptr = NULL;
        char* token = strtok_r(str, ",", &next_ptr);
        string name = (token != NULL) ? token : "Невідомо";

        
        token = strtok_r(NULL, ",", &next_ptr);
        int h = (token != NULL) ? stoi(token) : 0;

        token = strtok_r(NULL, ",", &next_ptr);
        float k = (token != NULL) ? stof(token) : 0.0f;

        token = strtok_r(NULL, ",", &next_ptr);
        int q = (token != NULL) ? stoi(token) : 0;

        Cost item = {h, k};
        
        cout << left << setw(20) << name << h << "грн " << k << "коп x " << q << endl;

        item.multiply(q);
        totalSum.add(item);
    }

    cout << "----------------------------------------------------" << endl;
    cout << "Загальна сума: ";
    totalSum.print();

    cout << "До сплати (заокруглено): ";
    totalSum.round_to_10();
    totalSum.print();

    pfile.close();
    return 0;


}