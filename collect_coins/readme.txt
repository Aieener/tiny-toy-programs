-------------------------------
Welcome to "Collect the Coins"!
-------------------------------
Simply open the program hw6.pde from Processing and play!

--------------------
Game play and Goals:
--------------------
4 objects will be falling from the sky and our mission is to
collect the good ones to raise the player's score. 
(My record is 268 points.) 

---------
Objects:
---------
In this game, there are 5 main objects including the player itself.
These objects are:
1. Coins  ---   Try to catch them, whenever a Coin has been collected, 
		it increments the player's score by 2. 
2. Gold   ---   Try hard to catch them, whenever a gold has been collected, 
		it increments the player's score by 10.
3. Turd   ---   Try to get rid of them, because it will decrement your
                score by 10 everytime you hit it.
4. bomb   ---   Try hard to get rid of them, because whenever you hit
                it, the game is over.
5. player ---   player can move to the right or left to catch the 4 objects
                introduced above.

---------
Control:
---------
To start/restart the game, click the mouse or press ENTER.
To move the player, Press LEFT to move left and RIGHT to move right

--------------------------------------
One tiny issue about exiting the game:
--------------------------------------
I have noticed that due to the usage of sound files:
if we close the program by closing the window
instead of pressing the 'stop' button in processing,
it will throw error message due to the sound files has 
not been closed appropriately. (occationaly, if we keep replay the
game for a long time, say 5+ times, then even if we
exit the program correctly by pressing the 'stop' button,
it still throws some error messages while we are playing, for 
example: 'ERROR: /node/free: Node ## not found'. It is
again, due to the usage of soundfiles, but and I am not sure why
it randomly throws such error message)

The error message doesn't bother me much since it won't crach the program, 
but if it bothers you, try to exit the program by pressing the 
'Stop' button and then there is a very good chance that it won't throw 
any error message at all. 

----------------------
Soundfiles attribution:
----------------------
colleted coin/gold; hit turd and gameover sound are all from super mario's original soundtrack:
http://downloads.khinsider.com/game-soundtracks/album/super-mario-world-original-soundtrack

Game theme music:
'overture of the spring festival', a traditional Chinese music download from Baidu


Thanks and Have Fun :)
