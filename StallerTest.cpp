#include <iostream>

#include "DFA.h"
#include "EntryPoint.h"
using namespace staller;

#pragma 

int main(int argc, char* argv[]){
    
    /*auto nfa=ConcatNFA(
        UnionNFA(
            CreateNFA('a'),
            CreateNFA('b')
            ),
            K_ClosureNFA(
                UnionNFA(
                    CreateNFA('a'),
                    CreateNFA('b'))
                )
                ); */

    NFAContext context;
    context.ConcatNFA(context.CreateNFA('a'),context.CreateNFA('b'));
    
    
    return 0;
}
