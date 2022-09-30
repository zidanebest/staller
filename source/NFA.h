#pragma once
#include <map>
#include <vector>


#define EPSILON 0x80

namespace staller{
    class DFA;

    struct NFANode{
        using Edges = std::map<char, NFANode*>;
        using EpEdges = std::vector<std::pair<char, NFANode*>>;

        bool is_end_ = false;

        Edges edges_;

        EpEdges ep_edges_;
    };

    struct NFA{
        NFANode *start_, *end_;

        void Clear(){
            start_ = nullptr;
            end_   = nullptr;
        }
    };

    class NFAContext{
    public:
        NFAContext(){ }

        ~NFAContext(){ delete nfa_; }

    public:
        NFA ConcatNFA(NFA&& a, NFA&& b);

        NFA UnionNFA(NFA&& a, NFA&& b);

        NFA K_ClosureNFA(NFA&& a);

        NFA CreateNFA(char element);

    private:
        void LinkNode(NFANode* a, NFANode* b, char element);

        void EpLinkNode(NFANode* a, NFANode* b);

        friend DFA;

        NFA* nfa_;

        std::vector<NFANode*> idx2node_;

        std::map<NFANode*, size_t> node2idx_;

        std::map<char,bool> char_set_;

        NFANode* CreateNode();
    };
}
