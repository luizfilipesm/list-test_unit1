// Alias predicate
typedef bool (*Equal)( const void *, const void *);
//Alias byte com base no tamanho predefinido de char (1 byte)
typedef unsigned char byte;

//Função Find : (Início do Array, Final do Array, Tamanho dos elementos a serem testados, função predicado a ser verificada)
const void *Unique( const void* first, const void* last, size_t size, Equal eq )
{
    //conversão para recebimento do primeiro elemento
    const byte *it = static_cast< const byte *>( first );//ponteiro para primeiro elemento apontando para início do array
    const byte *last = static_cast< const byte *>(last);  //ponteiro em last para caso não satisfaça o predicado 
    const byte *slow = it;
    const byte *init = it;
    const byte *verify = it;
    
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

}