#include <bits/stdc++.h>
#include <string.h>
using namespace std;
 
// Decimal to binary conversion
// using recursion
string reverseDivide(string str){
        if(str.length()<=1)
            return str;
         
        else{
        return  reverseDivide(str.substr(str.length()/2,str.length()))+
          reverseDivide(str.substr(0,str.length()/2));
             
        }
         
         
    }
 
// Driver code
int findBinary(int decimal_number)
{
    if (decimal_number == 0)
        return 0;
    else
        return (decimal_number % 2 + 10 *
                findBinary(decimal_number / 2));
}
int bintoDecimal(char binary[],int len, int i=0){
   if (i == len-1)
   return (binary[i] - '0');

   int temp=binary[i]-'0';
   temp=temp<<len-i-1;
   temp=temp+bintoDecimal(binary,len,i+1);
   return (temp);
}
int main()
{
  int a;
  cout<<"Introduzca el numero al que desea encontrar el binario inverso: ";
  cin>>a;
  string str=std::to_string(findBinary(a));
  string str2=reverseDivide(str);
   cout<<"el numero binario inverso es:"+str2<<endl;
    char char_array[str2.length() + 1];
    strcpy(char_array, str2.c_str());
    cout<<"el numero decimal del binario inverso es:";cout<<bintoDecimal(char_array,str2.length());
}
