#include "NFA.h"

staller::NFA staller::NFAContext::ConcatNFA(NFA&& a, NFA&& b){
    a.end_->is_end_ = false;
    b.end_->is_end_ = true;
    EpLinkNode(a.end_, b.start_);

    NFA ret{};
    ret.start_ = a.start_;
    ret.end_   = b.end_;

    a.Clear();
    b.Clear();
    return ret;
}

staller::NFA staller::NFAContext::UnionNFA(NFA&& a, NFA&& b){
    NFANode* start_node = CreateNode();
    NFANode* end_node   = CreateNode();

    EpLinkNode(start_node, a.start_);
    EpLinkNode(start_node, b.start_);
    EpLinkNode(a.end_, end_node);
    EpLinkNode(b.end_, end_node);

    a.end_->is_end_   = false;
    b.end_->is_end_   = false;
    end_node->is_end_ = true;

    NFA ret{};
    ret.start_ = start_node;
    ret.end_   = end_node;

    a.Clear();
    b.Clear();
    return ret;
}

staller::NFA staller::NFAContext::K_ClosureNFA(NFA&& a){
    NFANode* start_node = CreateNode();
    NFANode* end_node   = CreateNode();

    EpLinkNode(start_node, a.start_);
    EpLinkNode(a.end_, end_node);
    EpLinkNode(a.end_, a.start_);
    EpLinkNode(start_node, end_node);

    a.end_->is_end_   = false;
    end_node->is_end_ = true;

    NFA ret{};
    ret.start_ = start_node;
    ret.end_   = end_node;

    a.Clear();
    return ret;
}

staller::NFA staller::NFAContext::CreateNFA(char element){
    NFA ret{};
    ret.start_ = CreateNode();
    ret.end_   = CreateNode();
    LinkNode(ret.start_, ret.end_, element);
    char_set_[element]=true;
    return ret;
}

void staller::NFAContext::LinkNode(NFANode* a, NFANode* b, char element){ a->edges_[element] = b; }

void staller::NFAContext::EpLinkNode(NFANode* a, NFANode* b){ a->ep_edges_.push_back(std::make_pair(EPSILON, b)); }

staller::NFANode* staller::NFAContext::CreateNode(){
    auto node = new NFANode();
    idx2node_.push_back(node);
    node2idx_[node] = idx2node_.size() - 1;
    return node;
}
