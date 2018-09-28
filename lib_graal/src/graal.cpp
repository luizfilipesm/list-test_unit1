    #include <cstring>  // memcpy, memset, memmove    
    #include <stdlib.h>

    // Basic unit of manipulation.
    using byte = unsigned char;

    // Basic predicate type function pointer
    using Predicate = bool (*) (  void * );

    // Basic predicate for compare elements
    using PredComp = bool (*) ( void *,  void *);

    // Regular comparison function pointer
    using Compare = bool (*) (   void *,   void * );

    // Regular equality function pointer
    using Equal = bool (*) (  void *,  void * );

// ======================================================= # ============================================================


//Função Min : (Início do Array, Final do Array, Tamanho dos elementos a serem testados, função cmp)
 void *min(  void* first,  void* last, std::size_t size, Compare cmp )
{
    //conversão para recebimento do primeiro elemento
     byte *it = static_cast<  byte *>( first );
     byte *smallest = it; //ponteiro para menor elemento apontando para início do array 
    it += size; // iterador apontando para segunda posição

    while( it != last ) //comparação posição do iterador em relação ao fim do array
    {
        
        if ( cmp( it, smallest ) )//verificação com função compare
            smallest = it; //atualização de menor elemento
        it += size; //progressão do iterador
    }

    return smallest; //Retorna o endereço para a menor posição
}


// ======================================================= # ============================================================

//Função Reverse : (Início do array, Fina do array, Tamanho dos elementos)
void *reverse( void* first,  void* last, std::size_t size )
{
    //conversão para recebimento do primeiro elemento
    byte *it_up = static_cast< byte *>( first );

    //conversão para recebimento do último elemento
    byte *it_down = static_cast< byte *>( last );
    
    byte *aux [size];

    while( it_up < it_down ) //comparação posição do iterador para verificação se as posições já se alternaram.
    {
        
        memcpy( aux, it_up, size );
        memcpy( it_up, it_down, size );
        memcpy( it_down, aux, size );
        it_up += size;
        it_down -= size;
    }

    return first;
}

// ======================================================= # ============================================================

//Função copy: (Início do Array, Final do Array, array de cópia, Tamanho dos elementos a serem copiados)

void *copy(  void* first,  void* last, void* d_first, std::size_t size )
{
    //conversão para recebimento dos índices
    byte *it_base = static_cast<  byte *>( first );
    byte *it_final = static_cast<  byte *>( last );
    byte *it_cp = static_cast< byte *>( d_first );
    
    size_t size_new = it_final - it_base;

    memcpy( it_cp, it_base, size_new );

    
    return it_cp;

}

// ======================================================= # ============================================================


//Função clone: (Início do Array, Final do Array, array de cópia, Tamanho dos elementos a serem copiados)
 void *clone(  void* first,  void* last,  size_t size )
{
    

    //conversão para recebimento dos índices
     byte *it_base = static_cast<  byte *>( first );
     byte *it_final = static_cast<  byte *>( last );
    
    int size_new = it_final - it_base;
    
    //alocação de memória
    void *it_clone = (void *) malloc (size_new) ;



    memcpy( it_clone, it_base, size_new );

    
    return it_clone;

}

// ======================================================= # ============================================================

//Função Find_if : (Início do Array, Final do Array, Tamanho dos elementos a serem testados, função predicado a ser verificada)
 void *find_if(  void* first,  void* last, size_t size, Predicate p )
{
    //conversão para recebimento do primeiro elemento
     byte *it = static_cast<  byte *>( first );//ponteiro para primeiro elemento apontando para início do array
     byte *find_o = static_cast<  byte *>(last);  //ponteiro em last para caso não satisfaça o predicado 
    

    while( it != last ) //comparação posição do iterador em relação ao fim do array
    {
        
        if ( p( it ) )//verificação com função predicado
            {
                find_o = it; //atualização do primeiro elemento que satisfaz a função
            } 
        it += size; //progressão do iterador
    }

    return find_o; //Retorna o endereço que satisfaz o predicado
}

// ======================================================= # ============================================================

 void *find(  void* first,  void* last, size_t size,  void* value, Equal eq )
{
    //conversão para recebimento do primeiro elemento
     byte *it = static_cast<  byte *>( first );//ponteiro para primeiro elemento apontando para início do array
     byte *valu = static_cast<  byte *>( value );//ponteiro para elemento base de busca
     byte *find_o = static_cast<  byte *>(last);  //ponteiro em last para caso não satisfaça o predicado 
    

    while( it != last ) //comparação posição do iterador em relação ao fim do array
    {
        
        if ( eq( it , valu ) )//verificação com função predicado
            {
                find_o = it; //atualização do primeiro elemento que satisfaz a função
            } 
        it += size; //progressão do iterador
    }

    return find_o; //Retorna o endereço que satisfaz o predicado
}


// ======================================================= # ============================================================

//Função all_of : (Início do Array, Final do Array, Tamanho dos elementos a serem testados, função predicado a ser verificada)
bool all_of(  void* first,  void* last, size_t size, Predicate p )
{
    //conversão para recebimento do primeiro elemento
     byte *it = static_cast<  byte *>( first );//ponteiro para primeiro elemento apontando para início do array
    bool all = true;

    while( it != last ) //comparação posição do iterador em relação ao fim do array
    {
        
        if ( !p( it ) )//verificação com função predicado
            {
                all = false; //atualização do booleano de retorno caso não satisfaça o predicado
            } 
        it += size; //progressão do iterador
    }

    return all; //Retorna o endereço que satisfaz o predicado
}


//Função any_of : (Início do Array, Final do Array, Tamanho dos elementos a serem testados, função predicado a ser verificada)
bool any_of(  void* first,  void* last, size_t size, Predicate p )
{
    //conversão para recebimento do primeiro elemento
     byte *it = static_cast<  byte *>( first );//ponteiro para primeiro elemento apontando para início do array
    
    bool any = false;

    if(it == last)
    {
        any = true; //atualização do booleano de retorno caso array vazio
        return any;
    }

    while( it != last ) //comparação posição do iterador em relação ao fim do array
    {
        
        if ( p( it ) )//verificação com função predicado
            {
                any = true; //atualização do booleano de retorno caso satisfaça o predicado
            } 
        it += size; //progressão do iterador
    }

    return any; //Retorna o endereço que satisfaz o predicado
}


//Função none_of : (Início do Array, Final do Array, Tamanho dos elementos a serem testados, função predicado a ser verificada)
bool none_of(  void* first,  void* last, size_t size, Predicate p )
{
    //conversão para recebimento do primeiro elemento
     byte *it = static_cast<  byte *>( first );//ponteiro para primeiro elemento apontando para início do array
    bool none = true;

    while( it != last ) //comparação posição do iterador em relação ao fim do array
    {
        
        if ( !p( it ) )//verificação com função predicado
            {
                none = false; //atualização do booleano de retorno caso não satisfaça o predicado
            } 
        it += size; //progressão do iterador
    }

    return none; //Retorna o endereço que satisfaz o predicado
}


// ======================================================= # ============================================================


//Função equal : (Início do Array, Final do Array, Tamanho dos elementos a serem testados, função predicado a ser verificada)
bool equal(  void* first,  void* last,  void* first_2, size_t size, Predicate p)
{
    //conversão para recebimento do primeiro elemento
     byte *start = static_cast<  byte *>( first );//ponteiro para primeiro elemento apontando para início do array
     byte *the_end = static_cast<  byte *>( last );//ponteiro para último elemento apontando para início do array
     byte *start_2 = static_cast<  byte *>( first_2 );//ponteiro para 1 elemento do segundo array

    bool eq = true;
    while( start != the_end ) //comparação posição do iterador em relação ao fim do array
    {
        if ( !p( start ) )//verificação com função predicado
            {
            eq = false; //atualização do booleano de retorno caso não satisfaça o predicado
            } 
           
            start += size; //progressão do iterador
            start_2 += size; //progressão do iterador
    }
    return eq;//Retorna o endereço que satisfaz o predicado
}

bool equal(  void* first,  void* last,  void* first_2,  void* last_2, size_t size, Predicate p)
{
    //conversão para recebimento do primeiro elemento
     byte *start = static_cast<  byte *>( first );//ponteiro para primeiro elemento apontando para início do array
     byte *the_end = static_cast<  byte *>( last );//ponteiro para último elemento apontando para início do array
     byte *start_2 = static_cast<  byte *>( first_2 );//ponteiro para 1 elemento do segundo array


    bool eq = true;
    
    while( start != the_end ) //comparação posição do iterador em relação ao fim do array
    {
        if ( !p( start ) )//verificação com função predicado
            {
            eq = false; //atualização do booleano de retorno caso não satisfaça o predicado
            } 
           
            start += size; //progressão do iterador
            start_2 += size; //progressão do iterador
    }
    return eq;//Retorna o endereço que satisfaz o predicado
}

// ======================================================= # ============================================================


//Função Find : (Início do Array, Final do Array, Tamanho dos elementos a serem testados, função predicado a ser verificada)
 void *unique(  void* first,  void* last, size_t size, Equal eq )
{
    //conversão para recebimento do primeiro elemento
     byte *it = static_cast<  byte *>( first );//ponteiro para primeiro elemento apontando para início do array
     byte *slow = it;
     byte *init = it;
     byte *verify = it;
    
    while( it != last ) //comparação posição do iterador em relação ao fim do array
    {
        bool verification = true;
        
        while (verify != slow)
        {
            if (eq( verify , it ) )//verificação com função predicado
            {
                verification = false;
            } 
        
            verify += size;
        }

        if( verification)
        {
            memcpy( slow , it, size);
            slow += size; 
        }

        verify = init;

        it += size; //progressão do iterador
    }

    last = slow - size;

    return last;

}

// ======================================================= # ============================================================


//Função Find : (Início do Array, Final do Array, Tamanho dos elementos a serem testados, função predicado a ser verificada)
 void *partition(  void* first,  void* last, size_t size, Predicate p )
{
    //conversão para recebimento do primeiro elemento
     byte *it = static_cast<  byte *>( first );//ponteiro para primeiro elemento apontando para início do array
     byte *ult = static_cast<  byte *>(last);  //ponteiro em last para caso não satisfaça o predicado 
     byte *slow = it;

    while( it != ult ) //comparação posição do iterador em relação ao fim do array
    {
        if (p(it))
        {
            memcpy( slow , it, size);
            slow += size;
        }

        it += size;
    }

    ult = slow - size;

    return ult;
}

// ======================================================= # ============================================================


void *qsort( void *first , std::size_t size_a, std::size_t size_elem, PredComp sorting )
{
        //conversão para recebimento do primeiro elemento
     byte *it = static_cast<  byte *>( first );//ponteiro para primeiro elemento apontando para início do array
     byte *last = it + size_a ;
     byte aux[size_elem];
     byte *count = it;

    while (count != last)
    {
        while( it != last ) //comparação posição do iterador em relação ao fim do array
        {
            if (!sorting(it, it+size_elem))
            {
                memcpy( aux, it, size_elem );
                memcpy( it, it+size_elem, size_elem );
                memcpy( it+size_elem, aux, size_elem );
            }

            count += size_elem;
        }
    }

    return it;
}