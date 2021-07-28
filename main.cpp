#include <iostream>
#include <math.h>
#include <fstream>

using namespace std;
int main()
{setlocale (LC_ALL, "RUS");
int n=4;
double* a = new double[n];
double* b = new double[n];
double* c = new double[n-1];
double* d = new double[n];
double* P = new double[n];
double* Q = new double[n];
double* x = new double[n];
ifstream fin;
    fin.open("matr.txt");

for(int j=0;j<n-1;j++){
            fin >> c[j];
        }
for(int j=0;j<n;j++){
            fin >> b[j];
        }
for(int j=1;j<n;j++){
            fin >> a[j];
        }
for(int j=0;j<n;j++){
            fin >> d[j];
        }
fin.close();

for(int i =0;i<n;i++) b[i]=-b[i];

P[0]=c[0]/b[0];
Q[0]=-d[0]/b[0];

for(int i=1;i<n-1;i++){
    P[i]=c[i]/(-a[i]*P[i-1]+b[i]);
    Q[i]=(-d[i]+a[i]*Q[i-1])/(-a[i]*P[i-1]+b[i]);

}


    x[n-1]=(d[n-1]-Q[n-2]*a[n-1])/(-b[n-1]+P[n-2]*a[n-1]);


for(int i=n-2;i>=0;i--){
    x[i]=P[i]*x[i+1]+Q[i];

}

ofstream fout("vivod.txt");
for (int i=0;i<n-1;i++){
            cout <<"P["<<i<<"]= "<<P[i] <<" ";
    }
     cout<<endl;

    for (int i=0;i<n-1;i++){
            cout <<"Q["<<i<<"]= "<< Q[i] <<" ";

    }

    cout<<endl;

    for (int i=0;i<n;i++){
            cout <<"x["<<i<<"]= "<< x[i]<<" "<<endl;
    }
    for (int i=0;i<n;i++){
            fout <<"x["<<i<<"]= "<< x[i]<<" "<<endl;
    }

    cout<<"Точное значение x[0] = 0.871 x[1] = -2.353 x[2] = 2.792 x[3] = 0.133"<<endl;
    fout<<"Точное значение x[0] = 0.871 x[1] = -2.353 x[2] = 2.792 x[3] = 0.133"<<endl;

    return 0;
}
