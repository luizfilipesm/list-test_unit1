// Alias predicate
typedef bool (*predicate)( const void *);
//Alias byte com base no tamanho predefinido de char (1 byte)
typedef unsigned char byte;

//Função Find : (Início do Array, Final do Array, Tamanho dos elementos a serem testados, função predicado a ser verificada)
const void *partition( const void* first, const void* last, size_t size, predicate p )
{
    //conversão para recebimento do primeiro elemento
    const byte *it = static_cast< const byte *>( first );//ponteiro para primeiro elemento apontando para início do array
    const byte *last = static_cast< const byte *>(last);  //ponteiro em last para caso não satisfaça o predicado 
    const byt  *slow = it

    while( it != last ) //comparação posição do iterador em relação ao fim do array
    {
        if (p(it))
        {
            memcpy( slow , it, size);
            slow += size;
        }

        it += size;
    }

    last = slow - size;

}