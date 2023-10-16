#include <Wire.h>

#define DEFAULT_VAL 255
#define EXPANSOR_1 32
#define EXPANSOR_2 36
#define DELAY 500

#define LAYER_1 A0
#define LAYER_2 A1
#define LAYER_3 A2
#define LAYER_4 A3
#define LAYER_5 2

#define COLUNA_1 3
#define COLUNA_2 4
#define COLUNA_3 5
#define COLUNA_4 6
#define COLUNA_5 7
#define COLUNA_6 8
#define COLUNA_7 9
#define COLUNA_8 10
#define COLUNA_9 11
#define COLUNA_10 12
#define COLUNA_11 13

// Columns in expansor 1
#define COLUNA_12 1
#define COLUNA_13 2
#define COLUNA_14 4
#define COLUNA_15 8
#define COLUNA_16 16
#define COLUNA_17 32
#define COLUNA_18 64
#define COLUNA_19 128

// Columns in expansor 2
#define COLUNA_20 1
#define COLUNA_21 2
#define COLUNA_22 4
#define COLUNA_23 8
#define COLUNA_24 16
#define COLUNA_25 32

int signal_exp1 = DEFAULT_VAL;
int signal_exp2 = DEFAULT_VAL;

void transmissao(int address, byte val)
{
  Wire.beginTransmission(address);
  Wire.write(val);
  Wire.endTransmission();
}

void resetLayers()
{
  digitalWrite(LAYER_1, LOW);
  digitalWrite(LAYER_2, LOW);
  digitalWrite(LAYER_3, LOW);
  digitalWrite(LAYER_4, LOW);
  digitalWrite(LAYER_5, LOW);
}

void resetColumns()
{
  digitalWrite(COLUNA_1, HIGH);
  digitalWrite(COLUNA_2, HIGH);
  digitalWrite(COLUNA_3, HIGH);
  digitalWrite(COLUNA_4, HIGH);
  digitalWrite(COLUNA_5, HIGH);
  digitalWrite(COLUNA_6, HIGH);
  digitalWrite(COLUNA_7, HIGH);
  digitalWrite(COLUNA_8, HIGH);
  digitalWrite(COLUNA_9, HIGH);
  digitalWrite(COLUNA_10, HIGH);
  digitalWrite(COLUNA_11, HIGH);

  transmissao(EXPANSOR_1, DEFAULT_VAL);
  transmissao(EXPANSOR_2, DEFAULT_VAL);
}

void resetLEDs()
{
  resetLayers();
  resetColumns();
}

void setup()
{
  Serial.begin(9600);
  Wire.begin();

  pinMode(LAYER_1, OUTPUT);
  pinMode(LAYER_2, OUTPUT);
  pinMode(LAYER_3, OUTPUT);
  pinMode(LAYER_4, OUTPUT);
  pinMode(LAYER_5, OUTPUT);

  pinMode(COLUNA_1, OUTPUT);
  pinMode(COLUNA_2, OUTPUT);
  pinMode(COLUNA_3, OUTPUT);
  pinMode(COLUNA_4, OUTPUT);
  pinMode(COLUNA_5, OUTPUT);
  pinMode(COLUNA_6, OUTPUT);
  pinMode(COLUNA_7, OUTPUT);
  pinMode(COLUNA_8, OUTPUT);
  pinMode(COLUNA_9, OUTPUT);
  pinMode(COLUNA_10, OUTPUT);
  pinMode(COLUNA_11, OUTPUT);

  resetLEDs();

  delay(1000);
}

void escrevePET() {
  resetLEDs();
  signal_exp1 = DEFAULT_VAL;
  signal_exp2 = DEFAULT_VAL;

  // Writing P
  digitalWrite(COLUNA_6, LOW);
  digitalWrite(COLUNA_7, LOW);
  digitalWrite(COLUNA_8, LOW);
  digitalWrite(COLUNA_9, LOW);
  digitalWrite(COLUNA_10, LOW);
  signal_exp1 -= COLUNA_13;
  signal_exp1 -= COLUNA_15;
  signal_exp1 -= COLUNA_18;
  signal_exp1 -= COLUNA_19;
  signal_exp2 -= COLUNA_20;

  transmissao(EXPANSOR_1, signal_exp1);
  transmissao(EXPANSOR_2, signal_exp2);
  
  digitalWrite(LAYER_5, HIGH);
  delay(DELAY);
  digitalWrite(LAYER_5, LOW);
  digitalWrite(LAYER_4, HIGH);
  delay(DELAY);
  digitalWrite(LAYER_4, LOW);
  digitalWrite(LAYER_3, HIGH);
  delay(DELAY);
  digitalWrite(LAYER_3, LOW);
  digitalWrite(LAYER_2, HIGH);
  delay(DELAY);
  digitalWrite(LAYER_2, LOW);
  digitalWrite(LAYER_1, HIGH);
  delay(DELAY);
  
  resetLEDs();
  signal_exp1 = DEFAULT_VAL;
  signal_exp2 = DEFAULT_VAL;
  
  // Writing E
  digitalWrite(COLUNA_6, LOW);
  digitalWrite(COLUNA_7, LOW);
  digitalWrite(COLUNA_8, LOW);
  digitalWrite(COLUNA_9, LOW);
  digitalWrite(COLUNA_10, LOW);
  digitalWrite(COLUNA_11, LOW);
  signal_exp1 -= COLUNA_13;
  signal_exp1 -= COLUNA_15;
  signal_exp1 -= COLUNA_16;
  signal_exp1 -= COLUNA_18;
  signal_exp2 -= COLUNA_20;

  transmissao(EXPANSOR_1, signal_exp1);
  transmissao(EXPANSOR_2, signal_exp2);
  
  digitalWrite(LAYER_5, HIGH);
  delay(DELAY);
  digitalWrite(LAYER_5, LOW);
  digitalWrite(LAYER_4, HIGH);
  delay(DELAY);
  digitalWrite(LAYER_4, LOW);
  digitalWrite(LAYER_3, HIGH);
  delay(DELAY);
  digitalWrite(LAYER_3, LOW);
  digitalWrite(LAYER_2, HIGH);
  delay(DELAY);
  digitalWrite(LAYER_2, LOW);
  digitalWrite(LAYER_1, HIGH);
  delay(DELAY);

  resetLEDs();
  signal_exp1 = DEFAULT_VAL;
  signal_exp2 = DEFAULT_VAL;
  
  // Writing T
  digitalWrite(COLUNA_10, LOW);
  digitalWrite(COLUNA_11, LOW);
  signal_exp1 -= COLUNA_12;
  signal_exp1 -= COLUNA_13;
  signal_exp1 -= COLUNA_14;
  signal_exp1 -= COLUNA_15;
  signal_exp2 -= COLUNA_20;

  transmissao(EXPANSOR_1, signal_exp1);
  transmissao(EXPANSOR_2, signal_exp2);
  
  digitalWrite(LAYER_5, HIGH);
  delay(DELAY);
  digitalWrite(LAYER_5, LOW);
  digitalWrite(LAYER_4, HIGH);
  delay(DELAY);
  digitalWrite(LAYER_4, LOW);
  digitalWrite(LAYER_3, HIGH);
  delay(DELAY);
  digitalWrite(LAYER_3, LOW);
  digitalWrite(LAYER_2, HIGH);
  delay(DELAY);
  digitalWrite(LAYER_2, LOW);
  digitalWrite(LAYER_1, HIGH);
  delay(DELAY);
}

void progressaoCimaBaixo() {
  resetLEDs();
  signal_exp1 = 0;
  signal_exp2 = 0;
  
  digitalWrite(COLUNA_1, LOW);
  digitalWrite(COLUNA_2, LOW);
  digitalWrite(COLUNA_3, LOW);
  digitalWrite(COLUNA_4, LOW);
  digitalWrite(COLUNA_5, LOW);
  digitalWrite(COLUNA_6, LOW);
  digitalWrite(COLUNA_7, LOW);
  digitalWrite(COLUNA_8, LOW);
  digitalWrite(COLUNA_9, LOW);
  digitalWrite(COLUNA_10, LOW);
  digitalWrite(COLUNA_11, LOW);
  transmissao(EXPANSOR_1, signal_exp1);
  transmissao(EXPANSOR_2, signal_exp2);

  digitalWrite(LAYER_5, HIGH);
  delay(DELAY);

// ******************************************
  resetLayers();
  digitalWrite(LAYER_4, HIGH);
  delay(DELAY);
// ******************************************
  resetLayers();
  digitalWrite(LAYER_3, HIGH);
  delay(DELAY);

// ******************************************
  resetLayers();
  digitalWrite(LAYER_2, HIGH);
  delay(DELAY);

// ******************************************
  resetLayers();
  digitalWrite(LAYER_1, HIGH);
  delay(DELAY);

}

void progressaoFrenteTras() {
  resetLEDs();
  signal_exp1 = DEFAULT_VAL;
  signal_exp2 = DEFAULT_VAL;
  
  digitalWrite(LAYER_1, HIGH);
  digitalWrite(LAYER_2, HIGH);
  digitalWrite(LAYER_3, HIGH);
  digitalWrite(LAYER_4, HIGH);
  digitalWrite(LAYER_5, HIGH);

  digitalWrite(COLUNA_1, LOW);
  digitalWrite(COLUNA_6, LOW);
  digitalWrite(COLUNA_11, LOW);
  signal_exp1 -= COLUNA_16;
  signal_exp2 -= COLUNA_21;

  transmissao(EXPANSOR_1, signal_exp1);
  transmissao(EXPANSOR_2, signal_exp2);
  delay(DELAY);

// ******************************************
  resetColumns();
  signal_exp1 = DEFAULT_VAL;
  signal_exp2 = DEFAULT_VAL;

  digitalWrite(COLUNA_2, LOW);
  digitalWrite(COLUNA_7, LOW);
  signal_exp1 -= COLUNA_12;
  signal_exp1 -= COLUNA_17;
  signal_exp2 -= COLUNA_22;

  transmissao(EXPANSOR_1, signal_exp1);
  transmissao(EXPANSOR_2, signal_exp2);
  delay(DELAY);
// ******************************************
  resetColumns();
  signal_exp1 = DEFAULT_VAL;
  signal_exp2 = DEFAULT_VAL;

  digitalWrite(COLUNA_3, LOW);
  digitalWrite(COLUNA_8, LOW);
  signal_exp1 -= COLUNA_13;
  signal_exp1 -= COLUNA_18;
  signal_exp2 -= COLUNA_23;

  transmissao(EXPANSOR_1, signal_exp1);
  transmissao(EXPANSOR_2, signal_exp2);
  delay(DELAY);
// ******************************************
  resetColumns();
  signal_exp1 = DEFAULT_VAL;
  signal_exp2 = DEFAULT_VAL;

  digitalWrite(COLUNA_4, LOW);
  digitalWrite(COLUNA_9, LOW);
  signal_exp1 -= COLUNA_14;
  signal_exp1 -= COLUNA_19;
  signal_exp2 -= COLUNA_24;

  transmissao(EXPANSOR_1, signal_exp1);
  transmissao(EXPANSOR_2, signal_exp2);
  delay(DELAY);
// ******************************************
  resetColumns();
  signal_exp1 = DEFAULT_VAL;
  signal_exp2 = DEFAULT_VAL;

  digitalWrite(COLUNA_5, LOW);
  digitalWrite(COLUNA_10, LOW);
  signal_exp1 -= COLUNA_15;
  signal_exp2 -= COLUNA_20;
  signal_exp2 -= COLUNA_25;

  transmissao(EXPANSOR_1, signal_exp1);
  transmissao(EXPANSOR_2, signal_exp2);
  delay(DELAY);
}

void progressaoTrasFrente() {
  resetLEDs();
  signal_exp1 = DEFAULT_VAL;
  signal_exp2 = DEFAULT_VAL;
  
  digitalWrite(LAYER_1, HIGH);
  digitalWrite(LAYER_2, HIGH);
  digitalWrite(LAYER_3, HIGH);
  digitalWrite(LAYER_4, HIGH);
  digitalWrite(LAYER_5, HIGH);

  digitalWrite(COLUNA_5, LOW);
  digitalWrite(COLUNA_10, LOW);
  signal_exp1 -= COLUNA_15;
  signal_exp2 -= COLUNA_20;
  signal_exp2 -= COLUNA_25;

  transmissao(EXPANSOR_1, signal_exp1);
  transmissao(EXPANSOR_2, signal_exp2);
  delay(DELAY);

// ******************************************
  resetColumns();
  signal_exp1 = DEFAULT_VAL;
  signal_exp2 = DEFAULT_VAL;

  digitalWrite(COLUNA_4, LOW);
  digitalWrite(COLUNA_9, LOW);
  signal_exp1 -= COLUNA_14;
  signal_exp1 -= COLUNA_19;
  signal_exp2 -= COLUNA_24;

  transmissao(EXPANSOR_1, signal_exp1);
  transmissao(EXPANSOR_2, signal_exp2);
  delay(DELAY);
// ******************************************
  resetColumns();
  signal_exp1 = DEFAULT_VAL;
  signal_exp2 = DEFAULT_VAL;

  digitalWrite(COLUNA_3, LOW);
  digitalWrite(COLUNA_8, LOW);
  signal_exp1 -= COLUNA_13;
  signal_exp1 -= COLUNA_18;
  signal_exp2 -= COLUNA_23;

  transmissao(EXPANSOR_1, signal_exp1);
  transmissao(EXPANSOR_2, signal_exp2);
  delay(DELAY);
// ******************************************
  resetColumns();
  signal_exp1 = DEFAULT_VAL;
  signal_exp2 = DEFAULT_VAL;

  digitalWrite(COLUNA_2, LOW);
  digitalWrite(COLUNA_7, LOW);
  signal_exp1 -= COLUNA_12;
  signal_exp1 -= COLUNA_17;
  signal_exp2 -= COLUNA_22;

  transmissao(EXPANSOR_1, signal_exp1);
  transmissao(EXPANSOR_2, signal_exp2);
  delay(DELAY);
// ******************************************
  resetColumns();
  signal_exp1 = DEFAULT_VAL;
  signal_exp2 = DEFAULT_VAL;

  digitalWrite(COLUNA_1, LOW);
  digitalWrite(COLUNA_6, LOW);
  digitalWrite(COLUNA_11, LOW);
  signal_exp1 -= COLUNA_16;
  signal_exp2 -= COLUNA_21;

  transmissao(EXPANSOR_1, signal_exp1);
  transmissao(EXPANSOR_2, signal_exp2);
  delay(DELAY);
}

void progressaoDireitaEsquerda() {
  resetLEDs();
  signal_exp1 = DEFAULT_VAL;
  signal_exp2 = DEFAULT_VAL;
  
  digitalWrite(LAYER_1, HIGH);
  digitalWrite(LAYER_2, HIGH);
  digitalWrite(LAYER_3, HIGH);
  digitalWrite(LAYER_4, HIGH);
  digitalWrite(LAYER_5, HIGH);

  signal_exp2 -= COLUNA_21;
  signal_exp2 -= COLUNA_22;
  signal_exp2 -= COLUNA_23;
  signal_exp2 -= COLUNA_24;
  signal_exp2 -= COLUNA_25;

  transmissao(EXPANSOR_1, signal_exp1);
  transmissao(EXPANSOR_2, signal_exp2);
  delay(DELAY);

// ******************************************
  resetColumns();
  signal_exp1 = DEFAULT_VAL;
  signal_exp2 = DEFAULT_VAL;

  signal_exp1 -= COLUNA_16;
  signal_exp1 -= COLUNA_17;
  signal_exp1 -= COLUNA_18;
  signal_exp1 -= COLUNA_19;
  signal_exp2 -= COLUNA_20;

  transmissao(EXPANSOR_1, signal_exp1);
  transmissao(EXPANSOR_2, signal_exp2);
  delay(DELAY);
// ******************************************
  resetColumns();
  signal_exp1 = DEFAULT_VAL;
  signal_exp2 = DEFAULT_VAL;

  digitalWrite(COLUNA_10, LOW);
  digitalWrite(COLUNA_11, LOW);
  signal_exp1 -= COLUNA_12;
  signal_exp1 -= COLUNA_14;
  signal_exp1 -= COLUNA_15;

  transmissao(EXPANSOR_1, signal_exp1);
  transmissao(EXPANSOR_2, signal_exp2);
  delay(DELAY);
// ******************************************
  resetColumns();
  signal_exp1 = DEFAULT_VAL;
  signal_exp2 = DEFAULT_VAL;

  digitalWrite(COLUNA_6, LOW);
  digitalWrite(COLUNA_7, LOW);
  digitalWrite(COLUNA_8, LOW);
  digitalWrite(COLUNA_9, LOW);
  digitalWrite(COLUNA_10, LOW);

  transmissao(EXPANSOR_1, signal_exp1);
  transmissao(EXPANSOR_2, signal_exp2);
  delay(DELAY);
// ******************************************
  resetColumns();
  signal_exp1 = DEFAULT_VAL;
  signal_exp2 = DEFAULT_VAL;

  digitalWrite(COLUNA_1, LOW);
  digitalWrite(COLUNA_2, LOW);
  digitalWrite(COLUNA_3, LOW);
  digitalWrite(COLUNA_4, LOW);
  digitalWrite(COLUNA_5, LOW);

  transmissao(EXPANSOR_1, signal_exp1);
  transmissao(EXPANSOR_2, signal_exp2);
  delay(DELAY);
}

void progressaoEsquerdaDireita() {
  resetLEDs();
  signal_exp1 = DEFAULT_VAL;
  signal_exp2 = DEFAULT_VAL;
  
  digitalWrite(LAYER_1, HIGH);
  digitalWrite(LAYER_2, HIGH);
  digitalWrite(LAYER_3, HIGH);
  digitalWrite(LAYER_4, HIGH);
  digitalWrite(LAYER_5, HIGH);

  digitalWrite(COLUNA_1, LOW);
  digitalWrite(COLUNA_2, LOW);
  digitalWrite(COLUNA_3, LOW);
  digitalWrite(COLUNA_4, LOW);
  digitalWrite(COLUNA_5, LOW);

  transmissao(EXPANSOR_1, signal_exp1);
  transmissao(EXPANSOR_2, signal_exp2);
  delay(DELAY);

// ******************************************
  resetColumns();
  signal_exp1 = DEFAULT_VAL;
  signal_exp2 = DEFAULT_VAL;

  digitalWrite(COLUNA_6, LOW);
  digitalWrite(COLUNA_7, LOW);
  digitalWrite(COLUNA_8, LOW);
  digitalWrite(COLUNA_9, LOW);
  digitalWrite(COLUNA_10, LOW);

  transmissao(EXPANSOR_1, signal_exp1);
  transmissao(EXPANSOR_2, signal_exp2);
  delay(DELAY);
// ******************************************
  resetColumns();
  signal_exp1 = DEFAULT_VAL;
  signal_exp2 = DEFAULT_VAL;

  digitalWrite(COLUNA_10, LOW);
  digitalWrite(COLUNA_11, LOW);
  signal_exp1 -= COLUNA_12;
  signal_exp1 -= COLUNA_14;
  signal_exp1 -= COLUNA_15;

  transmissao(EXPANSOR_1, signal_exp1);
  transmissao(EXPANSOR_2, signal_exp2);
  delay(DELAY);
// ******************************************
  resetColumns();
  signal_exp1 = DEFAULT_VAL;
  signal_exp2 = DEFAULT_VAL;

  signal_exp1 -= COLUNA_16;
  signal_exp1 -= COLUNA_17;
  signal_exp1 -= COLUNA_18;
  signal_exp1 -= COLUNA_19;
  signal_exp2 -= COLUNA_20;

  transmissao(EXPANSOR_1, signal_exp1);
  transmissao(EXPANSOR_2, signal_exp2);
  delay(DELAY);
// ******************************************
  resetColumns();
  signal_exp1 = DEFAULT_VAL;
  signal_exp2 = DEFAULT_VAL;

  signal_exp2 -= COLUNA_21;
  signal_exp2 -= COLUNA_22;
  signal_exp2 -= COLUNA_23;
  signal_exp2 -= COLUNA_24;
  signal_exp2 -= COLUNA_25;

  transmissao(EXPANSOR_1, signal_exp1);
  transmissao(EXPANSOR_2, signal_exp2);
  delay(DELAY);
}

void rotacaoExternaHorario()
{
  resetLEDs();
  signal_exp1 = DEFAULT_VAL;
  signal_exp2 = DEFAULT_VAL;
  
  digitalWrite(LAYER_1, HIGH);
  digitalWrite(LAYER_2, HIGH);
  digitalWrite(LAYER_3, HIGH);
  digitalWrite(LAYER_4, HIGH);
  digitalWrite(LAYER_5, HIGH);

  digitalWrite(COLUNA_1, LOW);
  signal_exp2 -= COLUNA_25;

  transmissao(EXPANSOR_1, signal_exp1);
  transmissao(EXPANSOR_2, signal_exp2);
  delay(DELAY);
  // ******************************************
  resetColumns();
  signal_exp1 = DEFAULT_VAL;
  signal_exp2 = DEFAULT_VAL;

  digitalWrite(COLUNA_6, LOW);
  signal_exp2 -= COLUNA_20;

  transmissao(EXPANSOR_1, signal_exp1);
  transmissao(EXPANSOR_2, signal_exp2);
  delay(DELAY);
  // ******************************************
  resetColumns();
  signal_exp1 = DEFAULT_VAL;
  signal_exp2 = DEFAULT_VAL;

  digitalWrite(COLUNA_11, LOW);
  signal_exp1 -= COLUNA_15;

  transmissao(EXPANSOR_1, signal_exp1);
  transmissao(EXPANSOR_2, signal_exp2);
  delay(DELAY);
  // ******************************************
  resetColumns();
  signal_exp1 = DEFAULT_VAL;
  signal_exp2 = DEFAULT_VAL;
  
  digitalWrite(COLUNA_10, LOW);
  signal_exp1 -= COLUNA_16;

  transmissao(EXPANSOR_1, signal_exp1);
  transmissao(EXPANSOR_2, signal_exp2);
  delay(DELAY);
  // ******************************************
  resetColumns();
  signal_exp1 = DEFAULT_VAL;
  signal_exp2 = DEFAULT_VAL;
  
  digitalWrite(COLUNA_5, LOW);
  signal_exp2 -= COLUNA_21;

  transmissao(EXPANSOR_1, signal_exp1);
  transmissao(EXPANSOR_2, signal_exp2);
  delay(DELAY);
  // ******************************************
  resetColumns();
  signal_exp1 = DEFAULT_VAL;
  signal_exp2 = DEFAULT_VAL;
  
  digitalWrite(COLUNA_4, LOW);
  signal_exp2 -= COLUNA_22;

  transmissao(EXPANSOR_1, signal_exp1);
  transmissao(EXPANSOR_2, signal_exp2);
  delay(DELAY);
  // ******************************************
  resetColumns();
  signal_exp1 = DEFAULT_VAL;
  signal_exp2 = DEFAULT_VAL;
  
  digitalWrite(COLUNA_3, LOW);
  signal_exp2 -= COLUNA_23;

  transmissao(EXPANSOR_1, signal_exp1);
  transmissao(EXPANSOR_2, signal_exp2);
  delay(DELAY);
  // ******************************************
  resetColumns();
  signal_exp1 = DEFAULT_VAL;
  signal_exp2 = DEFAULT_VAL;
  
  digitalWrite(COLUNA_2, LOW);
  signal_exp2 -= COLUNA_24;

  transmissao(EXPANSOR_1, signal_exp1);
  transmissao(EXPANSOR_2, signal_exp2);
  delay(DELAY);
  // ******************************************
  resetColumns();
  signal_exp1 = DEFAULT_VAL;
  signal_exp2 = DEFAULT_VAL;

  digitalWrite(COLUNA_1, LOW);
  signal_exp2 -= COLUNA_25;

  transmissao(EXPANSOR_1, signal_exp1);
  transmissao(EXPANSOR_2, signal_exp2);
  delay(DELAY);
  // ******************************************
  resetColumns();
  signal_exp1 = DEFAULT_VAL;
  signal_exp2 = DEFAULT_VAL;

  digitalWrite(COLUNA_6, LOW);
  signal_exp2 -= COLUNA_20;

  transmissao(EXPANSOR_1, signal_exp1);
  transmissao(EXPANSOR_2, signal_exp2);
  delay(DELAY);
  // ******************************************
  resetColumns();
  signal_exp1 = DEFAULT_VAL;
  signal_exp2 = DEFAULT_VAL;

  digitalWrite(COLUNA_11, LOW);
  signal_exp1 -= COLUNA_15;

  transmissao(EXPANSOR_1, signal_exp1);
  transmissao(EXPANSOR_2, signal_exp2);
  delay(DELAY);
  // ******************************************
  resetColumns();
  signal_exp1 = DEFAULT_VAL;
  signal_exp2 = DEFAULT_VAL;
  
  digitalWrite(COLUNA_10, LOW);
  signal_exp1 -= COLUNA_16;

  transmissao(EXPANSOR_1, signal_exp1);
  transmissao(EXPANSOR_2, signal_exp2);
  delay(DELAY);
  // ******************************************
  resetColumns();
  signal_exp1 = DEFAULT_VAL;
  signal_exp2 = DEFAULT_VAL;
  
  digitalWrite(COLUNA_5, LOW);
  signal_exp2 -= COLUNA_21;

  transmissao(EXPANSOR_1, signal_exp1);
  transmissao(EXPANSOR_2, signal_exp2);
  delay(DELAY);
  // ******************************************
  resetColumns();
  signal_exp1 = DEFAULT_VAL;
  signal_exp2 = DEFAULT_VAL;
  
  digitalWrite(COLUNA_4, LOW);
  signal_exp2 -= COLUNA_22;

  transmissao(EXPANSOR_1, signal_exp1);
  transmissao(EXPANSOR_2, signal_exp2);
  delay(DELAY);
  // ******************************************
  resetColumns();
  signal_exp1 = DEFAULT_VAL;
  signal_exp2 = DEFAULT_VAL;
  
  digitalWrite(COLUNA_3, LOW);
  signal_exp2 -= COLUNA_23;

  transmissao(EXPANSOR_1, signal_exp1);
  transmissao(EXPANSOR_2, signal_exp2);
  delay(DELAY);
  // ******************************************
  resetColumns();
  signal_exp1 = DEFAULT_VAL;
  signal_exp2 = DEFAULT_VAL;
  
  digitalWrite(COLUNA_2, LOW);
  signal_exp2 -= COLUNA_24;

  transmissao(EXPANSOR_1, signal_exp1);
  transmissao(EXPANSOR_2, signal_exp2);
  delay(DELAY);
}

void rotacaoExternaAntiHorario()
{
  resetLEDs();
  signal_exp1 = DEFAULT_VAL;
  signal_exp2 = DEFAULT_VAL;
  
  digitalWrite(LAYER_1, HIGH);
  digitalWrite(LAYER_2, HIGH);
  digitalWrite(LAYER_3, HIGH);
  digitalWrite(LAYER_4, HIGH);
  digitalWrite(LAYER_5, HIGH);

  digitalWrite(COLUNA_1, LOW);
  signal_exp2 -= COLUNA_25;

  transmissao(EXPANSOR_1, signal_exp1);
  transmissao(EXPANSOR_2, signal_exp2);
  delay(DELAY);
  // ******************************************
  resetColumns();
  signal_exp1 = DEFAULT_VAL;
  signal_exp2 = DEFAULT_VAL;
  
  digitalWrite(COLUNA_2, LOW);
  signal_exp2 -= COLUNA_24;

  transmissao(EXPANSOR_1, signal_exp1);
  transmissao(EXPANSOR_2, signal_exp2);
  delay(DELAY);
  // ******************************************
  resetColumns();
  signal_exp1 = DEFAULT_VAL;
  signal_exp2 = DEFAULT_VAL;
  
  digitalWrite(COLUNA_3, LOW);
  signal_exp2 -= COLUNA_23;

  transmissao(EXPANSOR_1, signal_exp1);
  transmissao(EXPANSOR_2, signal_exp2);
  delay(DELAY);
  // ******************************************
  resetColumns();
  signal_exp1 = DEFAULT_VAL;
  signal_exp2 = DEFAULT_VAL;
  
  digitalWrite(COLUNA_4, LOW);
  signal_exp2 -= COLUNA_22;

  transmissao(EXPANSOR_1, signal_exp1);
  transmissao(EXPANSOR_2, signal_exp2);
  delay(DELAY);
  
  // ******************************************
  resetColumns();
  signal_exp1 = DEFAULT_VAL;
  signal_exp2 = DEFAULT_VAL;
  
  digitalWrite(COLUNA_5, LOW);
  signal_exp2 -= COLUNA_21;

  transmissao(EXPANSOR_1, signal_exp1);
  transmissao(EXPANSOR_2, signal_exp2);
  delay(DELAY);
  // ******************************************
  resetColumns();
  signal_exp1 = DEFAULT_VAL;
  signal_exp2 = DEFAULT_VAL;
  
  digitalWrite(COLUNA_10, LOW);
  signal_exp1 -= COLUNA_16;

  transmissao(EXPANSOR_1, signal_exp1);
  transmissao(EXPANSOR_2, signal_exp2);
  delay(DELAY);
  // ******************************************
  resetColumns();
  signal_exp1 = DEFAULT_VAL;
  signal_exp2 = DEFAULT_VAL;

  digitalWrite(COLUNA_11, LOW);
  signal_exp1 -= COLUNA_15;

  transmissao(EXPANSOR_1, signal_exp1);
  transmissao(EXPANSOR_2, signal_exp2);
  delay(DELAY);
  // ******************************************
  resetColumns();
  signal_exp1 = DEFAULT_VAL;
  signal_exp2 = DEFAULT_VAL;

  digitalWrite(COLUNA_6, LOW);
  signal_exp2 -= COLUNA_20;

  transmissao(EXPANSOR_1, signal_exp1);
  transmissao(EXPANSOR_2, signal_exp2);
  delay(DELAY);
  // ******************************************
  resetColumns();
  signal_exp1 = DEFAULT_VAL;
  signal_exp2 = DEFAULT_VAL;

  digitalWrite(COLUNA_1, LOW);
  signal_exp2 -= COLUNA_25;

  transmissao(EXPANSOR_1, signal_exp1);
  transmissao(EXPANSOR_2, signal_exp2);
  delay(DELAY);
  // ******************************************
  resetColumns();
  signal_exp1 = DEFAULT_VAL;
  signal_exp2 = DEFAULT_VAL;
  
  digitalWrite(COLUNA_2, LOW);
  signal_exp2 -= COLUNA_24;

  transmissao(EXPANSOR_1, signal_exp1);
  transmissao(EXPANSOR_2, signal_exp2);
  delay(DELAY);
  // ******************************************
  resetColumns();
  signal_exp1 = DEFAULT_VAL;
  signal_exp2 = DEFAULT_VAL;
  
  digitalWrite(COLUNA_3, LOW);
  signal_exp2 -= COLUNA_23;

  transmissao(EXPANSOR_1, signal_exp1);
  transmissao(EXPANSOR_2, signal_exp2);
  delay(DELAY);
  // ******************************************
  resetColumns();
  signal_exp1 = DEFAULT_VAL;
  signal_exp2 = DEFAULT_VAL;
  
  digitalWrite(COLUNA_4, LOW);
  signal_exp2 -= COLUNA_22;

  transmissao(EXPANSOR_1, signal_exp1);
  transmissao(EXPANSOR_2, signal_exp2);
  delay(DELAY);
  
  // ******************************************
  resetColumns();
  signal_exp1 = DEFAULT_VAL;
  signal_exp2 = DEFAULT_VAL;
  
  digitalWrite(COLUNA_5, LOW);
  signal_exp2 -= COLUNA_21;

  transmissao(EXPANSOR_1, signal_exp1);
  transmissao(EXPANSOR_2, signal_exp2);
  delay(DELAY);
  // ******************************************
  resetColumns();
  signal_exp1 = DEFAULT_VAL;
  signal_exp2 = DEFAULT_VAL;
  
  digitalWrite(COLUNA_10, LOW);
  signal_exp1 -= COLUNA_16;

  transmissao(EXPANSOR_1, signal_exp1);
  transmissao(EXPANSOR_2, signal_exp2);
  delay(DELAY);
  // ******************************************
  resetColumns();
  signal_exp1 = DEFAULT_VAL;
  signal_exp2 = DEFAULT_VAL;

  digitalWrite(COLUNA_11, LOW);
  signal_exp1 -= COLUNA_15;

  transmissao(EXPANSOR_1, signal_exp1);
  transmissao(EXPANSOR_2, signal_exp2);
  delay(DELAY);
  // ******************************************
  resetColumns();
  signal_exp1 = DEFAULT_VAL;
  signal_exp2 = DEFAULT_VAL;

  digitalWrite(COLUNA_6, LOW);
  signal_exp2 -= COLUNA_20;

  transmissao(EXPANSOR_1, signal_exp1);
  transmissao(EXPANSOR_2, signal_exp2);
  delay(DELAY);
}

void loop()
{
  //progressaoFrenteTras();
  //progressaoTrasFrente();
  //rotacaoExternaHorario();
  //rotacaoExternaAntiHorario();
  //progressaoCimaBaixo();
  //progressaoDireitaEsquerda();
  //progressaoEsquerdaDireita();
  escrevePET();
}
