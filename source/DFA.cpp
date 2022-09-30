#include "DFA.h"

#include <assert.h>

staller::DFA_State_Bitmap::DFA_State_Bitmap(size_t length): length_(length){
    bitmap_.resize(BoundUpTo8(length_) / 8, 0);
}

void staller::DFA_State_Bitmap::SetBit(size_t index){
    assert(index<length_);
    bitmap_[index / 8] |= (1 << (index % 8));
}

bool staller::DFA_State_Bitmap::operator==(const DFA_State_Bitmap& set){
    if(length_ != set.length_){ return false; }
    for(size_t i = 0; i < length_; ++i){ if(bitmap_[i] != set.bitmap_[i]){ return false; } }
    return true;
}
