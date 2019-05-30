#ifndef __MSMVIEW_H__
#define __MSMVIEW_H__

#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>
#include <deque>
#include <set>

template<class T>
class multisets_merge_view{
	
	
	typename std::multiset<T> a;
	typename std::multiset<T> b;
	typename std::multiset<T> *p;
	typename std::multiset<T> *q;
	
public:

	multisets_merge_view(std::multiset<T> &a, std::multiset<T> &b) {
        this->a = a;
        this->b = b;
        this->p = &a;
        this->q = &b;

        std::multiset<T> t;
        for(typename std::multiset<T>::const_iterator it = a.begin();it != a.end();it++) {
            t.insert(*it);
        }
        for(typename std::multiset<T>::const_iterator it = b.begin();it != b.end();it++) {
            t.insert(*it);
        }
        int div = a.size();
        a.clear();
        b.clear();
        int c = 0;
        for(typename std::multiset<T>::const_iterator it = t.begin();it != t.end();it++) {

            if(c < div) {
                a.insert(*it);
            } else {
                b.insert(*it);
            }
            c++;
        }
    }
    ~multisets_merge_view() {
        *p = a;
        *q = b;
    }
	    int size() const {
        return p->size() + q->size();
    }
    int count(T v) const {
        return p->count(v) + q->count(v);
    }
	
};

#endif