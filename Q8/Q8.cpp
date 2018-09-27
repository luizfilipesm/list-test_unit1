// Alias predicate
typedef bool (*predicate)( const void *);
//Alias byte com base no tamanho predefinidode char (1 byte)
typedef unsigned char byte;

//Função equal : (Início do Array, Final do Array, Tamanho dos elementos a serem testados, função predicado a ser verificada)
bool equal( const void* first, const void* last, const void* first_2, size_t size, predicate p)
{
    //conversão para recebimento do primeiro elemento
    const byte *start = static_cast< const byte *>( first );//ponteiro para primeiro elemento apontando para início do array
    const byte *the_end = static_cast< const byte *>( last );//ponteiro para último elemento apontando para início do array
    const byte *start_2 = static_cast< const byte *>( first_2 );//ponteiro para 1 elemento do segundo array

    bool eq = true;
    while( start1 != the_end ) //comparação posição do iterador em relação ao fim do array
    {
        if ( !p( start, start_2 ) )//verificação com função predicado
            {
            eq = false; //atualização do booleano de retorno caso não satisfaça o predicado
            } 
           
            start += size; //progressão do iterador
            start_2 += size; //progressão do iterador
    }
    return eq//Retorna o endereço que satisfaz o predicado
}

bool equal( const void* first, const void* last, const void* first_2, const void* last_2, size_t size, predicate p)
{
    //conversão para recebimento do primeiro elemento
    const byte *start = static_cast< const byte *>( first );//ponteiro para primeiro elemento apontando para início do array
    const byte *the_end = static_cast< const byte *>( last );//ponteiro para último elemento apontando para início do array
    const byte *start_2 = static_cast< const byte *>( first_2 );//ponteiro para 1 elemento do segundo array
    const byte *the_end_2 = static_cast< const byte *>( last_2 );//ponteiro para 1 elemento do segundo array


    bool eq = true;
    
    while( start1 != the_end ) //comparação posição do iterador em relação ao fim do array
    {
        if ( !p( start, start_2 ) )//verificação com função predicado
            {
            eq = false; //atualização do booleano de retorno caso não satisfaça o predicado
            } 
           
            start += size; //progressão do iterador
            start_2 += size; //progressão do iterador
    }
    return eq//Retorna o endereço que satisfaz o predicado
}