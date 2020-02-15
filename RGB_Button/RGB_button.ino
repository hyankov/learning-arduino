#define BLUE_LED 3
#define GREEN_LED 5
#define RED_LED 6
#define BUTTON 8

#define MIN_COLOR 0
#define MAX_COLOR 255

int redValue = MAX_COLOR;
int greenValue = MIN_COLOR;
int blueValue = MIN_COLOR;

int leds[] = { RED_LED, GREEN_LED, BLUE_LED };
int currentLedIndex = 0;

void setup()
{
    // Setup pins
    pinMode(RED_LED, OUTPUT);
    pinMode(GREEN_LED, OUTPUT);
    pinMode(BLUE_LED, OUTPUT);
    pinMode(BUTTON, INPUT_PULLUP);  
}

void lightLeds()
{
    // Light up the leds
    for (int i = 0; i <= 2; i++)
    {
        // By default, the LED is off
        int highLow = LOW;

        if (i == currentLedIndex)
        {
            // If it's the current led, light it up
            highLow = HIGH;
        }

        digitalWrite(leds[i], highLow);
    }
}

void transitionLeds(int ledToFadeOut, int ledToFadeIn, int delayMs)
{
    // Value1 goes from 255 to 0
    for (int led1_color = MAX_COLOR; led1_color >= MIN_COLOR; led1_color--)
    {
        // Light the LEDs
        analogWrite(ledToFadeOut, led1_color);
        
        delay(delayMs);
    }

        // Value1 goes from 255 to 0
    for (int led2_color = MIN_COLOR; led2_color <= MAX_COLOR; led2_color++)
    {
        // Light the LEDs
        analogWrite(ledToFadeIn, led2_color);
        
        delay(delayMs);
    }
}

// main loop
void loop()
{
    // If button is pressed ...
    if (digitalRead(BUTTON) == LOW)
    {
        int oldLedIndex = currentLedIndex;
        
        if (++currentLedIndex > 2)
        {
            currentLedIndex = 0;
        }

        transitionLeds(leds[oldLedIndex], leds[currentLedIndex], 5);
    }
    
    lightLeds();

    delay(100);
}