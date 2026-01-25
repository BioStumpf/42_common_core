*This project has been created as part of the 42 curriculum by \<dstumpf\>.*

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
- Handling keyboard and mouse events

## Instructions
### Requirements
- **Linux**
- **clang** (sudo apt install clang)
- **make** (sudo apt install make)
- **MiniLibX** 
    - on the 42 infrastructure, the library is preinstalled, the makefile includes it during compilation (-lmlx)
    - if not at 42:
    - install the required libraries on your system (sudo apt install ...)
    -  install mlx in the project folder:   
      - ```git clone https://github.com/42paris/minilibx-linux.git | cd minilibx-linux | make```    
      - add/replace in the makefile:
        - ```MINI_DIR := minilibx-linux/```
        - ```CFLAGS_OBJS = -Wall -Wextra -Werror -g -I$(LIBFT_DIR) -I$(MINI_DIR) -c $< -o $@```
        - ```CFLAGS_NAME = -Wall -Wextra -Werror -g -o $@ $(OBJS) $(LIBFT) -lm -L$(MINI_DIR) -lmlx_Linux -lXext -lX11```

### Compilation
- ```make``` will compile a binary called fdf
- ```make clean``` will remove all object and dependency files
- ```make fclean``` will clean and remove the fdf binary
- ```make re``` will fclean and make
- ```make bonus``` will run ```make``` since all bonus files are embedded in the mandatory part

### Excecution
The binary takes in one single argument, which is a valid fdf map.   
```./fdf <mapname>```

## Resources
- For [isometric projection](https://en.wikipedia.org/wiki/Isometric_projection) and [rotations](https://en.wikipedia.org/wiki/Rotation_matrix), the formulas from Wikipedia were used. Note that a z–x rotation was applied instead of the classical y–x rotation, since z represents height rather than y.
- For cavalier projection, the formula from a lecture at [Marburg University](https://www.mathematik.uni-marburg.de/~thormae/lectures/graphics1/graphics_6_2_eng_web.html#1) was followed.
- To understand the fundamentals of the mlx library, this [guide](https://harm-smits.github.io/42docs/) was used.
