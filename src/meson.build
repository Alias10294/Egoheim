subdir('game_systems')

src_files = ['Game.cpp', 'SDLContext.cpp']
src_lib = static_library(
    'src_lib', 
    src_files, 
    include_directories: [inc, include_directories('../include')], 
    dependencies: [sdl2, nlohmann_json]
)