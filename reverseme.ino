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
char decPassword[20];
int x = 0;

void setup() {
  char ch;
  
  Serial.begin(9600);
  delay(2000);

  Serial.println("Enter password: ");
  
  // Decrypt the password in memory
  int i = 0;
  ch = encPassword[i];
  while ( ch != '\0' )
  {
    decPassword[i] = xorch(ch);
    i += 1;
    ch = encPassword[i];
  }
}

void loop() {
    
  if (Serial.available()) {
    input = Serial.read();
    password[x] = input;
    x++;
    
    if ( input == '\x0A' )
    {
      if ( strncmp(password,decPassword,strlen(decPassword)) == 0 )
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

char xorch(char ch)
{
 return ch ^ 0xEC;
}
