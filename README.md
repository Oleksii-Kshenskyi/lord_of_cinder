# Lord Of Cinder

Lord Of Cinder is a playground for me to play around with the [Cinder library](https://libcinder.org/) for creative coding. 

There are no plans to make this repository anything specific or to implement anything specific. At the time of writing this, I have no experience with 2D/3D graphics/creative coding whatsoever, and therefore I want to see what it looks like and what I can do with it. I'm also simply curious about libcinder and want to poke around it, get a feel for it and see what it can do.

"Lord Of Cinder" is a reference to the Dark Souls game series. This was what popped up in my brain immediately after I'd first encountered libcinder a couple of years ago.

There won't be any issues or milestones or projects created for now, and no branches. Everything is pushed directly into master. If this project ever becomes something bigger than a playground, then I'll think about formalizing it more.

## Getting libcinder

This work is being done on Linux (Manjaro), and on Linux, you don't have any choice but to build and configure libcinder yourself. I did it according to instructions on the libcinder website [here](https://libcinder.org/docs/guides/linux-notes/ubuntu.html) and [here](https://libcinder.org/docs/guides/cmake/cmake.html#configuring-libcinder). If you're on Windows or Mac, you can simply install the libcinder binaries and use those. You can get the binaries [here](https://libcinder.org/download). Here are the instructions for [OS X](https://libcinder.org/docs/guides/mac-setup/index.html) and [Windows](https://libcinder.org/docs/guides/windows-setup/index.html).

## Building

This project just uses cmake (3.19.6, but any cmake starting from 3.0 will do). To build it, while in the lord_of_cinder repo:
```console
mkdir build
cd build
cmake ..
make
```
to start the executable, while in the build directory after building has finished successfully:
```console
./los
```
Of course, libcinder has to already be properly set up before you attempt to build the project. Make sure the parameters in the CMakeLists.txt correspond to your configurations. Take special care about the CINDER_PATH variable: it has to point to your built installation of libcinder. I put it into `/opt/cinder`, you may need to reconfigure that. If you don't want to mess with the CMakeLists.txt file itself, just give cmake the argument like so:
```console
cmake .. -DCINDER_PATH=<your/path/to/libcinder/here>
```
You may also have to set the cmake build file generator accordingly. I usually use either GCC or Ninja, you may need to use Visual Studio if you're on Windows for example. Example generator:
```console
cmake .. -G "Visual Studio 16 2019 Win64"
```