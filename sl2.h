#ifndef __SortedList_H__
#define __SortedList_H__

#include <list>
#include <functional>
#include <algorithm>
#include <iterator>

template<class T >
class SortedList {
	std::list<T> items;
	
public:
	void insert(const T& item) {
		items.push_back(item);
		items.sort();
	}

	int size() const {
		return items.size();
	}

	const T& front() const {
		return items.front();
	}
	const T& back() const {
		return items.back();
	}
	void remove(const T& item) {
		items.remove(item);
	}
	typedef std::list<T>::const_iterator = asd;
	typename asd begin() const {
		return items.begin();
	}
	typename std::list<T>::const_iterator end() const {
		return items.end();
	}
};
#endif