#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << fixed << setprecision(2);
    cout << "Arithmetic Mean = " << B[0] << endl;
    cout << "Standard Deviation = " << B[1] << endl;
    cout << "Geometric Mean = " << B[2] << endl;
    cout << "Harmonic Mean = " << B[3] << endl;
    cout << "Max = " << B[4] << endl;
    cout << "Min = " << B[5];
    return 0;
}

void stat(const double num[],int count,double result[]){
    double sum,sd,hm[count],sumhm;
    result[2] = 1.00;
    result[5] += num[0];
    for (int i = 0; i < count; i++){
        sum += num[i];
        result[2] *= num[i];
        hm[i] = 1/num[i];
    }
    result[0] = sum/count;
    result[2] = pow(result[2],(double)1/count);
    for (int i = 0; i < count; i++){
        sd += pow(num[i]-result[0],2);
        sumhm += hm[i];
        if(result[4] < num[i]) result[4] = num[i];
        if(result[5] > num[i]) result[5] = num[i];
    }
    result[1] = sqrt(sd/count);
    result[3] = count/sumhm;
}