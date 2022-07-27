# ModFinder

ModFinder is one of my first useful C++ applications that I've developed that would get occasional use. It took me a decent amount of time to create, but I am currently quite satisfied with the result. The purpose of ModFinder is to detect memory regions that are injected via the manual-map method. (The program is unfortunately only compatible with x86 processes. (x64 Implementation is planned in the future and should be extremely simple to implement.)

The reason that ModFinder distinguishes from other manual-map detection programs, is due to how well it performs at detecting regions which were mapped.

The following injectors have been tested and have successfully been detected:

- https://github.com/DarthTon/Xenos
- https://github.com/master131/ExtremeInjector
- AlisaAlis Manual Map DLL Injector
- https://github.com/danielkrupinski/MemJect

# To Do

    Ignore natively loaded dll base addresses
    Check for dll manifest string
    Support for x64 processes
    Possible code improvements (if needed)
