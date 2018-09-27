// Alias predicate
typedef bool (*predicate)( const void *);
//Alias byte com base no tamanho predefinidode char (1 byte)
typedef unsigned char byte;

//Função all_of : (Início do Array, Final do Array, Tamanho dos elementos a serem testados, função predicado a ser verificada)
bool all_of( const void* first, const void* last, size_t size, predicate p )
{
    //conversão para recebimento do primeiro elemento
    const byte *it = static_cast< const byte *>( first );//ponteiro para primeiro elemento apontando para início do array
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
bool any_of( const void* first, const void* last, size_t size, predicate p )
{
    //conversão para recebimento do primeiro elemento
    const byte *it = static_cast< const byte *>( first );//ponteiro para primeiro elemento apontando para início do array
    
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
bool none_of( const void* first, const void* last, size_t size, predicate p )
{
    //conversão para recebimento do primeiro elemento
    const byte *it = static_cast< const byte *>( first );//ponteiro para primeiro elemento apontando para início do array
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