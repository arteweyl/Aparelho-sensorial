//Codigo Aparelho sensorial foi desenvolvido para a disciplina de Projetos de Engenharia 1
//Curso de Engenharia da Computação da universidade Federal do Pará
//Participantes Aleandra Ximenes, Artemisia Souza ,Ellen Gomes, Ilard Lamarão e Vivian Santos


#include "Ultrasonic.h"//BIBLIOTECA PARA O SENSOR ULTRASSÔNICO
#define N 300

//DECLARAÇÃO DOS PINOS NO ARDUÍNO
#define AltoFalante 9
#define vibracall 2
float echoPin = 5;
float trigPin = 8;

float distancia; //CRIA UMA VARIÁVEL CHAMADA "distancia" DO TIPO FLOAT

Ultrasonic ultrasonic(trigPin,echoPin); //INICIALIZANDO OS PINOS DO SENSOR 

void setup()
{
    //DEFINE OS PINOS COMO ENTRADA OU SAÍDA
    pinMode(echoPin, INPUT);
    pinMode(trigPin, OUTPUT);
    pinMode(AltoFalante, OUTPUT);
    pinMode(vibracall, OUTPUT);
    
    //ALERTA AO USUÁRIO QUE O APARELHO INICIALIZOU
    tone(AltoFalante,500);
    digitalWrite(vibracall,HIGH);
    delay(100);
    noTone(AltoFalante);
    delay(100);
    digitalWrite(vibracall,LOW);
    tone(AltoFalante,500);
    delay(100);
    noTone(AltoFalante);
    delay(100);
}

//CALCULA A DISTÂNCIA E A FUNÇÃO RANGING FAZ A CONVERSÃO DO TEMPO DE RESPOSTA DO ECHO EM CM E ARMAZENA EM "distancia"
void sensor()
{
    digitalWrite(trigPin, LOW); //DEFINE O PINO 8 COM UM PULSO BAIXO "LOW"
    delayMicroseconds(2); // DELAY DE 2 MICROSSEGUNDOS
    digitalWrite(trigPin, HIGH); //DEFINE O PINO 8 COM PULSO ALTO "HIGH"
    delayMicroseconds(5); // DELAY DE 5 MICROSSEGUNDOS
    digitalWrite(trigPin, LOW); //DEFINE O PINO 8 COM PULSO BAIXO "LOW" NOVAMENTE
    distancia = (ultrasonic.Ranging(CM)); // VARIÁVEL RECEBE O VALOR DA DISTÂNCIA MEDIDA
    delay(5); //INTERVALO DE 5 MILISSEGUNDOS
}

void loop()
{
    sensor(); // FAZ A CHAMADA DA FUNÇÃO "sensor()"
    
    //ALERTA AO USUÁRIO SOBRE OBSTÁCULOS
    if(distancia <= 150 && distancia > 125)
    {
        tone(AltoFalante,N);
        digitalWrite(vibracall,HIGH);
        delay(400);
        noTone(AltoFalante);
        digitalWrite(vibracall,LOW);
        delay(400);
    }
    else
    {
        if(distancia <= 125 && distancia > 100)
        {
            tone(AltoFalante,N);
            digitalWrite(vibracall,HIGH);
            delay(200);
            noTone(AltoFalante);
            digitalWrite(vibracall,LOW);
            delay(200);
        }
        else
        {
            if(distancia <= 100)
            {
                tone(AltoFalante,N
                );
                digitalWrite(vibracall,HIGH);
            }
            else
            {
                noTone(AltoFalante);
                digitalWrite(vibracall,LOW);
            }
        }
    }
}
