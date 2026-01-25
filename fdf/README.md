*This project has been created as part of the 42 curriculum by <dstumpf>.*

# FDF

## Description

**FDF** (*Fil de Fer*, French for “wireframe”*)* is a 42 graphics project that introduces
basic computer graphics, 3D transformations, and event handling using the **MiniLibX**
library.

The goal of the project is to render a 3D wireframe representation of a map described
by a text file containing height values. The program reads the map, projects it from
3D to 2D using an isometric (and cavalier) projection, and displays the result in a
window where the user can interact with the scene.

This project focuses on:
- Parsing structured data from files
- Applying mathematical transformations (scaling, rotation, translation)
- Understanding projection concepts
- Rendering graphics with MiniLibX
- Handling keyboard and window events

## Instructions

### Requirements

- **Linux**
- **clang**
- **make**
- **MiniLibX** (provided by 42)

### Compilation

Clone the repository and compile the project using:

```bash
make
