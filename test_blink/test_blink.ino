 /*ESP32 Blink
  esp32-blink.ino
  Rewrite of classic Blink sketch for ESP32
  Use LED on GPIO2   
  DroneBot Workshop 2020
  https://dronebotworkshop.com
*/
 
// LED is on GPIO2
// int digit1 = 21;

int DELAY = 700;

int digit1 = 21;
int digit2 = 16;
int digit3 = 0;
int digit4 = 22;
// int digit4 = 34;
int led = 2;
int segA = 19;
int segB = 15;
int segC = 27;
int segD = 25;
int segE = 32;
int segF = 14;
int segG = 12;
// int segPoint = 8;
int LEDs[] = {segA,segB,segC,segD,segE,segF,segG};
int one[] = {1,0,0,1,1,1,1};
int two[] = {0,0,1,0,0,1,0};
int three[] = {0,0,0,0,1,1,0};
int four[] = {1,0,0,1,1,0,0};
int five[] = {0,1,0,0,1,0,0};
int six[] = {0,1,0,0,0,0,0};
int seven[] = {0,0,0,1,1,1,1};
int eight[] = {0,0,0,0,0,0,0};
int nine[] = {0,0,0,1,1,0,0};
int zero[] = {0,0,0,0,0,0,1};
int exe[] = {1,0,0,1,0,0,0};


typedef struct {
  int nb_elem;
  int *m;
} Decompo;

Decompo* initDecompo(){
  Decompo *decomp;
  // (*decomp).nb_elem = int malloc(sizeof(int));
  (*decomp).nb_elem = 1;
  (*decomp).m = (int*)calloc(4,sizeof(int));
  return decomp;
}

void setup()
{
  // Set LED as output
  pinMode(digit1, OUTPUT);
  pinMode(digit2, OUTPUT);
  pinMode(digit3, OUTPUT);
  pinMode(digit4, OUTPUT);
  pinMode(led, OUTPUT);
  for (int i = 0; i<7; i++) pinMode(LEDs[i], OUTPUT);
  digitalWrite(digit1, HIGH);
  digitalWrite(digit2, HIGH);
  digitalWrite(digit3, HIGH);
  digitalWrite(digit4, HIGH);
  // Serial monitor setup
  Serial.begin(115200);
  Decompo* tab = initDecompo();
}


void division(int n, Decompo* tab){
  if(n/1000 != 0){
    (*tab).nb_elem = 4;
    (*tab).m[0] = n/1000;
    (*tab).m[1] = n/100;
    (*tab).m[2] = n/10;
    (*tab).m[3] = n%10;
  }else if(n/100 != 0){
    (*tab).nb_elem = 3;
    (*tab).m[1] = n/100;
    (*tab).m[2] = n/10;
    (*tab).m[3] = n%10;
  }else if(n/10 != 0){
    (*tab).nb_elem = 2;
    (*tab).m[2] = n/10;
    (*tab).m[3] = n%10;
  }else{
    (*tab).m[3] = n%10;
  }
  }

void afficher(int n, Decompo* tab){
division(n,tab);
/*
Update the display
*/

}



void loop()
{
  // digitalWrite(led, HIGH);
  for (int i = 0; i<7; i++){ digitalWrite(LEDs[i], one[i]);};
  delay(DELAY);
  for (int i = 0; i<7; i++){ digitalWrite(LEDs[i], two[i]);};
  delay(DELAY);
  // digitalWrite(led, LOW);
  for (int i = 0; i<7; i++){ digitalWrite(LEDs[i], three[i]);};
  delay(DELAY);
  for (int i = 0; i<7; i++){ digitalWrite(LEDs[i], four[i]);};
  delay(DELAY);
  for (int i = 0; i<7; i++){ digitalWrite(LEDs[i], five[i]);};
  delay(DELAY);
  for (int i = 0; i<7; i++){ digitalWrite(LEDs[i], six[i]);};
  delay(DELAY);
  for (int i = 0; i<7; i++){ digitalWrite(LEDs[i], seven[i]);};
  delay(DELAY);
  for (int i = 0; i<7; i++){ digitalWrite(LEDs[i], eight[i]);};
  delay(DELAY);
  for (int i = 0; i<7; i++){ digitalWrite(LEDs[i], nine[i]);};
  delay(DELAY);
  for (int i = 0; i<7; i++){ digitalWrite(LEDs[i], zero[i]);};
  delay(DELAY);
  for (int i = 0; i<7; i++){ digitalWrite(LEDs[i], exe[i]);};
  Serial.println("un_tour");
  delay(DELAY);
   
}
