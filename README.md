# Ultrasonic Sensor Project

This repository contains a Raspberry Pi Pico C project for reading an ultrasonic distance sensor.

## Files
- `Ultrasonic.c`: application entry point
- `codesonic.c` / `codesonic.h`: ultrasonic sensor support code
- `CMakeLists.txt`: build configuration

## Build
From the project root:

```bash
mkdir -p build
cd build
cmake ..
make
```

## Demo
![Ultrasonic demo](Media/Ultrasonic.gif)

Full-quality video: [Ultrasonic.MOV](Media/Ultrasonic.MOV)
