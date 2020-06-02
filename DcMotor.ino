/*
Définitions des pins de l'arduino
Pin 2: Défini sur INPUT pour capturer l'etat du bouton.
Pin 9: Défini sur OUTPUT pour envoyer le signal PWM au transistor MosFET.
Pin A0: Capture la tension entrante du potentiomètre.
*/
int onoff = 2;
int motor = 9;
int pot = A0;
int DC = 0;
int potVal = 0; //Définition d'une variable pour stocker la valeur du potentiomètre.

int button = 0;     //Définition d'une variable pour stocker la valeur du bouton poussoir.
int prevButton = 0; //Variable qui enregistre le dernier état du bouton poussoir.

void setup()
{
    pinMode(onoff, INPUT);
    pinMode(motor, OUTPUT);
    Serial.begin(9600);
}

void loop()
{
    potVal = map(analogRead(A0), 0, 1023, 0, 255); //Re-mappe les valeurs du potentiometre de 0-1023 à 0-255.
    button = digitalRead(onoff);                   // Permet de lire l'etat du bouton poussoir.

    /* 
        Ecrire une fonction qui sert à mémoriser l'état du moteur et le basculer quand on appuie sur le bouton poussoir.
    */
    if (digitalRead(onoff) == HIGH)
    {
        if (prevButton == 0)
        {
            prevButton = 1;
            DC = 1;
        }
        else
        {
            prevButton = 0;
            DC = 0;
        }
    }
    if (DC == 1)
    {
        analogWrite(motor, potVal);
    }
    else
    {
        analogWrite(motor, 0);
    }

    /*
        Ecrire sur le moniteur serie l'etat du moteur.
    */
    Serial.print("%_moteur: ");
    Serial.print((potVal * 100) / 255);
    Serial.print(" ,Etat moteur: ");
    if (prevButton == 1)
    {
        Serial.println("Marche");
    }
    else
    {
        Serial.println("Arret");
    }
}
