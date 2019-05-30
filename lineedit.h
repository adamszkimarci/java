#ifndef __LINEEDIT_H__
#define __LINEEDIT_H__

#include <functional>
#include <algorithm>
#include <iterator>
#include <vector>
#include <iostream>

template<class Collection, class T>
class line_editor {
	typename Collection::iterator it;
	Collection lineEdit;
	
public:
	
	line_editor() {
		it = lineEdit.begin();
	}
	void press(const T& item){
		
		it = lineEdit.insert(it, item); 
		//insert iteratort ad vissza
		it = std::next(it);
		
	}
	void home() {
		it = lineEdit.begin();
	}
	Collection enter() {
		Collection tmp(lineEdit);
		lineEdit.clear();
		return tmp;
	}
};

#endif