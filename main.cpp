#include <iostream>
#include <math.h>
#include "Hash.h"

using namespace std;
#include <stdio.h>

int divisao(int key,int tam){ 
    return key%tam;
} 

int multiplicacao(int key, int tam){
    int a  = (sqrt(5) - 1) / 2;
    return floor(tam*((key*a) % 1));
}

int minhaHash(int key,int tam){return (key * 2 )% tam;}

int main (){

    clock_t inicio, fim;
    inicio = clock();
    srand(time(NULL)*clock());

    Hash a;
    int tam = 20;
    a.create(tam, divisao);

    //TESTE HASH
    /*
    for(int i= 0; i<tam; i++){
        cout<<divisao(rand()%100,tam)<<endl;
    }
    */
    
    for(int i= 0; i<tam; i++){
        int b = rand()%100;
        int c = rand()%100;
        cout<<b << " "<< c<<endl;

        a.insert(b,c);
    }
    a.print();
    a.destroy();
    cout<<"teste"<<endl;

    fim = clock();
    cout<<"Tempo total: "<<(fim - inicio) / CLOCKS_PER_SEC;
    
    //a.create(tam, multiplicacao);
    //a.create(tam, minhaHash);
}