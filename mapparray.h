#ifndef MAPARRAY_H_INCLUDED
#define MAPARRAY_H_INCLUDED
#include <map>


template<typename T, typename T2>
class map_array_util {
    private:
        std::map<T, T2> &Container;
        typename std::map<T, T2>::iterator it;
    public:
        map_array_util(std::map<T, T2> &Cont) : Container(Cont){}

        void copy(T2 t[], int n) {
            int i = 0;
            for(it=Container.begin(); it!=Container.end(); ++it){
                Container[it->first] = t[i];
                i++;
            }
        }

        bool equals(T2 t[], int Size) const {
            if(Size > Container.size()){
                return false;
            }
            bool ok = true;
            int i = 0;
            typename std::map<T, T2>::iterator its;
            for(its=Container.begin(); its!=Container.end(); ++its){
                if(t[i] != its->second) {
                    ok = false;
                }
                i++;
            }

            return ok;
        }
		
};

#endif // MAPARRAY_H_INCLUDED
