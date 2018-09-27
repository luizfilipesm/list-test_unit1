typedef unsigned char byte;

//Função clone: (Início do Array, Final do Array, array de cópia, Tamanho dos elementos a serem copiados)
const void *clone( const void* first, const void* last,  size_t size )
{
    

    //conversão para recebimento dos índices
    const byte *it_base = static_cast< const byte *>( first );
    const byte *it_final = static_cast< const byte *>( last );
    
    int size_new = it_final - it_base;
    
    //alocação de memória
    void *it_clone = (void *) malloc (size_new) ;



    memcpy( it_clone, it_base, size_new );

    
    return it_clone;

}