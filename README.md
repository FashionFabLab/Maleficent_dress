# Maleficent_dress

T.Dallapè, T.Minerbi, M.Perini

At the end of the school, students and teachers of Centro Moda Canossa
accomplish works developed during the year. The projects are shown at
the ending fashion show. This year Fashion FabLab contributed with two
items of clothing: Maleficent dress and volcano skirt.
Maleficent dress is a textile project with wearable technology
integrated, inspired by the stage custume of the Maleficent's character
in the omonimous Disney's film.
Microcontroller Flora is sewed on inner collar of the dress and it
controls two LED RGB strips.
It's programmed to simulate the green vapour effects behind the
protagonist in a scene of the film.

What we need is:

- [Flora](https://learn.adafruit.com/getting-started-with-flora/flora-pinout-diagram)
- [intelligent LED RGB strips](https://github.com/FashionFabLab/Maleficent_dress/blob/master/datasheet/RGB_LED_strip_datasheet.pdf)
- 3.7V battery to supply microcontroller
- 5V battery to supply strips
- wiring to connect strips to microcontroller
- needle and wire to sewed up electronic parts on skirt

Datas and informations about components can be consulted in specific
file:

- electronic components - [DATASHEET](https://github.com/FashionFabLab/Maleficent_dress/tree/master/datasheet)
- electronic scheme to soldering components - [SCHEMATICS](https://github.com/FashionFabLab/Maleficent_dress/tree/master/schematics)
- Arduino code - [SRC](https://github.com/FashionFabLab/Maleficent_dress/tree/master/src/maleficent)
- pictures of project - [PICTURES](https://github.com/FashionFabLab/Maleficent_dress/tree/master/pictures)

Solder wiring from input side of the strips to microcontroller Flora
based on the [electronic scheme](https://github.com/FashionFabLab/Maleficent_dress/blob/master/schematics/Maleficent_dress.fzz)
and on details in [PICTURES](https://github.com/FashionFabLab/Maleficent_dress/blob/master/pictures)
folder.
Remove the silicone casings of the two strips, then insert and set them
in the facings on the shoulders. Sew Flora on inner collar of the dress 
thanks to the free pins' holes of the board.
Connect microcontroller to a computer by USB cable. Download and open
[maleficent.ino](https://github.com/FashionFabLab/Maleficent_dress/blob/master/src/maleficent/maleficent.ino)
file and be sure you have [Arduino IDE](https://learn.adafruit.com/adafruit-arduino-ide-setup/arduino-1-dot-6-x-ide)
and Flora hardware included. Uploaded the code, Flora is programmed and
ready to run.