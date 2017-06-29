
import processing.sound.*;
SoundFile file,file2,file3,file4,file5;
int gscreen = 0;
int score = 0;
float SPEED = 1;   //globalspeed: variefy this SPEED could change
                   //all the objects' speed
                   //So if the speed is too fast or too
                   //slow, modify this SPEED to adjust it
//------- global setting ---------
coin[] coins = new coin[8];
bomb[] bombs = new bomb[4];
gold[] golds = new gold[4];
turd[] turds = new turd[8];
player p = new player();
//---------Initial setup, call once --------
void setup() {
    size(800, 500);
    // FYI: if we close the program by closing the window
    // instead of pressing the 'stop' button in processing
    // (right next to 'play' button), it will throw error message 
    // due to the sound files has not been closed appropriately. 
    // The error message doesn't bother me much, but if it 
    // bothers you, please exit the program by pressing the 
    // 'Stop' button. Have Fun :)
    
    file = new SoundFile(this, "spring.mp3");
    file2 = new SoundFile(this,"coin.mp3" );
    file3 = new SoundFile(this,"gameover.mp3" );
    file4 = new SoundFile(this,"turd.mp3" );
    file5 = new SoundFile(this, "up.mp3");
    smooth();
    // set up the initial coin list and turd list
    for(int i = 0; i<8; i++){
        float yspeed = random (1,9);
        float x = random(20,780);
        coins[i] = new coin(yspeed*SPEED,x);
        
        float tspeed = random (3,11);
        float tx = random (20,780);
        turds[i] = new turd(tspeed*SPEED,tx);
        
    }
    // set up the initial bomb list and gold list
    for(int i = 0; i<4; i++){
        float yspeed = random (5,9);
        float x = random(20,780);
        bombs[i] = new bomb(yspeed*SPEED,x);
        
        float gyspeed = random(3,7);
        float gx = random(20,780);
        golds[i] = new gold(gyspeed*SPEED,gx);
    }
}

//------------------------------------
// set up 3 screens:
// a: initialscreen
// b: gameplay
// c: gameoverscreen 
//-------- the three screens ---------
void initialscreen(){
    background(236, 240, 241);
    textAlign(CENTER);
    fill(52, 73, 94);
    textSize(70);
    text("Collect the Coins", width/2, height/2);
    textSize(15); 
    text("By Yuding Ai", width/2, height/2+45);
    text("Click/Hit 'Enter' to start", width/2, height-30);
}
//------the main gamming program--------------
void gameplay() {
    background(236, 240, 241);
    fill(0);
    text("(Press LEFT/RIGHT to move)", width/2, 20);
    text("Score: ",30,58);
    text(score,75,58);
    p.drawplayer();
    if (keyPressed) {
        if (keyCode == LEFT) {
            if (p.getxpos() > 0) {
                p.moveleft();
            }
        }

        if (keyCode == RIGHT) {
            if (p.getxpos() < 800) {
                p.moveright();
            }
        }
    }
    for (int i = 0; i<8; i++){
        coins[i].drawcoin();
        turds[i].drawturd();
        //collition detection:
        if(dist(coins[i].getxpos(),coins[i].getypos(),p.getxpos(),p.getypos())<30){
            float yspeed = random (1,9);
            float x = random(20,780);
            coins[i] = new coin(yspeed*SPEED,x);
            file2.play();
            file2.amp(0.3);
            score+=2;
        }
        if(dist(turds[i].getxpos(),turds[i].getypos(),p.getxpos(),p.getypos())<30){
            float tspeed = random (3,11);
            float x = random(20,780);
            turds[i] = new turd(tspeed*SPEED,x);
            file4.play();
            score -=10;
            if (score < 0){
              score = 0;
            }
        }        
    }
    for (int i = 0; i<4;i++){
        bombs[i].drawbomb();
        golds[i].drawgold();
        if(dist(golds[i].getxpos(),golds[i].getypos(),p.getxpos(),p.getypos())<30){
            float yspeed = random (3,7);
            float x = random(20,780);
            golds[i] = new gold(yspeed*SPEED,x);
            file5.play();
            score +=10;
        }
        if(dist(bombs[i].getxpos(),bombs[i].getypos(),p.getxpos(),p.getypos())<30){
            gameOver();
        }
    }
}
void gameoverscreen() {
    background(44, 62, 80);
    textAlign(CENTER);
    fill(236, 240, 241);
    textSize(21);
    text("Score",340,240);
    text(score,440,240);
    textSize(15);
    text("Click/Hit 'Enter' to Restart", width/2, height-30);
}
//-------------------------------
//---------- draw the objects----
void draw(){
    if(gscreen ==0){
        initialscreen();
    }
    else if(gscreen ==1){
        gameplay();
    }
    else if(gscreen ==2){
        gameoverscreen();
    }
}
//---------------------------------------------
//---- inputs to start/restart the game -------
public void mousePressed() {
    // click mouse to start the game from initial screen 
    if (gscreen==0) { 
        file.play();
        startGame();
    }
    // click mouse to restart the game from gameover screen 
    else if(gscreen == 2){
        file.play();
        score = 0;
        //reset up the coinlist and bomblist
        // set up the initial coin list
        for(int i = 0; i<8; i++){
            float yspeed = random (1,9);
            float x = random(20,780);
            coins[i] = new coin(yspeed*SPEED,x);
          
            float tspeed = random (3,11);
            float tx = random (20,780);
            turds[i] = new turd(tspeed*SPEED,tx);
        }
        // set up the initial bomb and gold list
        for(int i = 0; i<4; i++){
            float yspeed = random (5,9);
            float x = random(20,780);
            bombs[i] = new bomb(yspeed*SPEED,x);
            
            float gyspeed = random(3,7);
            float gx = random(20,780);
            golds[i] = new gold(gyspeed*SPEED,gx);
        }
        startGame();
    }
}

public void keyPressed(){
    if(keyCode == ENTER){
        // click mouse to start the game from initial screen 
        if (gscreen==0) { 
            file.play();
            startGame();
        }
        // click mouse to restart the game from gameover screen 
        else if(gscreen == 2){
            file.play();
            score = 0;
            //reset up the coinlist and bomblist
            // set up the initial coin list
            for(int i = 0; i<8; i++){
                float yspeed = random (1,9);
                float x = random(20,780);
                coins[i] = new coin(yspeed*SPEED,x);

                float tspeed = random (3,11);
                float tx = random (20,780);
                turds[i] = new turd(tspeed*SPEED,tx);
            }
            // set up the initial bomb and gold list
            for(int i = 0; i<4; i++){
                float yspeed = random (5,9);
                float x = random(20,780);
                bombs[i] = new bomb(yspeed*SPEED,x);

                float gyspeed = random(3,7);
                float gx = random(20,780);
                golds[i] = new gold(gyspeed*SPEED,gx);
            }
            startGame();
        }
    }
}

void startGame() {
    if (file3.isPlaying()==1){
          file3.stop();
    }
    gscreen=1;
}
void gameOver() {
    gscreen=2;
    if (file.isPlaying() ==1){
          file.stop();
    }
    file3.play();
}

// -----------------objects---------------------
class coin{
    //attributes
    float xPos,yPos,ySpeed;
    float coinsize = 20;
    color coincolor = color(255,215,0);
    //constructor
    coin(float speed,float x){
        ySpeed = speed;
        xPos = x; 
        yPos = 0;
    }
    void drawcoin(){
        //draw the coin
        fill(coincolor);
        yPos += ySpeed;
        ellipse(xPos, yPos, coinsize, coinsize);
        fill(255);
        ellipse(xPos, yPos, coinsize/3, coinsize/3); 
        if (yPos > 500){
            // the idea is to reuse each object
            // until it hits the player
            // so when it touch the ground, relauch it with random position and speed;          
            yPos = 0;
            //define a new speed and position
            ySpeed = random(1,9)*SPEED;
            xPos = random(20,780);
        }
    }
    //get xpos
    float getxpos(){return xPos;}
    //get ypos
    float getypos(){return yPos;}
}
class gold{
    //attributes
    float xPos,yPos,ySpeed;
    float goldsize = 30;
    color goldcolor = color(255,215,0);
    //constructor
    gold(float speed,float x){
        ySpeed = speed;
        xPos = x; 
        yPos = 0;
    }
    void drawgold(){
        //draw the gold
        fill(goldcolor);
        yPos += ySpeed;
        ellipse(xPos, yPos, goldsize*2/3, goldsize*2/3);
        quad(xPos-goldsize,yPos,xPos+goldsize,yPos,xPos+goldsize*2/3,
            yPos+0.7*goldsize,xPos-goldsize*2/3,yPos+0.7*goldsize);
        if (yPos > 500){
            //reuse each object
            yPos = 0;
            //define a new speed and position
            ySpeed = random(3,7)*SPEED;
            xPos = random(20,780);
        }
    }
    //get xpos
    float getxpos(){return xPos;}
    //get ypos
    float getypos(){return yPos;}
}

class bomb{
    //attributes
    float xPos,yPos,ySpeed;
    float bombsize = 30;
    color bombcolor = color(119,136,153);
    //constructor
    bomb(float speed,float x){
        ySpeed = speed;
        xPos = x; 
        yPos = 0;
    }
    void drawbomb(){
        //draw the bomb
        fill(bombcolor);
        yPos += ySpeed;
        line(xPos,yPos,xPos+bombsize,yPos-0.4*bombsize);
        quad(xPos,yPos+bombsize*0.2,xPos-bombsize*0.3,yPos-bombsize*0.1,
        xPos+bombsize*0.6,yPos-bombsize*0.4,xPos + 0.7*bombsize, yPos - 0.1*bombsize);
        ellipse(xPos, yPos, bombsize, bombsize);
        fill(255,0,0);
        ellipse(xPos+bombsize, yPos-0.3*bombsize, 0.4*bombsize, 0.2*bombsize);
        fill(255,127,80);
        ellipse(xPos+bombsize, yPos-0.3*bombsize, 0.2*bombsize, 0.1*bombsize);

        if (yPos > 500){
            //reuse each object
            yPos = 0;
            //define a new speed and position
            ySpeed = random(5,9)*SPEED;
            xPos = random(20,780);
        }
    }
    //get xpos
    float getxpos(){return xPos;}
    //get ypos
    float getypos(){return yPos;}
}

class turd{
    //attributes
    float xPos,yPos,ySpeed;
    float turdsize = 30;
    color turdcolor = color(205,133,63);
    //constructor
    turd(float speed,float x){
        ySpeed = speed;
        xPos = x; 
        yPos = 0;
    }
    void drawturd(){
        //draw the turd
        fill(turdcolor);
        yPos += ySpeed;
        triangle(xPos-0.1*turdsize, yPos-turdsize*0.15,xPos+0.1*turdsize, yPos-turdsize*0.15,
        xPos+0.15*turdsize, yPos-turdsize*0.5);
        ellipse(xPos, yPos, turdsize, turdsize/2.5);
        ellipse(xPos, yPos-turdsize*0.15, turdsize/2, turdsize/4);

        if (yPos > 500){
            //reuse each object
            yPos = 0;
            //define a new speed and position
            ySpeed = random(3,11)*SPEED;
            xPos = random(20,780);
        }
    }
    //get xpos
    float getxpos(){return xPos;}
    //get ypos
    float getypos(){return yPos;}
}

class player{
    //attributes
    float xPos, yPos;
    float psize = 50;
    float xSpeed = 10*SPEED;
    
    //constructor
    player(){
        xPos = 400;
        yPos = 480;
    }
    
    void drawplayer(){
        // draw the player
        fill(215,170,130);
        rectMode(CENTER);
        rect(xPos, yPos-psize*0.4, psize, psize/2);
        fill(100,0,129);
        ellipse(xPos-psize*0.3,yPos,psize/3,psize/3);
        ellipse(xPos+psize*0.3,yPos,psize/3,psize/3);
    }
    //get xpos
    float getxpos(){return xPos;}
    //get ypos
    float getypos(){return yPos;}

    //move to the left
    void moveleft(){
        xPos -=xSpeed;
    }
    //move to the right
    void moveright(){
        xPos +=xSpeed;
    }
}

// sound reference:
// colleted coin/gold/; hit turd and gameover all from super mario's soundtrack:
// http://downloads.khinsider.com/game-soundtracks/album/super-mario-world-original-soundtrack
// theme music:
// 'overture of the spring festival';