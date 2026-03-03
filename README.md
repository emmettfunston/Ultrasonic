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

## Demo Video
<video src="assets/Ultrasonic.MOV" controls width="720"></video>

If your viewer does not render embedded video, use this direct link:

[Download demo video](assets/Ultrasonic.MOV)
