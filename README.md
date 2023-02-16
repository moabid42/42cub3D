# cub3d
This project is inspired by the world-famous eponymous 90’s game, which was the first FPS ever. It will enable you to explore ray-casting. Your goal will be to make a dynamic view inside a maze, in which you’ll have to find your way.

## Rating
***105/100*** :white_check_mark:

## Prerequisites
`sudo apt-get install libbsd-dev libx11-dev libxext-dev`

## Utilisation

1. Run `make` to compile the base version.
2. Follow the instructions.

## Controls
If you are running Linux the controls are based on a QWERTY keyboard and on MAC a QWERTY keyboard.

<kbd>W</kbd> <kbd>A</kbd> <kbd>S</kbd> <kbd>D</kbd>: Move and Strafe


### Map editor controls:
| Key | Action |
|--|--|
| <kbd>Ctrl</kbd> | (Hold) add floor and ceiling |
| <kbd>Numpad 1</kbd> | (Toggle) Wall <-> Interior empty space (0 <-> 1) |
| <kbd>Numpad 2</kbd> | (Toggle) Exterior Floor w/ skybox <-> Interior Floor w/ skybox |
| <kbd>Numpad 3</kbd> | (Toggle) Alternate wall texture |
| <kbd>Numpad 4</kbd> | Pushable wall |
| <kbd>Numpad 5</kbd> | (Toggle) Doors (Unlocked > Locked Key 1 > Locked Key 2) |
| <kbd>Numpad 6</kbd> | Spinning cylinder |
| <kbd>Numpad 7</kbd> | (Toggle) Angled wall (2 diagonals) |
| <kbd>Numpad 8</kbd> | (Toggle) Rounded wall (one for each corner) |
