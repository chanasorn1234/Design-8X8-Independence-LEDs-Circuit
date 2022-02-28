int ground[8] ={22,24,26,28,30,32,34,36};
int led[8] = {2,3,4,5,6,7,8,9};
int boo = 1;
int sw1 = 40;
int sw2 = 42;
int sw3 = 44;
int sw4 = 46;
int statesw1;
int statesw2;
int statesw3;
int statesw4;

void setup() {
  Serial.begin(9600);
for(int i=0;i<=7;i++){
  pinMode(ground[i],OUTPUT);
}
for(int j=0;j<=7;j++){
  pinMode(led[j],OUTPUT);
}
pinMode(sw1,INPUT);
pinMode(sw2,INPUT);
pinMode(sw3,INPUT);
pinMode(sw4,INPUT);
digitalWrite(ground[0],HIGH);
digitalWrite(ground[1],HIGH);
digitalWrite(ground[2],HIGH);
digitalWrite(ground[3],HIGH);
digitalWrite(ground[4],HIGH);
digitalWrite(ground[5],HIGH);
digitalWrite(ground[6],HIGH);
digitalWrite(ground[7],HIGH);
}
void loop() {
statesw1 = digitalRead(sw1);
statesw3 = digitalRead(sw3);
statesw4 = digitalRead(sw4);
while(statesw1 && statesw3 == HIGH && statesw4 == HIGH){
  Serial.println("No Active");
  statesw1 = digitalRead(sw1);
  statesw3 = digitalRead(sw3);
  statesw4 = digitalRead(sw4);

  }


if(statesw3 == LOW){
  Serial.println("Switch 3 Active");
  ledloop();
  clearled();
  }
else if(statesw4 == LOW){
  Serial.println("Switch 4 Active");
  prayut();
  clearled();
  }
else if(statesw1 == LOW){
  Serial.println("Switch 1 Active");
  all_led();
  }
}
void ledloop(){
  for(int n=0;n<=7;n++){
  digitalWrite(ground[n],LOW);
  for(int k=0;k<=7;k++){
    for(int p=0;p<=100;p++){
    analogWrite(led[k],p);
    delay(4);
    }

  if(k==7){
    for(int t=0;t<=7;t++){
          for(int q=100;q>=0;q--){
            analogWrite(led[t],q);
            delay(3);   
          }
      }
  }
  }
}
}
void prayut(){
  for(int i=0;i<=7;i++){
    digitalWrite(ground[i],LOW);
    for(int j=i;j<=7;j++){
      if(i<=3){
      for(int p=0;p<=100;p++){
        analogWrite(led[j],p);
        delay(3);
        }
      for(int q=100;q>=0;q--){
        analogWrite(led[j],q);
        delay(3);
        }}
     if(i+j== 7){
        clearled();
        for(int k=i+1;k<=7-i;k++){
          digitalWrite(ground[k],LOW);
            for(int p=0;p<=100;p++){
              analogWrite(led[7-i],p);
              delay(3);
              }
              for(int q=100;q>=0;q--){
              analogWrite(led[7-i],q);
              delay(3);
              }
           digitalWrite(ground[k],HIGH);
          }
         digitalWrite(ground[7-i],LOW);
         for(int m=(7-i)-1;m>=i;m--){
              for(int p=0;p<=100;p++){
              analogWrite(led[m],p);
              delay(3);
              }
              for(int q=100;q>=0;q--){
              analogWrite(led[m],q);
              delay(3);
              }
          }
          digitalWrite(ground[7-i],HIGH);
          for(int x=(7-i)-1;x>i;x--){
              digitalWrite(ground[x],LOW);
              for(int y=0;y<=100;y++){
              analogWrite(led[i],y);
              delay(3);
              }
              for(int z=100;z>=0;z--){
              analogWrite(led[i],z);
              delay(3);
              }
              digitalWrite(ground[x],HIGH);
            }
      } 
    } 
  }
}
void all_led(){
  clearled();
  delay(100);
  for(int c=0;c<=7;c++){
  digitalWrite(ground[c],LOW);
   }
   for(int y=0;y<=100;y++){
    analogWrite(led[0],y);
    analogWrite(led[1],y);
    analogWrite(led[2],y);
    analogWrite(led[3],y);
    analogWrite(led[4],y);
    analogWrite(led[5],y);
    analogWrite(led[6],y);
    analogWrite(led[7],y);
    delay(4);
   }
   statesw2 = digitalRead(sw2);
   statesw1 = digitalRead(sw1);
   while(statesw2 == HIGH && statesw1 == HIGH){
    statesw1 = digitalRead(sw1);
    statesw2 = digitalRead(sw2);
    }
    if(statesw1 == LOW){all_led();}
    if(statesw2 == LOW){
        for(int z=100;z>=0;z--){
                  analogWrite(led[0],z);
                  analogWrite(led[1],z);
                  analogWrite(led[2],z);
                  analogWrite(led[3],z);
                  analogWrite(led[4],z);
                  analogWrite(led[5],z);
                  analogWrite(led[6],z);
                  analogWrite(led[7],z);
              delay(3);
           }
      }
    clearled();
 }
void clearled(){
  for(int c=0;c<=7;c++){
  digitalWrite(ground[c],HIGH);
}
for(int v=0;v<=7;v++){
  pinMode(led[v],LOW);
}
  }
