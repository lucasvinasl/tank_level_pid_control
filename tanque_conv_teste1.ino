// Definindo os pinos dos sensores e da bomba
#define Sensor1 A9  //alto
#define Sensor2 A8  //baixo
#define Bomba 11


// iniciando as variávels
int sP = 0; // setpoint
int cont = 0; // contador de ciclos
float VS1 = 0, VS2 = 0; // armazenamento do sensor
int Alt_Max = 26; // limite máximo
int Alt_Estab = 25; // chave para limite máximo
float alttanque1 = 0; // leitura do tanque 1
float alttanque2 = 0; // leitura do tanque 2
float kp = 7.5, ki = 0.0125, kd =19;

float P = 0, I = 0, D = 0, PID = 0;
float erro = 0, erro_soma, erro_dif = 0, erro_ant = 0;

//incializando o programa
void setup() {

Serial.begin(9600);
pinMode(Bomba, OUTPUT);
}

void loop() {

// faz a leitura dos sensores, armazena os valores e faz a média dos valores armazenados
float saida1;
float VS1 = 0;

float saida2;
float VS2 = 0;

for(int i = 1; i < 300; i++){
  saida1 = analogRead(Sensor1);
  VS1 = VS1 + saida1;
  saida2 = analogRead(Sensor2);
  VS2 = VS2 + saida2;
  
}
VS1 = VS1/300;
VS2 = VS2/300;

//iniciando os ciclos
cont += 1; //incrementa 1

if (cont <= 3000) {
sP = 10;
Serial.print("  Over: ");
Serial.print("1.50");
Serial.print("  Limite +-: ");
Serial.print("0.50");
}

else if (cont <= 4500) {
sP = 5;
Serial.print("  Over: ");
Serial.print("0.80");
Serial.print("  Limite +-: ");
Serial.print("0.30");
}

else if (cont <= 6000) {
sP = 18;
Serial.print("  Over: ");
Serial.print("1.95");
Serial.print("  Limite +-: ");
Serial.print("0.90");
}

else if (cont <= 7500) {
sP = 15;
Serial.print("  Over: ");
Serial.print("0.50");
Serial.print("  Limite +-: ");
Serial.print("0.8");
}else {
  cont = 0;
}

//alttanque2 = (0.03499 * VS2 - 0.9441);
//alttanque1 = 0.0342*VS1 + 0.3511;

alttanque2 = 0.0317*VS2 - 0.8325;
alttanque1 = 0.0324*VS1 + 0.4439;

erro = sP - alttanque2;
erro_soma = erro_soma + erro;
erro_dif = erro - erro_ant;
erro_ant = erro;
P = erro * kp;
I = erro_soma * ki;
D = erro_dif * kd;
PID = P + I + D;

if (PID < 0) {
PID = 0;
}
if (PID > 200) {
PID = 200;
}
if (alttanque1 > Alt_Max || alttanque2 > Alt_Max) {
PID = 100;
}
analogWrite(Bomba, PID);
// Monitor Serial
Serial.print("--- ");
Serial.print("ALT2: ");
Serial.print(alttanque2);
Serial.print("\t");
Serial.print("--- ");
Serial.print("SP: ");
Serial.print(sP);
Serial.print("\t");
Serial.print("--- ");
Serial.print("MV: ");
Serial.print(PID * 5 / 255);
Serial.print("\t");
Serial.print(" --- ");
Serial.print("CONTADOR: ");
Serial.print(cont);
Serial.println();
}
