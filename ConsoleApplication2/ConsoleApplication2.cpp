// ConsoleApplication2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <fstream>

using namespace std;


struct Student
{
    string name;
    int age;
    Student(string _name, int _age)
    {
       name = _name;
        age = _age;
    }
};

class Parent
{
private:
    vector <Student> students;
public:
    Parent(string path_file)
    {
        string buf;
        bool is_name = true;
        ifstream file(path_file);
        while (file >> buf)
        {
            if (is_name)
            {
                students.push_back(Student(buf, 0));
            }
            else
            {
                students.back().age = stoi(buf);
            }
            is_name = !is_name;
        }

    }
    virtual void toString()
    {
        string result;
        for (vector<Student>::iterator iter = students.begin(); iter != students.end(); ++iter)
        {
            result += iter->name;
            result += " ";
            result += iter->age;
            result += "  ";
        }
    }
};

class Child : public Parent
{
public:
    Child(string path_file) :Parent(path_file)
    {
 
    }

};

int main()
{
    std::cout << "Hello World!\n";
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
