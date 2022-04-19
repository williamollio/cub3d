# CUB3D

![cub3D](https://github.com/williamollio/cub3d/blob/master/cub3d.gif)
<br/>
<strong>Overview</strong>

Developed by Id Software by the über famous John Carmack and John Romero, pub- lished in 1992 by Apogee Software, [Wolfenstein 3D](http://users.atw.hu/wolf3d/) is the first true “First Person Shooter” in the history of video games.
This project introduced the notion of [Raycasting](https://en.wikipedia.org/wiki/Ray_casting)

[Subject PDF](https://github.com/williamollio/cub3d/blob/master/subject/cub3D.pdf)
# Goal
Create a “realistic” 3D graphical representation of the inside of a maze from a first-person perspective. The representation has to be created using the Ray-Casting principles.

# Explanations

Movements
* <strong>Key A</strong>: move left.
* <strong>Key D</strong>: move right.
* <strong>Key S</strong>: move back.
* <strong>Key W</strong>: move forward.
* <strong>Left/Right arrow keys</strong>: look left and right.
* <strong>Mouse</strong>: look left and right.

# Clone
The mlx library included works only on MacOS.
Project tested on macOS Catalina.

Open a terminal and run following command:
```
git clone <repository url>
```
# How to use

Go to the created repository and run following command:
```
make
```
To start run the following command (the last argument is optionnal):
```
./cub3D ./maps/maps_choosed.cub
```
Press ESC to exit the game since your mouse will be capture by the game.

For further informations about the content of the map, read the [Subject PDF](https://github.com/williamollio/cub3d/blob/master/subject/cub3D.pdf)
