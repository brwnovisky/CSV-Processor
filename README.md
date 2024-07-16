# Processador de Arquivos .csv em C++

Este repositório contém um processador de arquivos `.csv` desenvolvido em C++ com interface para uma aplicação em linguagem C. 
É compilada uma biblioteca compartilhada `libcsv.so` e realizado testes unitários utilizando Google Test (GTest).
Incluem-se também arquivos de teste, configuração e construção de imagem Docker em ambiente `alpine:3.20.1`.

## Objetivo

O projeto visa atender aos requisitos demandados pelo [**desafio técnico**](codeChallenge_README.md) proposto pela [**Milenio Capital**](https://www.milenio.capital/).

## Estrutura do Projeto

- [**inc/**](inc/): Contém os arquivos de cabeçalho.
- [**src/**](src/): Contém os arquivos-fonte em C++.
- [**test/**](test/): Contém os testes unitários em C++ utilizando GTest.
- [**build.sh**](build.sh): Script para compilar a biblioteca compartilhada e suas dependências no contêiner Docker.
- [**data.csv**](data.csv): Arquivo CSV(Comma-Separated Values) utilizado no teste do contêiner Docker.
- [**Dockerfile**](Dockerfile): Definição do ambiente Docker.
- [**libcsv.h**](libcsv.h): Header com a interface em C implementada em [**src/libcsv/**](src/libcsv/).
- [**Makefile**](Makefile): Arquivo gerenciador da compilação da biblioteca compartilhada e execução dos testes unitários.
- [**test_libcsv**](test_libcsv): Binário teste utilizado na imagem Docker.

## Pré-requisitos
	
- Ambiente Linux ou WSL(Windows)
- GoogleTest 1.14.0
- Docker

## Instalação

### Como instalar o Google Test

1.  **Clonar repositório**

    Clone o repositório da versão 1.14.0:
    ```sh
    git clone https://github.com/google/googletest.git -b v1.14.0
	```
2.  **Criar pasta de construção**
		
	```sh
	cd googletest
	mkdir build
	```
3.  **Compilar e instalar arquivos fonte**
	
	Para acessar a pasta ``build/`` e instalar, execute:
	```sh
	cd build
	cmake ..
	make
	sudo make install # Por padrão, instala em /usr/local/
	```

4.  **Remover repositório (opcional)**
	
	Com os arquivos fonte já instalados, o clone do repositório pode ser removido:
	```sh
	cd ../..
	rm -rf googletest/
    ```
### Como Instalar o Docker

1.  **Atualizar o Repositório de Pacotes**

    Certifique-se de que seu repositório de pacotes esteja atualizado:
    ```sh
    sudo apt update
	```
2.  **Instalar o Docker**

	Instale o Docker usando o seguinte comando:	
	```sh
	sudo apt install docker.io -y
	```
3.  **Iniciar e Ativar o Docker**
	
	Inicie o serviço do Docker e ative-o para iniciar automaticamente na inicialização:
	```sh
	sudo systemctl enable --now docker
	```
4.  **Verificar a Instalação**
	
	Confirme que o Docker está em execução:
	```sh
	docker --version
    ```

## Como Construir e Executar os Testes Unitários

1. **Construir a biblioteca compartilhada**

   Para gerar o arquivo ``libscsv.so``, na pasta raiz execute:
   ```sh
   make
   ```
	Caso precise re-gerar o arquivo ``libscsv.so``:
   ```sh
   make re
   ```
   Para apagar a pasta ``build/`` e objetos ``(.o)`` gerados:
   ```sh
   make clean
   ```

   Para apagar todos os arquivos gerados:
   ```sh
   make fclean
	  ```
3.  **Executar os Testes**

	Após a construção, para executar os testes, utilize:

	```sh
	make test
	```
## Como gerar e executar imagem Docker

1. **Gerar imagem Docker**

	Para construir a imagem Docker, execute:
	```sh
	docker build -t csv-processor .
   	```
	Para melhor leitura dos eventos de construção e testes, pode-se direcionar todos os logs para ``build.log``:
	```sh
	docker build -t csv-processor . 2>&1 | tee build.log
   	```

3. **Executar o Contêiner Docker**

	```sh
   docker run csv-processor
   ```
## Como usar a interface
	
### Funções da interface

```C
void processCsv(const char csv[], const char selectedColumns[], const char rowFilterDefinitions[])
```
**Parâmetros:**
	
- ``const char csv[]``: String com os dados do CSV, onde cada linha representa um registro e as colunas são separadas por vírgulas.
    - Exemplo: `"header1,header2,header3\n1,2,3\n4,5,6"`
- ``const char selectedColumns[]``: Uma string onde os nomes das colunas a serem selecionadas são separados por vírgulas.
    - Exemplo: `"header1,header3"`
- ``const char rowFilterDefinitions[]``: Uma string onde cada filtro é definido em uma nova linha, no formato `header(comparador)valor`.
    - Exemplo: `"header1>1\nheader2=2\nheader3<6"`

**Saída:**

- Uma string contendo o conteúdo bruto da nova tabela CSV aplicadas as operações de seleção e filtragem inseridas nos parâmetros.

```C
void processCsvFile(const char csvFilePath[], const char selectedColumns[], const char rowFilterDefinitions[])
```
**Parâmetros:**
	
- ``const char csvFilePath[]``: String com o caminho do arquivo CSV.
    - Exemplo: `"path/to/csv_file.csv"`
- ``const char selectedColumns[]``: Uma string onde os nomes das colunas a serem selecionadas, são separados por vírgulas.
    - Exemplo: `"header1,header3"`
- ``const char rowFilterDefinitions[]``: Uma string onde cada filtro é definido em uma nova linha, no formato `header(comparador)valor`.
    - Exemplo: `"header1>1\nheader2=2\nheader3<6"`

**Saída:**

- Uma string contendo o conteúdo bruto da nova tabela CSV aplicadas as operações de seleção e filtragem inseridas nos parâmetros.

**Exemplo de Uso**

```c
const char csv[] = "header1,header2,header3\n1,2,3\n4,5,6\n7,8,9";
processCsv(csv, "header1,header3", "header1>1\nheader3<8");

// output
// header1,header3
// 4,6

const char csv_file[] = "path/to/csv_file.csv";
processCsvFile(csv_file, "header1,header3", "header1>1\nheader3<8");

// output
// header1,header3
// 4,6
```

## Descrição Técnica

### Compilação da Biblioteca Compartilhada
A biblioteca compartilhada ``libscsv.so`` é compilada a partir dos arquivos-fonte em C++ localizados no diretório [**src/**](src/). 
A compilação é gerenciada pelo [**Makefile**](Makefile), que define as regras para compilar e ligar os arquivos objeto em uma biblioteca compartilhada.

### Testes Unitários
Os testes unitários são escritos utilizando o framework **Google Test** (GTest) e estão localizados no diretório [**test/**](test/). Estes, visam catalogar e neutralizar erros que comprometam o funcionamento da aplicação, bem como atendam os requisitos do desafio técnico proposto. 

Os grupos de testes estão dividos em: 
- ``mandatory``: abragendo requisitos mandatórios do desafio.
- ``bonus``: abragendo requisitos bônus do desafio.

### Integração com Aplicações em C
A biblioteca compartilhada expõe uma [**interface**](inc/libcsv.h) para facilitar a integração com aplicações escritas em linguagem C.

### Teste em Container Docker
O script contido em [**build.sh**](build.sh) executa a instalação de dependências do projeto no ambiente da imagem Docker, de modo a garantir a integração da interface entre linguagens e a execução dos testes implementados.  

### Observações Finais
Este projeto é parte de um desafio técnico para contratação, não sendo portanto, de código aberto. Toda a propriedade intelectual contida no [**desafio técnico**](codeChallenge_README.md) pertence a [**Milenio Capital**](https://www.milenio.capital/).

---