/*Jerome Hayes JrMap.h3/16/16This program100%*/#ifndef MAP_H#define MAP_H#include "../lab8/Set.h"#include "Pair.h"using namespace std;template <class key, class value>class Map: public Set < Pair < key, value > >{public:    typedef Set < Pair < key, value > > parent;    typedef Set_iterator < Pair < key, value > > iterator;    Map():parent() {}    iterator find(const key & k) {return parent::find(Pair <key, value>(k,value()));}    value & operator[](const key & k)    {        iterator it = parent::insert( Pair<key, value> (k, value()));        return (*it).second;    }    void erase(const key & k) {parent::erase(Pair <key, value>(k,value()));}};#endif