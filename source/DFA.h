#pragma once
#include "NFA.h"

namespace staller{

    class DFA_State_Bitmap{
    public:
        using byte = unsigned char;

        DFA_State_Bitmap(size_t length);

        void SetBit(size_t index);

        bool operator==(const DFA_State_Bitmap& set);

    private:
        inline size_t BoundUpTo8(size_t length){ return length % 8 == 0 ? length : length + (8 - length % 8); }

        size_t length_;

        std::vector<byte> bitmap_;
    };

    struct DFANode{
        inline DFANode(DFA_State_Bitmap&& bitmap): bitmap_(bitmap){}

        using Edges = std::map<char, NFANode*>;

        DFA_State_Bitmap bitmap_;

        Edges edges_;
    };

    /*class DFA{
    public:
        DFA(NFAContext& context): context_(context){
            DFA_State_Bitmap bitmap(context.idx2node_.size());
            size_t           first_index = context.node2idx_[context.nfa_->start_];
            bitmap.SetBit(first_index);
            nodes_.push_back(new DFANode(std::move(bitmap)));
            size_t current_idx = 0;

            while(){ for(size_t i = 0; i < context.char_set_.size(); ++i){ } }

        }

    private:
        std::vector<NFANode*> CreateClosure(const DFANode& dfa_node){ }

        NFAContext& context_;

        std::vector<DFANode*> nodes_;
    };*/

}
