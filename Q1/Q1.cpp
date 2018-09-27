// Alias cmp
typedef bool (*cmp)( const void *, const void * );
//Aliar byte com base no tamanho predefinidode char (1 byte)
typedef unsigned char byte;

//Função Min : (Início do Array, Final do Array, Tamanho dos elementos a serem testados, função MinCompare)
const void *min( const void* first, const void* last, std::size_t size, cmp compare )
{
    //conversão para recebimento do primeiro elemento
    const byte *it = static_cast< const byte *>( first );
    const byte *smallest = it; //ponteiro para menor elemento apontando para início do array 
    it += size; // iterador apontando para segunda posição

    while( it != last ) //comparação posição do iterador em relação ao fim do array
    {
        
        if ( compare( it, smallest ) )//verificação com função compare
            smallest = it; //atualização de menor elemento
        it += size; //progressão do iterador
    }

    return smallest; //Retorna o endereço para a menor posição
}