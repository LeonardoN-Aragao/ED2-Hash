#include "Lista.h"
#include <vector>

using namespace std;

typedef int (func)(int key,int tam); 

class Hash{

    public:
        int tam;
        vector<Lista*> table;
        func * func_hash;

        Hash(){};

        //m tamanho
        //hash func hash
        void create(int m,func *hash){
            tam = m;
            table.clear();

            table.resize(tam);
            for(int i = 0; i < tam;i++){
                table[i] = new Lista();
            }
            func_hash = hash;
        }
        //Pesquisa se data com chave key está na tabela. Se estiver, retorna ponteiro para data, caso contrário retorne NULL.

        No* lookup(int key,int data){
            if(table.empty())
                return NULL;

            for (int i = 0; i< tam; i++){
                No* p = table[func_hash(key,tam)]->buscaNo(data);
                if(!p){
                    return NULL;
                }
                return p;
            }      
            return NULL; 
        }
        
        // Insere data com chave key na tabela. A função deve retornar um 
        // ponteiro para o elemento inserido. Se data  já existir, retorna-se um ponteiro para ele. 
        
        No* insert(int key,int data){
            No* p = lookup(key,data);

            if(!p){
                p = table[func_hash(key,tam)]->insereNo(data);
                tam ++;
            }
            return p;
        }

        void print(){  

            if(table.empty()){
                cout<<"Tá vazia!"<<endl;
                return;
            }
            
            
            for(int i = 0; i < tam;i++){
                if(!table[i]->isEmpty()){
                    table[i]->print();
                    cout<<endl;
                }
            }


        }
        
        void destroy(){
            table.clear();
        }  
};

