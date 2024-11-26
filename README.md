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

## Building

This tool should build and work on any CPU architecture.

### General building instructions

To build **Bullfrog Engine graphic formats converter**, you will need the following:

* GNU Autotools
* GNU C++ compiler

Once you've made sure you have the above, proceed with the following steps:

1. go into the directory with `sndbanker` source release (containing `res`, `src` etc.)
2. do `autoreconf -if` to create build scripts from templates
3. do `./configure` to make the build scripts find required toolchain and libraries
4. do `make` to compile the executable file

You should now have a working `sndbanker` executable file.

#### Build example - Ubuntu 22.04

Here are specific commands required to compile the executable on Ubuntu linux.

Install the dependencies:

```
sudo apt install gcc-multilib g++-multilib lib32z1
sudo apt install build-essential autoconf libtool make pkg-config
```

Now as our host is ready, we can start working on the actual `sndbanker` sources.
Go to that folder, and generate build scripts from templates using autotools:

```
autoreconf -ivf
```

Next, proceed with the build steps; we will do that in a separate folder.

```
mkdir -p release; cd release
../configure
make V=1
```

The `V=1` variable makes `make` print each command it executes, which makes
diagnosing issues easier.

On success, you will have the executable.

Finally, you can copy the files to some installation folder, ie. `pkg`:

```
make V=1 DESTDIR=$PWD/pkg install
```

## Done

This concludes the document.
Remember that with most console tools you can use `--help`.
