# em100
A web implementation of ase100. View the [live demo here](https://raw.githack.com/peterapps/em100/master/index.html).

This is not actually a port of ase100, but rather an emulator of the E100 built from scratch in JavaScript. The CPU was reverse engineered from the description of the E100 opcodes in [Lab 5](https://grader2.eecs.umich.edu/engr100/lab5/) and the hardware drivers were reverse engineered from the description of the driver protocols in [Lab 7](https://grader2.eecs.umich.edu/engr100/lab7/).

Originally, the project was implemented in [pure JavaScript](https://github.com/peterapps/js100), but this version is using WebAssembly and Emscripten to achieve near-native speed, similar to ase100. Assembly is still done in JavaScript, the CPU is now emulated in C++, and the hardware components are implemented with a mix of both.

# Features
- [x] Assembly
- [x] Memory
- [x] CPU
- [x] Memory
- [x] VGA monitor

# TODO
- [ ] DE2 board switches
- [ ] Hex displays
- [ ] LEDs
- [ ] Clock
- [ ] SDRAM
- [ ] SD card
- [ ] Serial console send
- [ ] Touchscreen
- [ ] Speaker
- [ ] PS/2 keyboard
- [ ] Serial receive
- [ ] USB mouse
- [ ] LCD display
- [ ] Camera
- [ ] Microphone
- [ ] Fast Fourier Transform
- [ ] Fix speaker output
