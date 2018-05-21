# RT @ UNIT Factory
RT (Ray tracer) is a mile-stone project in the 3D graphics curriculum of <a href="http://www.unit.ua" target="_blank" >UNIT Factory</a> [(42 School)](https://en.wikipedia.org/wiki/42_(school)).

At 42, we follow a strict norm in order to teach us to follow style guides. This norm also prevents us from using many built-in functions. In this project, we are limited to using a barebones graphic library called minilibx. This library limits the functionality to creating windows, handling input hooks, and coloring specific pixels.

In computer graphics, ray tracing is a technique for generating an image by tracing the path of light through pixels in an image plane and simulating the effects of its encounters with virtual objects. The technique is capable of producing a very high degree of visual realism, usually higher than that of typical scanline rendering methods, but at a greater computational cost. This makes ray tracing best suited for applications where the image can be rendered slowly ahead of time, such as in still images and film and television visual effects, and more poorly suited for real-time applications like video games where speed is critical. Ray tracing is capable of simulating a wide variety of optical effects, such as reflection and refraction, scattering, and dispersion phenomena (such as chromatic aberration).

We're a team of four who've realized this project by combing a series of modules and features to make a pretty fun ray tracer. This includes next features:
```diff
+ Blinn-Phong shading
+ Lambert shading
+ Cell shading
+ Super anti-aliasing
+ Fast anti aliasin
+ Cartoon effect
+ Motion blur
+ Visualization of normals
+ Visualization of dots
+ Draft mode
+ Multithreading
+ Reflection
+ Refraction
+ Outline
+ JSON format map

Filters:
+ Sepia
+ Black-White
+ Darkroom

Primitives:
+ Sphere
+ Half_sphere
+ Disk
+ Plane
+ Cone
+ Cylinder
+ Cd_Disc
+ Ellipsoid
```


All input parameters are set in a strictly formatted JSON format. And on this document will explain:
1. How to write scenes on JSON.
2. How to add switch on/off something raytrace effects
3. How set multi spots of lights

# :cd: Installation
The project only work on Mac OS X.

It uses the MinilibX, a micro-library that provides an easy way to create a window and push an image on it.
```
make
```

# Usage
	./rt ./maps/__map__.json

# Command List
|                Key               |                Function                 |
| -------------------------------- |:---------------------------------------:|
| <kbd>+</kbd> <kbd>-</kbd>        | move camera up/down on y axis 	     |
| <kbd>Y</kbd> <kbd>H</kbd>        | look up/down          		     |
| <kbd>W</kbd> <kbd>S</kbd>        | look left/right      		     |
| <kbd>A</kbd> <kbd>D</kbd>        | look around    		     |
| <kbd>UP</kbd> <kbd>DOWN</kbd>    | move camera  up/down	             |
| <kbd>LEFT</kbd> <kbd>RIGHT</kbd> | move camera left/right   		     |
| <kbd>ENTER</kbd>                 | switch off/on lights		     |
| <kbd>F-19</kbd>                  | save image on PPM format to current dir |	     |


## Your map has to extension .json format (JavaScript Object Notation)
A complete map will have the following Elements specified by the user:
```
General options
Light
Objects
```
Attention! The map is strictly structured and must correspond to the valid JSON format and parameters should be passed as in the example.

Light and objects are stored in the JSON array and should be highlighted with the following symbols [ ]

```diff
#Map Examle:
{
    "parameters": "General",
    "general":              /*Basic parameters are set in this structure*/
          {
            "screen_size":{
-             "width": 700,     / See available screen resolutions \
-             "height": 800     \   				   /
            },
            "name_win": "Raytrace by RT_MAFIA",
            "light_off_on": false,
+           "lambert_light":  true,   /*************\
-           "cel_shaded":  false,    | Only one      |
-           "blinn_fong":  false,    | parameter     |
-           "view_normal":  false,   | can be true   |
-           "view_point":  false,     \*************/
+           "ssaa":  true,           / only one     \
-	    "fxaa":  true,           \ can be true  /
            "size_ssaa": 8,
	    "shadow":  true,
+           "filters":  true,       	/***************\
-           "darkroom":  true,	       | only one filter |
+           "black_and_white":  true,  | can be true     |
-           "sepia":  true,  	        \***************/
            "motion_blur":  true,
+           "size_blur": 45,         /from 1 to 49/
            "fov_on":  true,
	    "speed": 9000,           /from 1 to 999/
            "depth_rec": 222,
            "fieldofview": 111,
            "draft_x":  2,           /from 1 to 5/   /if  ssaa == true or fxaa == true or motion blur == true  \
            "draft_y":  2,           /from 1 to 5/   \draft_x and draft_y must be 1                            /
            "background_color": {
              "r": 255,
              "g": 55,
              "b": 99},
            "camera_position": {
              "x": 10,
              "y": 20,
              "z": 40}
          },
    "light": "Lights",
      "lights"
+     [           /*Lights parameters are set in this array*/
        {
            "position": {
              "x": 1,
              "y": 2,
              "z": 3},
            "direction": {
              "x": -1,
              "y": -2,
              "z": -3},
            "color": {
              "r": 255,
              "g": 123,
              "b": 100}
          },
          {
            "position": {
              "x": -11,
              "y": -12,
              "z": -13},
            "direction": {
              "x": -12,
              "y": -11,
              "z": -112},
            "color": {
              "r": 25,
              "g": 123,
              "b": 70}
          },
          {
            "position": {
              "x": -121,
              "y": -121,
              "z": -213},
            "direction": {
              "x": -129,
              "y": -128,
              "z": -127},
            "color": {
              "r": 25,
              "g": 222,
              "b": 110}
          }
      ],
    "name": "Objects",
+       "objects":       /*Objects parameters are set in this array*/
        [
          {
            "type":       "Half_sphere",
+           "size":      111 ,       /from 0 to 999999, but CONE size must be 1-360/
            "height":   190,
            "weight":   170,
            "reflection": true,
            "refraction": false,
            "param_refract": 77,
+           "shines": 88,            /from 1 to 600/
            "position": {
              "x": 11,
              "y": 12,
              "z": 13},
            "rotation": {
              "x": 190,
              "y": 160,
              "z": 190},
-           "direction": {         /direction {0, 0, 0} is not valid/
              "x": -19,
              "y": -18,
              "z": -17},
            "color": {
              "r": 255,
              "g": 123,
              "b": 100}
          },
          {
            "type":       "Cone",
            "size":      24 ,
            "height":   280,
            "weight":   270,
            "reflection": true,
            "refraction": false,
            "param_refract": 77,
            "shines": 88,
            "position": {
              "x": -21,
              "y": -21,
              "z": -213},
            "rotation": {
              "x": 290,
              "y": 260,
              "z": 290},
            "direction": {
              "x": -29,
              "y": -28,
              "z": -27},
            "color": {
              "r": 25,
              "g": 123,
              "b": 70}
          }
        ]
}
```
# Available screen resolutions
```
320 х 240
352 х 240
352 х 288
400 х 24
480 х 576
640 х 240
320 х 480
640 х 360
640 х 480
800 х 480
800 х 600
848 х 480
960 х 540
1024 х 600
1024 х 768
1152 х 864
1200 х 600
1280 х 720
1280 х 768
1280 х 1024
1440 х 900
1400 х 1050
1500 х 1024
1536 х 960
1536 х 1024
1600 х 900
1600 х 1024
1600 х 1200
1680 х 1050
1920 х 1080
1920 х 1200
```

## :muscle: Authors
* [**Antonio Sviridov**](https://github.com/liderako/)
* [**Vadim Kuzmyk**](https://github.com/kuzmykvadim/)
* [**Alisa Soroka**](https://github.com/AliceSor/)
* [**Oleksandr Tkachyk**](https://github.com/otkachyk/)
