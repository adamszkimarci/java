#ifndef __PSTACK2_H__
#define __PSTACK2_H__

#include <stack>
#include <map>

template<class T>
class priority_stack {
	typedef std::map<int, std::stack<T> > PriorStack;
	PriorStack priorStack;
public:
	void push(const int& prior, const T& item) {
		priorStack[prior].push(item);
	}
	int size(const int& prior) const {
		typename PriorStack::const_iterator it = priorStack.find(prior);
		
		if (it != priorStack.end()) {
			return it->second.size();
		}
		return 0;
	}
	
	int size() const {
		int ret=0;
		for(typename PriorStack::const_iterator it = priorStack.begin();
		it!=priorStack.end(); ++ it) {
			ret += it->second.size();
		}
		return ret;
	}
	
	T& top() { //mainben értéket adunk neki (37.sor) ezért kell a ref.
		return priorStack.rbegin()->second.top();
	}
};
#endif