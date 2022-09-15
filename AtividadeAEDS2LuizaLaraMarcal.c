#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct coord{  
    float x, y;
} tCoord;

tCoord criarPonto(){ 
    tCoord p;       
    p.x= 0;
    p.y=0;
    return  p;
}

int analisarQuadrante(tCoord ponto){ 
    
    if (ponto.x==0 && ponto.y==0)
        return 0;

    else if (ponto.x==0)
        return -1; // não existe, mas está em cima do eixo y

    else if (ponto.y==0)
        return -2; // não existe, mas está em cima do eixo x.
    
    else if (ponto.x>0){
        if (ponto.y>0){
            return 1;
        }
        else{
            return 4;
        }
    }
    else{
        if (ponto.y>0){
            return 2;
        }
        else{
            return 3;
        }
    }
}

int checkQuadrante(tCoord ponto){ //Checar se está no quadrante correto. 
    int quadrante;
    printf("Digite o quadrante que você deseja que o ponto esteja: \n");
    scanf("%i", &quadrante);
    return analisarQuadrante(ponto) == quadrante;
}

void alterarPonto(tCoord *ponto){ 
    printf("Digite as coordenadas do plano cartesiano \n");
    printf("X: ");
    scanf("%f", &ponto->x);
    printf("Y: ");
    scanf("%f", &ponto->y);
}

float distancia (tCoord p1, tCoord p2){ //Retornar a distância entre dois pontos
    float distancia;
    distancia = sqrt(pow(p1.x - p2.x,2) + pow(p1.y - p2.y, 2));
    return distancia;
}

float maiorCoordenada (tCoord ponto){ //Retornar o maior valor de coordenada de um ponto
    if (ponto.x>=ponto.y){
        return ponto.x;
    } 
    else if (ponto.x<ponto.y){
        return ponto.y;
    }
}

int main(void)
{
	tCoord p1,p2;
	float d;
	int comando, q, max;
	
    printf("\n Escolha um comando:\n\n\n");
    printf("\n 1- Inicio:\n");
    printf("\n 2- Alterar os valores de um determinado ponto:\n");
    printf("\n 3- Verificar se um determinado ponto informado por parâmetro está em um determinado quadrante, também passado por parâmetro:\n");
    printf("\n 4- Analisar em qual quadrante está o ponto informado:\n");
    printf("\n 5- Qual a distância entre os dois pontos?\n");
    printf("\n 6- Qual o maior valor entre os pontos informados?\n");
    printf("\n 7- Sair:\n");
	
	while(1){
        printf("Comando:");
        scanf("%i", &comando);

        switch (comando){
            case(1):{
                p1 = criarPonto();
                break;
            }
            
            case(2):{
                alterarPonto(&p1);
                break;
            }
            
            case(3):{
                p2= criarPonto();
                printf("Agora, você vai precisar informar a coordenada:\n");
                alterarPonto(&p2);
                
                if (checkQuadrante(p2)==1){
                    printf("Está no quadrante informado!\n");
                } else { 
                    printf("Não está no quadrante informado!\n");
                }
            
                break;
            }
            
                case(4):{
                q = analisarQuadrante(p1); 
                if (q==0){
                    printf("Está no Centro.\n");
                } else if (q==-1){
                    printf("Está no Eixo Y\n");
                } else if (q==-2){
                    printf("Está no Eixo X\n");
                } else{
                    printf("Está no quadrante %i\n", q);
                }
                break;
            }
            
            case(5):{
                p2= criarPonto();
                printf("Agora, você vai precisar informar a coordenada de um segundo ponto para ser calculada a distancia entre ele e o ponto atual.\n");
                alterarPonto(&p2);
                d=distancia(p1,p2);
                printf("A distância é %f\n", d);
                break;
            }
            
            case(6):{
                max = maiorCoordenada(p1);
                printf("A maior coordenada é %i\n", max);
                break;
            }
        
            case(7):{
                return 0;
            }
        }
    }
    return 0;
} 