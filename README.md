# ESP32 basic web server

I was realy REALY bored recently and I decided to make a web server
using the ESP32. This specific example opens a Wi-Fi AP, that when connected to
will have a `home.local` domain. The website on the domain has two buttons, that when
pressed will change the displayed image on the screen. Very simple.

## The web server
The web server supports the following features:
- Serving static files (that are uploaded to SPIFFS)
- Endpoints with actions (like turning on and off a LED)
- Logging via serial when in debug mode
- The default action as written in `server.cpp` server the `index.html` file

Currently supported file types for static files are (but not limited to (it's very easy to expand upon)):
- HTML
- CSS
- JS
- PNG
- JPG

## The hardware
To run this you will need a:
- ESP32
- A display (I used a Sharp Memory low power LCD)

## Before running
Make sure to upload the file system image. All the files should be located in the
`data` folder.

## Included tools:
There is a script that will be run when the project is **BUILT**. 
It's the included binary image converter. Converts .jpg images to suitable
monochrome binary file formats, that are used with the provided graphics library.

If you wish to add any custom images of yours they can be easily added into the
`pre_upload.py` script, take a look it's just an array. I recommend reading the docs
on [this](https://github.com/Tevz-Beskovnik/Binary-image-converter) repository beforehand though.
