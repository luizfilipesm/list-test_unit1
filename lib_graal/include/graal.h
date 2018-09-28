// Generic Array Algorithms Library - graal.h
#ifndef _GRAAL_H_
#define _GRAAL_H_

#include <cstring>  // memcpy, memset, memmove

namespace graal
{

    // Basic unit of manipulation.
    using byte = unsigned char;

    // Basic predicate type function pointer
    using Predicate = bool (*) (  void * );

    // Basic predicate for compare elements
    using PredComp = bool (*) ( void *,  void *);

    // Regular comparison function pointer
    using Compare = bool (*) (  void *,  void * );

    // Regular equality function pointer
    using Equal = bool (*) (  void *,  void * );

    // Here are the prototypes.
     void * min(  void *,  void *, size_t, Compare );
    void reverse( void * , void * , size_t );
    void * copy(  void * ,  void * , void * , size_t size_ );
    void * clone(  void * ,  void * , size_t );
     void * find_if(  void * ,  void * , size_t , Predicate );
     void * find(  void * ,  void * , size_t ,  void * , Equal );
    bool all_of(  void * ,  void * , size_t , Predicate );
    bool any_of(  void * ,  void * , size_t , Predicate );
    bool none_of(  void * ,  void * , size_t , Predicate );
    bool equal(  void *,  void *,  void *, size_t , Equal );
    bool equal(  void *,  void *,  void *,  void *, size_t , Equal );
	void * unique( void *, void *, size_t, Equal );
    void * partition( void *, void *, size_t, Predicate );
    void qsort( void *, std::size_t, std::size_t, PredComp );

}

#endif
