# Lord Of Cinder

Lord Of Cinder is a playground for me to play around with the [Cinder library](https://libcinder.org/) for creative coding. 

There are no plans to make this repository anything specific or to implement anything specific. At the time of writing this, I have no experience with 2D/3D graphics/creative coding whatsoever, and therefore I want to see what it looks like and what I can do with it. I'm also simply curious about libcinder and want to poke around it, get a feel for it and see what it can do.

"Lord Of Cinder" is a reference to the Dark Souls game series. This was what popped up in my brain immediately after I'd first encountered libcinder a couple of years ago.

There won't be any issues or milestones or projects created for now, and no branches. Everything is pushed directly into master.

## WARNING: PROJECT ON HIATUS

This is what this project looks like at the moment:
![Lord of Cinder, current state](https://github.com/Oleksii-Kshenskyi/lord_of_cinder/blob/main/current_state.gif)

Even though this is not much, the initial idea for this project was a playground to get a feel for what Cinder is. After figuring out what needed to be done to make this cube with a controlled camera, I want to move on to more complex projects. Namely, the ideas right now are to create a 2D simulation (possibly genetic programming) in Rust and a few game demos in different engines/libraries. I'll very likely return to Lord of Cinder in the future though, especially when a new version of Cinder comes out.

## Getting libcinder

This work was done on Linux (Manjaro), and on Linux, you don't have any choice but to build and configure libcinder yourself. I did it according to instructions on the libcinder website [here](https://libcinder.org/docs/guides/linux-notes/ubuntu.html) and [here](https://libcinder.org/docs/guides/cmake/cmake.html#configuring-libcinder). If you're on Windows or Mac, you can simply install the libcinder binaries and use those. You can get the binaries [here](https://libcinder.org/download). Here are the instructions for [OS X](https://libcinder.org/docs/guides/mac-setup/index.html) and [Windows](https://libcinder.org/docs/guides/windows-setup/index.html).

Please note that on Manjaro, I experienced some problems with Cinder not importing Boost::system and Boost::filesystem properly (Lord of Cinder cmake output was that the project depends on those two libs, but can't find them). You can see in [CMakeLists.txt](https://github.com/Oleksii-Kshenskyi/lord_of_cinder/blob/main/CMakeLists.txt) that I had to manually link my Manjaro pacman-installed boost here. If you encounter the same issue while working with Cinder, just know that it can be fixed by simply manually linking boost in your CMakeLists.txt.

Also, it seems like Cinder is removing boost from their repo for future versions, so hopefully this problem is not going to persist in the future releases.

## Building

This project just uses cmake (3.19.6, but any cmake starting from 3.0 will do). To build it, while in the lord_of_cinder repo:
```console
mkdir build
cd build
cmake .. -DCMAKE_BUILD_TYPE=Release
make
```
to start the executable, while in the `build` directory after building has finished successfully:
```console
./Release/los/los
```
Of course, libcinder has to already be properly set up before you attempt to build the project. Make sure the parameters in the CMakeLists.txt correspond to your configurations. Take special care about the CINDER_PATH variable: it has to point to your built installation of libcinder. I put it into `/opt/cinder`, you may need to reconfigure that. If you don't want to mess with the CMakeLists.txt file itself, just give cmake the argument like so:
```console
cmake .. -DCINDER_PATH=<your/path/to/libcinder/here>
```
You may also have to set the cmake build file generator accordingly. I usually use either GCC or Ninja, you may need to use Visual Studio if you're on Windows for example. Example generator:
```console
cmake .. -G "Visual Studio 16 2019 Win64"
```