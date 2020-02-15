#define BLUE_LED 3
#define GREEN_LED 5
#define RED_LED 6
#define DELAY 10
#define MIN_COLOR 0
#define MAX_COLOR 255

int redValue = MAX_COLOR;
int greenValue = MIN_COLOR;
int blueValue = MIN_COLOR;

void setup()
{
    // Setup pins
    pinMode(RED_LED, OUTPUT);
    pinMode(GREEN_LED, OUTPUT);
    pinMode(BLUE_LED, OUTPUT);
}

void cycleColors(int led1, int led2)
{
    // Value1 goes from 255 to 0
    for (int led1_color = MAX_COLOR; led1_color >= MIN_COLOR; led1_color--)
    {
        // Value2 goes from 0 to 255
        int led2_color = MAX_COLOR - led1_color;

        // Light the LEDs
        analogWrite(led1, led1_color);
        analogWrite(led2, led2_color);
        
        delay(DELAY);
    }
}

// main loop
void loop()
{
    cycleColors(RED_LED, GREEN_LED);    
    cycleColors(GREEN_LED, BLUE_LED);
    cycleColors(BLUE_LED, RED_LED);
}
