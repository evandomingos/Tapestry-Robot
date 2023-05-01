#include <stdlib.h> // for random number generation

//define the size of the symmetric matrix
const int MATRIX_SIZE = 7;

//declare the matrix
int matrix[MATRIX_SIZE][MATRIX_SIZE];

const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns

//define the pin where the button is connected
const int buttonPin = 2;

void setup() {
  //initialize random seed
  randomSeed(analogRead(0));
  //set the button pin as an input
  pinMode(buttonPin, INPUT);
  Serial.begin(115200);
}

void loop() {
  //read the input from the button
  int buttonState = digitalRead(buttonPin);

  if (buttonState == HIGH) { //if the button is pressed
    //initialize random seed
    Serial.println("Button pressed");
    randomSeed(analogRead(0));

    //initialize the matrix with random numbers from 1 to 8
    for (int i = 0; i < MATRIX_SIZE; i++) {
      for (int j = 0; j < MATRIX_SIZE; j++) {
        matrix[i][j] = random(1, 9);
      }
    }

    //initialize the g-code string
    String gCode = "";

    //loop through each row of the matrix
    for (int i = 0; i < MATRIX_SIZE; i++) {
      //loop through each entry in the row
      for (int j = 0; j < MATRIX_SIZE; j++) {
        //create the g-code instruction to move to the x, y, and z position of the entry
        gCode += "G1 X" + String(i) + " Y" + String(j) + " Z" + String(matrix[i][j]) + "\n";

        //if the Z coordinate is greater than 0, add a line "M3" and a line "M5"
        if (matrix[i][j] > 0) {
          gCode += "M5\nM3\n";
        }
      }

      //add a g-code instruction to move to the next row along the x axis
      gCode += "G1 X" + String(i + 1) + "\n";
    }

    //send g-code instructions to the other Arduino using serial comunication
    Serial.println(gCode);
    delay(1000);
  }
}

