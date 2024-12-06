#pragma once
#include <iostream>
#include <vector>


using namespace std;

template <typename T>
struct stats {
    size_t comparison_count = 0;
    size_t copy_count = 0;

    stats() = default;
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
