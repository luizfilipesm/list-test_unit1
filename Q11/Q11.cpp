// Alias predicate
typedef bool (*PredComp)( const void *);
//Alias byte com base no tamanho predefinido de char (1 byte)
typedef unsigned char byte;

void qsort( void *first , std::size_t size_a, std::size_t size_elem, PredComp sorting )
{
        //conversão para recebimento do primeiro elemento
    const byte *it = static_cast< const byte *>( first );//ponteiro para primeiro elemento apontando para início do array
    const byte *last = it + size_a ;
    const byte aux[size];

    while (count != last)
    {
        while( it != last ) //comparação posição do iterador em relação ao fim do array
        {
            if (!sorting(it, it+size_elem))
            {
                memcpy( aux, it, size );
                memcpy( it, it+size, size );
                memcpy( it+size, aux, size );
            }

            count += size;
        }
    }
}