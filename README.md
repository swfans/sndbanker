# sndbanker

**Bullfrog DAT sound bank creator**

Packs a list of `.wav` sample files to Bullfrog sound bank `.dat` file.

## About

**sndbanker** is a tool for creating `SOUND.DAT` file for Bullfrog Productions
games. While the original iteration of the tool was for Dungeon Keeper, this
particular branch is intended only for Syndicate Wars.

Using a properly formatted .txt file and source sound files, the tool can
assemble a set of sound samples into a SOUND.DAT file usable by the game.

Place the tool in the root directory of the sound files from the swars-sfx repository.

### Usage

 sndbanker.exe [options] (filename)
 
e.g.  sndbanker.exe -o SOUND.DAT filelist_eng.txt

### Options:

-o or --output [filename] - specify the filename to create, otherwise the description line in the .txt file will be used. It's recommended to set -o SOUND.DAT
-v or --verbose - verbose output of what the tool is doing at each stage
