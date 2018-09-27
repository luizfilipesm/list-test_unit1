// Alias cmp
typedef bool (*predicate)( const void *, const void * );
//Alias byte com base no tamanho predefinidode char (1 byte)
typedef unsigned char byte;

//Função Find : (Início do Array, Final do Array, Tamanho dos elementos a serem testados, função predicado a ser verificada)
const void *find_if( const void* first, const void* last, size_t size, predicate p )
{
    //conversão para recebimento do primeiro elemento
    const byte *it = static_cast< const byte *>( first );//ponteiro para primeiro elemento apontando para início do array
    const byte *find_o = static_cast< const byte *>(last);  //ponteiro em last para caso não satisfaça o predicado 
    

    while( it != last ) //comparação posição do iterador em relação ao fim do array
    {
        
        if ( p( it, smallest ) )//verificação com função predicado
            {
                find_o = it; //atualização do primeiro elemento que satisfaz a função
            } 
        it += size; //progressão do iterador
    }

    return find_o; //Retorna o endereço que satisfaz o predicado