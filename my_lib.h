#ifndef MY_LIB_H
#define MY_LIB_H

template <typename TIPO>
void mergeSort(TIPO*, int, int);

template <typename TIPO>
void merge(TIPO*, int, int, int);

template <typename TIPO>
double mean(TIPO*, int);

template <typename TIPO>
double weighted_mean(TIPO*, TIPO*, int);

template <typename TIPO>
TIPO median(TIPO*, int);

template <typename TIPO>
double standard_deviation(TIPO*, int);

template <typename TIPO>
void distribution(TIPO*, int, TIPO*, int, int*, int&);

#endif /* MY_LIB_H */
