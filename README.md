# CUB3D 🎮

A raycasting game engine inspired by Wolfenstein 3D, built as part of the 42 School curriculum.

## 🌟 Overview

CUB3D is a project that recreates the magic of early 3D games using raycasting technology. This project implements a simple 3D graphics engine that creates the illusion of a 3D environment from a 2D map.

## 📁 Project Structure
```
CUB3D/
├── Makefile
├── includes/     # Header files
├── maps/        # Game map files
├── src/         # Source code
└── walls/       # Texture files for walls
```

## 🛠️ Technical Features

- Raycasting rendering engine
- Textured walls
- Player movement and rotation
- Collision detection
- Map parsing from file
- Minimap display (if implemented)

## 🗺️ Map Configuration

The game uses `.cub` files to define the game environment. Map elements include:
- Walls (1)
- Empty spaces (0)
- Player starting position (N/S/E/W)
- Textures for different walls
- Colors for floor and ceiling

Example map format:
```
NO ./path_to_the_north_texture
SO ./path_to_the_south_texture
WE ./path_to_the_west_texture
EA ./path_to_the_east_texture

F 220,100,0
C 225,30,0

        1111111111111111111111111
        1000000000110000000000001
        1011000001110000000000001
        1001000000000000000000001
111111111011000001110000000000001
100000000011000001110111111111111
11110111111111011100000010001
11110111111111011101010010001
11000000110101011100000010001
10000000000000001100000010001
10000000000000001101010010001
11000001110101011111011110N0111
11110111 1110101 101111010001
11111111 1111111 111111111111
```

## 🚀 Getting Started

### Prerequisites
- GCC compiler
- Make
- MinilibX library
- X11 development libraries (for Linux)

### Installation

1. Clone the repository:
```bash
git clone https://github.com/Nellaoui/CUB3D.git
cd CUB3D
```

2. Compile the project:
```bash
make
```

### Usage

Run the program with a map file:
```bash
./cub3D maps/map.cub
```

## 🎮 Controls

- `W` - Move forward
- `S` - Move backward
- `A` - Strafe left
- `D` - Strafe right
- `←` - Rotate camera left
- `→` - Rotate camera right
- `ESC` - Exit game

## 🖥️ Technical Requirements

- The program must use the MiniLibX library
- Smooth window management
- Display different wall textures depending on wall orientation
- Different colors for floor and ceiling

## 🔍 Error Handling

The program includes extensive error checking for:
- Invalid map files
- Missing textures
- Incorrect map configuration
- Memory allocation failures
- Invalid map characters

## 🤝 Contributing

1. Fork the repository
2. Create your feature branch (`git checkout -b feature/AmazingFeature`)
3. Commit your changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

## 📝 License

This project is part of the 42 School curriculum. Please check with 42's policy regarding code usage and distribution.

## 👥 Authors

- [@Nellaoui](https://github.com/Nellaoui)

## 🙏 Acknowledgments

- 42 School for the project requirements
- Wolfenstein 3D for the inspiration
- MinilibX developers
