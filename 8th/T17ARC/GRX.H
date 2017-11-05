void Open( void );
void Close( void );
void PutPixel( int x, int y, int z);
void Shift( int *bx, int by, int bz, int bw );
void DrawBrick( int row, int column, int color );
void DrawBricks( void );
int Hit( int x, int y );
//void CollisionDetection( int x, int y, int vx, int vy );

#define STARTX 160
#define STARTY 100
#define STARTZ 14

#define DELAY 10

#define BRICKW 100
#define BRICKH 50
#define BNUMX 10
#define BNUMY 10
#define BSTARTX 110
#define BSTARTY 10

extern int Bricks[BNUMY][BNUMX];

#define SCRH 200
#define SCRW 320
#define BARZ 7
#define BARW 30

