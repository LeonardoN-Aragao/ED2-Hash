#include "No.h"
//construtor inicializa os ponteiros com NULL e a variavel com 0

class Lista{

    public:
        No* primeiro;
        No* ultimo;

        Lista(){
            primeiro = NULL;
            ultimo = NULL;
        }

        bool isEmpty(){
            if(!primeiro)
                return true;
            else 
                return false;
        }

        No* insereNo (int value) {

            No* p = new No();
            p->value = value;
            std::cout<<p->value<<std::endl;


            if (!primeiro) {
                primeiro = p;
                ultimo =  primeiro;
            }
            else{
                ultimo->proximo = p;
                ultimo = p;
            }
            return p;
        } 

        No* buscaNo(int info) {
        
            No * p = primeiro;
            
            while(p != NULL) {       
                if(p->value == info)
                    return p;
                p = p->proximo;
            }
            return NULL;
        }

        void print (){
            No * p = primeiro;

            while(p!= NULL){
                std::cout<<p->value<<" ";
                p = p->proximo;
            }
        }

        ~Lista(){
            No * p = primeiro;
            while(p!= NULL){
                No * t = p;
                p = p->proximo;
                delete t;
            }
        }
};