# ModFinder

ModFinder is one of my first useful C++ applications that I've developed that would get occasional use. It took me a decent amount of time to create, but I am currently quite satisfied with the result. The purpose of ModFinder is to detect memory regions that are injected via the manual-map method. (The program is unfortunately only compatible with x86 processes. (x64 Implementation is planned in the future and should be extremely simple to implement.)

The reason that ModFinder distinguishes from other manual-map detection programs, is due to how well it performs at detecting regions which were mapped.

The following injectors have been tested and have successfully been detected:

- https://www.unknowncheats.me/forum/c-and-c-/378849-dump-manually-mapped-dlls.html
- https://www.unknowncheats.me/forum/c-and-c-/469426-manual-map-detection.html
- https://www.unknowncheats.me/forum/c-and-c-/225605-detect-manual-map-injection.html"]Detect manual map injection
- https://www.unknowncheats.me/forum/c-and-c-/422511-detect-dll-injection-manual-map.html

# To Do

- Ignore natively loaded dll base addresses
- Check for dll manifest string
- Support for x64 processes
- Possible code improvements (if needed)
