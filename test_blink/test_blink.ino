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
int DIGIT_DELAY = 5;

int count = 9123;
int clock_ms = 0;

int digit3 = 21;
int digit1 = 16;
int digit2 = 0;
int digit0 = 22;
int digit[] = {digit0,digit1,digit2,digit3};
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
int seg[7] = {segA,segB,segC,segD,segE,segF,segG};
int one[7] = {1,0,0,1,1,1,1};
int two[7] = {0,0,1,0,0,1,0};
int three[7] = {0,0,0,0,1,1,0};
int four[7] = {1,0,0,1,1,0,0};
int five[7] = {0,1,0,0,1,0,0};
int six[7] = {0,1,0,0,0,0,0};
int seven[7] = {0,0,0,1,1,1,1};
int eight[7] = {0,0,0,0,0,0,0};
int nine[7] = {0,0,0,0,1,0,0};
int zero[7] = {0,0,0,0,0,0,1};
int exe[7] = {1,0,0,1,0,0,0};
int nothing[7] = {1,1,1,1,1,1,1};

int numbers[10][7] = {
  {0,0,0,0,0,0,1}, // zero
  {1,0,0,1,1,1,1}, // one
  {0,0,1,0,0,1,0}, // two
  {0,0,0,0,1,1,0}, // three
  {1,0,0,1,1,0,0}, // four
  {0,1,0,0,1,0,0}, // five
  {0,1,0,0,0,0,0}, // six
  {0,0,0,1,1,1,1}, // seven
  {0,0,0,0,0,0,0}, // eight
  {0,0,0,0,1,0,0}, // nine
  };


struct Decompo {
  int nb_elem;
  int m[4];
};

Decompo tab = {1,{0,0,0,0}};


void setup()
{
  // Set LED as output
  pinMode(digit0, OUTPUT);
  pinMode(digit1, OUTPUT);
  pinMode(digit2, OUTPUT);
  pinMode(digit3, OUTPUT);
  pinMode(led, OUTPUT);
  for (int i = 0; i<7; i++){ pinMode(seg[i], OUTPUT);};
  for (int i = 0; i<7; i++){ digitalWrite(seg[i], exe[i]);};
  digitalWrite(digit0, LOW);
  digitalWrite(digit1, LOW);
  digitalWrite(digit2, LOW);
  digitalWrite(digit3, LOW);
  // Serial monitor setup
  Serial.begin(115200);
}


Decompo division(int n, Decompo tab){
  if(n/1000 != 0){
    tab.nb_elem = 4;
    tab.m[3] = n/1000;
    tab.m[2] = (n - 1000*tab.m[3])/100;
    tab.m[1] = (n - 1000*tab.m[3] - 100*tab.m[2])/10;
    tab.m[0] = n%10;
  }else if(n/100 != 0){
    tab.nb_elem = 3;
    tab.m[2] = n/100;
    tab.m[1] = (n - 1000*tab.m[3] - 100*tab.m[2])/10;
    tab.m[0] = n%10;
  }else if(n/10 != 0){
    tab.nb_elem = 2;
    tab.m[1] = n/10;
    tab.m[0] = n%10;
  }else{
    tab.m[0] = n%10;
    tab.nb_elem = 1;
  }
  return tab;
  }

int afficher(int n, Decompo tab, int clock){
tab = division(n,tab);

//update the display
for (int i =0; i<=tab.nb_elem ; i++){ //for each digit
  for (int j = 0; j<7; j++){
      digitalWrite(seg[j], numbers[tab.m[i]][j]); //light the correct segment
     };
  digitalWrite(digit[i], HIGH); // display the number
  delay(DIGIT_DELAY);
  clock += DIGIT_DELAY;
  digitalWrite(digit[i], LOW);
}
// Serial.print(" m[0]= ");
// Serial.print(tab.m[0]);
// Serial.print(" m[1]= ");
// Serial.print(tab.m[1]);
// Serial.print(" m[2]= ");
// Serial.print(tab.m[2]);
// Serial.print(" m[3]= ");
// Serial.println(tab.m[3]);
return clock;

}



void loop()
{
  while(clock_ms <= 10000){ 
    clock_ms += afficher(count,tab,clock_ms);
  }
  count += 1;
  clock_ms = 0;


  // for (int i = 0; i<7; i++){ digitalWrite(seg[i], one[i]);};
  // delay(DELAY);
  // for (int i = 0; i<7; i++){ digitalWrite(seg[i], two[i]);};
  // delay(DELAY);
  // for (int i = 0; i<7; i++){ digitalWrite(seg[i], three[i]);};
  // delay(DELAY);
  // for (int i = 0; i<7; i++){ digitalWrite(seg[i], four[i]);};
  // delay(DELAY);
  // for (int i = 0; i<7; i++){ digitalWrite(seg[i], five[i]);};
  // delay(DELAY);
  // for (int i = 0; i<7; i++){ digitalWrite(seg[i], six[i]);};
  // delay(DELAY);
  // for (int i = 0; i<7; i++){ digitalWrite(seg[i], seven[i]);};
  // delay(DELAY);
  // for (int i = 0; i<7; i++){ digitalWrite(seg[i], eight[i]);};
  // delay(DELAY);
  // for (int i = 0; i<7; i++){ digitalWrite(seg[i], nine[i]);};
  // delay(DELAY);
  // for (int i = 0; i<7; i++){ digitalWrite(seg[i], zero[i]);};
  // delay(DELAY);
  // for (int i = 0; i<7; i++){ digitalWrite(seg[i], exe[i]);};
  // Serial.println("un_tour");
  // delay(DELAY);
   
}
