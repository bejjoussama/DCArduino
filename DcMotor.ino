int onoff = 2;
int motor = 9;
int pot = A0;

int potVal = 0;

int button = 0;
int prevButton = 0;

int DC = 0;

void setup()
{
    Serial.begin(9600);
    pinMode(onoff, INPUT);
    pinMode(motor, OUTPUT);
}

void loop()
{
    potVal = map(analogRead(A0), 0, 1023, 0, 255);
    button = digitalRead(onoff);
    if ((button == HIGH) && (prevButton == LOW))
    {
        DC = 1 - DC;
    }

    if (DC == 1)
    {
        analogWrite(motor, potVal);
    }
    else
    {
        digitalWrite(motor, LOW);
    }
}
