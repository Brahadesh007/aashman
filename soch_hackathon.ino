int filter_1=2,_filter_1=22;
int filter_1_stoper=3,_filter_1_stoper=24;
int filter_2=4,_filter_2=26;
int filter_2_stoper=5,_filter_2_stoper=28;
int filter_3=6,_filter_3=30;
int filter_3_stoper=7,_filter_3_stoper=32;

int f2fromf1=8,_f2fromf1=34;
int f2fromf1_stoper=9,_f2fromf1_stoper=36;

//int f3fromf1,_;
//int f3fromf1_stoper,_;

int f3fromfx=10,_f3fromfx=38;
int f1f3_f2_stoper=11,_f1f3_f2_stoper=40;
int f2f3_f1_stoper=12,_f2f3_f1_stoper=42;
int fxfromf3_stoper=23,_fxfromf3_stoper=44;


//input buttons
int button_1=31;bool b1=false;
int button_2=33;bool b2=false;
int button_3=35;bool b3=false;
int reset_btn=37;bool rb;
int start_btn=39;bool st=false;

bool rd=false;

void stopped(){
  digitalWrite(filter_1,false);
  digitalWrite(filter_1_stoper,false);
  digitalWrite(filter_2,false);
  digitalWrite(filter_2_stoper,false);
  digitalWrite(filter_3,false);
  digitalWrite(filter_3_stoper,false);
  
  digitalWrite(f2fromf1,false);
  digitalWrite(f2fromf1_stoper,false);
  
  digitalWrite(f3fromfx,false);
  digitalWrite(f1f3_f2_stoper,false);
  digitalWrite(f2f3_f1_stoper,false);
  digitalWrite(fxfromf3_stoper,false);
}
void setup() {
  // put your setup code here, to run once:
  pinMode(filter_1,OUTPUT);
  pinMode(filter_1_stoper,OUTPUT);
  pinMode(filter_2,OUTPUT);
  pinMode(filter_2_stoper,OUTPUT);
  pinMode(filter_3,OUTPUT);
  pinMode(filter_3_stoper,OUTPUT);
  
  pinMode(f2fromf1,OUTPUT);
  pinMode(f2fromf1_stoper,OUTPUT);
  
  pinMode(f3fromfx,OUTPUT);
  pinMode(f1f3_f2_stoper,OUTPUT);
  pinMode(f2f3_f1_stoper,OUTPUT);
  pinMode(fxfromf3_stoper,OUTPUT);



  // another set
  pinMode(_filter_1,OUTPUT);
  pinMode(_filter_1_stoper,OUTPUT);
  pinMode(_filter_2,OUTPUT);
  pinMode(_filter_2_stoper,OUTPUT);
  pinMode(_filter_3,OUTPUT);
  pinMode(_filter_3_stoper,OUTPUT);
  
  pinMode(_f2fromf1,OUTPUT);
  pinMode(_f2fromf1_stoper,OUTPUT);
  
  pinMode(_f3fromfx,OUTPUT);
  pinMode(_f1f3_f2_stoper,OUTPUT);
  pinMode(_f2f3_f1_stoper,OUTPUT);
  pinMode(_fxfromf3_stoper,OUTPUT);



  pinMode(button_1,INPUT);
  pinMode(button_2,INPUT);
  pinMode(button_3,INPUT);
  pinMode(reset_btn,INPUT);

  pinMode(13,OUTPUT);

  Serial.begin(9600);
  b1=b2=b3=false;
  stopped();// initially stopping all valves
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print(b1);
  Serial.print(" ");
  Serial.print(b2);
  Serial.print(" ");
  Serial.print(b3);
  Serial.print(" ");
  Serial.print(rb);
  Serial.print(" ");
  Serial.print(st);
  Serial.println(" ");
while(!st){
  if(digitalRead(button_1))rd=b1=true;
  if(digitalRead(button_2))rd=b2=true;
  if(digitalRead(button_3))rd=b3=true;
  if(digitalRead(start_btn)){
    st=true;
    rb=false;
    digitalWrite(13,1);
  }
}
  
  
  if(st){
                if(digitalRead(reset_btn))rb=true;
                if(rb){
                  stopped();
                  rd=false;
                  st=b1=b2=b3=false;
                  digitalWrite(13,0);
                }else{
    if(b1==true and b2==false and b3==false){ //F(flourine)
      digitalWrite(filter_1,true);
      digitalWrite(f2fromf1_stoper,true);
      digitalWrite(f2f3_f1_stoper,true);
      digitalWrite(fxfromf3_stoper,true);

      digitalWrite(_filter_1,true);
      digitalWrite(_f2fromf1_stoper,true);
      digitalWrite(_f2f3_f1_stoper,true);
      digitalWrite(_fxfromf3_stoper,true);


      Serial.println("F");
    }else if(b1==false and b2==true and b3==false){ //As(Arsanic)
      digitalWrite(filter_1_stoper,true);
      digitalWrite(filter_2,true);
      digitalWrite(fxfromf3_stoper,true);
      digitalWrite(f1f3_f2_stoper,true);

      digitalWrite(_filter_1_stoper,true);
      digitalWrite(_filter_2,true);
      digitalWrite(_fxfromf3_stoper,true);
      digitalWrite(_f1f3_f2_stoper,true);
      
      Serial.println("As");
    }else if(b1==false and b2==false and b3==true){ //pb(lead)
      digitalWrite(filter_1_stoper,true);
      digitalWrite(filter_2_stoper,true);
      digitalWrite(filter_3,true);

      digitalWrite(_filter_1_stoper,true);
      digitalWrite(_filter_2_stoper,true);
      digitalWrite(_filter_3,true);
      
      Serial.println("Pb");
    }else if(b1==true and b2==true and b3==false){ // F-As
      digitalWrite(filter_1,true);
      digitalWrite(f2fromf1,true);
      digitalWrite(fxfromf3_stoper,true);
      digitalWrite(f1f3_f2_stoper,true);

      digitalWrite(_filter_1,true);
      digitalWrite(_f2fromf1,true);
      digitalWrite(_fxfromf3_stoper,true);
      digitalWrite(_f1f3_f2_stoper,true);
      
      Serial.println("F-As");
    }else if(b1==true and b2==false and b3==true){ //F-Pb
      digitalWrite(filter_1,true);
      digitalWrite(f2fromf1_stoper,true);
      digitalWrite(f2f3_f1_stoper,true);
      digitalWrite(f3fromfx,true);

      digitalWrite(_filter_1,true);
      digitalWrite(_f2fromf1_stoper,true);
      digitalWrite(_f2f3_f1_stoper,true);
      digitalWrite(_f3fromfx,true);
      
      Serial.println("F-Pb");
    }else if(b1==false and b2==true and b3==true){ //As-Pb
      digitalWrite(filter_1_stoper,true);
      digitalWrite(filter_2,true);
      digitalWrite(f3fromfx,true);
      digitalWrite(f1f3_f2_stoper,true);

      digitalWrite(_filter_1_stoper,true);
      digitalWrite(_filter_2,true);
      digitalWrite(_f3fromfx,true);
      digitalWrite(_f1f3_f2_stoper,true);
      
      Serial.println("As-Pb");
    }else if(b1==true and b2==true and b3==true){ //F-As-Pb
      digitalWrite(filter_1,true);
      digitalWrite(f2fromf1,true);
      digitalWrite(f3fromfx,true);
      digitalWrite(f1f3_f2_stoper,true);
      
      Serial.println("F-As-Pb");
    }else if(b1==false and b2==false and b3==false){ //None
      digitalWrite(filter_1_stoper,true);
      digitalWrite(filter_2_stoper,true);
      digitalWrite(filter_3_stoper,true);

      digitalWrite(_filter_1_stoper,true);
      digitalWrite(_filter_2_stoper,true);
      digitalWrite(_filter_3_stoper,true);
      
      Serial.println("Pure");
    }
                }// else rb
  }// if rd close

}
