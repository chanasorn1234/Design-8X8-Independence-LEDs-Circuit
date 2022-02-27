int ground[8] ={2,3,4,5,6,7,8,9};
int led[4] = {10,11};
int boo = 1;
void setup() {
for(int i=0;i<=7;i++){
  pinMode(ground[i],OUTPUT);
}
for(int j=0;j<=3;j++){
  pinMode(led[j],OUTPUT);
}
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

for(int n=0;n<=7;n++){
  digitalWrite(ground[n],LOW);
  for(int k=0;k<=1;k++){
    for(int p=0;p<=100;p++){
    analogWrite(led[k],p);
    delay(2);
    }
    if(n!=0){
      digitalWrite(ground[n-1],HIGH);
    }
    for(int q=100;q>=5;q--){
    analogWrite(led[k],q);
    delay(2);   
  }
  }
  if(n==7){digitalWrite(ground[n],HIGH);}
  
}

//digitalWrite(ground[7],LOW);
//digitalWrite(led[0],HIGH);
//digitalWrite(led[1],HIGH);


}
