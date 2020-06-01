/*
Définitions des pins de l'arduino
Pin 2: Défini sur INPUT pour capturer l'etat du bouton.
Pin 9: Défini sur OUTPUT pour envoyer le signal PWM au transistor MosFET.
Pin A0: Capture la tension entrante du potentiomètre.
*/
int onoff = 2;
int motor = 9;
int pot = A0;

int potVal = 0; //Définition d'une variable pour stocker la valeur du potentiomètre.

int button = 0;     //Définition d'une variable pour stocker la valeur du bouton poussoir.
int prevButton = 0; //Variable qui enregistre le dernier état du bouton poussoir.

int DC = 0; // Variable qui enregistre l'etat du moteur.

void setup()
{
    pinMode(onoff, INPUT);
    pinMode(motor, OUTPUT);
}

void loop()
{
    potVal = map(analogRead(A0), 0, 1023, 0, 255); //Re-mappe les valeurs du potentiometre de 0-1023 à 0-255.
    button = digitalRead(onoff);                   // Permet de lire l'etat du bouton poussoir.

    /* 
        Ecrire une fonction qui sert à mémoriser l'état précèdent du moteur et le basculer quand on appuie sur le bouton poussoir.
    */
    if ((button == HIGH) && (prevButton == LOW))
    {
        DC = 1 - DC;
    }
    /*
        Si la valeur DC est égale à 1 le moteur se met en marche sinon le moteur est arrêté.
    */
    if (DC == 1)
    {
        analogWrite(motor, potVal); // la fonction analogWrite permet de generer un signal pwm sur le pin 9 à tension variable selon la valeur de la variable potVal.
    }
    else
    {
        digitalWrite(motor, LOW);
    }
}
