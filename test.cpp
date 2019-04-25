#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "my_lib.cpp"

using namespace std;

int main(int argc, char** argv) {
        int d[50]={1,6,2,3,5,4,2,5,8,2,
         6,0,2,5,7,4,4,2,5,4,
         6,2,5,4,5,6,1,2,0,2,
         5,4,12,5,1,2,1,2,4,5,
         3,5};
         int n = 42;

         int p[50]={1,2,3,1,2,3,1,2,3,1,
         2,3,1,2,3,1,2,3,1,2,
         3,1,2,3,1,2,3,1,2,3,
         1,2,3,1,2,3,1,2,3,1,
         2,3};
         int l[10]={1,2,3,4,5,6};
         int nl = 6;

         int fr[10],nf;

         cout.precision(5);
         cout<<fixed;

         double medA = mean(d,n);
         cout << "Media aritmetica: "<<setw(15)<<medA<<endl;

         double medAP = weighted_mean(d,p,n);
         cout << "Media aritmetica ponderada: "<<setw(15)<<medAP<<endl;

         int medi = median(d,n);
         cout << "Mediana: "<<setw(15)<<medi<<endl;

         double desvEst = standard_deviation(d,n);
         cout << "Desviacion estandar: "<<setw(15)<<desvEst<<endl;

         distribution(d, n, l, nl, fr, nf);
         cout << "Distribucion de frecuencias: "<<endl;

         for(int f=0; f<nf-1; f++){
                 if(f==0)cout<<"< "<<setw(2)<<l[f]<<" : "<<setw(4)<<fr[f]<<endl;
                 else cout<<" "<<setw(2)<<l[f-1]+1<<" : "<<setw(4)<<fr[f]<<endl;
         }
         cout<<" >"<<setw(2)<<l[nl-1]<<" : "<<setw(4)<<fr[nf-1]<<endl;

         mergeSort(d, 0, n-1);
         for (int i = 0; i < n; i++) {
                 cout << d[i] << " ";
         }
         cout << endl;
         return 0;
}
