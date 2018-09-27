typedef unsigned char byte;

//Função Min : (Início do Array, Final do Array, Tamanho dos elementos a serem testados)
const void *reverse( const void* first, const void* last, size_t size )
{
    //conversão para recebimento do primeiro elemento
    const byte *it_up = static_cast< const byte *>( first );
    //conversão para recebimento do último elemento
    const byte *it_down = static_cast< const byte *>( last );

    while( it_up < it_down ) //comparação posição do iterador para verificação se as posições já se alternaram.
    {
        
    memcpy( aux, it_up, size );
    memcpy( it_up, it_down, size );
    memcpy( it_down, aux, size );
    it_up += size;
    it_down -= size;
    }

}