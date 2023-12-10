# 42cursus_fdf
This project is about representing a landscape as a 3D object in which all surfaces are outlined in lines. The use of the MinilibX is mandatory. The project includes as bonus features isometric and parallel projections, three color themes (default, inverted colors and a specific theme for landscapes), model traslation and zoom.

![C](https://img.shields.io/badge/C-a?style=for-the-badge&logo=C&color=grey)

You can see the subject [**HERE.**](https://github.com/MGuardia10/42cursus/blob/main/subjects/en/fdf_subject_en.pdf)

<p align="center">
	<img src="https://raw.githubusercontent.com/MGuardia10/42cursus_fdf/main/img/fdf_42.png" />
	<img src="https://raw.githubusercontent.com/MGuardia10/42cursus_fdf/main/img/fdf_land.png" />
	<img src="https://raw.githubusercontent.com/MGuardia10/42cursus_fdf/main/img/fdf_himalaya.png" />
	<img src="https://raw.githubusercontent.com/MGuardia10/42cursus_fdf/main/img/fdf_mandelbrot.png" />
	<img src="https://raw.githubusercontent.com/MGuardia10/42cursus_fdf/main/img/fdf_julia.png" />
</p>

## Installing and running the project:

1- Clone this repository
	
	git clone https://github.com/MGuardia10/42cursus_fdf.git
2- Navigate to the new directory and run `make`
	
	cd 42cursus_fdf
   	make
3- `make clean` to remove the object files and work on a cleaner directory

	make clean
4- Start using the program with any map from the maps directory:

	./fdf maps/42.fdf

## Compiling the Program
The fdf program comes with a Makefile that includes the following rules:

- `all`: compiles the program.
- `re`: recompiles the program.
- `clean`: removes all object files.
- `fclean`: removes all object files and fdf binary.

## Disclaimer
> At [42School](https://en.wikipedia.org/wiki/42_(school)), almost every project must be written in accordance to the [Norm](https://github.com/MGuardia10/42cursus/blob/main/subjects/en/norm_en.pdf), the school's coding standard. As a result, the implementation of certain parts may appear strange and for sure had room for improvement.
