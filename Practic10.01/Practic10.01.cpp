#include <iostream>

using namespace std;

const int SIZE = 10;
int pancakes[SIZE] = { 12,11,10,9,8,7,6,4,5,3 }; // массив оладий

int maxPancake, max_index = 0;
int temp;
int counter = 0; // кол-во переворачиваний стопки

void findMaxPancake(int i); // поиск максимального размера оладушка и его индекса
void reversePancake();
void maxPanacakeUp(int i);


int main()
{
    // прохродим по всем оладям в массиве
    for (int i = 0; i < SIZE; i++) {

        findMaxPancake(i);

        if (pancakes[i] == maxPancake && i >= max_index) continue;
        else {
            reversePancake();
            maxPanacakeUp(i);
            

            for (int j = 0; j < SIZE; j++) {
                cout << pancakes[j] << " ";
            }
            cout << endl;
        }
    }
    cout << endl << counter;
}

void findMaxPancake(int i) {
    maxPancake = pancakes[i];
    for (int j = i; j < SIZE; j++) {
        if (maxPancake < pancakes[j]) {
            maxPancake = pancakes[j];
            max_index = j;
        }
    }
}

void reversePancake(){
    for (int i = max_index, j = SIZE - 1; i < j; i++, j--) {
        temp = pancakes[i];
        pancakes[i] = pancakes[j];
        pancakes[j] = temp;
    }
}
void maxPanacakeUp(int i){
    for (int h = i, j = SIZE - 1; h < j; h++, j--) {
        temp = pancakes[h];
        pancakes[h] = pancakes[j];
        pancakes[j] = temp;
    }
    if (i != SIZE - 1) counter++;
}