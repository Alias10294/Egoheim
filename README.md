# Egoheim

## Prerequisites :
- Compiler: C++ compiler
- Build system: Meson

To install Meson, follow this documentation : [Installing Meson]( https://mesonbuild.com/SimpleStart.html#installing-meson)

## Installation : 
Once all of the prerequisites are completed, these are the only commands you need to execute :
```
cd <path_to_directory_you_prefer>
git clone https://github.com/Alias10294/Egoheim.git
meson setup build
```

## Execution :
Once the installation is complete, the project should now be ready to be compiled using this command :
```
meson compile -C build
```
And you can execute the project using : 
```
.\egoheim
```

## Resources :
- [Installing Meson]( https://mesonbuild.com/SimpleStart.html#installing-meson)
- [SDL2 Documentation](https://wiki.libsdl.org/)