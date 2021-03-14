# Cub3D

This project relates to the Codam Core curriculum.
Codam is part of the #42network, with 9.000 students around the world.


## Project overview

>Summary: This project is inspired by the world-famous eponymous 90’s game, which
>was the first FPS ever. It will enable you to explore ray-casting. Your goal will be to
>make a dynamic view inside a maze, in which you’ll have to find your way.


## Usage

```
git clone git@github.com:Mollie-S/cub3D.git
```

then

```
cd cub3D && make                                                           
```

To start the maze window choose one of the maps inside the `maps` directory.

For example:

```
./cub3D maps/map.cub
```
or
```
./cub3D maps/skybox_map.cub
```

And here you are
![inside the map.cub maze](screenshots/map_screenshot.png)![inside the skybox_basic maze](screenshots/skybox_maze_basic.png)

Use **W**, **S**, **A**, **D** to move inside the maze
and :arrow_right: :arrow_left: to rotate.

In order to compile the bonus part (skybox)

```
make fclean                                                          
```

and then

```
make bonus                                                          
```

and run the skybox map

```
./cub3D maps/skybox_map.cub                                                        
```
![inside the skybox bonus maze](screenshots/skybox_bonus.png)
or![inside the skybox bonus maze](screenshots/bonus_map.png)