
#include <LiquidCrystal_I2C.h> 

#define BUZZER_PIN 12

LiquidCrystal_I2C lcd(0x27, 20, 4);// an lcd displayer object 


int buttons[4]={2,3,4,5};// defining an array to store pins of the buttons 



int choices[4]={0,0,0, 0}; // array to store the choices , one of them is correct an in a random position
int score=0; // incoreases for every correct answer 
int typing=0;// 0 to show the operation then switched to 1 to avoid showing it again and give the user the chance to choose his answer

int the_game_is_on=1;// a bool give the user the choice to start another game or no 

int factor1=0,factor2=0; // the two factors of the operation

int result=0; // the result (correct answer) of the operation in question

int time=100; // the timer 




int button1_state=HIGH; // variable for the state of each speed button
int button2_state=HIGH;
int button3_state=HIGH;
int button4_state=HIGH;



void setup() {

  lcd.init(); // initialisation of the displayer
  lcd.clear();
  lcd.backlight(); // active le rétro-éclairage


  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);

  randomSeed(analogRead(A0)); // to initialise the random function to generate diffrent number each time 

  lcd.print("   WELCOME !!   ");
  delay(1500);


}

void loop()
{
  if (typing==0 && the_game_is_on ) // if the user is not asked to type his answer and the game is on 
  {
    new_operation();
  }
  else  
  {
    button1_state=digitalRead(5); // reading the state of the button 
    button2_state=digitalRead(4);
    button3_state=digitalRead(3);
    button4_state=digitalRead(2);

     
        if (button1_state==LOW) // if the buttun number one is pressed 
        {
              check_answer_or_activate_the_game(0); // checing if the choice correspanding to this button is the correct answer if the game is on , if it is not on we turn it on 
        }
        else if (button2_state==LOW)
        {
              check_answer_or_activate_the_game(1);
        }
        else if (button3_state==LOW)
        {
              check_answer_or_activate_the_game(2);
        }
        else if (button4_state==LOW)
        {
              check_answer_or_activate_the_game(3);
        }

        
  }
  delay(100); // Pause avant de recommencer
  if (the_game_is_on)
  {
    decrease_time();
  }
  if (time<1)
  {
    time_out();
  }
}




void check_answer_or_activate_the_game(int index) // a function to check the answer or activate the game if it is off 
{
          if(the_game_is_on)
          {
                if (choices[index]==result) // checking the answer 
                { 
                  correct();
                }
                else {
                {
                  wrong();
                }
                }
          }
          else
          {
            the_game_is_on=1; // turning the game on 
          }
}


  
  
  




void new_operation() // a function to randomly make  a new operation 
{
  factor1 = random(29)+2; // randomly choosing the two factors of the operation
  factor2 = random(29)+2;
  int operator_selector=random(3); // a random variable to choose which operation gonna be used , (0: multiplication , 1:addition , 2: substraction)
  switch (operator_selector) { 
    case 0:
      show_operation('*');
      result=factor1*factor2;
      break;
    case 1:
      show_operation('+');
      result=factor1+factor2;
      break;
    case 2:
      show_operation('-');
      result=factor1-factor2;
      break;
  }
  
  set_choices(); 
  show_choices();

  typing=1;
}


void show_operation(char _operator_) // a function to show the operation 
{
  lcd.clear();
  lcd.print(factor1);
  lcd.print(_operator_);
  lcd.print(factor2);
  lcd.print("=?");
  lcd.setCursor(12,0);
  lcd.print(time);
  delay(500);
}

void set_choices() // a function to randomly choose the index of the correct answer in the choices array and fill the rest with close answer 
{
  int correct_choice_index=random(4); // randomly choosing the right choice spot in the choices array 
  choices[correct_choice_index]=result; // putting the correct choice in its randomly chosen spot in the choices array 
  for (int i=0;i<4;i++)
  {
    if (i!=correct_choice_index) // if i is not the index of the correct answer , to not override the right choice 
    {
      choices[i]=result+(random(10)-random(10)); // filling the other spots with random ,but close to the right answer , answers 
    }
  }
}


void show_choices() // a function to show the choices 
{
  lcd.setCursor(0,1);
  for (int i=0;i<4;i++)
  {
   lcd.setCursor(4*i, 1); 
    lcd.print(choices[i]);
    
  }
}


void correct() // a function to show the user that his answer was correct , increase his score and restart tha timer 
{
  lcd.clear();
  lcd.print("correct !");
  lcd.setCursor(0,1);
  score++; // increaseing the score 
  lcd.print("score:");
  lcd.print(score); // displaying the users score 
  delay(2000);
  typing=0; // put the in making another operation mode 
  time=100; // timer reset 

}

void wrong() // a function to show the user that his answer was wrong , reset the score and the timer then ask if he want to continu or no 
{
  the_game_is_on=0; // turning the game off 

  lcd.clear();
  lcd.print("wrong !");
  typing=0; // // put the in making another operation mode 
  lcd.setCursor(0,1);
  lcd.print("correction:");
  lcd.print(result); // showing the right answer 
  delay(2500);
  lcd.clear();
  lcd.print("score:"); // sowing the score 
  lcd.setCursor(0,1);
  lcd.print(score);
  delay(2500);
  lcd.clear();
  lcd.print("new game ?"); // asking the user if he wants to start a new game 
  lcd.setCursor(0, 1);
  lcd.print("press any button");// by pressing any button the game will restart 
  delay(1500);
  score=0; // score reset 
  time=100;// timer reset 

}



void decrease_time() // a function to decrease the timer
{
  time--;
  lcd.setCursor(12,0);
  lcd.print(time);
  lcd.print("  ");
}

void time_out() // a function announcing that the user took too long and the time is out 
{

  the_game_is_on=0; // turning the game off 

  lcd.clear();
  lcd.print("Time out !");
  typing=0; 

  delay(2500);
  lcd.clear();
  lcd.print("score:");// showing the score 
  lcd.setCursor(0,1);
  lcd.print(score);
  delay(2500);
  lcd.clear();
  lcd.print("new game ?");// asking the user if he wants to start a new game 
  lcd.setCursor(0, 1);
  lcd.print("press any button");
  delay(500);
  score=0;
  time=100;

}


