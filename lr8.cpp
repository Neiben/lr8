// lr8.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include<iostream>
#include <vector>
#include <string>
using namespace std;


struct GUITAR {
    string Brand_name;
    string Model_name;
    int Price;
};
ostream& operator<< (ostream& out, const GUITAR& guitar )
{
    out << endl;
    out << " Name of the brand is " << guitar.Brand_name << endl;
    out << " Model: " << guitar.Model_name << endl;
    out << " you can buy this for: " << guitar.Price << " dollars" <<  endl;
    return out;
}
bool operator !=(const GUITAR& one, const GUITAR& two) {
    return one.Price != two.Price;
}
bool operator ==(const GUITAR& one, const GUITAR& two) {
    return one.Price == two.Price;
}

template <typename T>
struct Ring_element
{
    T value;
    Ring_element* prev = nullptr;
    Ring_element* next = nullptr;
};

template <typename T>
struct Ring_struct
{
    Ring_element<T>* first;
    Ring_element<T>* last;
};

template <typename T>
void constructor(Ring_struct<T>& rg)
{
    rg.first = nullptr;
    rg.last = nullptr;
}
 template <typename T>
void destructor(Ring_struct<T>& rg) {
    
    while (rg.first != rg.last)    {    
        Ring_element<T>* abc = rg.first;
        rg.first = rg.first->next;
        delete abc;
       
    }

    delete rg.first;
    rg.first = nullptr;
    rg.last = nullptr;
  
}

template <typename T>
void print(Ring_struct<T>& rg) {
    if (rg.last == nullptr) {
        cout << "empty";
    }
    else {
        Ring_element<T>* abc = rg.first;       
        while (abc != rg.last) {
            cout << abc->value << " ";
            abc = abc->next;

        }
        cout << abc->value;
    }
}
template <typename T>
void push_start(Ring_struct<T>& rg, T val) {
    if (rg.first == nullptr) {
        Ring_element<T>* abc = new Ring_element<T>;
        abc->value = val;
        rg.first = abc;
        rg.last = abc;
        abc->next = abc;
        abc->prev = abc;
    }
    else {
        Ring_element<T>* abc = new Ring_element<T>;
        abc->value = val;
        Ring_element<T>* def = rg.first;
       rg.first=abc;
       def->prev = abc;
       abc-> next = def;
       abc->prev = rg.last;
       rg.last->next = abc;
    }
}
template <typename T>
void push_end(Ring_struct<T>& rg, T val) {
    if (rg.last == nullptr) {
        Ring_element<T>* abc = new Ring_element<T>;
        abc->value = val;
        rg.first = abc;
        rg.last = abc;
    }
    else {
        Ring_element<T>* abc = new Ring_element<T>;
        abc->value = val;
        Ring_element<T>* def = rg.last;
        rg.last = abc;
        abc->prev = def;
        abc->next = rg.first;
        def->next = abc;
        rg.first->prev = abc;
    }
}

template <typename T>
T pop_first(Ring_struct<T>& rg) {
    Ring_element<T>* abc = rg.first;  
   Ring_element<T>* rl = rg.first->next;;
   T val = abc->value;   
    rl->prev = rg.last;
    rg.last->next = rl;
    delete abc;
    rg.first = rl;
    return val;
}
template <typename T>
T pop_last(Ring_struct<T>& rg) {
    Ring_element<T>* abc = rg.last;
    Ring_element<T>* rl = rg.last->prev;
    T val = abc->value;
    rl->next = rg.first;
    rg.first->prev = rl;
    delete abc;
    rg.last = rl;
    return val;
}
template <typename T>
int find_pos(Ring_struct<T>& rg, T val) {
    int counter = 0;
    int counter2 = 0;
    Ring_element<T>* abc = rg.first;
    Ring_element<T>* def = rg.first;
    while (def != rg.last) {
        def = def->next;
        counter2++;
    }
    while (abc->value != val) {
        abc = abc->next;
        counter++;
        if (abc->value == val) {
            cout << "element`s pos is " << counter;
            break;
        }

        if ((counter+1) > counter2) {
            cout << "wrong value ";
            break;
        }
    }   
    return counter;
}

template <typename T>
void push_index(Ring_struct<T>& rg, int indx, T val) {
    Ring_element<T>* abc = rg.first;
    int counter = 0;
    while (counter != indx) {
        counter++;
        abc = abc->next;
    }
    Ring_element<T>* def = new Ring_element<T>;
    Ring_element<T>* gh = abc->prev;
    def->value = val;
    def->prev = abc->prev;
    abc->prev = def;
    def->next = abc;
    gh->next = def;
    
}
template <typename T>
T pop_index(Ring_struct<T>& rg, int indx) {
    Ring_element<T>* abc= rg.first;
    int counter = 0;
    while (counter != indx) {
        
           abc =  abc->next;
           counter++;
    } 
    Ring_element<T>* def = abc->prev;
    Ring_element<T>* gh = abc->next;
    def->next = gh;
    gh->prev = def;
    T val = abc->value;
    delete abc;
    return val;
}
template <typename T>
int size(Ring_struct<T>& rg) {
    int counter = 0;
    Ring_element<T>* abc = rg.first;
    if (rg.first == nullptr) {
        cout << "empty";
    }
    else {
        while (abc != rg.last) {
            abc = abc->next;
            counter++;

        }
        cout << "size of this list =  " << counter;
    }
    return counter;
}
template <typename T>
void push_point(Ring_struct<T>& rg, Ring_element<T>* point, T val)
{ 
    Ring_element<T>* new_el = new Ring_element<T>;  
    new_el->value = val;
    Ring_element<T>* abc = rg.first;
    while (abc != point) {
        abc = abc->next;
  }
    Ring_element<T>* def = abc -> next;
    new_el->next = def;
    new_el->prev = abc;
    abc -> next = new_el;
    def->prev = new_el;
}
template <typename T>
T index_value(Ring_struct<T>& rg, int indx) {
    Ring_element<T>* abc = rg.first;
    int counter = 0;
    while (counter != indx) {
        counter++;
        abc = abc->next;
    }
    Ring_element<T>* def = abc;
    cout << " element`s value = " << def->value;
    return def->value;
}
template <typename T>
 T pop_point(Ring_struct<T>& rg, Ring_element<T>* abc) {
    Ring_element<T>* new_el;
    new_el = rg.first;
    while (new_el != abc) {
        new_el = new_el->next;
    }
    T val = abc->value;
    new_el->next ->prev = new_el->prev;
    new_el->prev -> next = new_el->next;
    delete abc;
    return val;
}
 int main() {

     // проверка для int

     Ring_element<int> elem;
     Ring_struct<int> rg;
     int val = 720207;
     int val2 = 18;
     int val3 = 12;
     int indx = 5;
     int indx2 = 7;
     int indx3 = 6;
     constructor(rg);
     push_start(rg,1);
     push_start(rg, 2);
     push_start(rg, 3);
     push_start(rg, 4);
     push_start(rg, 5);
     print(rg);
     cout << endl;
     push_end(rg, 6);
     push_end(rg, 7);
     push_end(rg, 8);
     push_end(rg, 9);
     push_end(rg, 0);
     print(rg);
     cout << endl;
     pop_first(rg);
     print(rg);
     cout << endl;
     pop_last(rg);
     print(rg);
     cout << endl;

     find_pos(rg, val);
     cout << endl;
     print(rg);
     cout << endl;
     push_index(rg, indx, val2);
     print(rg);
     cout << endl;
     pop_index(rg, indx2);
     print(rg);
     cout << endl;
     size(rg);
     cout << endl;
     print(rg);
     cout << endl;
     Ring_element<int>* abc = rg.first->next;
     push_point(rg, abc, val3);
     print(rg);
     cout << endl;
     index_value(rg, indx3);
     cout << endl;
     Ring_element<int>* def = rg.last->prev;
     pop_point(rg, def);
     print(rg);
     cout << endl;
     destructor(rg);
     size(rg);
     cout << endl;
     print(rg);

     cout << endl;

     // проверка для пользовательского типа данных

     GUITAR guitar1, guitar2, guitar3, guitar4, guitar5;

     guitar1.Brand_name = "ESP";
     guitar1.Model_name = "LTD Snakebyte";
     guitar1.Price = 1599;

     guitar2.Brand_name = "Schecter";
     guitar2.Model_name = "Dan Donegan Ultra";
     guitar2.Price = 1200;

     guitar3.Brand_name = "Fender";
     guitar3.Model_name = "Jim Root Telecaster";
     guitar3.Price = 1600;

     guitar4.Brand_name = "PRS";
     guitar4.Model_name = "P245";
     guitar4.Price = 5499;

     guitar5.Brand_name = "USSR";
     guitar5.Model_name = "Handmade piece of shit";
     guitar5.Price = 10;
   

     Ring_struct<GUITAR> rgg;
     constructor(rgg); 
     push_start(rgg,guitar1);
     push_start(rgg, guitar2);
     print(rgg);
     cout  << "--------------";
     push_end(rgg, guitar4);
     print(rgg);
     cout << "--------------";
     index_value(rgg, 2);
     cout << "--------------";
     cout << endl;
     find_pos(rgg,guitar1);
     cout << "--------------" << endl;
     push_index(rgg,2,guitar5);
     print(rgg);
     cout << "--------------";
     pop_first(rgg);
     pop_last(rgg);
     print(rgg);
     cout << "--------------";
     push_end(rgg, guitar3);
     push_start(rgg, guitar1);
     pop_index(rgg,2);
     print(rgg);
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
