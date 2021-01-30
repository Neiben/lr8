// lr8_2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
using namespace std;
struct Metallica_bassists {
	string name;
	int duration;
	void operator=(int a) {
		duration = a;
		name = a;
	}
	
};

ostream& operator << (ostream& out, const Metallica_bassists& mb)
{
	out << " name of the basiist is " << mb.name << endl;
	out << " was band`s member for " << mb.duration << " year(s)" << endl;
	return out;
}

bool operator==(const Metallica_bassists& left, const Metallica_bassists& right) {
	return ((left.duration == right.duration) && (left.name== right.name));
}

template<typename T, int size>
struct list_arr {
	T value[size];
	int true_size ;
};

template <typename T, int size>
void constructor(list_arr<T, size>& LA) {
	LA.true_size = 0;
	
	for (int i = 0; i < size; ++i)
	{
		LA.value[i] = 0;
		
	}
}
template <typename T, int size>
void print(list_arr<T, size>& LA) {
	if (LA.true_size == 0) {
		cout << "List is empty " << endl;
	}
	else {
		for (int i = 0; i < LA.true_size; i++) {
			cout << LA.value[i] << " ";
		}
		cout << endl;
	}
}

template <typename T, int size>
void push_end(list_arr<T, size>& LA, T val) {
	
		if (LA.true_size >= size) {
			cout << " List is full ";
		}
		else {
			LA.value[LA.true_size] = val;
			LA.true_size++;
		}
	
}

template<typename T , int size>
void push_index(list_arr<T, size>& LA, T val, int indx)
{
	if ((LA.true_size >= size) && (indx > size)) {
		cout << " unvaliable operation " << endl;
	}
	else {
		for (int i = LA.true_size; i > indx; i--) {
			LA.value[i] = LA.value[i-1];	
				
	   }
		LA.value[indx] = val;
		LA.true_size++;
	}
}
template<typename T , int size>
void pop_first(list_arr<T, size>& LA ) {
	for (int i = 0; i < LA.true_size; i++) {
		LA.value[i] = LA.value[i + 1];
	}
	LA.true_size--;
}
template <typename T, int size>
void pop_last(list_arr<T, size>& LA) {
	for (int i = 0; i > LA.true_size; i++ ) {
		LA.value[i] = LA.value[i - 1];
	}
	LA.true_size--;
}
template <typename T, int size>
void pop_index(list_arr<T, size>& LA, int indx) {
	if (indx <= size) {
		for (int i = indx; i < LA.true_size; i++) {
			LA.value[i] = LA.value[i+1];
		}
		LA.true_size--;
	}
	else {
		cout << " unvaliable operation " << endl;
	}
}
 template <typename T, int size>
 void size_l(list_arr<T, size>& LA) {
	 int counter = 0;
	 for (int i = 0; i < LA.true_size; i++) {
		 counter++;
	 }
	 cout << counter;
 }
template <typename T , int size>
void find_pos(list_arr<T, size>& LA, T val) {
	int counter = 0;
	for (int i = 0; i < LA.true_size; i++) {
		if (LA.value[i] == val) {
			counter = i;			
		}		
	}
	cout << counter;
}

template <typename T, int size>
void get_value(list_arr<T, size>& LA, int indx) {
	if (indx <= LA.true_size) {
		cout << LA.value[indx] << endl;
	}	
	else {
		cout << " unvaliable operation ";
	}
}


template<typename T, int size>
void destructor(list_arr<T, size>& LA) {
	for (int i = 0; i < LA.true_size; i++) {
		LA.true_size--;
	}
	LA.true_size--;
}
int main() {

	// проверка для стандартного типа данных
	list_arr<int, 7> LA;
	constructor(LA);
	push_end(LA, 5);
	push_end(LA, 9);
	push_end(LA, 2);
	push_end(LA, 8);
	push_end(LA, 65);
	get_value(LA,3);
	push_index(LA, 10, 2);
	print(LA);
	pop_first(LA);
	cout << endl;
	print(LA);
	cout << endl;
	pop_last(LA);
	print(LA);
	cout << endl;
	pop_index(LA, 3);
	print(LA);
	cout << endl;
	find_pos(LA, 10);
	cout << endl;
	size_l (LA);
	cout << endl;
	destructor(LA);
	print(LA);
	

	// проверка для пользовательского типа данных

	Metallica_bassists mb1, mb2, mb3, mb4;
	mb1.name = " Ron McGovney";
	mb1.duration = 1;
	mb2.name = " Cliff Burton";
	mb2.duration = 4;
	mb3.name = "Jason Newsted";
	mb3.duration = 15;
	mb4.name = " Roberto Trujillo";
	mb4.duration = 18;

	list_arr<Metallica_bassists, 4> mb;
	constructor(mb);
	push_end(mb, mb1);
	push_end(mb,mb2);
	print(mb); 
	cout << "--------------" << endl;
	push_index(mb, mb3, 2);
	print(mb);
	pop_first(mb);
	pop_last(mb);
	cout << "--------------" << endl;
	print(mb);
	push_end(mb, mb1);
	push_end(mb, mb4);
	push_end(mb, mb3);
	pop_index(mb,5);
	find_pos(mb, mb2);
	cout << endl;
	print(mb);
	cout << endl;
	get_value(mb, 3);



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
