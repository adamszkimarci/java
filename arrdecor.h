#ifndef ARRDECOR_H_INCLUDED
#define ARRDECOR_H_INCLUDED

#include <algorithm>
#include <vector>
#include <set>

template<class C, class T >
class array_decorator{

    public:
        array_decorator(T* first, int size ){
            for(int i=0;i<size;i++){
                container.push_back(*(first+i));
            }

        }

        /*void print(){
          for(int i=0;i<container.size();i++){

              std::cout<*(<container.begin()+i)<<std::endl;
          }
        }*/

        array_decorator<C, T>& sort(){
            std::vector<T> tmp(container.begin(), container.end());
            std::sort(tmp.begin(), tmp.end());
            C tmp2(tmp.begin(), tmp.end());
            container=tmp2;
            return *this;
        }

        array_decorator<C, T>& reverse(){
           std::reverse(container.begin(), container.end());
           return *this;
        }

        const C& get() const{
            return container;
        }

        array_decorator<C, T>& unique(){

        typename C::iterator last = std::unique(container.begin(),container.end ());
        container.erase(last, container.end());
        return *this;

        }

        void swap(array_decorator<C, T>& other){

        C tmp = container;
        container = other.container;
        other.container = tmp;

        }


    private:
    C container;
};


#endif
