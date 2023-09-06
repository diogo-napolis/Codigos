/*
Este c�digo em C realiza uma opera��o de codifica��o de mensagem usando o c�digo de Bacon. 
O c�digo de Bacon � um c�digo de substitui��o que representa letras do alfabeto atrav�s de sequ�ncias de caracteres 'A' e 'B'. 
O c�digo recebe uma mensagem oculta e uma frase de entrada e codifica a frase de acordo com a mensagem oculta.
Resumidamente, o programa recebe uma frase e uma mensagem oculta, converte a frase para letras min�sculas, e para cada letra da mensagem oculta, codifica a frase de acordo com o c�digo de Bacon. 
O resultado � a frase codificada impressa na sa�da padr�o.

Esta atividade foi feita no terceiro semestre, na disciplina de Estrutura de Dados Lineares
*/


#include <stdlib.h>
#include <stdio.h>

void codificarBacon(char frase[200], char mensagem[19]);

int main() {
    char frase[200] = "Avance alem dos limites, supere desafios, conquiste seus objetivos! Sonhe alto, conquiste tudo! Ame, sorria, viva! Explore!";
    printf("Texto enviado: %s\n", frase);

    char mensagem[19] = "KNOWLEDGE IS POWER";
    printf("Mensagem Oculta: %s\n", mensagem);

    printf("Frase Codificada:\n");
    codificarBacon(frase, mensagem);

    return 0;
}

void codificarBacon(char frase[200], char mensagem[19]) {
    char alfabetoBacon[26][6] = {
        "AAAAA", "AAAAB", "AAABA", "AAABB", "AABAA", "AABAB", "AABBA", "AABBB",
        "ABAAA", "ABAAB", "ABABA", "ABABB", "ABBAA", "ABBAB", "ABBBA", "ABBBB",
        "BAAAA", "BAAAB", "BAABA", "BAABB", "BABAA", "BABAB", "BABBA", "BABBB",
        "BBAAA", "BBAAB"
    };

    int i = 0;

    while (frase[i] != '\0') {
        if (frase[i] >= 'A' && frase[i] <= 'Z') {
            frase[i] = frase[i] + 32;
        }
        i++;
    }

    int k = 0;
    int indiceLetra;
    int controleIndice = 0;

    while (mensagem[k] != '\0') {
        if (mensagem[k] >= 'A' && mensagem[k] <= 'Z') {
            indiceLetra = mensagem[k] - 'A';
            for (int j = 0; j < 5; j++) {
                if (alfabetoBacon[indiceLetra][j] == 'A') {
                    if (frase[controleIndice] >= 'a' && frase[controleIndice] <= 'z') {
                        frase[controleIndice] = frase[controleIndice] - 32;
                    }
                }
                controleIndice++;
            }
        } else {
            controleIndice++;
        }
        k++;
    }

    frase[controleIndice] = '\0';
    printf("%s\n", frase);
}
