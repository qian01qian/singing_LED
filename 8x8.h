
#define ROW1 3
#define ROW2 4
#define ROW3 5
#define ROW4 6
#define ROW5 7
#define ROW6 8
#define ROW7 9
#define ROW8 10

#define COL1 11
#define COL2 12
#define COL3 13
#define COL4 A0
#define COL5 A1
#define COL6 A2
#define COL7 A3
#define COL8 A4



const int row[] = {
  ROW1, ROW2, ROW3, ROW4, ROW5, ROW6, ROW7, ROW8};
const int col[] = {
  COL1,COL2, COL3, COL4, COL5, COL6, COL7, COL8};


byte scan[8][8] = {
  {1,0,0,0,0,0,0,0},
  {0,1,0,0,0,0,0,0},
  {0,0,1,0,0,0,0,0},
  {0,0,0,1,0,0,0,0},
  {0,0,0,0,1,0,0,0},
  {0,0,0,0,0,1,0,0},
  {0,0,0,0,0,0,1,0},
  {0,0,0,0,0,0,0,1}
};


byte squaree[8][8] = {
  {0,0,0,0,0,0,0,0},
  {0,1,1,1,1,1,1,0},
  {0,1,1,1,1,1,1,0},
  {0,1,1,1,1,1,1,0},
  {0,1,1,1,1,1,1,0},
  {0,1,1,1,1,1,1,0},
  {0,1,1,1,1,1,1,0},
  {0,0,0,0,0,0,0,0}};
  
byte heart[8][8] = {
  {1,0,0,1,1,0,0,1},
  {0,1,1,0,0,1,1,0},
  {0,1,1,1,1,1,1,0},
  {0,1,1,1,1,1,1,0},
  {0,1,1,1,1,1,1,0},
  {1,0,1,1,1,1,0,1},
  {1,1,0,1,1,0,1,1},
  {1,1,1,0,0,1,1,1}};


void showPattern(byte matrix[8][8]){
  for(byte i = 0; i < 8; i++){
    for(byte j = 0; j < 8; j++){
      digitalWrite(row[j], scan[i][j]);
      digitalWrite(col[j], matrix[i][j]);  
    }
        for(byte j = 0; j < 8; j++){
      digitalWrite(row[j], LOW);
      digitalWrite(col[j], HIGH); 
    }
  }
}
