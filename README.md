# TivWorld
a Zelda-like game

I'm working on that game to learn more about C++.
I started to learn it something like 6 months ago with few tutorials.

I'm coding that game in C++ with SFML (http://www.sfml-dev.org/) and I'm using "tile-mapping".

In my reposit you could find 2 folders :

- The first one 'pictures'
You could find here the tileset I'm using. I will change them later to have my own tileset, I foung those ones on Google to have something ready to use.

- The second one 'levels'
You could find here .txt files used to generate the levels.
Few explainations...
      + the first line is the number of hostiles on the map
      + Robot1 700 100 (1 to 4 lines) are the type of hostile, its X and Y positions
      + pictures/tileset.bmp is the path of the tileset to draw the map
      + 14 7 are the numbers of tiles in both X and Y axis of the tileset
      + 25 25 are the width and height of each tile of the tileset
      + tile0 grass tile1 grass tile2 rock... are the attributs of each tile opf the tileset
      + 32 20 are the numbers of tiles to display o, both X and Y axis of the game window
      + the few last lines are the tilemap

So I'm opened to all the help you can give me to continue my game, to have better knowledge in C++, to have a better organization for my code, to show me things I forgot...

For the moment here are the few things to do :
- to add a class for the characters (main characters and hostiles or a class for each one)
- to add a class for the collision (for not to walk through the walls...)
- to add a class for the exit of the map (to load the next map, hostiles...)
- to add a claas for weapons (so health attributs will be needed for the characters, object to take back health...)
- few more to come... but not in mind for the moment ;-)

Thank you by advance for all your help ;-)
