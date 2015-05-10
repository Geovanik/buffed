#include <stdlib.h>
#include <string.h>
#include "buffend.h"

int main(){
    int nrTabelas = 1;
    int nTabela[nrTabelas];
    table  *tab[nrTabelas]; 
    column *colunas;
    int object, schema;
    
    object      = existeArquivo("fs_object.dat");
    schema      = existeArquivo("fs_schema.dat");
    nTabela[0]  = existeArquivo("Aluno.dat");

    
     if(!object || !schema){
    
        if(!nTabela[0]){                                                                    //Se ainda não existe a Aluno, a mesma é criada
            tab[0] = iniciaTabela("Aluno");                                                 //Cria a tabela 
            tab[0] = adicionaCampo(tab[0], "CPF"     , 'I', (sizeof(int))   ,PK,"","");     //Cria os atributos
            tab[0] = adicionaCampo(tab[0], "Nome"    , 'S', 20              ,NPK,"","");        
            tab[0] = adicionaCampo(tab[0], "Endereco", 'S', 20              ,NPK,"","");
            tab[0] = adicionaCampo(tab[0], "Peso"    , 'D', (sizeof(double)),NPK,"","");
            finalizaTabela(tab[0]);
         }
         
    }
    
     
     //Inserção de tuplas na tabela1   
    colunas = NULL;     
    colunas = insereValor(colunas, "CPF", "123456");
    colunas = insereValor(colunas, "Nome", "Rogerio");
    colunas = insereValor(colunas, "Endereco", "Rua Marechal");
    colunas = insereValor(colunas, "Peso", "81.4");
    finalizaInsert("Aluno", colunas); 
    
    
    imprime("Aluno");        //Imprime os atributos da tabela "Aluno"
    //imprime("Inst");
    
    
    
    return 0;
}
