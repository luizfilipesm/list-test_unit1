typedef unsigned char byte;

//Função copy: (Início do Array, Final do Array, array de cópia, Tamanho dos elementos a serem copiados)
const void *copy( const void* first, const void* last, const void* d_first size_t size , )
{
    //conversão para recebimento dos índices
    const byte *it_base = static_cast< const byte *>( first );
    const byte *it_final = static_cast< const byte *>( last );
    const byte *it_cp = static_cast< const byte *>( d_first );
    
    size_t size_new = it_final - it_base;

    memcpy( it_cp, it_base, size_new );

    
    return it_cp;

}