#include <Keypad.h>

const byte rows = 4; //four rows
const byte cols = 4; //three columns
char keys[rows][cols] = {
  {'1','2','3', 'A'},
  {'4','5','6', 'B'},
  {'7','8','9', 'C'},
  {'*','0','#', 'D'}
};
byte rowPins[rows] = {5, 4, 3, 2}; //connect to the row pinouts of the keypad
byte colPins[cols] = {9, 8, 7, 6}; //connect to the column pinouts of the keypad
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, rows, cols );

const int LEDAKI_PINAKI_PRASINO = 10;
const int LEDAKI_PINAKI_KOKKINO = 11;


const int correctPass = 5432; // Ο σωστός κωδικός
int inPass,
    number,
    flag;

void setup(){
  // Ξεκίνα το Serial Monitor και ετοίμασε τα λαμπάκια.
  Serial.begin(9600);
  pinMode(LEDAKI_PINAKI_PRASINO, OUTPUT);
  pinMode(LEDAKI_PINAKI_KOKKINO, OUTPUT);
  digitalWrite(LEDAKI_PINAKI_PRASINO, LOW);
  digitalWrite(LEDAKI_PINAKI_KOKKINO, LOW);
}

void loop(){
  char key = keypad.getKey();

  if (key != NO_KEY){ // Αν πατηθεί κάποιο κουμπί, ξεκίνα τον έλεγχο.
    Serial.println(key);
    // Μετατροπή χαρακτήρα σε ακέραια τιμή.
    switch (key) {
      case '1':
          number = 1;
          break;

      case '2':
          number = 2;
          break;

      case '3':
          number = 3;
          break;

      case '4':
          number = 4;
          break;

      case '5':
          number = 5;
          break;

      case '6':
          number = 6;
          break;

      case '7':
          number = 7;
          break;

      case '8':
          number = 8;
          break;

      case '9':
          number = 9;
          break;

      case '0':
          number = 0;
          break;
  }

  switch (flag) {
      case 0: // Χιλιάδα
          number = 1000 * number;
          inPass += number;
          flag = 1;
          break;

      case 1: // Εκατοντάδα
          number = 100 * number;
          inPass += number;
          flag = 2;
          break;

      case 2: // Δεκάδα
          number = 10 * number;
          inPass += number;
          flag = 3;
          break;

      case 3: // Μονάδα
          number = number * 1;
          inPass += number;
          flag = 4;
          break;   

      case 4: // Έλεγχος κωδικού
          if (key == 'A') {
            Serial.print(inPass);
            if (correctPass == inPass) { // Σωστός Κωδικός
              digitalWrite(LEDAKI_PINAKI_PRASINO, HIGH);
              digitalWrite(LEDAKI_PINAKI_KOKKINO, LOW);
            }

            else { // Λάθος Κωδικός;
              digitalWrite(LEDAKI_PINAKI_PRASINO, LOW);
              digitalWrite(LEDAKI_PINAKI_KOKKINO, HIGH);
            }
          }
          break;
  }

    delay(100);
  }  
}
