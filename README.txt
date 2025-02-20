Compilando projeto:
O projeto exige ao menos o Cmake versão 3.10 e C++14

- (Opcional para usar a extensão) **CMake Tools Extension** instalada no VS Code  
  [Link para a extensão](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cmake-tools).


Usando a extensão Cmake no VS code

1. Abra a pasta raiz do projeto.
2. No canto inferior esquerdo, clique para escolher o kit apropriado.
3. A extensão detectará automaticamente o `CMakeLists.txt` e executará a configuração.
4. Use o comando `CMake: Build` disponível via o Command Palette (Ctrl+Shift+P) ou clique no botão de build na barra de status.
5. Utilize os comandos `CMake: Run Without Debugging` ou `CMake: Debug` conforme necessário.

Compilando sem a extensão (exige Cmake instalado na máquina):

Linux:
1. Abra a pasta raiz do projeto na linha de comando.
2. Crie um diretório build com "mkdir build".
3. Acesse o diretório build com "cd build".
4. Configure o projeto com "cmake ..".
5. Compile o projeto com "make".
6. Rode o projeto com "./Biocad".

Windows:
1. Abra a pasta raiz do projeto na linha de comando.
2. Crie um diretório build com "mkdir build".
3. Acesse o diretório build com "cd build".
4. Configure o projeto com "cmake .. -G "MinGW Makefiles"".
5. Compile o projeto com "mingw32-make".
6. Rode o projeto com "./Biocad.exe".