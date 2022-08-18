#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

using namespace std;

int binarioInverso(int n);
vector<int> binarioInv(int n);
vector<int> decimal_a_binario(int n);
vector<int> invertir(vector<int> v, int hi, int lo);
vector <int> binario_a_decimal(vector<int> v);
vector<int>analisisExperimental();
void binarioInver(int n);

int main() {

  vector<int> v;
  random_device rd; // obtener un numero al azar del hardware
  mt19937 gen(rd()); // semilla para el generador
  uniform_int_distribution<> distr(25, 200); // definir el rango

  //Analisis Experimental con algoritmo Iterativo

  for(int n=0; n<10;n++){
    cout <<"Numero decimal aleatorio:"<<distr(gen)<<endl; 
    int dec = binarioInverso(distr(gen));
    cout<<"Binario inverso a decimal: "<<dec<<endl<<endl;
    
  }

}


int binarioInverso(int n){

  vector<int> v;
  int i = 0;

  while(n>=1){
    
    if(n%2==0){
      v.insert(v.end(),0);
    }else{
      v.insert(v.end(),1);
    }
    
    n=n/2;
    cout<<v[i]<<endl;
    i++;
    
  }
  int decimal = 0;
  for(int i = 0 ; i < v.size() ; i++){
    
    decimal = (decimal << 1) + v[i];
  }
  
  return decimal;
  
}





 



