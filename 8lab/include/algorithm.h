#pragma once
#include "../include/exceptions.h"
#include "../include/ring.h"

template <typename T>
class Algorithm {
   public:
    bool find(const Ring<T>& ring, const T& value) const;
    void sort(Ring<T>& ring) const;
};

template <typename T>
void Algorithm<T>::sort(Ring<T>& ring) const {
    if (ring.empty()) return;
    ring.sort();
}

template <typename T>
bool Algorithm<T>::find(const Ring<T>& ring, const T& value) const {
    if (ring.empty()) return false;

    typename Ring<T>::Iterator it = ring.begin();
    for (size_t i = 0; i < ring.getSize(); i++) {
        if (*it == value) return true;
        it++;
    }
    return false;
}