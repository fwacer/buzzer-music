#define SONG_LENGTH 30
int pin = 9;

/*
int mary_lamb[][SONG_LENGTH]   = {{3,2,1,2,3,3,3, 2,2,2, 3,5,5, 3,2,1,2,3,3,3, 2,1,2,3,2,1, -1},
                                  {0,0,0,0,1,1,5, 1,1,5, 1,1,7, 0,0,0,0,1,1,5, 1,1,1,1,1,7, -1}
                                 };
*/
//first level of array = note
//second level         = note length (4 = 1/2, 2 = 1/8, 1 = 1/16)
//third level          = delay after note
char mary_lamb[][SONG_LENGTH] = {{'e','d','c','d','e','e','e', 'd','d','d', 'e','g','g', 'e','d','c','d','e','e','e', 'd','c','d','e','d','c', -1},
                                  {2,2,2,2,2,2,2, 2,2,2, 2,2,2, 2,2,2,2,2,2,2, 2,2,2,2,2,2, -1},
                                  {0,0,0,0,1,1,5, 1,1,5, 1,1,7, 0,0,0,0,1,1,5, 1,1,1,1,1,7, -1}
                                 };
char amazing_grace_v1[][SONG_LENGTH] = {{'d','g', 'b','a','g', 'b', 'a', 'g', 'e','d', 'd','g', 'b','a','g','b', 'a','d', -1},
                                                  {2,4, 1,2,2, 4, 4, 4, 2,4, 2,4, 1,1,2, 4,2, 6, -1},
                                                  {2,2, 0,0,2, 3, 2, 3, 2,3, 2,3, 0,0,2, 3,2, 6, -1}
                                                 };
char amazing_grace_v2[][SONG_LENGTH] = {{'d','d', 'b','b', 'a','g', 'e','d', 'd','g', 'g','b', 'a','g', -1},
                                                  {2,4, 2,4, 2,4, 2,4, 2,4, 2,4, 2,4, -1},
                                                  {2,2, 2,2, 2,2, 2,2, 2,2, 2,2, 2,2, -1}
                                                 };
void readSong(char notes[][SONG_LENGTH]){
  int i = 0;
  for(i=0; i< SONG_LENGTH; i++){
    if (notes[0][i]==-1){
      return;
    }
    play(notes[0][i], notes[1][i], notes[2][i]);
  }
}
void play(char note, int duration, int len){
  //int freq = 225 + (note*20);
  int freq;
  switch(note){
    case 'a': freq = 440;
    break;
    case 'b': freq = 494;
    break;
    case 'c': freq = 262;
    break;
    case 'd': freq = 294;
    break;
    case 'e': freq = 330;
    break;
    case 'f': freq = 349;
    break;
    case 'g':  freq = 392;
    break;
    default: freq = 600;
    Serial.println("default triggered");
    break;
  }
  tone(pin, freq);
  delay(100);
  delay(duration*200);
  
  if(len>0){
    noTone(pin);
    delay(25 + (25*len));
  }
}
void setup() {
  Serial.begin(9600);
  readSong(mary_lamb);
  delay(3000);
  readSong(amazing_grace_v1);
  delay(2000);
  readSong(amazing_grace_v2);
}

void loop() {
  // put your main code here, to run repeatedly:
}
