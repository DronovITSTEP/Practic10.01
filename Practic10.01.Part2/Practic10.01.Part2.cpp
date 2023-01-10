#include <iostream>

using namespace std;

void hello();
void goobye();

//void add(int, int);
int add(int, int);
//void subract(int, int);
int subract(int, int);
//void multiply(int, int);
int multiply(int, int);

int operation(int(*)(int, int), int, int);

int isEven(int);
int isPositive(int);
void action(int(*)(int), int[], int);

void goodmorning();
void gooevening();
void(*message(int))();

int(*select())(int, int);

int main()
{
    //тип(*имя_указателя)(парметры);
    /*void (*message)();
    message = hello;
    message();
    message = goobye;
    message();*/

    /*int a = 10, b = 5, result;
    int (*operation)(int a, int b);
    operation = add;
    result = operation(a, b);
    cout << "Result a + b = " << result << endl;

    operation = subract;
    result = operation(a, b);
    cout << "Result a - b = " << result << endl;*/

    //тип(*имя_указателя[размер])(параметры);
    /*int a = 10, b = 5;
    void (*operation[3])(int, int) = { add, subract, multiply };

    int length = sizeof(operation) / sizeof(operation[0]);
    for (int i = 0; i < length; i++) {
        operation[i](a, b);
    }*/

    //указатель на функцию в параметрах функции
    /*int a = 10, b = 5, result;
    result = operation(add, a, b);
    cout << "Result a + b = " << result << endl;

    result = operation(subract, a, b);
    cout << "Result a - b = " << result << endl;*/

    /*const int SIZE = 8;
    int nums[SIZE] = { 5,-6,-7,3,4,6,-9,1};
    cout << "Even numbers: " << endl;
    action(isEven, nums, SIZE);
    cout << "Positive numbers:" << endl;
    action(isPositive, nums, SIZE);*/

    /*void(*action)();
    action = message(10);
    action();*/

    int x = 8, y = 5;
    cout << "x = " << x << ", y = " << y << endl;
    cout << "1: Add\n"
        << "2: Subrtract\n"
        << "3: Multiply\n"
        << "4: Exit\n\n";

    int (*action)(int, int);
    int result;
    while (1) {
        action = select();
        if (action == NULL) break;
        result = action(x, y);
        cout << "Result = " << result << endl;
    }
    cout << "End" << endl;
}

void hello() { cout << "Hello" << endl; }
void goobye() { cout << "Goodbye" << endl; }

int add(int x, int y){
    //cout << "Result a + b = " << x + y << endl;
    return x + y;
}
int subract(int x, int y){
    //cout << "Result a - b = " << x - y << endl;
    return x - y;
}
int multiply(int x, int y) {
    //cout << "Result a * b = " << x * y << endl;
    return x * y;
}

int operation(int(*op)(int, int), int a, int b) {
    return op(a, b);
}

int isEven(int x){
    return x % 2 == 0;
}
int isPositive(int x){
    return x > 0;
}
void action(int(*condition)(int), int numbers[], int n){
    for (int i = 0; i < n; i++) {
        if (condition(numbers[i]) != 0) cout << numbers[i] << " ";
    }
    cout << endl;
}


void goodmorning() {
    cout << "Good morning" << endl;
}
void gooevening() {
    cout << "Good evening" << endl;
}
void(*message(int hour))() {
    if (hour > 12) return gooevening;
    else return goodmorning;
}


int(*select())(int, int) {
    int choice;
    int(*actions[])(int x, int y) = { add, subract, multiply };

    cout << "Enter action (1,2,3,4): ";
    cin >> choice;
    if (choice > 0 && choice < 4) return actions[choice - 1];
    else return NULL;
}