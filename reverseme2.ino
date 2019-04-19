/*
 * Sample for reversing demo
 * 
 * yeah, I know coding is lame, but it's done
 * on purpose, trust me.
 * 
 */
char input;
char password[20];
char encPassword[] = "\xad\x9e\x88\x99\x85\x82\x83\xa8\x8d\x95";
int x = 0;

void setup() {
  char ch;
  
  Serial.begin(9600);
  delay(2000);

  Serial.println("Enter password: ");
}

void loop() {
    
  if (Serial.available()) {
    input = Serial.read();
    password[x] = input;
    x++;
    
    if ( input == '\x0A' )
    {
      int correct = 0;
      for ( int i = 0; i < strlen(password) - 1; i++ )
      {
        //Serial.println(decch(encPassword[i]));
        if ( decch(encPassword[i]) == password[i] )
        {
          correct += 1;
        }
      }
      if ( correct == 10 )
      {
        Serial.println("Great Work! ^_^");
      } else 
      {
        Serial.println("You need to work more on this");
      }

      x = 0;
      memset(password,0,sizeof(password));
    }
  }
}

char decch(char ch)
{
 return (ch ^ 0xEC);
}
