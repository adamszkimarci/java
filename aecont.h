
#ifndef AECONT
#define AECONT
#include <deque>
 
template<class T>
class alternating_endpoint_container{
private:
    std::deque<T> de;
    bool front;
public:
     alternating_endpoint_container() : front(true){
         de.clear();
     }
    // template<typename it>
    // alternating_endpoint_container(it start, it stop) : front(true) {
        // de.clear();
        // for(;start != stop; ++start){
            // insert(*start);
        // }
    // }
    void insert(T element){
        if(front){
            de.push_front(element);
        }
        else{
            de.push_back(element);
        }
        front = !front;
    }
 
    T at(int index) const {return de[index];}
 
    int size() const {return de.size();}

    T& operator[](int index){return de[index];}
 
   const T& operator[] (int index) const {return de[index];}
 
    void erase(){
        if(front){
            de.pop_front();
        }
        else{
            de.pop_back();
        }
        front = !front;
    }
  
    typedef typename std::deque<T>::iterator iterator;
 
    iterator begin(){
        return de.begin();
    }
 
    iterator end(){
        return de.end();
    }
	/**/
};
 
#endif // AECONT