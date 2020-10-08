#include <iostream>

class No{

    public:
        No * proximo;
        int value;

        No(){
            proximo = NULL;
            value = 0;
        }

        ~No(){};
};