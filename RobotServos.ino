#include <Servo.h>
class RoboServo
{
  //These are the variables that will be used within the RoboServo class
  private:
    #define ARRAY_LENGTH 5 //Change this value to modulate the smoothing (can only work for all with smoothing)
    int dataArray[ARRAY_LENGTH] = {};
    int currentDataIndex = 0;
    Servo includedServo;
    int minRangeValue  = 0;
    int maxRangeValue  = 180;
    int minAnalogInput = 0;
    int maxAnalogInput = 1023;
    int servoLocation  = 90;
    int analogInputPin = 0;
    int inputValue = (maxAnalogInput + minAnalogInput) /2; //set the default to the average of the min and max

  public:
    //This is the main constructor that will be used to develop any RoboServo object
    RoboServo(int servoPin, int rangeMin, int rangeMax, int analogPin, int analogMin, int analogMax)
    {
      includedServo.attach(servoPin);
      minRangeValue  = rangeMin; 
      maxRangeValue  = rangeMax;
      minAnalogInput = analogMin;
      maxAnalogInput = analogMax;
      analogInputPin = analogPin;

      //we may need to fill the array with the default inputValue here so the robot does not freak out at start-up
      
      includedServo.write(inputValue);
    }

    //overloaded Constructor 1: if incomplete parameters are given, initalized the RoboServo will default values filled in their places
    RoboServo(int servoPin, int rangeMin, int rangeMax, int analogPin)
    {
      RoboServo instanceRoboServo(servoPin,rangeMin,rangeMax,analogPin,minAnalogInput,maxAnalogInput);
    }
    
    //overloaded Constructor 2: if incomplete parameters are given, initalized the RoboServo will default values filled in their places
    RoboServo(int servoPin, int rangeMin, int rangeMax)
    {
      RoboServo instanceRoboServo(servoPin,rangeMin,rangeMax,analogInputPin,minAnalogInput,maxAnalogInput);
    }
    
    //overloaded Constructor 3: if incomplete parameters are given, initalized the RoboServo will default values filled in their places
    RoboServo(int servoPin)
    {
      RoboServo instanceRoboServo(servoPin,minRangeValue,maxRangeValue,analogInputPin,minAnalogInput,maxAnalogInput);
    }

    void simpleAnalogUpdate()   //read the analog input and move the servo to that location
    {
      inputValue = analogRead(analogInputPin);
      inputValue = constrain(inputValue, minAnalogInput, maxAnalogInput);
      servoLocation = map(inputValue, minAnalogInput, maxAnalogInput, minRangeValue, maxRangeValue);
      servoLocation = constrain(servoLocation, minRangeValue, maxRangeValue);
    
      includedServo.write(servoLocation);
    }
  
    float smoothing ()    //log the analog input value into an array, and output the average of the array
    {
      currentDataIndex = ++currentDataIndex % ARRAY_LENGTH; 
        
      inputValue = analogRead(analogInputPin);
      dataArray[currentDataIndex] = inputValue;
  
      int arrayTotal = 0; //if your ARRAY_LENGTH is above 30, change this to a long and the following float to a double
      for(int i = 0; i<ARRAY_LENGTH; i++){
        arrayTotal = arrayTotal + dataArray[i];
      }
      float smoothCriminal = arrayTotal / ARRAY_LENGTH;
    
      return smoothCriminal;
    }
    
    void setServoLocation(int inputPosition)   //set the servoLocation value and move the servo
    {
      servoLocation = inputPosition;
      includedServo.write(servoLocation);
    }
    
    void smoothMoves()    //use the smoothing function to move the servo
    {
      setServoLocation(smoothing());
    }
    
    int getServoLocation()
    {
      return servoLocation;
    }
    
    int getInputValue()
    {
      return inputValue;
    }


};

//this is an example
RoboServo shoulder(9);

void setup() {
}

void loop() {
  //more example...
  shoulder.smoothMoves();
  delay(10);
}

