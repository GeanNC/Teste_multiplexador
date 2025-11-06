#define POT_PIN 0 //POT_PIN está na porta 0 de um dos canais (X0 ou Y0)
#define POT_2_PIN 2 //POT_2_PIN está na porta 2 de um dos canais (X2 ou Y2)
#define LDR_PIN 3 //LDR_PIN está na porta 3 de um dos canais (X3 ou Y3)

const int pinos_selecao_canal[] = {D2, D1}; // vetor representa os pinos de seleção do canal no multiplexaador.

void iniciar_pinos() // Esta função coloca as portas digitais para controlar os pinos A e B do multiplexador.
{
  for(int i = 0; i < 2; i++) 
  {
    pinMode(pinos_selecao_canal[i], OUTPUT);
  }
}

void ativa_porta_analog(int porta) // Esta função abre a porta do multiplexador que desejamos. E definimos as constantes no inicio do programa
{
  if(porta == POT_PIN) // De acordo com a tabela de portas do 74HC4052, a porta 0 (pot) é aberta com o pino A = 0 e o pino B = 0.
  {
      digitalWrite(pinos_selecao_canal[0], 0);
      digitalWrite(pinos_selecao_canal[1], 0);
  }
  else if(porta == POT_2_PIN) // De acordo com a tabela de portas do 74HC4052, a porta 2 (pot_2) é aberta com o pino A = 0 e o pino B = 1.
  {
      digitalWrite(pinos_selecao_canal[0], 0);
      digitalWrite(pinos_selecao_canal[1], 1);

  } 
  else // De acordo com a tabela de portas do 74HC4052, a porta 3 (ldr) é aberta com o pino A = 1 e o pino B = 1.
  {
      digitalWrite(pinos_selecao_canal[0], 1);
      digitalWrite(pinos_selecao_canal[1], 1);
  }
}

void setup() 
{
  Serial.begin(9600);
  iniciar_pinos();
}

void loop() 
{
  ativa_porta_analog(POT_2_PIN); // Potenciometro 2
  int pot_2 = analogRead(A0);
  
  ativa_porta_analog(LDR_PIN); // LDR
  int luz = analogRead(A0);
  
  ativa_porta_analog(POT_PIN); // Potenciometro
  int pot = analogRead(A0);

  Serial.print("Pot 2: ");
  Serial.print(pot_2);
  Serial.print("\tLuz: ");
  Serial.println(luz);
  Serial.print("\tPot: ");
  Serial.println(pot);

  delay(500);
}