const int trigPin = 7;  //트리거 핀 설정
const int echoPin = 6;  //에코 핀 설정
const int led = 8;  //led 핀 설

long duration;  //펄스 지속 시간 변수
int distance; //거리 변수

void setup() {
  Serial.begin(9600);

  pinMode(trigPin, OUTPUT); //트리거 핀 = 출력
  pinMode (echoPin, INPUT); //에코 핀 = 입력
}

void loop() {
  digitalWrite(trigPin, LOW); //트리커 핀을 LOW로 설정하여 클리어
  delayMicroseconds(2); //2 마이크로초 대기정

  digitalWrite(trigPin, HIGH);  //트리거 핀을 HIGH로 설정하여 초음파 신호 전송
  delayMicroseconds(10);  //10 마이크로초 동안 유지
  digitalWrite(trigPin, LOW); //트리거 핀을 다시 LOW로 설정
  duration = pulseIn(echoPin, HIGH);  //에코 핀에서 펄스 지속 시간 측정

  distance = duration * 0.034 / 2;  //거리 계산

  if(distance <= 30){
    digitalWrite(led, HIGH);
    }else{
      digitalWrite(led, LOW);
    }
  
  Serial.println(distance); //시리어 모니터에 거리 출력

  delay(1000);  //1초 대기
}