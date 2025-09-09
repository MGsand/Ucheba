#include<stdlib.h>
#include<iostream>
#include<math.h>
#include <limits>

#define MAX_MASSIV 20

using namespace std;

int bin_length = 0;

void binary (int x, int bin_pow[]){
    int last_bit;
    int i = 0;
    cout<<"Binary form is:"<<endl;
    
    //for (i = 0; i < MAX_MASSIV; i++ ){
      //  cout<<" " << bin_pow[i];     
    //}
    
    i = 0;
    while (x!=0) {
        last_bit=x&1;
        bin_pow[i] = last_bit;      
        x=x>>1;
        i++;
    }
    
    bin_length = i;
    
}

int fast_power (int num, int bin_pow[], int last){
    int y = 1, s = num; 
    
    for (int i = 0; i < bin_length; i++){
        if(bin_pow[i] == 1){
            y = y * s % last;
            s = s * s % last;
        }    
    }
    return y;
}

void my_gcd(int a, int b){
    int* U = new int[3];
    int V[3];
    if(a >= b){
        U[0] = a; U[1] = 1; U[2] = 0;
        V[0] = b; V[1] = 0; V[2] = 1;
    }
    else{ 
        U[0] = b; U[1] = 0; U[2] = 1;
        V[0] = a; V[1] = 1; V[2] = 0;
    }
    
    while(V[0] != 0){
        int q = U[0] / V[0];
        int T[3] = {U[0] % V[0], U[1] - q*V[1], U[2] - q*V[2] };
        U[0] = V[0];
        U[1] = V[1];
        U[2] = V[2];
        
        V[0] = T[0];
        V[1] = T[1];
        V[2] = T[2];
        
       
    }
    cout << "\n";
    for(int i = 0; i < 3; i++)
        cout<< "output " << U[i];
    
    cout << endl;
} 

long long modul(long long base, long long exponent, long long mod)
{
    long long x = 1;
    long long y = base;
    while (exponent > 0)
    {
        if (exponent % 2 == 1)
            x = (x * y) % mod;
        y = (y * y) % mod;
        exponent = exponent / 2;
    }
    return x % mod;
}

bool test_Ferma(long long p)
{
    if (p == 1)
    {
        return false;
    }
    for (int i = 0; i < 50; i++)
    {
        long long a = rand() % (p - 1) + 1; 
        if (modul(a, p - 1, p) != 1)
        { 
            return false;
        }
    }
    return true;
}



int main()
{
    
    int num, power, last;
    int i;
    //int *gcd_result;
    cin >> num >> power >> last;
    

    
    int bin_pow[MAX_MASSIV] = { 0 } ;
  
    binary(power, bin_pow);
    
    for (i = 0; i < MAX_MASSIV; i++ )
    cout<<" " << bin_pow[i]; 
 
    int f_result = fast_power(num, bin_pow, last);
    
    cout<<"y= " << f_result << endl;
    
    int a, b;
    
    cin >> a >> b;
    
    my_gcd(a, b);
    
    long long isPrime;
    cin >> isPrime;
    
    if (test_Ferma(isPrime))
        cout << isPrime<< " is prime" << endl;
    else
        cout << isPrime<< " is not prime" << endl;
    
    return 0;
}