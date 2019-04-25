#include "my_lib.h"
#include <cmath>

template <typename TIPO>
void mergeSort(TIPO* arr, int l, int r)
{
    if (l < r)
    {
        int m = l+(r-l)/2;

        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);

        merge(arr, l, m, r);
    }
}

template <typename TIPO>
void merge(TIPO* arr, int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

template <typename TIPO>
double mean(TIPO* data, int size) {
        TIPO sum = 0;
        for (int i = 0; i < size; i++)
                sum += data[i];
        return (double)sum/size;
}

template <typename TIPO>
double weighted_mean(TIPO* data, TIPO* weights, int size) {
        TIPO sum = 0;
        TIPO weights_sum = 0;
        for (int i = 0; i < size; i++) {
                sum += data[i]*weights[i];
                weights_sum += weights[i];
        }
        return (double)sum/weights_sum;
}

template <typename TIPO>
TIPO median(TIPO* data, int size) {
        TIPO aux[size];
        for (int i = 0; i < size; i++)
                aux[i] = data[i];
        mergeSort(aux, 0, size-1);
        return aux[size/2];
}

template <typename TIPO>
double standard_deviation(TIPO* data, int size) {
        TIPO data_mean = mean(data, size);
        TIPO sum = 0;
        for (int i = 0; i < size; i++)
                sum += pow(data[i] - data_mean, 2.0);
        return sqrt(sum/(size-1));
}

template <typename TIPO>
void distribution(TIPO* data, int data_size, TIPO* limits, int limits_size, int* frequency, int& frequency_size) {
        frequency_size = limits_size + 1;
        for (int i = 0; i < frequency_size; i++)
                frequency[i] = 0;

        for (int d_index = 0; d_index < data_size; d_index++) {
                for (int f_index = 0; f_index < frequency_size; f_index++) {
                        if ( (f_index == 0 && data[d_index] <= limits[f_index]) ||
                        (f_index==frequency_size-1 && data[d_index]>limits[f_index-1]) ||
                        (f_index > 0 && data[d_index] > limits[f_index-1] && data[d_index] <= limits[f_index] ) ) {
                                 frequency[f_index]++;
                                 break;
                         }
                }
        }
}

template void distribution(double*, int, double*, int, int*, int&);
template void distribution(int*, int, int*, int, int*, int&);

template double mean(double*, int);
template double mean(int*, int);

template double weighted_mean(double*, double*, int);
template double weighted_mean(int*, int*, int);

template void merge(double*, int, int, int);
template void merge(int*, int, int, int);

template void mergeSort(double*, int, int);
template void mergeSort(int*, int, int);

template double median(double*, int);
template int median(int*, int);

template double standard_deviation(int*, int);
template double standard_deviation(double*, int);
