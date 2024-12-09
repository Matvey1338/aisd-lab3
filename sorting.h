#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <ctime>


using namespace std;

template <typename T>
struct stats {
    size_t comparison_count = 0;
    size_t copy_count = 0;

    stats() = default;

    stats& operator+=(const stats a) {
        this->comparison_count += a.comparison_count;
        this->copy_count += a.copy_count;
        return *this;
    }
};

template <typename T>
stats<T> BublleSort(vector<T>& vector) {
    stats<T> res{};
    size_t size = vector.size();

    for (int j = 1; j < size; j++) {
        bool issorted = true;
        for (int i = 0; i < size - j; i++) {
            res.comparison_count++;
            if (vector[i] > vector[i + 1]) {
                swap(vector[i], vector[i + 1]);
                res.copy_count += 3;
                issorted = false;
            }
        }
        if (issorted) {
            break;
        }
    }

    return res;
}


template <typename T>
stats<T> CombSort(vector<T>& vector) {
    stats<T> res{};
    int step = vector.size() - 1;
    bool flag = false;

    while (step > 1 or flag) {
        if (step > 1) {
            step = step * 4 / 5;
        }
        flag = false;
        int i = 0;
        while (i + step < vector.size()) {
            res.comparison_count++;
            if (vector[i] > vector[i + step]) {
                flag = true;
                swap(vector[i], vector[i + step]);
                res.copy_count += 3;
            }
            i += step;
        }
    }

    return res;
}

template <typename T>
stats<T> heapify(vector<T>& arr, int n, int i) {
    int largest = i;          // Инициализируем корень как самый большой
    int left = 2 * i + 1;     // Левый дочерний элемент
    int right = 2 * i + 2;    // Правый дочерний элемент
    stats<T> res{};

    // Если левый дочерний элемент больше корня
    res.comparison_count++;
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
        res.copy_count++;
    }

    // Если правый дочерний элемент больше самого большого элемента
    res.comparison_count++;
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
        res.copy_count++;
    }
    // Если самый большой элемент не корень
    res.comparison_count++;
    if (largest != i) {
        swap(arr[i], arr[largest]); // Меняем местами
        res.copy_count += 3;

        // Рекурсивно преобразуем поддерево в кучу
        res = heapify(arr, n, largest);
    }
    
    return res;
}

// Основная функция пирамидальной сортировки
template <typename T>
stats<T> heapSort(vector<T>& arr) {
    int n = arr.size();
    stats<T> res{};
    stats<T> merge_res{};

    // Построение кучи (перестройка массива)
    for (int i = n / 2 - 1; i >= 0; i--) {
        merge_res = heapify(arr, n, i);
        res += merge_res;

    }

    // Один за другим извлекаем элементы из кучи
    for (int i = n - 1; i > 0; i--) {
        // Перемещаем текущий корень в конец
        swap(arr[0], arr[i]);
        res.copy_count += 3;


        // Вызываем heapify на уменьшенной куче
        merge_res = heapify(arr, i, 0);
        res += merge_res;
    }

    return res;
}

void printArray(const vector<int>& arr) {
    for (int val : arr)
        cout << val << " ";
    cout << endl;
}

void generator(std::vector<int>& arr, size_t size, unsigned int seed)
{
    std::srand(seed);
    for (size_t i = 0; i < size; ++i) {
        arr[i] = rand() % 100000;
    }
}

void generateSortedArray(std::vector<int>& arr, size_t size)
{
    for (size_t i = 0; i < size; ++i) {
        arr[i] = i;
    }
}

void generateReverseSortedArray(std::vector<int>& arr, size_t size)
{
    for (size_t i = 0; i < size; ++i) {
        arr[i] = size - i - 1;
    }
}