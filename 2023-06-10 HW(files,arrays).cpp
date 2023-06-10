#include <iostream>
#include <Windows.h>
#include <fstream>
#include <string>
#include <cstdlib>

class MyException {};

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::ifstream fin{ "in.txt" };
    if (!fin.is_open()) {
        std::cout << "Файл in.txt отсутствует!\n";
        system("pause");
        return 1;
    }
    std::string s;
    int size_arr1 = 0, size_arr2 = 0;
    fin >> s;
    if (s == "") {
        std::cout << "Данные для работы программы отсутствуют!\n";
        system("pause");
        return 2;
    }
    try {
        size_arr1 = static_cast<int>(std::stoi(s));
    }
    catch (const std::invalid_argument& size_arr1) {
        std::cout << "Данные не корректны!\n";
        system("pause");
        return 3;
    }
    if (!size_arr1) {
        std::cout << "Размер массива не может быть равен 0!\n";
        system("pause");
        return 4;
    }
    int tmp;
    int* arr1 = new int[size_arr1];
    for (auto i = 0; i < size_arr1; i++) {
        fin >> s;
        if (s == "") {
            std::cout << "Данные для работы программы отсутствуют!\n";
            system("pause");
            return 5;
        }
        try {
            tmp = static_cast<int>(std::stoi(s));
        }
        catch (const std::invalid_argument& tmp) {
            std::cout << "Данные не корректны!\n";
            system("pause");
            return 6;
        }
        arr1[i] = tmp;
    }

    fin >> s;
    if (s == "") {
        std::cout << "Данные для работы программы отсутствуют!\n";
        system("pause");
        return 7;
    }
    try {
        size_arr2 = static_cast<int>(std::stoi(s));
    }
    catch (const std::invalid_argument& size_arr2) {
        std::cout << "Данные не корректны!\n";
        system("pause");
        return 8;
    }
    if (!size_arr2) {
        std::cout << "Размер массива не может быть равен 0!\n";
        system("pause");
        return 9;
    }
    int* arr2 = new int[size_arr2];
    for (auto i = 0; i < size_arr2; i++) {
        fin >> s;
        if (s == "") {
            std::cout << "Данные для работы программы отсутствуют!\n";
            system("pause");
            return 10;
        }
        try {
            tmp = static_cast<int>(std::stoi(s));
        }
        catch (const std::invalid_argument& tmp) {
            std::cout << "Данные не корректны!\n";
            system("pause");
            return 11;
        }
        arr2[i] = tmp;
    }

    std::ofstream fout{ "out.txt" };

    fout << size_arr2 << std::endl;
    for (auto i = 0; i < size_arr2; i++) {
        fout << arr2[size_arr2 - i - 1] << ' ';
    }
    fout << std::endl;

    fout << size_arr1 << std::endl;
    for (auto i = 1; i < size_arr1; i++) {
        fout << arr1[i] << ' ';
    }
    fout << arr1[0];
}