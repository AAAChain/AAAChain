#pragma once


namespace reflect {

template<typename T>
struct reflector{
    typedef T type;

    template<typename Visitor>
    static inline void visit( const Visitor& v );
};

} 




