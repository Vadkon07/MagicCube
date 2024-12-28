<p align="center">
  <img src="https://img.shields.io/badge/LICENSE-MIT-green"/>
</p>

# ***MagicCube***

Try to look in your future and make a right decision before it by using MagicCube!

MagicCube that'a a magic cube which can tell you about something what's going on in your life. Like, if you think "Will I get a driver's license during the next year?", and if cube shows to you "Unlikely...", probably now you shouldn't buy a car.

## Requirements

OS: Linux, Windows
RAM: 128MB
GPU: any

## Installation

### Prerequisites
Make sure GTK3 is installed on your system. If not, you can install them with the following commands:
```bash
sudo apt-get install libgtk-3-dev
```

### Compilation
After installing the required libraries, compile the app using:

```bash
gcc -o magiccube main.c `pkg-config --cflags --libs gtk+-3.0`
```

Running the Application
Once compiled, run the application with:
```bash
./magiccube
```

## Features
- **Offline:** This app is fully offline, so you can use her even when you're not connected to internet.
- **Very Funny:** I think that you understand that it's all not real and it's just a piece of code which shows to you random words which I prescribed to him. So, don't live in your fantasies, use this app only for entertainment!

## To-Do
Below is a list of potential features that can be added in future versions of the app:

- [X] **Cool Animation:** Add a fade-in animation and also a blue light below her.
- [ ] **Fix this README and make him better at all.**
- [ ] **More Responses.**
- [ ] **Fix Bugs.**

## License

This project is licenced under the MIT.
