# Lib Graal

Pra compilar, copie o seu `graal.cpp` para `src` e `graal.h` para a pasta `include`.


Depois:

1. No diretório raiz crie a basta `build`.
2. Entre na `build` com: `cd build`.
3. Gere o arquivo de makefile com: `cmake -G "Unix Makefiles" ..`
4. Compile o projeto com: `cmake --build . --config release` ou simplesmente `make`
5. Rode os testes com: `.\run_tests`
